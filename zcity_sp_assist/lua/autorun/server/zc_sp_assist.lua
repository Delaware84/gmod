-- Z-City solo practice helper. Server-side only: it runs where you are the host.
--
-- Field and function names below were read from Z-City commit 403cbaf (2026-11-10):
--   ply.isTraitor / ply.MainTraitor / ply.SubRole / ply.isGunner
--       gamemodes/zcity/gamemode/modes/homicide/sv_homicide.lua (MODE:Intermission)
--   Entity:FireLuaBullets(bullet)      lua/homigrad/sh_luabullets.lua
--   hg.PhysBullet.CreateBullet(bullet) lua/homigrad/phys_bullets/sh_plugin.lua
--   bullet.Src / bullet.Dir / bullet.Attacker
--       lua/weapons/homigrad_base/sh_bullet.lua (SWEP:FireBullet)
--   hg.GetCurrentCharacter(ply)        lua/homigrad/fake/sv_tier_0.lua
-- Another Z-City revision may rename any of these; the helper then stays idle
-- and says so through zc_sp_status.

if not SERVER then return end

local Pick = include("zc_sp_assist/pick.lua")

local TAG = "[zc_sp] "
local LOG_DIR = "zc_sp_assist"
local LOG_FILE = LOG_DIR .. "/roles.txt"

local cvAim = CreateConVar("zc_sp_aim", "1", FCVAR_ARCHIVE, "Redirect the host's bullets to the nearest bot inside the FOV cone.", 0, 1)
local cvFov = CreateConVar("zc_sp_aim_fov", "10", FCVAR_ARCHIVE, "Cone half-angle in degrees around the bullet direction.", 0, 180)
local cvBone = CreateConVar("zc_sp_aim_bone", "ValveBiped.Bip01_Head1", FCVAR_ARCHIVE, "Bone to aim at.")
local cvRoleLog = CreateConVar("zc_sp_rolelog", "1", FCVAR_ARCHIVE, "Log traitor role changes to console, host chat and data/" .. LOG_FILE, 0, 1)

-- Everything is gated on this: a local session whose only human is the host.
local function SoloHost()
	if game.IsDedicated() then return nil end

	local host

	for _, ply in ipairs(player.GetAll()) do
		if not ply:IsBot() then
			if host then return nil end
			host = ply
		end
	end

	if not IsValid(host) then return nil end
	if not game.SinglePlayer() and not host:IsListenServerHost() then return nil end

	return host
end

local function Character(ply)
	local char = hg and hg.GetCurrentCharacter and hg.GetCurrentCharacter(ply)
	return IsValid(char) and char or ply
end

local function AimPoint(char, boneName)
	local bone = char:LookupBone(boneName)

	if bone then
		local matrix = char:GetBoneMatrix(bone)
		if matrix then return matrix:GetTranslation() end

		local pos = char:GetBonePosition(bone)
		if pos and pos ~= char:GetPos() then return pos end
	end

	return char:WorldSpaceCenter()
end

local function Redirect(bullet)
	if not cvAim:GetBool() then return end
	if not istable(bullet) or bullet.zcspRedirected then return end
	if not isvector(bullet.Src) or not isvector(bullet.Dir) then return end

	local attacker = bullet.Attacker
	if not IsValid(attacker) or not attacker:IsPlayer() or attacker:IsBot() then return end
	if attacker.suiciding then return end
	if SoloHost() ~= attacker then return end

	local src = bullet.Src
	local dir = bullet.Dir:GetNormalized()
	local boneName = cvBone:GetString()

	local points = {}

	for _, bot in ipairs(player.GetBots()) do
		if bot:Alive() then
			local char = Character(bot)
			points[#points + 1] = { pos = AimPoint(char, boneName), bot = bot, char = char }
		end
	end

	local candidates = Pick.WithinFov(src, dir, points, cvFov:GetFloat())
	if #candidates == 0 then return end

	local filter = { attacker, Character(attacker), bullet.Inflictor }

	for i = 1, #candidates do
		local target = candidates[i]
		local tr = util.TraceLine({ start = src, endpos = target.pos, filter = filter, mask = MASK_SHOT })

		if not tr.Hit or tr.Entity == target.char or tr.Entity == target.bot then
			bullet.Dir = (target.pos - src):GetNormalized()
			bullet.zcspRedirected = true
			return
		end
	end
end

-- Wrappers are re-applied from the timer because a Lua refresh of the Z-City
-- files replaces the originals.
local wrapped = { lua = false, phys = false }

local function WrapBulletPaths()
	local ENTITY = FindMetaTable("Entity")
	local fireLua = ENTITY.FireLuaBullets

	if isfunction(fireLua) and fireLua ~= ENTITY.zcspFireLuaBullets then
		local wrapper = function(self, bullet, ...)
			Redirect(bullet)
			return fireLua(self, bullet, ...)
		end

		ENTITY.zcspFireLuaBullets = wrapper
		ENTITY.FireLuaBullets = wrapper
	end

	wrapped.lua = isfunction(ENTITY.FireLuaBullets) and ENTITY.FireLuaBullets == ENTITY.zcspFireLuaBullets

	local phys = hg and hg.PhysBullet
	local create = phys and phys.CreateBullet

	if isfunction(create) and create ~= phys.zcspCreateBullet then
		local wrapper = function(bullet, ...)
			Redirect(bullet)
			return create(bullet, ...)
		end

		phys.zcspCreateBullet = wrapper
		phys.CreateBullet = wrapper
	end

	wrapped.phys = phys ~= nil and isfunction(phys.CreateBullet) and phys.CreateBullet == phys.zcspCreateBullet
end

local lastRole = {}

local function RoleKey(ply)
	if not ply.isTraitor then return "" end
	return (ply.MainTraitor and "main" or "plain") .. "|" .. tostring(ply.SubRole or "")
end

local function LogRoles()
	if not cvRoleLog:GetBool() then return end

	local host = SoloHost()
	if not host then return end

	for _, ply in ipairs(player.GetAll()) do
		local key = RoleKey(ply)

		if lastRole[ply] ~= key then
			lastRole[ply] = key

			if key ~= "" then
				local line = string.format(
					"traitor: %s%s | main=%s | subrole=%s | round=%s",
					ply:Nick(),
					ply:IsBot() and " (bot)" or " (you)",
					tostring(ply.MainTraitor == true),
					tostring(ply.SubRole or "none"),
					tostring(zb and zb.CROUND or "unknown")
				)

				print(TAG .. line)
				host:ChatPrint(TAG .. line)

				file.CreateDir(LOG_DIR)
				file.Append(LOG_FILE, os.date("%Y-%m-%d %H:%M:%S ") .. line .. "\n")
			end
		end
	end
end

hook.Add("PlayerDisconnected", "zc_sp_assist", function(ply)
	lastRole[ply] = nil
end)

timer.Create("zc_sp_assist", 1, 0, function()
	WrapBulletPaths()
	LogRoles()
end)

concommand.Add("zc_sp_status", function(ply)
	if IsValid(ply) and ply ~= SoloHost() then return end

	local host = SoloHost()
	local lines = {
		"solo session (host is the only human): " .. tostring(host ~= nil),
		"Entity:FireLuaBullets wrapped: " .. tostring(wrapped.lua),
		"hg.PhysBullet.CreateBullet wrapped: " .. tostring(wrapped.phys),
		"hg.GetCurrentCharacter present: " .. tostring(hg ~= nil and isfunction(hg.GetCurrentCharacter)),
		"bots alive: " .. tostring(#player.GetBots()),
		"aim=" .. cvAim:GetString() .. " fov=" .. cvFov:GetString() .. " bone=" .. cvBone:GetString() .. " rolelog=" .. cvRoleLog:GetString(),
	}

	for _, line in ipairs(lines) do
		print(TAG .. line)
		if IsValid(ply) then ply:PrintMessage(HUD_PRINTCONSOLE, TAG .. line) end
	end
end)
