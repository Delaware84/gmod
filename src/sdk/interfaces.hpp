// Auto-generated GMod x64 SDK — interfaces.hpp
#pragma once
#include <windows.h>
#include <cstdint>

namespace SDK {
    class InterfaceManager {
    private:
        typedef void* (*CreateInterfaceFn)(const char* pName, int* pReturnCode);
    public:
        template <typename T>
        static T get(const char* moduleName, const char* interfaceName) {
            HMODULE hModule = GetModuleHandleA(moduleName);
            if (!hModule) return nullptr;
            auto createInterface = reinterpret_cast<CreateInterfaceFn>(GetProcAddress(hModule, "CreateInterface"));
            if (!createInterface) return nullptr;
            return reinterpret_cast<T>(createInterface(interfaceName, nullptr));
        }
    };

    namespace Interfaces {
        namespace client {
            constexpr const char* VCLIENTTOOLS001 = "VCLIENTTOOLS001";
            constexpr const char* Shield_IMaterialProxy003 = "Shield_IMaterialProxy003";
            constexpr const char* GameMovement001 = "GameMovement001";
            constexpr const char* VortEmissive_IMaterialProxy003 = "VortEmissive_IMaterialProxy003";
            constexpr const char* HeliBlade_IMaterialProxy003 = "HeliBlade_IMaterialProxy003";
            constexpr const char* WorldDims_IMaterialProxy003 = "WorldDims_IMaterialProxy003";
            constexpr const char* WaterLOD_IMaterialProxy003 = "WaterLOD_IMaterialProxy003";
            constexpr const char* MotionBlur_IMaterialProxy003 = "MotionBlur_IMaterialProxy003";
            constexpr const char* engine_post_IMaterialProxy003 = "engine_post_IMaterialProxy003";
            constexpr const char* VCENTERPRINT002 = "VCENTERPRINT002";
            constexpr const char* ToggleTexture_IMaterialProxy003 = "ToggleTexture_IMaterialProxy003";
            constexpr const char* CurrentTime_IMaterialProxy003 = "CurrentTime_IMaterialProxy003";
            constexpr const char* TextureScroll_IMaterialProxy003 = "TextureScroll_IMaterialProxy003";
            constexpr const char* Pupil_IMaterialProxy003 = "Pupil_IMaterialProxy003";
            constexpr const char* PlayerLogo_IMaterialProxy003 = "PlayerLogo_IMaterialProxy003";
            constexpr const char* EntityRandom_IMaterialProxy003 = "EntityRandom_IMaterialProxy003";
            constexpr const char* EntitySpeed_IMaterialProxy003 = "EntitySpeed_IMaterialProxy003";
            constexpr const char* PlayerPosition_IMaterialProxy003 = "PlayerPosition_IMaterialProxy003";
            constexpr const char* PlayerSpeed_IMaterialProxy003 = "PlayerSpeed_IMaterialProxy003";
            constexpr const char* PlayerView_IMaterialProxy003 = "PlayerView_IMaterialProxy003";
            constexpr const char* PlayerTeamMatch_IMaterialProxy003 = "PlayerTeamMatch_IMaterialProxy003";
            constexpr const char* PlayerProximity_IMaterialProxy003 = "PlayerProximity_IMaterialProxy003";
            constexpr const char* Health_IMaterialProxy003 = "Health_IMaterialProxy003";
            constexpr const char* VParticleSystemQuery001 = "VParticleSystemQuery001";
            constexpr const char* ParticleSphereProxy_IMaterialProxy003 = "ParticleSphereProxy_IMaterialProxy003";
            constexpr const char* MatrixRotate_IMaterialProxy003 = "MatrixRotate_IMaterialProxy003";
            constexpr const char* TextureTransform_IMaterialProxy003 = "TextureTransform_IMaterialProxy003";
            constexpr const char* SelectFirstIfNonZero_IMaterialProxy003 = "SelectFirstIfNonZero_IMaterialProxy003";
            constexpr const char* WrapMinMax_IMaterialProxy003 = "WrapMinMax_IMaterialProxy003";
            constexpr const char* LessOrEqual_IMaterialProxy003 = "LessOrEqual_IMaterialProxy003";
            constexpr const char* Empty_IMaterialProxy003 = "Empty_IMaterialProxy003";
            constexpr const char* Abs_IMaterialProxy003 = "Abs_IMaterialProxy003";
            constexpr const char* Exponential_IMaterialProxy003 = "Exponential_IMaterialProxy003";
            constexpr const char* GaussianNoise_IMaterialProxy003 = "GaussianNoise_IMaterialProxy003";
            constexpr const char* UniformNoise_IMaterialProxy003 = "UniformNoise_IMaterialProxy003";
            constexpr const char* LinearRamp_IMaterialProxy003 = "LinearRamp_IMaterialProxy003";
            constexpr const char* Int_IMaterialProxy003 = "Int_IMaterialProxy003";
            constexpr const char* Frac_IMaterialProxy003 = "Frac_IMaterialProxy003";
            constexpr const char* Equals_IMaterialProxy003 = "Equals_IMaterialProxy003";
            constexpr const char* Sine_IMaterialProxy003 = "Sine_IMaterialProxy003";
            constexpr const char* Clamp_IMaterialProxy003 = "Clamp_IMaterialProxy003";
            constexpr const char* Divide_IMaterialProxy003 = "Divide_IMaterialProxy003";
            constexpr const char* Multiply_IMaterialProxy003 = "Multiply_IMaterialProxy003";
            constexpr const char* Subtract_IMaterialProxy003 = "Subtract_IMaterialProxy003";
            constexpr const char* Add_IMaterialProxy003 = "Add_IMaterialProxy003";
            constexpr const char* lamphalo_IMaterialProxy003 = "lamphalo_IMaterialProxy003";
            constexpr const char* lampbeam_IMaterialProxy003 = "lampbeam_IMaterialProxy003";
            constexpr const char* IsNPC_IMaterialProxy003 = "IsNPC_IMaterialProxy003";
            constexpr const char* Ep1IntroVortRefract_IMaterialProxy003 = "Ep1IntroVortRefract_IMaterialProxy003";
            constexpr const char* EntityOriginAlyx_IMaterialProxy003 = "EntityOriginAlyx_IMaterialProxy003";
            constexpr const char* EntityOrigin_IMaterialProxy003 = "EntityOrigin_IMaterialProxy003";
            constexpr const char* IEffects001 = "IEffects001";
            constexpr const char* Dummy_IMaterialProxy003 = "Dummy_IMaterialProxy003";
            constexpr const char* ShadowModel_IMaterialProxy003 = "ShadowModel_IMaterialProxy003";
            constexpr const char* Shadow_IMaterialProxy003 = "Shadow_IMaterialProxy003";
            constexpr const char* ClientLeafSystem002 = "ClientLeafSystem002";
            constexpr const char* VClientEntityList003 = "VClientEntityList003";
            constexpr const char* VClient017 = "VClient017";
            constexpr const char* Camo_IMaterialProxy003 = "Camo_IMaterialProxy003";
            constexpr const char* MaterialModifyAnimated_IMaterialProxy003 = "MaterialModifyAnimated_IMaterialProxy003";
            constexpr const char* MaterialModify_IMaterialProxy003 = "MaterialModify_IMaterialProxy003";
            constexpr const char* ConveyorScroll_IMaterialProxy003 = "ConveyorScroll_IMaterialProxy003";
            constexpr const char* BreakableSurface_IMaterialProxy003 = "BreakableSurface_IMaterialProxy003";
            constexpr const char* AnimateSpecificTexture_IMaterialProxy003 = "AnimateSpecificTexture_IMaterialProxy003";
            constexpr const char* AnimatedTexture_IMaterialProxy003 = "AnimatedTexture_IMaterialProxy003";
            constexpr const char* AnimatedOffsetTexture_IMaterialProxy003 = "AnimatedOffsetTexture_IMaterialProxy003";
            constexpr const char* AnimatedEntityTexture_IMaterialProxy003 = "AnimatedEntityTexture_IMaterialProxy003";
            constexpr const char* Alpha_IMaterialProxy003 = "Alpha_IMaterialProxy003";
            constexpr const char* IntroScreen004 = "IntroScreen004";
            constexpr const char* FleshInterior_IMaterialProxy003 = "FleshInterior_IMaterialProxy003";
            constexpr const char* VClientPrediction001 = "VClientPrediction001";
            constexpr const char* UpdateScreenEffectTexture_IMaterialProxy003 = "UpdateScreenEffectTexture_IMaterialProxy003";
            constexpr const char* YellowLevel_IMaterialProxy003 = "YellowLevel_IMaterialProxy003";
            constexpr const char* InvulnLevel_IMaterialProxy003 = "InvulnLevel_IMaterialProxy003";
            constexpr const char* BurnLevel_IMaterialProxy003 = "BurnLevel_IMaterialProxy003";
            constexpr const char* spy_invis_IMaterialProxy003 = "spy_invis_IMaterialProxy003";
            constexpr const char* ClientRenderTargets001 = "ClientRenderTargets001";
            constexpr const char* IServerAddons001 = "IServerAddons001";
        }
        namespace engine {
            constexpr const char* VEngineVGui001 = "VEngineVGui001";
            constexpr const char* VSERVERENGINETOOLS001 = "VSERVERENGINETOOLS001";
            constexpr const char* VCLIENTENGINETOOLS001 = "VCLIENTENGINETOOLS001";
            constexpr const char* VTOOLFRAMEWORKVERSION002 = "VTOOLFRAMEWORKVERSION002";
            constexpr const char* VENGINETOOLFRAMEWORK003 = "VENGINETOOLFRAMEWORK003";
            constexpr const char* VENGINETOOL003 = "VENGINETOOL003";
            constexpr const char* XboxSystemInterface001 = "XboxSystemInterface001";
            constexpr const char* VProfExport001 = "VProfExport001";
            constexpr const char* VoiceServer002 = "VoiceServer002";
            constexpr const char* VENGINE_GAMEUIFUNCS_VERSION005 = "VENGINE_GAMEUIFUNCS_VERSION005";
            constexpr const char* VENGINE_HLDS_API_VERSION002 = "VENGINE_HLDS_API_VERSION002";
            constexpr const char* VENGINE_LAUNCHER_API_VERSION004 = "VENGINE_LAUNCHER_API_VERSION004";
            constexpr const char* StaticPropMgrServer002 = "StaticPropMgrServer002";
            constexpr const char* StaticPropMgrClient004 = "StaticPropMgrClient004";
            constexpr const char* SpatialPartition001 = "SpatialPartition001";
            constexpr const char* VEngineRandom001 = "VEngineRandom001";
            constexpr const char* VEngineServerStringTable001 = "VEngineServerStringTable001";
            constexpr const char* VEngineClientStringTable001 = "VEngineClientStringTable001";
            constexpr const char* VModelInfoClient006 = "VModelInfoClient006";
            constexpr const char* VModelInfoServer004 = "VModelInfoServer004";
            constexpr const char* GAMEEVENTSMANAGER001 = "GAMEEVENTSMANAGER001";
            constexpr const char* GAMEEVENTSMANAGER002 = "GAMEEVENTSMANAGER002";
            constexpr const char* EngineTraceClient003 = "EngineTraceClient003";
            constexpr const char* EngineTraceServer003 = "EngineTraceServer003";
            constexpr const char* VCvarQuery001 = "VCvarQuery001";
            constexpr const char* VEngineServer021 = "VEngineServer021";
            constexpr const char* GameServerData001 = "GameServerData001";
            constexpr const char* ISERVERPLUGINHELPERS001 = "ISERVERPLUGINHELPERS001";
            constexpr const char* VEngineRenderView014 = "VEngineRenderView014";
            constexpr const char* VEngineShadowMgr002 = "VEngineShadowMgr002";
            constexpr const char* VEngineEffects001 = "VEngineEffects001";
            constexpr const char* VEngineModel016 = "VEngineModel016";
            constexpr const char* VPhysicsDebugOverlay001 = "VPhysicsDebugOverlay001";
            constexpr const char* VDebugOverlay003 = "VDebugOverlay003";
            constexpr const char* VEngineClient015 = "VEngineClient015";
            constexpr const char* IEngineSoundServer003 = "IEngineSoundServer003";
            constexpr const char* IEngineSoundClient003 = "IEngineSoundClient003";
        }
        namespace vstdlib {
            constexpr const char* VProcessUtils001 = "VProcessUtils001";
            constexpr const char* EventSystem001 = "EventSystem001";
            constexpr const char* VEngineCvar007 = "VEngineCvar007";
        }
        namespace materialsystem {
            constexpr const char* ShaderDLL004 = "ShaderDLL004";
            constexpr const char* ShaderSystem002 = "ShaderSystem002";
            constexpr const char* VMaterialSystemStub001 = "VMaterialSystemStub001";
            constexpr const char* VEngineCvar007 = "VEngineCvar007";
            constexpr const char* MaterialSystemHardwareConfig012 = "MaterialSystemHardwareConfig012";
            constexpr const char* VMaterialSystemConfig002 = "VMaterialSystemConfig002";
            constexpr const char* VMaterialSystem080 = "VMaterialSystem080";
            constexpr const char* COLORCORRECTION_VERSION_1 = "COLORCORRECTION_VERSION_1";
        }
        namespace studiorender {
            constexpr const char* VStudioRender025 = "VStudioRender025";
        }
        namespace vphysics {
            constexpr const char* VPhysicsSurfaceProps001 = "VPhysicsSurfaceProps001";
            constexpr const char* VPhysicsCollision007 = "VPhysicsCollision007";
            constexpr const char* VPhysics031 = "VPhysics031";
        }
        namespace vguimatsurface {
            constexpr const char* VGUI_Surface030 = "VGUI_Surface030";
        }
        namespace vgui2 {
            constexpr const char* VGUI_Panel009 = "VGUI_Panel009";
            constexpr const char* VGUI_ivgui008 = "VGUI_ivgui008";
            constexpr const char* VGUI_System010 = "VGUI_System010";
            constexpr const char* VGUI_Surface030 = "VGUI_Surface030";
            constexpr const char* VGUI_Scheme010 = "VGUI_Scheme010";
            constexpr const char* VguiLocalize004 = "VguiLocalize004";
            constexpr const char* VGUI_InputInternal001 = "VGUI_InputInternal001";
            constexpr const char* VGUI_Input005 = "VGUI_Input005";
        }
        namespace inputsystem {
            constexpr const char* InputSystemVersion001 = "InputSystemVersion001";
            constexpr const char* InputStackSystemVersion001 = "InputStackSystemVersion001";
        }
        namespace lua_shared {
            constexpr const char* LUASHARED003 = "LUASHARED003";
            constexpr const char* LUACONVARS001 = "LUACONVARS001";
        }
        namespace server {
            constexpr const char* VSERVERCHOREOTOOLS001 = "VSERVERCHOREOTOOLS001";
            constexpr const char* VSERVERTOOLS002 = "VSERVERTOOLS002";
            constexpr const char* ServerGameTags001 = "ServerGameTags001";
            constexpr const char* GameMovement001 = "GameMovement001";
            constexpr const char* PluginHelpersCheck001 = "PluginHelpersCheck001";
            constexpr const char* BotManager001 = "BotManager001";
            constexpr const char* PlayerInfoManager002 = "PlayerInfoManager002";
            constexpr const char* PlayerInfoManager001 = "PlayerInfoManager001";
            constexpr const char* HLTVDirector001 = "HLTVDirector001";
            constexpr const char* VServerDllSharedAppSystems001 = "VServerDllSharedAppSystems001";
            constexpr const char* ServerGameClients004 = "ServerGameClients004";
            constexpr const char* ServerGameClients003 = "ServerGameClients003";
            constexpr const char* ServerGameEnts001 = "ServerGameEnts001";
            constexpr const char* ServerGameDLL009 = "ServerGameDLL009";
            constexpr const char* ServerGameDLL008 = "ServerGameDLL008";
            constexpr const char* IEffects001 = "IEffects001";
        }
        namespace datacache {
            constexpr const char* VStudioDataCache005 = "VStudioDataCache005";
            constexpr const char* MDLCache004 = "MDLCache004";
            constexpr const char* VDataCache003 = "VDataCache003";
        }
    }
}
