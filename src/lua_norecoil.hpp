#pragma once

inline const char* kNoRecoilScript = R"LUA(
    if _G.__NORECOIL_LOADED then return end
    _G.__NORECOIL_LOADED = true

    __dll_RegisterFeature("norecoil", false)

    local PUNCH_GLOBALS = {
        'ViewPunch', 'ViewPunch2', 'ViewPunch3', 'ViewPunch4',
        'Viewpunch', 'Viewpunch2', 'Viewpunch3', 'Viewpunch4',
        'SetViewPunchAngles', 'SetViewPunchVelocity'
    }
    local ORIGINALS = {}
    local STUBBED = false
    local function Noop() end

    local function EnablePunchStub()
        if STUBBED then return end
        for _, name in ipairs(PUNCH_GLOBALS) do
            local fn = _G[name]
            if isfunction(fn) and not ORIGINALS[name] then ORIGINALS[name] = fn end
            _G[name] = Noop
        end
        STUBBED = true
    end

    local function DisablePunchStub()
        if not STUBBED then return end
        for _, name in ipairs(PUNCH_GLOBALS) do 
            if ORIGINALS[name] then _G[name] = ORIGINALS[name] end 
        end
        STUBBED = false
    end

    local function SyncNorecoil()
        if not LocalPlayer or not IsValid(LocalPlayer()) then return end
        
        local enabled = __dll_IsFeatureEnabled("norecoil") or __dll_GetEspSetting("norecoil")
        local punch = __dll_GetEspSetting("norecoilPunch")
        local spread = __dll_GetEspSetting("norecoilSpread")
        local spray = __dll_GetEspSetting("norecoilSpray")
        
        if enabled and punch then
            EnablePunchStub()
        else
            DisablePunchStub()
        end

        local lp = LocalPlayer()
        local wep = lp:GetActiveWeapon()
        if not IsValid(wep) then return end

        if not wep.OrigApplyEyeSpray and wep.ApplyEyeSpray and wep.ApplyEyeSpray ~= Noop then
            wep.OrigApplyEyeSpray = wep.ApplyEyeSpray
        end
        if not wep.OrigApplyEyeSprayVel and wep.ApplyEyeSprayVel and wep.ApplyEyeSprayVel ~= Noop then
            wep.OrigApplyEyeSprayVel = wep.ApplyEyeSprayVel
        end

        if enabled then
            wep.norecoil = spread and true or false
            if spray then
                wep.ApplyEyeSpray = Noop
                wep.ApplyEyeSprayVel = Noop
                if wep.EyeSpray then wep.EyeSpray:Zero() end
                if wep.EyeSprayVel then wep.EyeSprayVel:Zero() end
            else
                wep.ApplyEyeSpray = wep.OrigApplyEyeSpray or Noop
                wep.ApplyEyeSprayVel = wep.OrigApplyEyeSprayVel or Noop
            end
        else
            wep.norecoil = false
            wep.ApplyEyeSpray = wep.OrigApplyEyeSpray or Noop
            wep.ApplyEyeSprayVel = wep.OrigApplyEyeSprayVel or Noop
        end
    end

    hook.Add('Think', 'norecoil_dll_sync', SyncNorecoil)
)LUA";