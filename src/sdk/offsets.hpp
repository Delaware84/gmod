// Auto-generated GMod x64 SDK — offsets.hpp
// Module bases are resolved at runtime (GetModuleHandleA); no ASLR-dependent
// absolute addresses are kept here.
#pragma once
#include <cstdint>

namespace SDK {
    namespace VMT {
        constexpr int VClient_GetClientMode           = 10;
        constexpr int ClientMode_CreateMove           = 21;
        constexpr int CHLClient_CreateMove            = 20;
        constexpr int CHLClient_FrameStageNotify      = 35;
        constexpr int Engine_GetLocalPlayer           = 12;
        constexpr int EntityList_GetClientEntity      = 3;
        constexpr int CInput_GetUserCmd               = 8;
        constexpr int CInput_MakeWeaponSelection      = 9;
    }

    namespace Offsets {
        namespace client {
            constexpr size_t    Size = 0xb7a000;
            namespace Interfaces {
                constexpr uintptr_t VCLIENTTOOLS001 = 0x3ab130;
                constexpr uintptr_t Shield_IMaterialProxy003 = 0x350470;
                constexpr uintptr_t GameMovement001 = 0x342cf0;
                constexpr uintptr_t VortEmissive_IMaterialProxy003 = 0x33b030;
                constexpr uintptr_t HeliBlade_IMaterialProxy003 = 0x325280;
                constexpr uintptr_t WorldDims_IMaterialProxy003 = 0x30b500;
                constexpr uintptr_t WaterLOD_IMaterialProxy003 = 0x308d90;
                constexpr uintptr_t MotionBlur_IMaterialProxy003 = 0x2f76a0;
                constexpr uintptr_t engine_post_IMaterialProxy003 = 0x2f7650;
                constexpr uintptr_t VCENTERPRINT002 = 0x2dd2e0;
                constexpr uintptr_t ToggleTexture_IMaterialProxy003 = 0x2d5520;
                constexpr uintptr_t CurrentTime_IMaterialProxy003 = 0x2d5330;
                constexpr uintptr_t TextureScroll_IMaterialProxy003 = 0x2d52c0;
                constexpr uintptr_t Pupil_IMaterialProxy003 = 0x2b2c10;
                constexpr uintptr_t PlayerLogo_IMaterialProxy003 = 0x2b2730;
                constexpr uintptr_t EntityRandom_IMaterialProxy003 = 0x2b26b0;
                constexpr uintptr_t EntitySpeed_IMaterialProxy003 = 0x2b26f0;
                constexpr uintptr_t PlayerPosition_IMaterialProxy003 = 0x2b2790;
                constexpr uintptr_t PlayerSpeed_IMaterialProxy003 = 0x2b2810;
                constexpr uintptr_t PlayerView_IMaterialProxy003 = 0x2b2890;
                constexpr uintptr_t PlayerTeamMatch_IMaterialProxy003 = 0x2b2850;
                constexpr uintptr_t PlayerProximity_IMaterialProxy003 = 0x2b27d0;
                constexpr uintptr_t Health_IMaterialProxy003 = 0x2b1e90;
                constexpr uintptr_t VParticleSystemQuery001 = 0x2944a0;
                constexpr uintptr_t ParticleSphereProxy_IMaterialProxy003 = 0x287a10;
                constexpr uintptr_t MatrixRotate_IMaterialProxy003 = 0x27d3e0;
                constexpr uintptr_t TextureTransform_IMaterialProxy003 = 0x27d420;
                constexpr uintptr_t SelectFirstIfNonZero_IMaterialProxy003 = 0x27ce30;
                constexpr uintptr_t WrapMinMax_IMaterialProxy003 = 0x27cf30;
                constexpr uintptr_t LessOrEqual_IMaterialProxy003 = 0x27cd70;
                constexpr uintptr_t Empty_IMaterialProxy003 = 0x27cc00;
                constexpr uintptr_t Abs_IMaterialProxy003 = 0x27cb00;
                constexpr uintptr_t Exponential_IMaterialProxy003 = 0x27cc70;
                constexpr uintptr_t GaussianNoise_IMaterialProxy003 = 0x27ccf0;
                constexpr uintptr_t UniformNoise_IMaterialProxy003 = 0x27cef0;
                constexpr uintptr_t LinearRamp_IMaterialProxy003 = 0x27cdb0;
                constexpr uintptr_t Int_IMaterialProxy003 = 0x27cd30;
                constexpr uintptr_t Frac_IMaterialProxy003 = 0x27ccb0;
                constexpr uintptr_t Equals_IMaterialProxy003 = 0x27cc30;
                constexpr uintptr_t Sine_IMaterialProxy003 = 0x27ce70;
                constexpr uintptr_t Clamp_IMaterialProxy003 = 0x27cb80;
                constexpr uintptr_t Divide_IMaterialProxy003 = 0x27cbc0;
                constexpr uintptr_t Multiply_IMaterialProxy003 = 0x27cdf0;
                constexpr uintptr_t Subtract_IMaterialProxy003 = 0x27ceb0;
                constexpr uintptr_t Add_IMaterialProxy003 = 0x27cb40;
                constexpr uintptr_t lamphalo_IMaterialProxy003 = 0x27aa50;
                constexpr uintptr_t lampbeam_IMaterialProxy003 = 0x27a960;
                constexpr uintptr_t IsNPC_IMaterialProxy003 = 0x277a60;
                constexpr uintptr_t Ep1IntroVortRefract_IMaterialProxy003 = 0x237f30;
                constexpr uintptr_t EntityOriginAlyx_IMaterialProxy003 = 0x237eb0;
                constexpr uintptr_t EntityOrigin_IMaterialProxy003 = 0x237ef0;
                constexpr uintptr_t IEffects001 = 0x2376b0;
                constexpr uintptr_t Dummy_IMaterialProxy003 = 0x236a70;
                constexpr uintptr_t ShadowModel_IMaterialProxy003 = 0x221700;
                constexpr uintptr_t Shadow_IMaterialProxy003 = 0x221750;
                constexpr uintptr_t ClientLeafSystem002 = 0x211980;
                constexpr uintptr_t VClientEntityList003 = 0x20bba0;
                constexpr uintptr_t VClient017 = 0x2077d0;
                constexpr uintptr_t Camo_IMaterialProxy003 = 0x203760;
                constexpr uintptr_t MaterialModifyAnimated_IMaterialProxy003 = 0x1e0930;
                constexpr uintptr_t MaterialModify_IMaterialProxy003 = 0x1e0970;
                constexpr uintptr_t ConveyorScroll_IMaterialProxy003 = 0x1d8de0;
                constexpr uintptr_t BreakableSurface_IMaterialProxy003 = 0x1d8a80;
                constexpr uintptr_t AnimateSpecificTexture_IMaterialProxy003 = 0x1672a0;
                constexpr uintptr_t AnimatedTexture_IMaterialProxy003 = 0x167100;
                constexpr uintptr_t AnimatedOffsetTexture_IMaterialProxy003 = 0x167070;
                constexpr uintptr_t AnimatedEntityTexture_IMaterialProxy003 = 0x166f80;
                constexpr uintptr_t Alpha_IMaterialProxy003 = 0x166610;
                constexpr uintptr_t IntroScreen004 = 0x159680;
                constexpr uintptr_t FleshInterior_IMaterialProxy003 = 0x6f900;
                constexpr uintptr_t VClientPrediction001 = 0x67840;
                constexpr uintptr_t UpdateScreenEffectTexture_IMaterialProxy003 = 0x67580;
                constexpr uintptr_t YellowLevel_IMaterialProxy003 = 0x67510;
                constexpr uintptr_t InvulnLevel_IMaterialProxy003 = 0x674d0;
                constexpr uintptr_t BurnLevel_IMaterialProxy003 = 0x67490;
                constexpr uintptr_t spy_invis_IMaterialProxy003 = 0x67550;
                constexpr uintptr_t ClientRenderTargets001 = 0x650e0;
                constexpr uintptr_t IServerAddons001 = 0x62810;
            }
            namespace VTables {
                constexpr uintptr_t vtable_0x632A20 = 0x632a20;
                constexpr uintptr_t vtable_0x63C680 = 0x63c680;
                constexpr uintptr_t vtable_0x63C9C0 = 0x63c9c0;
                constexpr uintptr_t vtable_0x63D228 = 0x63d228;
                constexpr uintptr_t vtable_0x63D3E0 = 0x63d3e0;
                constexpr uintptr_t vtable_0x63DC80 = 0x63dc80;
                constexpr uintptr_t vtable_0x63E4B0 = 0x63e4b0;
                constexpr uintptr_t vtable_0x63E6C0 = 0x63e6c0;
                constexpr uintptr_t vtable_0x63E930 = 0x63e930;
                constexpr uintptr_t vtable_0x63EA10 = 0x63ea10;
                constexpr uintptr_t vtable_0x63EAA0 = 0x63eaa0;
                constexpr uintptr_t vtable_0x63EB98 = 0x63eb98;
                constexpr uintptr_t vtable_0x63EC18 = 0x63ec18;
                constexpr uintptr_t vtable_0x63ECB0 = 0x63ecb0;
                constexpr uintptr_t vtable_0x63ED18 = 0x63ed18;
                constexpr uintptr_t vtable_0x63EF50 = 0x63ef50;
                constexpr uintptr_t vtable_0x63F260 = 0x63f260;
                constexpr uintptr_t vtable_0x63FA98 = 0x63fa98;
                constexpr uintptr_t vtable_0x63FC10 = 0x63fc10;
                constexpr uintptr_t vtable_0x640010 = 0x640010;
                constexpr uintptr_t vtable_0x640090 = 0x640090;
                constexpr uintptr_t vtable_0x6408C0 = 0x6408c0;
                constexpr uintptr_t vtable_0x640930 = 0x640930;
                constexpr uintptr_t vtable_0x6409A8 = 0x6409a8;
                constexpr uintptr_t vtable_0x640A00 = 0x640a00;
                constexpr uintptr_t vtable_0x640A68 = 0x640a68;
                constexpr uintptr_t vtable_0x640AA0 = 0x640aa0;
                constexpr uintptr_t vtable_0x640AF0 = 0x640af0;
                constexpr uintptr_t vtable_0x640BC0 = 0x640bc0;
                constexpr uintptr_t vtable_0x641228 = 0x641228;
                constexpr uintptr_t vtable_0x641AF0 = 0x641af0;
                constexpr uintptr_t vtable_0x641C68 = 0x641c68;
                constexpr uintptr_t vtable_0x641E38 = 0x641e38;
                constexpr uintptr_t vtable_0x642668 = 0x642668;
                constexpr uintptr_t vtable_0x6427E0 = 0x6427e0;
                constexpr uintptr_t vtable_0x642968 = 0x642968;
                constexpr uintptr_t vtable_0x6431C8 = 0x6431c8;
                constexpr uintptr_t vtable_0x643340 = 0x643340;
                constexpr uintptr_t vtable_0x6433F0 = 0x6433f0;
                constexpr uintptr_t vtable_0x643538 = 0x643538;
                constexpr uintptr_t vtable_0x643580 = 0x643580;
                constexpr uintptr_t vtable_0x6435C8 = 0x6435c8;
                constexpr uintptr_t vtable_0x643708 = 0x643708;
                constexpr uintptr_t vtable_0x643D70 = 0x643d70;
                constexpr uintptr_t vtable_0x643EE8 = 0x643ee8;
                constexpr uintptr_t vtable_0x643FF8 = 0x643ff8;
                constexpr uintptr_t vtable_0x644128 = 0x644128;
                constexpr uintptr_t vtable_0x644B80 = 0x644b80;
                constexpr uintptr_t vtable_0x6457E0 = 0x6457e0;
                constexpr uintptr_t vtable_0x645958 = 0x645958;
                constexpr uintptr_t vtable_0x645E88 = 0x645e88;
                constexpr uintptr_t vtable_0x646750 = 0x646750;
                constexpr uintptr_t vtable_0x6468C8 = 0x6468c8;
                constexpr uintptr_t vtable_0x6469A8 = 0x6469a8;
                constexpr uintptr_t vtable_0x647150 = 0x647150;
                constexpr uintptr_t vtable_0x647BC0 = 0x647bc0;
                constexpr uintptr_t vtable_0x649138 = 0x649138;
                constexpr uintptr_t vtable_0x649208 = 0x649208;
                constexpr uintptr_t vtable_0x649280 = 0x649280;
                constexpr uintptr_t vtable_0x649350 = 0x649350;
                constexpr uintptr_t vtable_0x6493C0 = 0x6493c0;
                constexpr uintptr_t vtable_0x649490 = 0x649490;
                constexpr uintptr_t vtable_0x649500 = 0x649500;
                constexpr uintptr_t vtable_0x6495D0 = 0x6495d0;
                constexpr uintptr_t vtable_0x649640 = 0x649640;
                constexpr uintptr_t vtable_0x649710 = 0x649710;
                constexpr uintptr_t vtable_0x649780 = 0x649780;
                constexpr uintptr_t vtable_0x649850 = 0x649850;
                constexpr uintptr_t vtable_0x6498C8 = 0x6498c8;
                constexpr uintptr_t vtable_0x649998 = 0x649998;
                constexpr uintptr_t vtable_0x649A08 = 0x649a08;
                constexpr uintptr_t vtable_0x649AD8 = 0x649ad8;
                constexpr uintptr_t vtable_0x649B48 = 0x649b48;
                constexpr uintptr_t vtable_0x649C18 = 0x649c18;
                constexpr uintptr_t vtable_0x649C88 = 0x649c88;
                constexpr uintptr_t vtable_0x649D58 = 0x649d58;
                constexpr uintptr_t vtable_0x649DC8 = 0x649dc8;
                constexpr uintptr_t vtable_0x649E98 = 0x649e98;
                constexpr uintptr_t vtable_0x649F08 = 0x649f08;
                constexpr uintptr_t vtable_0x649FD8 = 0x649fd8;
            }
        }
        namespace engine {
            constexpr size_t    Size = 0xe53000;
            namespace Interfaces {
                constexpr uintptr_t VEngineVGui001 = 0x242020;
                constexpr uintptr_t VSERVERENGINETOOLS001 = 0x23dd30;
                constexpr uintptr_t VCLIENTENGINETOOLS001 = 0x23dd20;
                constexpr uintptr_t VTOOLFRAMEWORKVERSION002 = 0x23dd40;
                constexpr uintptr_t VENGINETOOLFRAMEWORK003 = 0x23c280;
                constexpr uintptr_t VENGINETOOL003 = 0x23c280;
                constexpr uintptr_t XboxSystemInterface001 = 0x230410;
                constexpr uintptr_t VProfExport001 = 0x22c6b0;
                constexpr uintptr_t VoiceServer002 = 0x22a930;
                constexpr uintptr_t VENGINE_GAMEUIFUNCS_VERSION005 = 0x224340;
                constexpr uintptr_t VENGINE_HLDS_API_VERSION002 = 0x224320;
                constexpr uintptr_t VENGINE_LAUNCHER_API_VERSION004 = 0x224330;
                constexpr uintptr_t StaticPropMgrServer002 = 0x21f200;
                constexpr uintptr_t StaticPropMgrClient004 = 0x21f1f0;
                constexpr uintptr_t SpatialPartition001 = 0x219200;
                constexpr uintptr_t VEngineRandom001 = 0x207990;
                constexpr uintptr_t VEngineServerStringTable001 = 0x203c00;
                constexpr uintptr_t VEngineClientStringTable001 = 0x2036d0;
                constexpr uintptr_t VModelInfoClient006 = 0x1e58e0;
                constexpr uintptr_t VModelInfoServer004 = 0x1e58f0;
                constexpr uintptr_t GAMEEVENTSMANAGER001 = 0x1b4960;
                constexpr uintptr_t GAMEEVENTSMANAGER002 = 0x1b46b0;
                constexpr uintptr_t EngineTraceClient003 = 0x1b1140;
                constexpr uintptr_t EngineTraceServer003 = 0x1b1150;
                constexpr uintptr_t VCvarQuery001 = 0x189d10;
                constexpr uintptr_t VEngineServer021 = 0x16ae80;
                constexpr uintptr_t GameServerData001 = 0x164ba0;
                constexpr uintptr_t ISERVERPLUGINHELPERS001 = 0x15f0d0;
                constexpr uintptr_t VEngineRenderView014 = 0x148d30;
                constexpr uintptr_t VEngineShadowMgr002 = 0x145f80;
                constexpr uintptr_t VEngineEffects001 = 0x138c80;
                constexpr uintptr_t VEngineModel016 = 0x1081d0;
                constexpr uintptr_t VPhysicsDebugOverlay001 = 0xc7930;
                constexpr uintptr_t VDebugOverlay003 = 0xc7920;
                constexpr uintptr_t VEngineClient015 = 0x7abc0;
                constexpr uintptr_t IEngineSoundServer003 = 0x1ed60;
                constexpr uintptr_t IEngineSoundClient003 = 0x1dc00;
            }
            namespace VTables {
                constexpr uintptr_t vtable_0x38FD18 = 0x38fd18;
                constexpr uintptr_t vtable_0x392500 = 0x392500;
                constexpr uintptr_t vtable_0x392640 = 0x392640;
                constexpr uintptr_t vtable_0x392678 = 0x392678;
                constexpr uintptr_t vtable_0x392838 = 0x392838;
                constexpr uintptr_t vtable_0x3928A0 = 0x3928a0;
                constexpr uintptr_t vtable_0x392918 = 0x392918;
                constexpr uintptr_t vtable_0x392BB0 = 0x392bb0;
                constexpr uintptr_t vtable_0x393280 = 0x393280;
                constexpr uintptr_t vtable_0x393390 = 0x393390;
                constexpr uintptr_t vtable_0x393580 = 0x393580;
                constexpr uintptr_t vtable_0x394248 = 0x394248;
                constexpr uintptr_t vtable_0x3966E8 = 0x3966e8;
                constexpr uintptr_t vtable_0x396940 = 0x396940;
                constexpr uintptr_t vtable_0x396A50 = 0x396a50;
                constexpr uintptr_t vtable_0x396B60 = 0x396b60;
                constexpr uintptr_t vtable_0x396C90 = 0x396c90;
                constexpr uintptr_t vtable_0x396DB8 = 0x396db8;
                constexpr uintptr_t vtable_0x396E38 = 0x396e38;
                constexpr uintptr_t vtable_0x397048 = 0x397048;
                constexpr uintptr_t vtable_0x3974A0 = 0x3974a0;
                constexpr uintptr_t vtable_0x397530 = 0x397530;
                constexpr uintptr_t vtable_0x3975C0 = 0x3975c0;
                constexpr uintptr_t vtable_0x397650 = 0x397650;
                constexpr uintptr_t vtable_0x3976E0 = 0x3976e0;
                constexpr uintptr_t vtable_0x3978A8 = 0x3978a8;
                constexpr uintptr_t vtable_0x3979A8 = 0x3979a8;
                constexpr uintptr_t vtable_0x397A98 = 0x397a98;
                constexpr uintptr_t vtable_0x397C18 = 0x397c18;
                constexpr uintptr_t vtable_0x397D68 = 0x397d68;
                constexpr uintptr_t vtable_0x397ED8 = 0x397ed8;
                constexpr uintptr_t vtable_0x398040 = 0x398040;
                constexpr uintptr_t vtable_0x398B10 = 0x398b10;
                constexpr uintptr_t vtable_0x398B48 = 0x398b48;
                constexpr uintptr_t vtable_0x398C20 = 0x398c20;
                constexpr uintptr_t vtable_0x3996B8 = 0x3996b8;
                constexpr uintptr_t vtable_0x399760 = 0x399760;
                constexpr uintptr_t vtable_0x3997D8 = 0x3997d8;
                constexpr uintptr_t vtable_0x399850 = 0x399850;
                constexpr uintptr_t vtable_0x3998C8 = 0x3998c8;
                constexpr uintptr_t vtable_0x399940 = 0x399940;
                constexpr uintptr_t vtable_0x3999B8 = 0x3999b8;
                constexpr uintptr_t vtable_0x399A30 = 0x399a30;
                constexpr uintptr_t vtable_0x399AA8 = 0x399aa8;
                constexpr uintptr_t vtable_0x399B28 = 0x399b28;
                constexpr uintptr_t vtable_0x399BA0 = 0x399ba0;
                constexpr uintptr_t vtable_0x399C20 = 0x399c20;
                constexpr uintptr_t vtable_0x399CA0 = 0x399ca0;
                constexpr uintptr_t vtable_0x399D20 = 0x399d20;
                constexpr uintptr_t vtable_0x399DA0 = 0x399da0;
                constexpr uintptr_t vtable_0x399E18 = 0x399e18;
                constexpr uintptr_t vtable_0x399E90 = 0x399e90;
                constexpr uintptr_t vtable_0x399F08 = 0x399f08;
                constexpr uintptr_t vtable_0x399FB8 = 0x399fb8;
                constexpr uintptr_t vtable_0x39A100 = 0x39a100;
                constexpr uintptr_t vtable_0x39AE20 = 0x39ae20;
                constexpr uintptr_t vtable_0x39AF30 = 0x39af30;
                constexpr uintptr_t vtable_0x39B030 = 0x39b030;
                constexpr uintptr_t vtable_0x39B0A8 = 0x39b0a8;
                constexpr uintptr_t vtable_0x39B120 = 0x39b120;
                constexpr uintptr_t vtable_0x39B198 = 0x39b198;
                constexpr uintptr_t vtable_0x39B218 = 0x39b218;
                constexpr uintptr_t vtable_0x39B290 = 0x39b290;
                constexpr uintptr_t vtable_0x39B308 = 0x39b308;
                constexpr uintptr_t vtable_0x39B380 = 0x39b380;
                constexpr uintptr_t vtable_0x39B3F8 = 0x39b3f8;
                constexpr uintptr_t vtable_0x39B470 = 0x39b470;
                constexpr uintptr_t vtable_0x39B4F0 = 0x39b4f0;
                constexpr uintptr_t vtable_0x39B568 = 0x39b568;
                constexpr uintptr_t vtable_0x39B5E0 = 0x39b5e0;
                constexpr uintptr_t vtable_0x39B660 = 0x39b660;
                constexpr uintptr_t vtable_0x39B6E0 = 0x39b6e0;
                constexpr uintptr_t vtable_0x39B760 = 0x39b760;
                constexpr uintptr_t vtable_0x39B7E0 = 0x39b7e0;
                constexpr uintptr_t vtable_0x39B860 = 0x39b860;
                constexpr uintptr_t vtable_0x39D048 = 0x39d048;
                constexpr uintptr_t vtable_0x39E4C0 = 0x39e4c0;
                constexpr uintptr_t vtable_0x39E540 = 0x39e540;
                constexpr uintptr_t vtable_0x39E610 = 0x39e610;
                constexpr uintptr_t vtable_0x39E6E8 = 0x39e6e8;
            }
        }
        namespace tier0 {
            constexpr size_t    Size = 0x7e000;
            namespace VTables {
                constexpr uintptr_t vtable_0x475C0 = 0x475c0;
                constexpr uintptr_t vtable_0x476C8 = 0x476c8;
                constexpr uintptr_t vtable_0x47768 = 0x47768;
                constexpr uintptr_t vtable_0x478D0 = 0x478d0;
                constexpr uintptr_t vtable_0x47F48 = 0x47f48;
                constexpr uintptr_t vtable_0x480C8 = 0x480c8;
                constexpr uintptr_t vtable_0x48600 = 0x48600;
                constexpr uintptr_t vtable_0x494C8 = 0x494c8;
                constexpr uintptr_t vtable_0x49510 = 0x49510;
                constexpr uintptr_t vtable_0x4C970 = 0x4c970;
                constexpr uintptr_t vtable_0x4C9B8 = 0x4c9b8;
            }
        }
        namespace vstdlib {
            constexpr size_t    Size = 0x79000;
            namespace Interfaces {
                constexpr uintptr_t VProcessUtils001 = 0x12d10;
                constexpr uintptr_t EventSystem001 = 0xad40;
                constexpr uintptr_t VEngineCvar007 = 0x8d10;
            }
            namespace VTables {
                constexpr uintptr_t vtable_0x42580 = 0x42580;
                constexpr uintptr_t vtable_0x42800 = 0x42800;
                constexpr uintptr_t vtable_0x428C8 = 0x428c8;
                constexpr uintptr_t vtable_0x42978 = 0x42978;
                constexpr uintptr_t vtable_0x42A40 = 0x42a40;
                constexpr uintptr_t vtable_0x42AE0 = 0x42ae0;
                constexpr uintptr_t vtable_0x431D0 = 0x431d0;
                constexpr uintptr_t vtable_0x432D8 = 0x432d8;
                constexpr uintptr_t vtable_0x43310 = 0x43310;
                constexpr uintptr_t vtable_0x43410 = 0x43410;
                constexpr uintptr_t vtable_0x43490 = 0x43490;
                constexpr uintptr_t vtable_0x43558 = 0x43558;
                constexpr uintptr_t vtable_0x435B0 = 0x435b0;
                constexpr uintptr_t vtable_0x43600 = 0x43600;
                constexpr uintptr_t vtable_0x43888 = 0x43888;
                constexpr uintptr_t vtable_0x438D8 = 0x438d8;
                constexpr uintptr_t vtable_0x43A08 = 0x43a08;
                constexpr uintptr_t vtable_0x43A78 = 0x43a78;
                constexpr uintptr_t vtable_0x43CA8 = 0x43ca8;
                constexpr uintptr_t vtable_0x43E70 = 0x43e70;
                constexpr uintptr_t vtable_0x43F20 = 0x43f20;
                constexpr uintptr_t vtable_0x44128 = 0x44128;
                constexpr uintptr_t vtable_0x441D8 = 0x441d8;
                constexpr uintptr_t vtable_0x44228 = 0x44228;
                constexpr uintptr_t vtable_0x44290 = 0x44290;
                constexpr uintptr_t vtable_0x44310 = 0x44310;
                constexpr uintptr_t vtable_0x443C0 = 0x443c0;
                constexpr uintptr_t vtable_0x47EE0 = 0x47ee0;
                constexpr uintptr_t vtable_0x47F28 = 0x47f28;
            }
        }
        namespace materialsystem {
            constexpr size_t    Size = 0x2152000;
            namespace Interfaces {
                constexpr uintptr_t ShaderDLL004 = 0x6d190;
                constexpr uintptr_t ShaderSystem002 = 0x4cc30;
                constexpr uintptr_t VMaterialSystemStub001 = 0x440a0;
                constexpr uintptr_t VEngineCvar007 = 0x1d980;
                constexpr uintptr_t MaterialSystemHardwareConfig012 = 0x1d900;
                constexpr uintptr_t VMaterialSystemConfig002 = 0x1d6c0;
                constexpr uintptr_t VMaterialSystem080 = 0x26120;
                constexpr uintptr_t COLORCORRECTION_VERSION_1 = 0xc800;
            }
            namespace VTables {
                constexpr uintptr_t vtable_0xB44E8 = 0xb44e8;
                constexpr uintptr_t vtable_0xB48C8 = 0xb48c8;
                constexpr uintptr_t vtable_0xB4C08 = 0xb4c08;
                constexpr uintptr_t vtable_0xB4F30 = 0xb4f30;
                constexpr uintptr_t vtable_0xB6068 = 0xb6068;
                constexpr uintptr_t vtable_0xB6FF8 = 0xb6ff8;
                constexpr uintptr_t vtable_0xB7050 = 0xb7050;
                constexpr uintptr_t vtable_0xB70A0 = 0xb70a0;
                constexpr uintptr_t vtable_0xB7828 = 0xb7828;
                constexpr uintptr_t vtable_0xB78C8 = 0xb78c8;
                constexpr uintptr_t vtable_0xB7D88 = 0xb7d88;
                constexpr uintptr_t vtable_0xB95C0 = 0xb95c0;
                constexpr uintptr_t vtable_0xB98E0 = 0xb98e0;
                constexpr uintptr_t vtable_0xBA2E0 = 0xba2e0;
                constexpr uintptr_t vtable_0xBAD88 = 0xbad88;
                constexpr uintptr_t vtable_0xBADE8 = 0xbade8;
                constexpr uintptr_t vtable_0xBAE58 = 0xbae58;
                constexpr uintptr_t vtable_0xBAF40 = 0xbaf40;
                constexpr uintptr_t vtable_0xBB918 = 0xbb918;
                constexpr uintptr_t vtable_0xBC070 = 0xbc070;
                constexpr uintptr_t vtable_0xBD068 = 0xbd068;
                constexpr uintptr_t vtable_0xBD258 = 0xbd258;
                constexpr uintptr_t vtable_0xBD400 = 0xbd400;
                constexpr uintptr_t vtable_0xBDA00 = 0xbda00;
                constexpr uintptr_t vtable_0xBDB10 = 0xbdb10;
                constexpr uintptr_t vtable_0xBDC38 = 0xbdc38;
                constexpr uintptr_t vtable_0xBDEB0 = 0xbdeb0;
                constexpr uintptr_t vtable_0xBE0D0 = 0xbe0d0;
                constexpr uintptr_t vtable_0xBE598 = 0xbe598;
                constexpr uintptr_t vtable_0xBEBF8 = 0xbebf8;
                constexpr uintptr_t vtable_0xBECE0 = 0xbece0;
                constexpr uintptr_t vtable_0xBEE70 = 0xbee70;
                constexpr uintptr_t vtable_0xBEEC0 = 0xbeec0;
                constexpr uintptr_t vtable_0xBF420 = 0xbf420;
                constexpr uintptr_t vtable_0xBF4D8 = 0xbf4d8;
                constexpr uintptr_t vtable_0xBFB00 = 0xbfb00;
                constexpr uintptr_t vtable_0xC0548 = 0xc0548;
                constexpr uintptr_t vtable_0xC07F8 = 0xc07f8;
                constexpr uintptr_t vtable_0xC08A8 = 0xc08a8;
                constexpr uintptr_t vtable_0xC08F0 = 0xc08f0;
                constexpr uintptr_t vtable_0xC0958 = 0xc0958;
                constexpr uintptr_t vtable_0xC09D8 = 0xc09d8;
                constexpr uintptr_t vtable_0xC0A88 = 0xc0a88;
                constexpr uintptr_t vtable_0xC1350 = 0xc1350;
                constexpr uintptr_t vtable_0xC1518 = 0xc1518;
                constexpr uintptr_t vtable_0xC6570 = 0xc6570;
                constexpr uintptr_t vtable_0xC65B8 = 0xc65b8;
            }
        }
        namespace studiorender {
            constexpr size_t    Size = 0x835000;
            namespace Interfaces {
                constexpr uintptr_t VStudioRender025 = 0x65ed0;
            }
            namespace VTables {
                constexpr uintptr_t vtable_0x95340 = 0x95340;
                constexpr uintptr_t vtable_0x96608 = 0x96608;
                constexpr uintptr_t vtable_0x970C0 = 0x970c0;
                constexpr uintptr_t vtable_0x97170 = 0x97170;
                constexpr uintptr_t vtable_0x971C0 = 0x971c0;
                constexpr uintptr_t vtable_0x97228 = 0x97228;
                constexpr uintptr_t vtable_0x972D8 = 0x972d8;
                constexpr uintptr_t vtable_0x9B290 = 0x9b290;
                constexpr uintptr_t vtable_0x9B2D8 = 0x9b2d8;
            }
        }
        namespace vphysics {
            constexpr size_t    Size = 0x159000;
            namespace Interfaces {
                constexpr uintptr_t VPhysicsSurfaceProps001 = 0x22720;
                constexpr uintptr_t VPhysicsCollision007 = 0x13ca0;
                constexpr uintptr_t VPhysics031 = 0xbff0;
            }
            namespace VTables {
                constexpr uintptr_t vtable_0xE4330 = 0xe4330;
                constexpr uintptr_t vtable_0xE4758 = 0xe4758;
                constexpr uintptr_t vtable_0xE4848 = 0xe4848;
                constexpr uintptr_t vtable_0xE48C0 = 0xe48c0;
                constexpr uintptr_t vtable_0xE4910 = 0xe4910;
                constexpr uintptr_t vtable_0xE4BB0 = 0xe4bb0;
                constexpr uintptr_t vtable_0xE4F90 = 0xe4f90;
                constexpr uintptr_t vtable_0xE5098 = 0xe5098;
                constexpr uintptr_t vtable_0xE5360 = 0xe5360;
                constexpr uintptr_t vtable_0xE5550 = 0xe5550;
                constexpr uintptr_t vtable_0xE5628 = 0xe5628;
                constexpr uintptr_t vtable_0xE58A8 = 0xe58a8;
                constexpr uintptr_t vtable_0xE5990 = 0xe5990;
                constexpr uintptr_t vtable_0xE5B08 = 0xe5b08;
                constexpr uintptr_t vtable_0xE5CE0 = 0xe5ce0;
                constexpr uintptr_t vtable_0xE5D40 = 0xe5d40;
                constexpr uintptr_t vtable_0xE6390 = 0xe6390;
                constexpr uintptr_t vtable_0xE6588 = 0xe6588;
                constexpr uintptr_t vtable_0xE6620 = 0xe6620;
                constexpr uintptr_t vtable_0xE66D8 = 0xe66d8;
                constexpr uintptr_t vtable_0xE67D0 = 0xe67d0;
                constexpr uintptr_t vtable_0xE6CB8 = 0xe6cb8;
                constexpr uintptr_t vtable_0xE6ED0 = 0xe6ed0;
                constexpr uintptr_t vtable_0xE7C08 = 0xe7c08;
                constexpr uintptr_t vtable_0xE81B0 = 0xe81b0;
                constexpr uintptr_t vtable_0xE8280 = 0xe8280;
                constexpr uintptr_t vtable_0xE8400 = 0xe8400;
                constexpr uintptr_t vtable_0xE8B38 = 0xe8b38;
                constexpr uintptr_t vtable_0xE8C60 = 0xe8c60;
                constexpr uintptr_t vtable_0xE8DB0 = 0xe8db0;
                constexpr uintptr_t vtable_0xE8DF0 = 0xe8df0;
                constexpr uintptr_t vtable_0xE9020 = 0xe9020;
                constexpr uintptr_t vtable_0xE90A0 = 0xe90a0;
                constexpr uintptr_t vtable_0xE9350 = 0xe9350;
                constexpr uintptr_t vtable_0xE9400 = 0xe9400;
                constexpr uintptr_t vtable_0xE94A0 = 0xe94a0;
                constexpr uintptr_t vtable_0xE94E8 = 0xe94e8;
                constexpr uintptr_t vtable_0xE9530 = 0xe9530;
                constexpr uintptr_t vtable_0xE9588 = 0xe9588;
                constexpr uintptr_t vtable_0xE95D8 = 0xe95d8;
                constexpr uintptr_t vtable_0xE9690 = 0xe9690;
                constexpr uintptr_t vtable_0xE96E0 = 0xe96e0;
                constexpr uintptr_t vtable_0xE9728 = 0xe9728;
                constexpr uintptr_t vtable_0xE9770 = 0xe9770;
                constexpr uintptr_t vtable_0xE97D0 = 0xe97d0;
                constexpr uintptr_t vtable_0xF7B98 = 0xf7b98;
                constexpr uintptr_t vtable_0xF7E08 = 0xf7e08;
                constexpr uintptr_t vtable_0xF8040 = 0xf8040;
                constexpr uintptr_t vtable_0xF80A0 = 0xf80a0;
                constexpr uintptr_t vtable_0xF8148 = 0xf8148;
                constexpr uintptr_t vtable_0xF81A8 = 0xf81a8;
                constexpr uintptr_t vtable_0xF8228 = 0xf8228;
                constexpr uintptr_t vtable_0xF82A0 = 0xf82a0;
                constexpr uintptr_t vtable_0xF82E8 = 0xf82e8;
                constexpr uintptr_t vtable_0xF8340 = 0xf8340;
                constexpr uintptr_t vtable_0xF8430 = 0xf8430;
                constexpr uintptr_t vtable_0xF84E8 = 0xf84e8;
                constexpr uintptr_t vtable_0xF8610 = 0xf8610;
                constexpr uintptr_t vtable_0xF8668 = 0xf8668;
                constexpr uintptr_t vtable_0xF87E8 = 0xf87e8;
                constexpr uintptr_t vtable_0xF88F8 = 0xf88f8;
                constexpr uintptr_t vtable_0xF8970 = 0xf8970;
                constexpr uintptr_t vtable_0xF8A58 = 0xf8a58;
                constexpr uintptr_t vtable_0xF8AD0 = 0xf8ad0;
                constexpr uintptr_t vtable_0xF8D60 = 0xf8d60;
                constexpr uintptr_t vtable_0xF8E30 = 0xf8e30;
                constexpr uintptr_t vtable_0xF8F68 = 0xf8f68;
                constexpr uintptr_t vtable_0xF9000 = 0xf9000;
                constexpr uintptr_t vtable_0xF90D0 = 0xf90d0;
                constexpr uintptr_t vtable_0xF9158 = 0xf9158;
                constexpr uintptr_t vtable_0xFC4A0 = 0xfc4a0;
                constexpr uintptr_t vtable_0xFC4E8 = 0xfc4e8;
                constexpr uintptr_t vtable_0x103E10 = 0x103e10;
                constexpr uintptr_t vtable_0x103E78 = 0x103e78;
                constexpr uintptr_t vtable_0x103EC0 = 0x103ec0;
                constexpr uintptr_t vtable_0x103F08 = 0x103f08;
                constexpr uintptr_t vtable_0x103FB8 = 0x103fb8;
                constexpr uintptr_t vtable_0x104038 = 0x104038;
                constexpr uintptr_t vtable_0x104218 = 0x104218;
            }
        }
        namespace vguimatsurface {
            constexpr size_t    Size = 0x1a1000;
            namespace Interfaces {
                constexpr uintptr_t VGUI_Surface030 = 0x1aa60;
            }
            namespace VTables {
                constexpr uintptr_t vtable_0xD74C8 = 0xd74c8;
                constexpr uintptr_t vtable_0xD7DD8 = 0xd7dd8;
                constexpr uintptr_t vtable_0xD8488 = 0xd8488;
                constexpr uintptr_t vtable_0xD9008 = 0xd9008;
                constexpr uintptr_t vtable_0xD9070 = 0xd9070;
                constexpr uintptr_t vtable_0xD9118 = 0xd9118;
                constexpr uintptr_t vtable_0xD95C0 = 0xd95c0;
                constexpr uintptr_t vtable_0xD9C20 = 0xd9c20;
                constexpr uintptr_t vtable_0xDA410 = 0xda410;
                constexpr uintptr_t vtable_0xDA4C0 = 0xda4c0;
                constexpr uintptr_t vtable_0xDA510 = 0xda510;
                constexpr uintptr_t vtable_0xDA578 = 0xda578;
                constexpr uintptr_t vtable_0xDA628 = 0xda628;
                constexpr uintptr_t vtable_0xDB6A0 = 0xdb6a0;
                constexpr uintptr_t vtable_0xDC0B8 = 0xdc0b8;
                constexpr uintptr_t vtable_0xDCE88 = 0xdce88;
                constexpr uintptr_t vtable_0xDD5B0 = 0xdd5b0;
                constexpr uintptr_t vtable_0xDE280 = 0xde280;
                constexpr uintptr_t vtable_0xDEAB8 = 0xdeab8;
                constexpr uintptr_t vtable_0xDF290 = 0xdf290;
                constexpr uintptr_t vtable_0xDFCD0 = 0xdfcd0;
                constexpr uintptr_t vtable_0xE0618 = 0xe0618;
                constexpr uintptr_t vtable_0xE0D50 = 0xe0d50;
                constexpr uintptr_t vtable_0xE14E0 = 0xe14e0;
                constexpr uintptr_t vtable_0xE1630 = 0xe1630;
                constexpr uintptr_t vtable_0xE20E8 = 0xe20e8;
                constexpr uintptr_t vtable_0xE29E8 = 0xe29e8;
                constexpr uintptr_t vtable_0xE34A0 = 0xe34a0;
                constexpr uintptr_t vtable_0xE3B60 = 0xe3b60;
                constexpr uintptr_t vtable_0xE44A0 = 0xe44a0;
                constexpr uintptr_t vtable_0xE4B90 = 0xe4b90;
                constexpr uintptr_t vtable_0xE54F8 = 0xe54f8;
                constexpr uintptr_t vtable_0xE5E08 = 0xe5e08;
                constexpr uintptr_t vtable_0xE66D0 = 0xe66d0;
                constexpr uintptr_t vtable_0xE6E28 = 0xe6e28;
                constexpr uintptr_t vtable_0xE7648 = 0xe7648;
                constexpr uintptr_t vtable_0xE7F10 = 0xe7f10;
                constexpr uintptr_t vtable_0xE8658 = 0xe8658;
                constexpr uintptr_t vtable_0xE8D68 = 0xe8d68;
                constexpr uintptr_t vtable_0xE96D0 = 0xe96d0;
                constexpr uintptr_t vtable_0xEA008 = 0xea008;
                constexpr uintptr_t vtable_0xEA1B0 = 0xea1b0;
                constexpr uintptr_t vtable_0xEAB40 = 0xeab40;
                constexpr uintptr_t vtable_0xEB228 = 0xeb228;
                constexpr uintptr_t vtable_0xEB970 = 0xeb970;
                constexpr uintptr_t vtable_0xEC0B8 = 0xec0b8;
                constexpr uintptr_t vtable_0xEC200 = 0xec200;
                constexpr uintptr_t vtable_0xECC10 = 0xecc10;
                constexpr uintptr_t vtable_0xED368 = 0xed368;
                constexpr uintptr_t vtable_0xEDA18 = 0xeda18;
                constexpr uintptr_t vtable_0xEE238 = 0xee238;
                constexpr uintptr_t vtable_0xEE9F8 = 0xee9f8;
                constexpr uintptr_t vtable_0xEF178 = 0xef178;
                constexpr uintptr_t vtable_0xEFBB8 = 0xefbb8;
                constexpr uintptr_t vtable_0xF0468 = 0xf0468;
                constexpr uintptr_t vtable_0xF1268 = 0xf1268;
                constexpr uintptr_t vtable_0xF1AE8 = 0xf1ae8;
                constexpr uintptr_t vtable_0xF2418 = 0xf2418;
                constexpr uintptr_t vtable_0xF2AF0 = 0xf2af0;
                constexpr uintptr_t vtable_0xF31A0 = 0xf31a0;
                constexpr uintptr_t vtable_0xF3988 = 0xf3988;
                constexpr uintptr_t vtable_0xF40B0 = 0xf40b0;
                constexpr uintptr_t vtable_0xF48E8 = 0xf48e8;
                constexpr uintptr_t vtable_0xF4928 = 0xf4928;
                constexpr uintptr_t vtable_0xF49B0 = 0xf49b0;
                constexpr uintptr_t vtable_0xF4BD0 = 0xf4bd0;
                constexpr uintptr_t vtable_0xF4C30 = 0xf4c30;
                constexpr uintptr_t vtable_0xF5618 = 0xf5618;
                constexpr uintptr_t vtable_0xF5F30 = 0xf5f30;
                constexpr uintptr_t vtable_0xF7000 = 0xf7000;
                constexpr uintptr_t vtable_0xF7148 = 0xf7148;
                constexpr uintptr_t vtable_0xF7248 = 0xf7248;
                constexpr uintptr_t vtable_0xF7BC0 = 0xf7bc0;
                constexpr uintptr_t vtable_0xF82D0 = 0xf82d0;
                constexpr uintptr_t vtable_0xF8988 = 0xf8988;
                constexpr uintptr_t vtable_0xF9378 = 0xf9378;
                constexpr uintptr_t vtable_0xFA190 = 0xfa190;
                constexpr uintptr_t vtable_0xFA920 = 0xfa920;
                constexpr uintptr_t vtable_0xFF0A0 = 0xff0a0;
                constexpr uintptr_t vtable_0xFF0E8 = 0xff0e8;
            }
        }
        namespace vgui2 {
            constexpr size_t    Size = 0xb3000;
            namespace Interfaces {
                constexpr uintptr_t VGUI_Panel009 = 0x1cda0;
                constexpr uintptr_t VGUI_ivgui008 = 0x1b3d0;
                constexpr uintptr_t VGUI_System010 = 0x18e00;
                constexpr uintptr_t VGUI_Surface030 = 0x16750;
                constexpr uintptr_t VGUI_Scheme010 = 0xff60;
                constexpr uintptr_t VguiLocalize004 = 0xbe00;
                constexpr uintptr_t VGUI_InputInternal001 = 0x8760;
                constexpr uintptr_t VGUI_Input005 = 0x8760;
            }
            namespace VTables {
                constexpr uintptr_t vtable_0x61870 = 0x61870;
                constexpr uintptr_t vtable_0x61958 = 0x61958;
                constexpr uintptr_t vtable_0x619E8 = 0x619e8;
                constexpr uintptr_t vtable_0x61A58 = 0x61a58;
                constexpr uintptr_t vtable_0x61AC8 = 0x61ac8;
                constexpr uintptr_t vtable_0x61B28 = 0x61b28;
                constexpr uintptr_t vtable_0x61CE0 = 0x61ce0;
                constexpr uintptr_t vtable_0x63720 = 0x63720;
                constexpr uintptr_t vtable_0x64558 = 0x64558;
                constexpr uintptr_t vtable_0x64880 = 0x64880;
                constexpr uintptr_t vtable_0x65B60 = 0x65b60;
                constexpr uintptr_t vtable_0x65BC0 = 0x65bc0;
                constexpr uintptr_t vtable_0x65F00 = 0x65f00;
                constexpr uintptr_t vtable_0x65F88 = 0x65f88;
                constexpr uintptr_t vtable_0x66610 = 0x66610;
                constexpr uintptr_t vtable_0x66760 = 0x66760;
                constexpr uintptr_t vtable_0x66948 = 0x66948;
                constexpr uintptr_t vtable_0x66BB8 = 0x66bb8;
                constexpr uintptr_t vtable_0x66D50 = 0x66d50;
                constexpr uintptr_t vtable_0x674A8 = 0x674a8;
                constexpr uintptr_t vtable_0x67558 = 0x67558;
                constexpr uintptr_t vtable_0x675A0 = 0x675a0;
                constexpr uintptr_t vtable_0x67608 = 0x67608;
                constexpr uintptr_t vtable_0x67688 = 0x67688;
                constexpr uintptr_t vtable_0x67738 = 0x67738;
                constexpr uintptr_t vtable_0x67E60 = 0x67e60;
                constexpr uintptr_t vtable_0x6ABC0 = 0x6abc0;
                constexpr uintptr_t vtable_0x6AC08 = 0x6ac08;
            }
        }
        namespace inputsystem {
            constexpr size_t    Size = 0x69000;
            namespace Interfaces {
                constexpr uintptr_t InputSystemVersion001 = 0x5010;
                constexpr uintptr_t InputStackSystemVersion001 = 0x1d20;
            }
            namespace VTables {
                constexpr uintptr_t vtable_0x34498 = 0x34498;
                constexpr uintptr_t vtable_0x345C8 = 0x345c8;
                constexpr uintptr_t vtable_0x348D8 = 0x348d8;
                constexpr uintptr_t vtable_0x34978 = 0x34978;
                constexpr uintptr_t vtable_0x35DF8 = 0x35df8;
                constexpr uintptr_t vtable_0x35EA8 = 0x35ea8;
                constexpr uintptr_t vtable_0x35EF8 = 0x35ef8;
                constexpr uintptr_t vtable_0x35F60 = 0x35f60;
                constexpr uintptr_t vtable_0x35FE0 = 0x35fe0;
                constexpr uintptr_t vtable_0x36090 = 0x36090;
                constexpr uintptr_t vtable_0x38D70 = 0x38d70;
                constexpr uintptr_t vtable_0x38DB8 = 0x38db8;
            }
        }
        namespace lua_shared {
            constexpr size_t    Size = 0xe2000;
            namespace Interfaces {
                constexpr uintptr_t LUASHARED003 = 0x14f20;
                constexpr uintptr_t LUACONVARS001 = 0x69b0;
            }
            namespace VTables {
                constexpr uintptr_t vtable_0x94410 = 0x94410;
                constexpr uintptr_t vtable_0x944A8 = 0x944a8;
                constexpr uintptr_t vtable_0x94558 = 0x94558;
                constexpr uintptr_t vtable_0x948F8 = 0x948f8;
                constexpr uintptr_t vtable_0x96D58 = 0x96d58;
                constexpr uintptr_t vtable_0x973E8 = 0x973e8;
                constexpr uintptr_t vtable_0x98880 = 0x98880;
                constexpr uintptr_t vtable_0x99060 = 0x99060;
                constexpr uintptr_t vtable_0x99350 = 0x99350;
                constexpr uintptr_t vtable_0x994C0 = 0x994c0;
                constexpr uintptr_t vtable_0x998B0 = 0x998b0;
                constexpr uintptr_t vtable_0x99AE0 = 0x99ae0;
                constexpr uintptr_t vtable_0x99B60 = 0x99b60;
                constexpr uintptr_t vtable_0x99C30 = 0x99c30;
                constexpr uintptr_t vtable_0x9AC70 = 0x9ac70;
                constexpr uintptr_t vtable_0x9C130 = 0x9c130;
                constexpr uintptr_t vtable_0x9C2C0 = 0x9c2c0;
                constexpr uintptr_t vtable_0x9C370 = 0x9c370;
                constexpr uintptr_t vtable_0x9C3C0 = 0x9c3c0;
                constexpr uintptr_t vtable_0x9C428 = 0x9c428;
                constexpr uintptr_t vtable_0x9C4A8 = 0x9c4a8;
                constexpr uintptr_t vtable_0x9C558 = 0x9c558;
                constexpr uintptr_t vtable_0xA1D60 = 0xa1d60;
                constexpr uintptr_t vtable_0xA1DA8 = 0xa1da8;
            }
        }
        namespace server {
            constexpr size_t    Size = 0x1062000;
            namespace Interfaces {
                constexpr uintptr_t VSERVERCHOREOTOOLS001 = 0x6ee650;
                constexpr uintptr_t VSERVERTOOLS002 = 0x6ee660;
                constexpr uintptr_t ServerGameTags001 = 0x6a8a10;
                constexpr uintptr_t GameMovement001 = 0x585690;
                constexpr uintptr_t PluginHelpersCheck001 = 0x3fa790;
                constexpr uintptr_t BotManager001 = 0x3f91e0;
                constexpr uintptr_t PlayerInfoManager002 = 0x3f91c0;
                constexpr uintptr_t PlayerInfoManager001 = 0x3f91d0;
                constexpr uintptr_t HLTVDirector001 = 0x383e20;
                constexpr uintptr_t VServerDllSharedAppSystems001 = 0x36c130;
                constexpr uintptr_t ServerGameClients004 = 0x36c140;
                constexpr uintptr_t ServerGameClients003 = 0x36c140;
                constexpr uintptr_t ServerGameEnts001 = 0x36c160;
                constexpr uintptr_t ServerGameDLL009 = 0x36c150;
                constexpr uintptr_t ServerGameDLL008 = 0x36c150;
                constexpr uintptr_t IEffects001 = 0x3352b0;
            }
            namespace VTables {
                constexpr uintptr_t vtable_0x87CA10 = 0x87ca10;
                constexpr uintptr_t vtable_0x888CE8 = 0x888ce8;
                constexpr uintptr_t vtable_0x8893C0 = 0x8893c0;
                constexpr uintptr_t vtable_0x889720 = 0x889720;
                constexpr uintptr_t vtable_0x88AF90 = 0x88af90;
                constexpr uintptr_t vtable_0x88B1D0 = 0x88b1d0;
                constexpr uintptr_t vtable_0x88BAC0 = 0x88bac0;
                constexpr uintptr_t vtable_0x88C298 = 0x88c298;
                constexpr uintptr_t vtable_0x88D310 = 0x88d310;
                constexpr uintptr_t vtable_0x88E5F8 = 0x88e5f8;
                constexpr uintptr_t vtable_0x88EDB0 = 0x88edb0;
                constexpr uintptr_t vtable_0x88F568 = 0x88f568;
                constexpr uintptr_t vtable_0x88FDB8 = 0x88fdb8;
                constexpr uintptr_t vtable_0x894728 = 0x894728;
                constexpr uintptr_t vtable_0x894FC0 = 0x894fc0;
                constexpr uintptr_t vtable_0x895118 = 0x895118;
                constexpr uintptr_t vtable_0x895290 = 0x895290;
                constexpr uintptr_t vtable_0x895528 = 0x895528;
                constexpr uintptr_t vtable_0x895578 = 0x895578;
                constexpr uintptr_t vtable_0x8956F0 = 0x8956f0;
                constexpr uintptr_t vtable_0x895740 = 0x895740;
                constexpr uintptr_t vtable_0x896380 = 0x896380;
                constexpr uintptr_t vtable_0x896680 = 0x896680;
                constexpr uintptr_t vtable_0x896FB0 = 0x896fb0;
                constexpr uintptr_t vtable_0x897218 = 0x897218;
                constexpr uintptr_t vtable_0x8974E8 = 0x8974e8;
                constexpr uintptr_t vtable_0x8979A0 = 0x8979a0;
                constexpr uintptr_t vtable_0x897A48 = 0x897a48;
                constexpr uintptr_t vtable_0x897E90 = 0x897e90;
                constexpr uintptr_t vtable_0x898758 = 0x898758;
                constexpr uintptr_t vtable_0x898A30 = 0x898a30;
                constexpr uintptr_t vtable_0x89AF00 = 0x89af00;
                constexpr uintptr_t vtable_0x89AF90 = 0x89af90;
                constexpr uintptr_t vtable_0x89B060 = 0x89b060;
                constexpr uintptr_t vtable_0x89B598 = 0x89b598;
                constexpr uintptr_t vtable_0x89B618 = 0x89b618;
                constexpr uintptr_t vtable_0x89B6C0 = 0x89b6c0;
                constexpr uintptr_t vtable_0x89B728 = 0x89b728;
                constexpr uintptr_t vtable_0x8B0228 = 0x8b0228;
                constexpr uintptr_t vtable_0x8B09F8 = 0x8b09f8;
                constexpr uintptr_t vtable_0x8B16F8 = 0x8b16f8;
                constexpr uintptr_t vtable_0x8B1788 = 0x8b1788;
                constexpr uintptr_t vtable_0x8B1998 = 0x8b1998;
                constexpr uintptr_t vtable_0x8B2180 = 0x8b2180;
                constexpr uintptr_t vtable_0x8B2268 = 0x8b2268;
                constexpr uintptr_t vtable_0x8B22B8 = 0x8b22b8;
                constexpr uintptr_t vtable_0x8B3738 = 0x8b3738;
                constexpr uintptr_t vtable_0x8B3788 = 0x8b3788;
                constexpr uintptr_t vtable_0x8B3870 = 0x8b3870;
                constexpr uintptr_t vtable_0x8B4D98 = 0x8b4d98;
                constexpr uintptr_t vtable_0x8B4DE8 = 0x8b4de8;
                constexpr uintptr_t vtable_0x8B4EF0 = 0x8b4ef0;
                constexpr uintptr_t vtable_0x8B5150 = 0x8b5150;
                constexpr uintptr_t vtable_0x8B66C0 = 0x8b66c0;
                constexpr uintptr_t vtable_0x8B6710 = 0x8b6710;
                constexpr uintptr_t vtable_0x8B6818 = 0x8b6818;
                constexpr uintptr_t vtable_0x8B6A18 = 0x8b6a18;
                constexpr uintptr_t vtable_0x8B7308 = 0x8b7308;
                constexpr uintptr_t vtable_0x8B77D8 = 0x8b77d8;
                constexpr uintptr_t vtable_0x8B7FA0 = 0x8b7fa0;
                constexpr uintptr_t vtable_0x8B8948 = 0x8b8948;
                constexpr uintptr_t vtable_0x8B9848 = 0x8b9848;
                constexpr uintptr_t vtable_0x8BA098 = 0x8ba098;
                constexpr uintptr_t vtable_0x8BA8C8 = 0x8ba8c8;
                constexpr uintptr_t vtable_0x8BAC60 = 0x8bac60;
                constexpr uintptr_t vtable_0x8BAED0 = 0x8baed0;
                constexpr uintptr_t vtable_0x8BB048 = 0x8bb048;
                constexpr uintptr_t vtable_0x8BB098 = 0x8bb098;
                constexpr uintptr_t vtable_0x8BBCE8 = 0x8bbce8;
                constexpr uintptr_t vtable_0x8BBF70 = 0x8bbf70;
                constexpr uintptr_t vtable_0x8BC0C8 = 0x8bc0c8;
                constexpr uintptr_t vtable_0x8BC138 = 0x8bc138;
                constexpr uintptr_t vtable_0x8BC3D0 = 0x8bc3d0;
                constexpr uintptr_t vtable_0x8BC6B0 = 0x8bc6b0;
                constexpr uintptr_t vtable_0x8BC700 = 0x8bc700;
                constexpr uintptr_t vtable_0x8BC9E0 = 0x8bc9e0;
                constexpr uintptr_t vtable_0x8BCF68 = 0x8bcf68;
                constexpr uintptr_t vtable_0x8BDA18 = 0x8bda18;
                constexpr uintptr_t vtable_0x8BE960 = 0x8be960;
                constexpr uintptr_t vtable_0x8BEAD0 = 0x8bead0;
            }
        }
        namespace datacache {
            constexpr size_t    Size = 0x8a000;
            namespace Interfaces {
                constexpr uintptr_t VStudioDataCache005 = 0x13e90;
                constexpr uintptr_t MDLCache004 = 0x13e80;
                constexpr uintptr_t VDataCache003 = 0x9890;
            }
            namespace VTables {
                constexpr uintptr_t vtable_0x47358 = 0x47358;
                constexpr uintptr_t vtable_0x47800 = 0x47800;
                constexpr uintptr_t vtable_0x47910 = 0x47910;
                constexpr uintptr_t vtable_0x47A20 = 0x47a20;
                constexpr uintptr_t vtable_0x47A58 = 0x47a58;
                constexpr uintptr_t vtable_0x49768 = 0x49768;
                constexpr uintptr_t vtable_0x49900 = 0x49900;
                constexpr uintptr_t vtable_0x4C448 = 0x4c448;
                constexpr uintptr_t vtable_0x4C4F8 = 0x4c4f8;
                constexpr uintptr_t vtable_0x4C548 = 0x4c548;
                constexpr uintptr_t vtable_0x4C5B0 = 0x4c5b0;
                constexpr uintptr_t vtable_0x4C660 = 0x4c660;
                constexpr uintptr_t vtable_0x4C750 = 0x4c750;
                constexpr uintptr_t vtable_0x4F6A0 = 0x4f6a0;
                constexpr uintptr_t vtable_0x4F6E8 = 0x4f6e8;
            }
        }
    }
}
