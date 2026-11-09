#pragma once

inline const char* kEspScript =
R"LUA(
    if _G.__ESP_LOADED then return end
    _G.__ESP_LOADED = true

    __dll_RegisterFeature("esp_boxes", true)

    local function col(name)
        local c = __dll_GetEspColor(name)
        return Color(c.r, c.g, c.b, c.a)
    end

    local traitorWeapons = {
        weapon_buck200knife = true,
        weapon_sogknife = true,
        weapon_p22 = true,
        weapon_hg_type59_tpik = true,
        weapon_walkie_talkie = true,
        weapon_traitor_ied = true,
        weapon_traitor_poison1 = true,
        weapon_traitor_poison2 = true,
        weapon_traitor_poison3 = true,
        weapon_traitor_poison4 = true,
        weapon_traitor_poison_consumable = true,
        weapon_traitor_suit = true,
        weapon_hg_jam = true,
        weapon_hg_shuriken = true,
        weapon_hg_rgd_tpik = true,
        weapon_hg_smokenade_tpik = true,
        weapon_hg_pipebomb_tpik = true,
        weapon_hg_molotov_tpik = true,
        weapon_hg_spear = true,
        weapon_hg_spear_pro = true,
    }

    local realTraitors = {}
    local itemTraitors = {}
    local currentMode = ""
    local iAmTraitor = false
    local traitorAllies = {}

    local boneIndices = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,19,20,21}
    local boneNames = {
        [0]="ValveBiped.Bip01_Pelvis",
        [1]="ValveBiped.Bip01_Spine",
        [2]="ValveBiped.Bip01_Spine1",
        [3]="ValveBiped.Bip01_Spine2",
        [4]="ValveBiped.Bip01_Spine4",
        [5]="ValveBiped.Bip01_Neck1",
        [6]="ValveBiped.Bip01_Head1",
        [7]="ValveBiped.Bip01_L_Clavicle",
        [8]="ValveBiped.Bip01_L_UpperArm",
        [9]="ValveBiped.Bip01_L_Forearm",
        [10]="ValveBiped.Bip01_L_Hand",
        [11]="ValveBiped.Bip01_R_Clavicle",
        [12]="ValveBiped.Bip01_R_UpperArm",
        [13]="ValveBiped.Bip01_R_Forearm",
        [14]="ValveBiped.Bip01_R_Hand",
        [15]="ValveBiped.Bip01_L_Thigh",
        [16]="ValveBiped.Bip01_L_Calf",
        [17]="ValveBiped.Bip01_L_Foot",
        [19]="ValveBiped.Bip01_R_Thigh",
        [20]="ValveBiped.Bip01_R_Calf",
        [21]="ValveBiped.Bip01_R_Foot",
    }

    local function ScanPlayer(ply)
        if not IsValid(ply) or not ply:Alive() then return false end
        local wep = ply:GetActiveWeapon()
        if IsValid(wep) and traitorWeapons[wep:GetClass()] then return true end
        for _, w in ipairs(ply:GetWeapons()) do
            if IsValid(w) and traitorWeapons[w:GetClass()] then return true end
        end
        local inv = ply:GetNetVar('Inventory')
        if istable(inv) and istable(inv.Weapons) then
            for class, _ in pairs(inv.Weapons) do
                if traitorWeapons[class] then return true end
            end
        end
        return false
    end

    net.Receive("RoundInfo", function()
        currentMode = net.ReadString()
        realTraitors = {}
        itemTraitors = {}
    end)

    net.Receive("HMCD_RoundStart", function()
        iAmTraitor = net.ReadBool()
        realTraitors = {}
        itemTraitors = {}

        timer.Simple(0.5, function()
            if not IsValid(LocalPlayer()) then return end
            for _, ply in ipairs(player.GetAll()) do
                if ply == LocalPlayer() then continue end
                if ScanPlayer(ply) then
                    realTraitors[ply] = true
                end
            end
        end)
    end)

    net.Receive("HMCD_UpdateTraitorAssistants", function()
        local amt = net.ReadUInt(8)
        traitorAllies = {}
        for i = 1, amt do
            net.ReadColor()
            net.ReadString()
            local steamID = net.ReadString()
            traitorAllies[steamID] = true
        end
    end)

    hook.Add("WeaponEquip", "ESP_ItemScan", function(wep, ply)
        if not IsValid(ply) or ply == LocalPlayer() then return end
        if currentMode ~= "hmcd" and currentMode ~= "standard" and currentMode ~= "soe" then return end

        if IsValid(wep) and traitorWeapons[wep:GetClass()] then
            if realTraitors[ply] then return end
            itemTraitors[ply] = true
        end
    end)
)LUA"
R"LUA(
    local function FindRagdollForPlayer(ply)
        for _, ent in ipairs(ents.FindByClass("prop_ragdoll")) do
            if IsValid(ent) and ent:GetNWEntity("ply") == ply then
                return ent
            end
        end
        return nil
    end

    local function GetCharacter(ply)
        if not IsValid(ply) then return nil end
        if not ply:IsPlayer() then return ply end

        local rd = ply:GetNWEntity("FakeRagdoll")
        if IsValid(rd) then return rd end

        rd = ply:GetNWEntity("RagdollDeath")
        if IsValid(rd) then return rd end

        if hg and hg.GetCurrentCharacter then
            local char = hg.GetCurrentCharacter(ply)
            if IsValid(char) and char ~= ply then return char end
        end

        if IsValid(ply.FakeRagdoll) then return ply.FakeRagdoll end

        if not ply:Alive() then
            local found = FindRagdollForPlayer(ply)
            if IsValid(found) then return found end
        end

        return ply
    end

    local function isVisible(ent)
        if not IsValid(ent) then return false end
        local tr = util.TraceLine({
            start = EyePos(),
            endpos = ent:GetPos() + Vector(0, 0, 64),
            filter = LocalPlayer(),
            mask = MASK_SOLID_BRUSHONLY
        })
        return not tr.Hit or tr.Entity == ent
    end

    local function ComputeAimPoints(target)
        local hx, hy, hz = 0, 0, 0
        local cx, cy, cz = 0, 0, 0
        local px, py, pz = 0, 0, 0

        local organs = nil
        if hg and hg.organism and hg.organism.GetHitBoxOrgans then
            organs = hg.organism.GetHitBoxOrgans(target:GetModel(), target)
        end

        if organs then
            local headBoneId = target:LookupBone("ValveBiped.Bip01_Head1")
            if headBoneId then
                local mat = target:GetBoneMatrix(headBoneId)
                if mat then
                    local bp, ba = mat:GetTranslation(), mat:GetAngles()
                    local chosen = nil
                    for _, o in ipairs(organs["ValveBiped.Bip01_Head1"] or {}) do
                        if o[1] == "skull" then chosen = o break end
                    end
                    if not chosen then
                        for _, o in ipairs(organs["ValveBiped.Bip01_Head1"] or {}) do
                            if o[1] == "brain" then chosen = o break end
                        end
                    end
                    if chosen then
                        local wp = LocalToWorld(chosen[3], chosen[4], bp, ba)
                        hx, hy, hz = wp.x, wp.y, wp.z
                    else
                        hx, hy, hz = bp.x, bp.y, bp.z
                    end
                end
            end

            local chestBoneId = target:LookupBone("ValveBiped.Bip01_Spine2")
            if chestBoneId then
                local mat = target:GetBoneMatrix(chestBoneId)
                if mat then
                    local bp, ba = mat:GetTranslation(), mat:GetAngles()
                    local chosen = nil
                    for _, o in ipairs(organs["ValveBiped.Bip01_Spine2"] or {}) do
                        if o[1] == "chest" then chosen = o break end
                    end
                    if not chosen then
                        for _, o in ipairs(organs["ValveBiped.Bip01_Spine2"] or {}) do
                            if o[1] == "heart" then chosen = o break end
                        end
                    end
                    if chosen then
                        local wp = LocalToWorld(chosen[3], chosen[4], bp, ba)
                        cx, cy, cz = wp.x, wp.y, wp.z
                    else
                        cx, cy, cz = bp.x, bp.y, bp.z
                    end
                end
            end

            local pelvisBoneId = target:LookupBone("ValveBiped.Bip01_Pelvis")
            if pelvisBoneId then
                local mat = target:GetBoneMatrix(pelvisBoneId)
                if mat then
                    local bp, ba = mat:GetTranslation(), mat:GetAngles()
                    local chosen = nil
                    for _, o in ipairs(organs["ValveBiped.Bip01_Pelvis"] or {}) do
                        if o[1] == "intestines" then chosen = o break end
                    end
                    if chosen then
                        local wp = LocalToWorld(chosen[3], chosen[4], bp, ba)
                        px, py, pz = wp.x, wp.y, wp.z
                    else
                        px, py, pz = bp.x, bp.y, bp.z
                    end
                end
            end
        else
            local hb = target:LookupBone("ValveBiped.Bip01_Head1")
            if hb then
                local hp = target:GetBonePosition(hb)
                if hp then hx, hy, hz = hp.x, hp.y, hp.z + 4 end
            end
            local cb = target:LookupBone("ValveBiped.Bip01_Spine2")
            if cb then
                local cp = target:GetBonePosition(cb)
                if cp then cx, cy, cz = cp.x, cp.y, cp.z end
            end
            local pb = target:LookupBone("ValveBiped.Bip01_Pelvis")
            if pb then
                local pp = target:GetBonePosition(pb)
                if pp then px, py, pz = pp.x, pp.y, pp.z end
            end
        end

        return hx, hy, hz, cx, cy, cz, px, py, pz
    end

    local function ComputeLocalMuzzle()
        local lp = LocalPlayer()
        if not IsValid(lp) then
            __dll_SetLocalMuzzle(0, 0, 0)
            return
        end
        local wep = lp:GetActiveWeapon()
        if not IsValid(wep) then
            __dll_SetLocalMuzzle(0, 0, 0)
            return
        end

        local wm = nil
        local getWM = wep.GetWM
        if type(getWM) == "function" then
            local ok, res = pcall(function() return wep:GetWM() end)
            if ok and IsValid(res) then
                wm = res
            end
        elseif isentity(getWM) and IsValid(getWM) then
            wm = getWM
        end

        if not IsValid(wm) then
            local getWE = wep.GetWeaponEntity
            if type(getWE) == "function" then
                local ok, res = pcall(function() return wep:GetWeaponEntity() end)
                if ok and IsValid(res) then
                    wm = res
                end
            end
        end

        if not IsValid(wm) then
            __dll_SetLocalMuzzle(0, 0, 0)
            return
        end

        local pos = nil

        local lookAtt = wm.LookupAttachment
        if type(lookAtt) == "function" then
            local ok, attId = pcall(function() return wm:LookupAttachment("muzzle") end)
            if ok and attId and attId > 0 then
                local ok2, att = pcall(function() return wm:GetAttachment(attId) end)
                if ok2 and istable(att) and att.Pos then
                    pos = att.Pos
                end
            end
        end

        if not pos then
            local lookBone = wm.LookupBone
            if type(lookBone) == "function" then
                local ok, bId = pcall(function() return wm:LookupBone("muzzle") end)
                if ok and bId and bId >= 0 then
                    local ok2, bp = pcall(function() return wm:GetBonePosition(bId) end)
                    if ok2 and bp then
                        pos = bp
                    end
                end
            end
        end

        if not pos and wep.LocalMuzzlePos then
            local ok, wp = pcall(function()
                return LocalToWorld(wep.LocalMuzzlePos, wep.LocalMuzzleAng or Angle(0,0,0), wm:GetPos(), wm:GetAngles())
            end)
            if ok and wp then pos = wp end
        end

        if not pos then
            local ok, wp = pcall(function() return wm:GetPos() end)
            if ok and wp then pos = wp end
        end

        if pos then
            __dll_SetLocalMuzzle(pos.x, pos.y, pos.z)
        else
            __dll_SetLocalMuzzle(0, 0, 0)
        end
    end

    -- Compute real weapon angle (barrel direction) after WorldModel_Transform.
    -- Call WorldModel_Transform(true) to only compute, not apply.
    local function ComputeLocalWeaponAng()
        local lp = LocalPlayer()
        if not IsValid(lp) then
            __dll_SetLocalWeaponAng(0, 0)
            return
        end
        local wep = lp:GetActiveWeapon()
        if not IsValid(wep) then
            __dll_SetLocalWeaponAng(0, 0)
            return
        end

        local wmt = wep.WorldModel_Transform
        if type(wmt) ~= "function" then
            __dll_SetLocalWeaponAng(0, 0)
            return
        end

        -- WorldModel_Transform(true) returns newPos, newAng, desiredPos, desiredAng
        -- where newAng is the real barrel angle after all offsets.
        local ok, newPos, newAng = pcall(function() return wep:WorldModel_Transform(true) end)
        if not ok or not newAng then
            __dll_SetLocalWeaponAng(0, 0)
            return
        end

        local ang = newAng:Forward():Angle()
        __dll_SetLocalWeaponAng(ang.p, ang.y)
    end

    hook.Add("Think", "__dll_roleBridge", function()
        local lp = LocalPlayer()
        if not IsValid(lp) then return end

        ComputeLocalMuzzle()
        ComputeLocalWeaponAng()

        local doVisible = __dll_GetEspSetting("espVisibleCheck")
        local doBones   = __dll_GetEspSetting("espSkeleton")

        for _, ply in ipairs(player.GetAll()) do
            if ply == lp then continue end
            if not IsValid(ply) then continue end

            local idx = ply:EntIndex()
            if idx <= 0 or idx > 64 then continue end

            if not ply:Alive() then
                __dll_ClearPlayerBones(idx)
                __dll_SetPlayerRole(idx, false, false, false, false, false)
                __dll_SetPlayerAimPoints(idx, 0,0,0, 0,0,0, 0,0,0)
                __dll_SetPlayerVelocity(idx, 0, 0, 0)
                continue
            end

            local isRealTraitor = realTraitors[ply] == true
            local isItemTraitor = itemTraitors[ply] == true
            local isAlly = traitorAllies[ply:SteamID()] == true

            local target = GetCharacter(ply)
            local inRagdoll = IsValid(target) and target:IsRagdoll() and target ~= ply

            local visible = true
            if doVisible and IsValid(target) then
                visible = isVisible(target)
            end

            __dll_SetPlayerRole(idx, isRealTraitor, isItemTraitor, isAlly, visible, inRagdoll)

            if doBones and IsValid(target) then
                __dll_ClearPlayerBones(idx)
                local boneCount = target:GetBoneCount()
                if boneCount and boneCount > 0 then
                    for _, bi in ipairs(boneIndices) do
                        local name = boneNames[bi]
                        if name then
                            local boneId = target:LookupBone(name)
                            if boneId then
                                local pos = target:GetBonePosition(boneId)
                                if pos then
                                    __dll_SetPlayerBone(idx, bi, pos.x, pos.y, pos.z)
                                end
                            end
                        end
                    end
                end
            else
                __dll_ClearPlayerBones(idx)
            end

            if IsValid(target) then
                local hx, hy, hz, cx, cy, cz, px, py, pz = ComputeAimPoints(target)
                __dll_SetPlayerAimPoints(idx, hx, hy, hz, cx, cy, cz, px, py, pz)

                local v = target:GetVelocity()
                __dll_SetPlayerVelocity(idx, v.x, v.y, v.z)
            else
                __dll_SetPlayerAimPoints(idx, 0,0,0, 0,0,0, 0,0,0)
                __dll_SetPlayerVelocity(idx, 0, 0, 0)
            end
        end

        __dll_MarkRoleFrame()
    end)
)LUA"
R"LUA(
    local function drawOutlinedRect(x, y, w, h, color, thickness)
        surface.SetDrawColor(color)
        for i = 0, thickness - 1 do
            surface.DrawOutlinedRect(x - i, y - i, w + i * 2, h + i * 2)
        end
    end

    local function drawCornerBox(x, y, w, h, color, thickness, len)
        surface.SetDrawColor(color)
        local l = math.min(len, math.min(w * 0.4, h * 0.4))
        surface.DrawLine(x, y, x + l, y)
        surface.DrawLine(x, y, x, y + l)
        surface.DrawLine(x + w - l, y, x + w, y)
        surface.DrawLine(x + w, y, x + w, y + l)
        surface.DrawLine(x, y + h - l, x, y + h)
        surface.DrawLine(x, y + h, x + l, y + h)
        surface.DrawLine(x + w - l, y + h, x + w, y + h)
        surface.DrawLine(x + w, y + h - l, x + w, y + h)
    end

    local function drawSkeletonLua(ent, color)
        local bones = {
            { "ValveBiped.Bip01_Head1", "ValveBiped.Bip01_Neck1" },
            { "ValveBiped.Bip01_Neck1", "ValveBiped.Bip01_Spine2" },
            { "ValveBiped.Bip01_Spine2", "ValveBiped.Bip01_Spine1" },
            { "ValveBiped.Bip01_Spine1", "ValveBiped.Bip01_Spine" },
            { "ValveBiped.Bip01_Spine", "ValveBiped.Bip01_Pelvis" },
            { "ValveBiped.Bip01_Pelvis", "ValveBiped.Bip01_L_Thigh" },
            { "ValveBiped.Bip01_L_Thigh", "ValveBiped.Bip01_L_Calf" },
            { "ValveBiped.Bip01_L_Calf", "ValveBiped.Bip01_L_Foot" },
            { "ValveBiped.Bip01_Pelvis", "ValveBiped.Bip01_R_Thigh" },
            { "ValveBiped.Bip01_R_Thigh", "ValveBiped.Bip01_R_Calf" },
            { "ValveBiped.Bip01_R_Calf", "ValveBiped.Bip01_R_Foot" },
            { "ValveBiped.Bip01_Spine2", "ValveBiped.Bip01_L_UpperArm" },
            { "ValveBiped.Bip01_L_UpperArm", "ValveBiped.Bip01_L_Forearm" },
            { "ValveBiped.Bip01_L_Forearm", "ValveBiped.Bip01_L_Hand" },
            { "ValveBiped.Bip01_Spine2", "ValveBiped.Bip01_R_UpperArm" },
            { "ValveBiped.Bip01_R_UpperArm", "ValveBiped.Bip01_R_Forearm" },
            { "ValveBiped.Bip01_R_Forearm", "ValveBiped.Bip01_R_Hand" },
        }
        surface.SetDrawColor(color)
        for _, b in ipairs(bones) do
            local b1 = ent:LookupBone(b[1])
            local b2 = ent:LookupBone(b[2])
            if b1 and b2 then
                local p1 = ent:GetBonePosition(b1)
                local p2 = ent:GetBonePosition(b2)
                local s1 = p1:ToScreen()
                local s2 = p2:ToScreen()
                if s1.visible and s2.visible then
                    surface.DrawLine(s1.x, s1.y, s2.x, s2.y)
                end
            end
        end
    end

    local function GetTargetColor(ply, visible)
        local defaultVis = col("espVisibleColor")
        local defaultInv = col("espInvisibleColor")
        local teammateCol = col("espTeammateColor")
        local traitorAllyCol = col("espTraitorAllyColor")
        local traitorEnemyCol = col("espTraitorEnemyColor")

        local baseColor = visible and defaultVis or defaultInv

        if currentMode == "gwars" or currentMode == "hl2dm" or currentMode == "tdm" or currentMode == "riot" then
            if ply:Team() == LocalPlayer():Team() then
                return teammateCol
            else
                return traitorEnemyCol
            end
        end

        if currentMode == "hmcd" or currentMode == "standard" or currentMode == "soe" then
            if traitorAllies[ply:SteamID()] or realTraitors[ply] then
                if iAmTraitor then
                    return traitorAllyCol
                else
                    return traitorEnemyCol
                end
            end

            if itemTraitors[ply] then
                return Color(255, 165, 0)
            end
        end

        return baseColor
    end
)LUA"
R"LUA(
    hook.Add("HUDPaint", "__dll_esp", function()
        if not __dll_IsFeatureEnabled("esp_boxes") then return end
        if not __dll_GetEspSetting("esp") then return end

        local lp = LocalPlayer()
        if not IsValid(lp) then return end

        local style      = __dll_GetEspSetting("espBoxStyle")
        local thickness  = math.max(1, math.floor(__dll_GetEspSetting("espBoxThickness") + 0.5))
        local widthScale = __dll_GetEspSetting("espBoxWidthScale")
        local skel       = __dll_GetEspSetting("espSkeleton")
        local lines      = __dll_GetEspSetting("espLines")
        local visCheck   = __dll_GetEspSetting("espVisibleCheck")
        local distMax    = __dll_GetEspSetting("espDistanceMax")
        local teamFilt   = __dll_GetEspSetting("espTeamFilter")
        local showStatus = __dll_GetEspSetting("espShowStatus")
        local showRole   = __dll_GetEspSetting("espShowRole")
        local showName   = __dll_GetEspSetting("espName")
        local showHealth = __dll_GetEspSetting("espHealth")
        local showDist   = __dll_GetEspSetting("espDistance")

        local cs = col("espSnaplineColor")
        local ck = col("espSkeletonColor")
        local cf = col("espFillColor")

        local scrW, scrH = ScrW(), ScrH()

        for _, ply in ipairs(player.GetAll()) do
            if ply == lp then continue end
            if not IsValid(ply) then continue end
            if not ply:Alive() then continue end

            local target = GetCharacter(ply)
            if not IsValid(target) then continue end

            local isMate = traitorAllies[ply:SteamID()] or (iAmTraitor and realTraitors[ply])
            if currentMode == "tdm" or currentMode == "gwars" or currentMode == "hl2dm" then
                isMate = (ply:Team() == lp:Team())
            end

            if teamFilt == 1 and isMate then continue end
            if teamFilt == 2 and not isMate then continue end

            local pos = target:GetPos()
            local dist = lp:GetPos():Distance(pos)
            if distMax > 0 and dist > distMax then continue end

            local visible = (not visCheck) or isVisible(target)
            local color = GetTargetColor(ply, visible)

            local headPos, feetPos
            local hb = target:LookupBone("ValveBiped.Bip01_Head1")
            local fl = target:LookupBone("ValveBiped.Bip01_L_Foot")
            local fr = target:LookupBone("ValveBiped.Bip01_R_Foot")
            if hb then
                local hp = target:GetBonePosition(hb)
                if hp then headPos = hp + Vector(0, 0, 6) end
            end
            if fl then
                local fp = target:GetBonePosition(fl)
                if fp then feetPos = fp end
            end
            if not feetPos and fr then
                local fp = target:GetBonePosition(fr)
                if fp then feetPos = fp end
            end

            if not headPos then headPos = pos + Vector(0, 0, 72) end
            if not feetPos then feetPos = pos - Vector(0, 0, 5) end

            local headScr = headPos:ToScreen()
            local feetScr = feetPos:ToScreen()

            if not headScr.visible and not feetScr.visible then continue end

            local top = math.min(headScr.y, feetScr.y)
            local bottom = math.max(headScr.y, feetScr.y)
            local height = bottom - top
            if height < 4 then continue end
            local width = height * widthScale
            local left = (headScr.x + feetScr.x) * 0.5 - width / 2

            if skel and target:GetBoneCount() > 0 then
                drawSkeletonLua(target, ck)
            end

            if style == 0 then
                drawCornerBox(left, top, width, height, color, thickness, width * 0.25)
            elseif style == 1 then
                drawOutlinedRect(left, top, width, height, color, thickness)
            elseif style == 2 then
                surface.SetDrawColor(cf.r, cf.g, cf.b, cf.a)
                surface.DrawRect(left, top, width, height)
                drawCornerBox(left, top, width, height, color, thickness, width * 0.25)
            end

            if lines then
                surface.SetDrawColor(cs)
                surface.DrawLine(scrW / 2, scrH, headScr.x, bottom)
            end

            if showName then
                local nameText = ply:Nick()
                if ply:GetNetVar("handcuffed", false) then nameText = nameText .. " [Cuffed]" end
                draw.SimpleText(nameText, "DermaDefault", left, top - 15, Color(255, 255, 255))
            end

            if showHealth then
                local hp = ply:Health()
                if hp <= 0 then hp = 0 end
                draw.SimpleText("HP: " .. hp, "DermaDefault", left, bottom + 2, Color(120, 255, 120))
            end

            if showDist then
                draw.SimpleText("D: " .. math.floor(dist), "DermaDefault", left, bottom + 15, Color(220, 220, 220))
            end

            if showStatus then
                local hp = math.Clamp(ply:Health(), 0, 100)
                local barH = height * (hp / 100)
                surface.SetDrawColor(0, 0, 0, 180)
                surface.DrawRect(left - 6, top, 4, height)
                surface.SetDrawColor(120, 255, 120, 220)
                surface.DrawRect(left - 6, bottom - barH, 4, barH)
            end

            if showRole then
                if currentMode == "gwars" or currentMode == "hl2dm" or currentMode == "tdm" or currentMode == "riot" then
                    local teamName = (ply:Team() == 0 and "T" or "CT")
                    draw.SimpleText(teamName, "DermaDefault", left, top - 28, color)
                elseif realTraitors[ply] then
                    draw.SimpleText("TRAITOR", "DermaDefaultBold", left, top - 28, col("espTraitorEnemyColor"))
                elseif itemTraitors[ply] then
                    draw.SimpleText("ITEM_T", "DermaDefaultBold", left, top - 28, Color(255, 165, 0))
                end
            end
        end
    end)
)LUA";