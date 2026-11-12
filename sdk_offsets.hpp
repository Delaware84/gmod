// ============================================================================
// Auto-generated GMod x64 SDK & Offsets
// ============================================================================
#pragma once
#include <cstdint>

namespace SDK {
    // Dynamic Interface Resolver using engine CreateInterface export
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

    struct Vector3D { float x, y, z; };
    struct QAngle   { float pitch, yaw, roll; };

    struct CUserCmd {
        virtual ~CUserCmd() {};
        int       command_number;     // 0x08
        int       tick_count;         // 0x0C
        QAngle    viewangles;         // 0x10
        float     forwardmove;        // 0x1C
        float     sidemove;           // 0x20
        float     upmove;             // 0x24
        int       buttons;            // 0x28
        uint8_t   impulse;            // 0x2C
        uint8_t   _pad0[3];           // 0x2D
        int       weaponselect;       // 0x30
        int       weaponsubtype;      // 0x34
        int       random_seed;        // 0x38
        short     mousedx;            // 0x3C
        short     mousedy;            // 0x3E
        bool      hasbeenpredicted;   // 0x40
        uint8_t   _pad1[7];           // 0x41
    };
    static_assert(sizeof(CUserCmd) == 0x48, "CUserCmd size mismatch!");

    namespace client {
        constexpr uintptr_t Base = 0x7ffcb17c0000;
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
        namespace NetVars {
            namespace DT_TEWorldDecal {
                constexpr uint32_t m_vecOrigin = 0x20;
                constexpr uint32_t m_nIndex = 0x2c;
            }
            namespace DT_TESpriteSpray {
                constexpr uint32_t m_vecOrigin = 0x20;
                constexpr uint32_t m_vecDirection = 0x2c;
                constexpr uint32_t m_nModelIndex = 0x38;
                constexpr uint32_t m_fNoise = 0x40;
                constexpr uint32_t m_nCount = 0x44;
                constexpr uint32_t m_nSpeed = 0x3c;
            }
            namespace DT_TESprite {
                constexpr uint32_t m_vecOrigin = 0x20;
                constexpr uint32_t m_nModelIndex = 0x2c;
                constexpr uint32_t m_fScale = 0x30;
                constexpr uint32_t m_nBrightness = 0x34;
            }
            namespace DT_TESparks {
                constexpr uint32_t m_nMagnitude = 0x30;
                constexpr uint32_t m_nTrailLength = 0x34;
                constexpr uint32_t m_vecDir = 0x38;
            }
            namespace DT_TESmoke {
                constexpr uint32_t m_vecOrigin = 0x20;
                constexpr uint32_t m_nModelIndex = 0x2c;
                constexpr uint32_t m_fScale = 0x30;
                constexpr uint32_t m_nFrameRate = 0x34;
            }
            namespace DT_TEShowLine {
                constexpr uint32_t m_vecEnd = 0x30;
            }
            namespace DT_TEProjectedDecal {
                constexpr uint32_t m_vecOrigin = 0x20;
                constexpr uint32_t m_angRotation = 0x2c;
                constexpr uint32_t m_flDistance = 0x38;
                constexpr uint32_t m_nIndex = 0x3c;
            }
            namespace DT_TEPlayerDecal {
                constexpr uint32_t m_vecOrigin = 0x24;
                constexpr uint32_t m_nEntity = 0x30;
                constexpr uint32_t m_nPlayer = 0x20;
            }
            namespace DT_TEPhysicsProp {
                constexpr uint32_t m_vecOrigin = 0x20;
                constexpr uint32_t m_angRotation[0] = 0x2c;
                constexpr uint32_t m_angRotation[1] = 0x30;
                constexpr uint32_t m_angRotation[2] = 0x34;
                constexpr uint32_t m_vecVelocity = 0x38;
                constexpr uint32_t m_nModelIndex = 0x44;
                constexpr uint32_t m_nFlags = 0x4c;
                constexpr uint32_t m_nSkin = 0x48;
                constexpr uint32_t m_nEffects = 0x50;
                constexpr uint32_t m_clrRender = 0x54;
                constexpr uint32_t m_fModelScale = 0x58;
            }
            namespace DT_TEParticleSystem {
                constexpr uint32_t m_vecOrigin[0] = 0x20;
                constexpr uint32_t m_vecOrigin[1] = 0x24;
                constexpr uint32_t m_vecOrigin[2] = 0x28;
            }
            namespace DT_TEMuzzleFlash {
                constexpr uint32_t m_vecOrigin = 0x20;
                constexpr uint32_t m_vecAngles = 0x2c;
                constexpr uint32_t m_flScale = 0x38;
                constexpr uint32_t m_nType = 0x3c;
            }
            namespace DT_TELargeFunnel {
                constexpr uint32_t m_nReversed = 0x30;
            }
            namespace DT_TEKillPlayerAttachments {
                constexpr uint32_t m_nPlayer = 0x20;
            }
            namespace DT_TEGlowSprite {
                constexpr uint32_t m_vecOrigin = 0x20;
                constexpr uint32_t m_nModelIndex = 0x2c;
                constexpr uint32_t m_fScale = 0x30;
                constexpr uint32_t m_fLife = 0x34;
                constexpr uint32_t m_nBrightness = 0x38;
            }
            namespace DT_TEShatterSurface {
                constexpr uint32_t m_vecOrigin = 0x20;
                constexpr uint32_t m_vecAngles = 0x2c;
                constexpr uint32_t m_vecForce = 0x38;
                constexpr uint32_t m_vecForcePos = 0x44;
                constexpr uint32_t m_flWidth = 0x50;
                constexpr uint32_t m_flHeight = 0x54;
                constexpr uint32_t m_flShardSize = 0x58;
                constexpr uint32_t m_nSurfaceType = 0x5c;
                constexpr uint32_t m_uchFrontColor[0] = 0x60;
                constexpr uint32_t m_uchFrontColor[1] = 0x61;
                constexpr uint32_t m_uchFrontColor[2] = 0x62;
                constexpr uint32_t m_uchBackColor[0] = 0x63;
                constexpr uint32_t m_uchBackColor[1] = 0x64;
                constexpr uint32_t m_uchBackColor[2] = 0x65;
            }
            namespace DT_TEFootprintDecal {
                constexpr uint32_t m_vecOrigin = 0x20;
                constexpr uint32_t m_vecDirection = 0x2c;
                constexpr uint32_t m_nEntity = 0x44;
                constexpr uint32_t m_nIndex = 0x48;
            }
            namespace DT_TEFizz {
                constexpr uint32_t m_nEntity = 0x20;
                constexpr uint32_t m_nModelIndex = 0x24;
                constexpr uint32_t m_nDensity = 0x28;
                constexpr uint32_t m_nCurrent = 0x2c;
            }
            namespace DT_TEExplosion {
                constexpr uint32_t m_fScale = 0x30;
                constexpr uint32_t m_nFlags = 0x34;
                constexpr uint32_t m_nRadius = 0x38;
                constexpr uint32_t m_nMagnitude = 0x3c;
            }
            namespace DT_TEEnergySplash {
                constexpr uint32_t m_vecPos = 0x20;
                constexpr uint32_t m_vecDir = 0x2c;
                constexpr uint32_t m_bExplosive = 0x38;
            }
            namespace DT_TEEffectDispatch {
                constexpr uint32_t m_vOrigin[0] = 0x20;
                constexpr uint32_t m_vOrigin[1] = 0x24;
                constexpr uint32_t m_vOrigin[2] = 0x28;
                constexpr uint32_t m_vStart[0] = 0x2c;
                constexpr uint32_t m_vStart[1] = 0x30;
                constexpr uint32_t m_vStart[2] = 0x34;
                constexpr uint32_t m_vAngles = 0x44;
                constexpr uint32_t m_vNormal = 0x38;
                constexpr uint32_t m_fFlags = 0x50;
                constexpr uint32_t m_flMagnitude = 0x5c;
                constexpr uint32_t m_flScale = 0x58;
                constexpr uint32_t m_nAttachmentIndex = 0x64;
                constexpr uint32_t m_nSurfaceProp = 0x68;
                constexpr uint32_t m_iEffectName = 0xac;
                constexpr uint32_t m_nMaterial = 0x6c;
                constexpr uint32_t m_nDamageType = 0x70;
                constexpr uint32_t m_nHitBox = 0x74;
                constexpr uint32_t entindex = 0x20;
                constexpr uint32_t m_nColor = 0x78;
                constexpr uint32_t m_flRadius = 0x60;
                constexpr uint32_t m_bCustomColors = 0x79;
                constexpr uint32_t m_CustomColors.m_vecColor1 = 0x7c;
                constexpr uint32_t m_CustomColors.m_vecColor2 = 0x88;
                constexpr uint32_t m_bControlPoint1 = 0x94;
                constexpr uint32_t m_ControlPoint1.m_eParticleAttachment = 0x98;
                constexpr uint32_t m_ControlPoint1.m_vecOffset[0] = 0x9c;
                constexpr uint32_t m_ControlPoint1.m_vecOffset[1] = 0xa0;
                constexpr uint32_t m_ControlPoint1.m_vecOffset[2] = 0xa4;
                constexpr uint32_t m_bAllowOverride = 0xa8;
            }
            namespace DT_TEDynamicLight {
                constexpr uint32_t m_vecOrigin = 0x20;
                constexpr uint32_t r = 0x30;
                constexpr uint32_t g = 0x34;
                constexpr uint32_t b = 0x38;
                constexpr uint32_t exponent = 0x3c;
                constexpr uint32_t m_fRadius = 0x2c;
                constexpr uint32_t m_fTime = 0x40;
                constexpr uint32_t m_fDecay = 0x44;
            }
            namespace DT_TEDecal {
                constexpr uint32_t m_vecOrigin = 0x20;
                constexpr uint32_t m_vecStart = 0x2c;
                constexpr uint32_t m_nEntity = 0x38;
                constexpr uint32_t m_nHitbox = 0x3c;
                constexpr uint32_t m_nIndex = 0x40;
            }
            namespace DT_TEClientProjectile {
                constexpr uint32_t m_vecOrigin = 0x20;
                constexpr uint32_t m_vecVelocity = 0x2c;
                constexpr uint32_t m_nModelIndex = 0x38;
                constexpr uint32_t m_nLifeTime = 0x3c;
                constexpr uint32_t m_hOwner = 0x40;
            }
            namespace DT_TEBubbleTrail {
                constexpr uint32_t m_vecMins = 0x20;
                constexpr uint32_t m_vecMaxs = 0x2c;
                constexpr uint32_t m_nModelIndex = 0x3c;
                constexpr uint32_t m_flWaterZ = 0x38;
                constexpr uint32_t m_nCount = 0x40;
                constexpr uint32_t m_fSpeed = 0x44;
            }
            namespace DT_TEBubbles {
                constexpr uint32_t m_vecMins = 0x20;
                constexpr uint32_t m_vecMaxs = 0x2c;
                constexpr uint32_t m_nModelIndex = 0x3c;
                constexpr uint32_t m_fHeight = 0x38;
                constexpr uint32_t m_nCount = 0x40;
                constexpr uint32_t m_fSpeed = 0x44;
            }
            namespace DT_TEBSPDecal {
                constexpr uint32_t m_vecOrigin = 0x20;
                constexpr uint32_t m_nEntity = 0x2c;
                constexpr uint32_t m_nIndex = 0x30;
            }
            namespace DT_TEBreakModel {
                constexpr uint32_t m_vecOrigin = 0x20;
                constexpr uint32_t m_angRotation[0] = 0x2c;
                constexpr uint32_t m_angRotation[1] = 0x30;
                constexpr uint32_t m_angRotation[2] = 0x34;
                constexpr uint32_t m_vecSize = 0x38;
                constexpr uint32_t m_vecVelocity = 0x44;
                constexpr uint32_t m_nModelIndex = 0x54;
                constexpr uint32_t m_nRandomization = 0x50;
                constexpr uint32_t m_nCount = 0x58;
                constexpr uint32_t m_fTime = 0x5c;
                constexpr uint32_t m_nFlags = 0x60;
            }
            namespace DT_TEBloodStream {
                constexpr uint32_t m_vecDirection = 0x30;
                constexpr uint32_t r = 0x3c;
                constexpr uint32_t g = 0x40;
                constexpr uint32_t b = 0x44;
                constexpr uint32_t a = 0x48;
                constexpr uint32_t m_nAmount = 0x4c;
            }
            namespace DT_TEBloodSprite {
                constexpr uint32_t m_vecOrigin = 0x20;
                constexpr uint32_t m_vecDirection = 0x2c;
                constexpr uint32_t r = 0x38;
                constexpr uint32_t g = 0x3c;
                constexpr uint32_t b = 0x40;
                constexpr uint32_t a = 0x44;
                constexpr uint32_t m_nSize = 0x48;
            }
            namespace DT_TEBeamSpline {
                constexpr uint32_t m_nPoints = 0xe0;
                constexpr uint32_t m_vecPoints[0] = 0x20;
                constexpr uint32_t m_vecPoints = 0x0;
            }
            namespace DT_TEBeamRingPoint {
                constexpr uint32_t m_vecCenter = 0x60;
                constexpr uint32_t m_flStartRadius = 0x6c;
                constexpr uint32_t m_flEndRadius = 0x70;
            }
            namespace DT_TEBeamRing {
                constexpr uint32_t m_nStartEntity = 0x60;
                constexpr uint32_t m_nEndEntity = 0x64;
            }
            namespace DT_TEBeamPoints {
                constexpr uint32_t m_vecStartPoint = 0x60;
                constexpr uint32_t m_vecEndPoint = 0x6c;
            }
            namespace DT_TEBeamLaser {
                constexpr uint32_t m_nStartEntity = 0x60;
                constexpr uint32_t m_nEndEntity = 0x64;
            }
            namespace DT_TEBeamFollow {
                constexpr uint32_t m_iEntIndex = 0x60;
            }
            namespace DT_TEBeamEnts {
                constexpr uint32_t m_nStartEntity = 0x60;
                constexpr uint32_t m_nEndEntity = 0x64;
            }
            namespace DT_TEBeamEntPoint {
                constexpr uint32_t m_nStartEntity = 0x60;
                constexpr uint32_t m_nEndEntity = 0x64;
                constexpr uint32_t m_vecStartPoint = 0x68;
                constexpr uint32_t m_vecEndPoint = 0x74;
            }
            namespace DT_BaseBeam {
                constexpr uint32_t m_nModelIndex = 0x20;
                constexpr uint32_t m_nHaloIndex = 0x24;
                constexpr uint32_t m_nStartFrame = 0x28;
                constexpr uint32_t m_nFrameRate = 0x2c;
                constexpr uint32_t m_fLife = 0x30;
                constexpr uint32_t m_fWidth = 0x34;
                constexpr uint32_t m_fEndWidth = 0x38;
                constexpr uint32_t m_nFadeLength = 0x3c;
                constexpr uint32_t m_fAmplitude = 0x40;
                constexpr uint32_t m_nSpeed = 0x54;
                constexpr uint32_t r = 0x44;
                constexpr uint32_t g = 0x48;
                constexpr uint32_t b = 0x4c;
                constexpr uint32_t a = 0x50;
                constexpr uint32_t m_nFlags = 0x58;
            }
            namespace DT_TEArmorRicochet {
            }
            namespace DT_TEMetalSparks {
                constexpr uint32_t m_vecPos = 0x20;
                constexpr uint32_t m_vecDir = 0x2c;
            }
            namespace DT_SteamJet {
                constexpr uint32_t m_SpreadSpeed = 0x17e8;
                constexpr uint32_t m_Speed = 0x17ec;
                constexpr uint32_t m_StartSize = 0x17f0;
                constexpr uint32_t m_EndSize = 0x17f4;
                constexpr uint32_t m_Rate = 0x17f8;
                constexpr uint32_t m_JetLength = 0x17fc;
                constexpr uint32_t m_bEmit = 0x1800;
                constexpr uint32_t m_bFaceLeft = 0x1808;
                constexpr uint32_t m_nType = 0x1804;
                constexpr uint32_t m_spawnflags = 0x180c;
                constexpr uint32_t m_flRollSpeed = 0x1810;
            }
            namespace DT_SmokeStack {
                constexpr uint32_t m_SpreadSpeed = 0x1840;
                constexpr uint32_t m_Speed = 0x1844;
                constexpr uint32_t m_StartSize = 0x1848;
                constexpr uint32_t m_EndSize = 0x184c;
                constexpr uint32_t m_Rate = 0x1850;
                constexpr uint32_t m_JetLength = 0x1854;
                constexpr uint32_t m_bEmit = 0x1858;
                constexpr uint32_t m_flBaseSpread = 0x185c;
                constexpr uint32_t m_flTwist = 0x18b0;
                constexpr uint32_t m_flRollSpeed = 0x18f8;
                constexpr uint32_t m_iMaterialModel = 0x18b4;
                constexpr uint32_t m_AmbientLight.m_vPos = 0x1860;
                constexpr uint32_t m_AmbientLight.m_vColor = 0x186c;
                constexpr uint32_t m_AmbientLight.m_flIntensity = 0x1878;
                constexpr uint32_t m_DirLight.m_vPos = 0x187c;
                constexpr uint32_t m_DirLight.m_vColor = 0x1888;
                constexpr uint32_t m_DirLight.m_flIntensity = 0x1894;
                constexpr uint32_t m_vWind = 0x18a4;
            }
            namespace DT_DustTrail {
                constexpr uint32_t m_SpawnRate = 0x17e8;
                constexpr uint32_t m_Color = 0x17ec;
                constexpr uint32_t m_ParticleLifetime = 0x17fc;
                constexpr uint32_t m_StopEmitTime = 0x1804;
                constexpr uint32_t m_MinSpeed = 0x1808;
                constexpr uint32_t m_MaxSpeed = 0x180c;
                constexpr uint32_t m_MinDirectedSpeed = 0x1810;
                constexpr uint32_t m_MaxDirectedSpeed = 0x1814;
                constexpr uint32_t m_StartSize = 0x1818;
                constexpr uint32_t m_EndSize = 0x181c;
                constexpr uint32_t m_SpawnRadius = 0x1820;
                constexpr uint32_t m_bEmit = 0x1830;
                constexpr uint32_t m_Opacity = 0x17f8;
            }
            namespace DT_FireTrail {
                constexpr uint32_t m_nAttachment = 0x17e8;
                constexpr uint32_t m_flLifetime = 0x17ec;
            }
            namespace DT_SporeTrail {
                constexpr uint32_t m_flSpawnRate = 0x17ec;
                constexpr uint32_t m_vecEndColor = 0x17e0;
                constexpr uint32_t m_flParticleLifetime = 0x17f0;
                constexpr uint32_t m_flStartSize = 0x17f4;
                constexpr uint32_t m_flEndSize = 0x17f8;
                constexpr uint32_t m_flSpawnRadius = 0x17fc;
                constexpr uint32_t m_bEmit = 0x180c;
            }
            namespace DT_SporeExplosion {
                constexpr uint32_t m_flSpawnRate = 0x17e8;
                constexpr uint32_t m_flParticleLifetime = 0x17ec;
                constexpr uint32_t m_flStartSize = 0x17f0;
                constexpr uint32_t m_flEndSize = 0x17f4;
                constexpr uint32_t m_flSpawnRadius = 0x17f8;
                constexpr uint32_t m_bEmit = 0x1800;
                constexpr uint32_t m_bDontRemove = 0x1801;
            }
            namespace DT_RocketTrail {
                constexpr uint32_t m_SpawnRate = 0x17e8;
                constexpr uint32_t m_StartColor = 0x17ec;
                constexpr uint32_t m_EndColor = 0x17f8;
                constexpr uint32_t m_ParticleLifetime = 0x1808;
                constexpr uint32_t m_StopEmitTime = 0x180c;
                constexpr uint32_t m_MinSpeed = 0x1810;
                constexpr uint32_t m_MaxSpeed = 0x1814;
                constexpr uint32_t m_StartSize = 0x1818;
                constexpr uint32_t m_EndSize = 0x181c;
                constexpr uint32_t m_SpawnRadius = 0x1820;
                constexpr uint32_t m_bEmit = 0x1830;
                constexpr uint32_t m_nAttachment = 0x1834;
                constexpr uint32_t m_Opacity = 0x1804;
                constexpr uint32_t m_bDamaged = 0x1831;
                constexpr uint32_t m_flFlareScale = 0x1844;
            }
            namespace DT_SmokeTrail {
                constexpr uint32_t m_SpawnRate = 0x17e8;
                constexpr uint32_t m_StartColor = 0x17ec;
                constexpr uint32_t m_EndColor = 0x17f8;
                constexpr uint32_t m_ParticleLifetime = 0x1808;
                constexpr uint32_t m_StopEmitTime = 0x180c;
                constexpr uint32_t m_MinSpeed = 0x1810;
                constexpr uint32_t m_MaxSpeed = 0x1814;
                constexpr uint32_t m_MinDirectedSpeed = 0x1818;
                constexpr uint32_t m_MaxDirectedSpeed = 0x181c;
                constexpr uint32_t m_StartSize = 0x1820;
                constexpr uint32_t m_EndSize = 0x1824;
                constexpr uint32_t m_SpawnRadius = 0x1828;
                constexpr uint32_t m_bEmit = 0x1838;
                constexpr uint32_t m_nAttachment = 0x183c;
                constexpr uint32_t m_Opacity = 0x1804;
            }
            namespace DT_PropVehicleDriveable {
                constexpr uint32_t m_hPlayer = 0x1bd0;
                constexpr uint32_t m_nSpeed = 0x1bd4;
                constexpr uint32_t m_nRPM = 0x1bd8;
                constexpr uint32_t m_flThrottle = 0x1bdc;
                constexpr uint32_t m_nBoostTimeLeft = 0x1be0;
                constexpr uint32_t m_nHasBoost = 0x1be4;
                constexpr uint32_t m_bEnterAnimOn = 0x1c04;
                constexpr uint32_t m_bExitAnimOn = 0x1c05;
                constexpr uint32_t m_bUnableToFire = 0x1c75;
                constexpr uint32_t m_vecEyeExitEndpoint = 0x1c68;
                constexpr uint32_t m_bHasGun = 0x1c74;
                constexpr uint32_t m_vecGunCrosshair = 0x1c0c;
                constexpr uint32_t m_bLocked = 0x1d00;
            }
            namespace DT_ParticleSmokeGrenade {
                constexpr uint32_t m_flSpawnTime = 0x17f8;
                constexpr uint32_t m_FadeStartTime = 0x17fc;
                constexpr uint32_t m_FadeEndTime = 0x1800;
                constexpr uint32_t m_CurrentStage = 0x17e8;
            }
            namespace DT_MovieExplosion {
            }
            namespace DT_TEGaussExplosion {
                constexpr uint32_t m_nType = 0x30;
                constexpr uint32_t m_vecDirection = 0x34;
            }
            namespace DT_QuadraticBeam {
                constexpr uint32_t m_targetPosition = 0x16b0;
                constexpr uint32_t m_controlPosition = 0x16bc;
                constexpr uint32_t m_scrollRate = 0x16c8;
                constexpr uint32_t m_flWidth = 0x16cc;
            }
            namespace DT_Embers {
                constexpr uint32_t m_nDensity = 0x16b0;
                constexpr uint32_t m_nLifetime = 0x16b4;
                constexpr uint32_t m_nSpeed = 0x16b8;
                constexpr uint32_t m_bEmit = 0x16bc;
            }
            namespace DT_EnvWind {
                constexpr uint32_t m_iMinWind = 0x16c0;
                constexpr uint32_t m_iMaxWind = 0x16c4;
                constexpr uint32_t m_iMinGust = 0x16cc;
                constexpr uint32_t m_iMaxGust = 0x16d0;
                constexpr uint32_t m_flMinGustDelay = 0x16d4;
                constexpr uint32_t m_flMaxGustDelay = 0x16d8;
                constexpr uint32_t m_iGustDirChange = 0x16e0;
                constexpr uint32_t m_iWindSeed = 0x16bc;
                constexpr uint32_t m_iInitialWindDir = 0x1720;
                constexpr uint32_t m_flInitialWindSpeed = 0x1724;
                constexpr uint32_t m_flStartTime = 0x16b8;
                constexpr uint32_t m_flGustDuration = 0x16dc;
                constexpr uint32_t m_windRadius = 0x16c8;
            }
            namespace DT_Precipitation {
                constexpr uint32_t m_nPrecipType = 0x16dc;
                constexpr uint32_t m_sParticleNameClose = 0x17ca;
                constexpr uint32_t m_sParticleNameInner = 0x184a;
                constexpr uint32_t m_sParticleNameOuter = 0x18ca;
                constexpr uint32_t m_flParticleDist = 0x194c;
            }
            namespace DT_PrecipitationBlocker {
            }
            namespace DT_BaseTempEntity {
            }
            namespace DT_PropEnergyBall {
                constexpr uint32_t m_bIsInfiniteLife = 0x1bf8;
                constexpr uint32_t m_fTimeTillDeath = 0x1bfc;
            }
            namespace DT_NPC_RocketTurret {
                constexpr uint32_t m_iLaserState = 0x2934;
                constexpr uint32_t m_nSiteHalo = 0x2938;
                constexpr uint32_t m_vecCurrentAngles = 0x2940;
            }
            namespace DT_NPC_Portal_FloorTurret {
                constexpr uint32_t m_bOutOfAmmo = 0x2934;
                constexpr uint32_t m_bLaserOn = 0x2935;
                constexpr uint32_t m_sLaserHaloSprite = 0x2938;
            }
            namespace DT_WeaponStunStick {
                constexpr uint32_t m_bActive = 0x1cfc;
            }
            namespace DT_WeaponSMG1 {
            }
            namespace DT_Weapon_SLAM {
                constexpr uint32_t m_tSlamState = 0x1ca8;
                constexpr uint32_t m_bDetonatorArmed = 0x1cac;
                constexpr uint32_t m_bNeedDetonatorDraw = 0x1cad;
                constexpr uint32_t m_bNeedDetonatorHolster = 0x1cae;
                constexpr uint32_t m_bNeedReload = 0x1caf;
                constexpr uint32_t m_bClearReload = 0x1cb0;
                constexpr uint32_t m_bThrowSatchel = 0x1cb1;
                constexpr uint32_t m_bAttachSatchel = 0x1cb2;
                constexpr uint32_t m_bAttachTripmine = 0x1cb3;
            }
            namespace DT_WeaponShotgun {
                constexpr uint32_t m_bNeedPump = 0x1ca8;
                constexpr uint32_t m_bDelayedFire1 = 0x1ca9;
                constexpr uint32_t m_bDelayedFire2 = 0x1caa;
                constexpr uint32_t m_bDelayedReload = 0x1cab;
            }
            namespace DT_WeaponRPG {
                constexpr uint32_t m_bInitialStateUpdate = 0x1cc0;
                constexpr uint32_t m_bGuiding = 0x1cc1;
                constexpr uint32_t m_bHideGuiding = 0x1cc2;
                constexpr uint32_t m_hMissile = 0x1cc4;
                constexpr uint32_t m_vecLaserDot = 0x1cc8;
            }
            namespace DT_LaserDot {
            }
            namespace DT_WeaponPistol {
                constexpr uint32_t m_flSoonestPrimaryAttack = 0x1cb8;
                constexpr uint32_t m_flLastAttackTime = 0x1cc0;
                constexpr uint32_t m_flAccuracyPenalty = 0x1cc8;
                constexpr uint32_t m_nNumShotsFired = 0x1ccc;
            }
            namespace DT_WeaponPhysCannon {
                constexpr uint32_t m_bActive = 0x2148;
                constexpr uint32_t m_hAttachedObject = 0x1cc0;
                constexpr uint32_t m_attachedPositionObjectSpace = 0x1cb4;
                constexpr uint32_t m_attachedAnglesPlayerSpace[0] = 0x1ca8;
                constexpr uint32_t m_attachedAnglesPlayerSpace[1] = 0x1cac;
                constexpr uint32_t m_attachedAnglesPlayerSpace[2] = 0x1cb0;
                constexpr uint32_t m_EffectState = 0x214c;
                constexpr uint32_t m_bOpen = 0x2150;
                constexpr uint32_t m_bPhyscannonState = 0x2151;
            }
            namespace DT_BaseHL2MPCombatWeapon {
            }
            namespace DT_BaseHL2MPBludgeonWeapon {
            }
            namespace DT_HL2MPMachineGun {
                constexpr uint32_t m_nShotsFired = 0x1ca8;
            }
            namespace DT_WeaponHL2MPBase {
            }
            namespace DT_WeaponFrag {
                constexpr uint32_t m_bRedraw = 0x1ca8;
                constexpr uint32_t m_fDrawbackFinished = 0x1cb0;
                constexpr uint32_t m_AttackPaused = 0x1cac;
            }
            namespace DT_WeaponCrowbar {
            }
            namespace DT_WeaponCrossbow {
                constexpr uint32_t m_bInZoom = 0x1cac;
                constexpr uint32_t m_bMustReload = 0x1cad;
            }
            namespace DT_WeaponAR2 {
            }
            namespace DT_Weapon357 {
            }
            namespace DT_HL2MPGameRulesProxy {
                constexpr uint32_t m_bTeamPlayEnabled = 0x38;
            }
            namespace DT_TEHL2MPFireBullets {
                constexpr uint32_t m_vecOrigin = 0x24;
                constexpr uint32_t m_vecDir = 0x30;
                constexpr uint32_t m_iAmmoID = 0x3c;
                constexpr uint32_t m_iSeed = 0x44;
                constexpr uint32_t m_iShots = 0x4c;
                constexpr uint32_t m_iPlayer = 0x20;
                constexpr uint32_t m_iWeaponIndex = 0x40;
                constexpr uint32_t m_flSpread = 0x48;
                constexpr uint32_t m_bDoImpacts = 0x50;
                constexpr uint32_t m_bDoTracers = 0x51;
                constexpr uint32_t m_TracerType = 0x58;
                constexpr uint32_t m_flSpreadY = 0x54;
            }
            namespace DT_TEPlayerAnimEvent {
                constexpr uint32_t m_hPlayer = 0x20;
                constexpr uint32_t m_iEvent = 0x24;
                constexpr uint32_t m_nData = 0x28;
            }
            namespace DT_HL2MPRagdoll {
                constexpr uint32_t m_vecRagdollOrigin = 0x1c60;
                constexpr uint32_t m_hPlayer = 0x1c50;
                constexpr uint32_t m_nModelIndex = 0xd4;
                constexpr uint32_t m_nForceBone = 0x1714;
                constexpr uint32_t m_vecForce = 0x1708;
                constexpr uint32_t m_vecRagdollVelocity = 0x1c54;
            }
            namespace DT_HL2MP_Player {
                constexpr uint32_t m_vecOrigin = 0x438;
                constexpr uint32_t m_angEyeAngles[0] = 0x35d8;
                constexpr uint32_t m_angEyeAngles[1] = 0x35dc;
                constexpr uint32_t m_vecOrigin = 0x438;
                constexpr uint32_t m_angEyeAngles[0] = 0x35d8;
                constexpr uint32_t m_angEyeAngles[1] = 0x35dc;
                constexpr uint32_t m_hRagdoll = 0x3638;
                constexpr uint32_t m_iSpawnInterpCounter = 0x367c;
                constexpr uint32_t m_fIsWalking = 0x3654;
            }
            namespace DT_WeaponBugBait {
                constexpr uint32_t m_bRedraw = 0x1ca9;
                constexpr uint32_t m_bDrawBackFinished = 0x1ca8;
            }
            namespace DT_CrossbowBolt {
            }
            namespace DT_WeaponOldManHarpoon {
            }
            namespace DT_WeaponCitizenSuitcase {
            }
            namespace DT_WeaponCitizenPackage {
            }
            namespace DT_WeaponAlyxGun {
            }
            namespace DT_WeaponCubemap {
            }
            namespace DT_WeaponAnnabelle {
            }
            namespace DT_WeaponCycler {
            }
            namespace DT_VortigauntEffectDispel {
                constexpr uint32_t m_bFadeOut = 0x16c0;
            }
            namespace DT_VortigauntChargeToken {
                constexpr uint32_t m_bFadeOut = 0x16b8;
            }
            namespace DT_NPC_Vortigaunt {
                constexpr uint32_t m_flBlueEndFadeTime = 0x2934;
                constexpr uint32_t m_bIsBlue = 0x2930;
                constexpr uint32_t m_bIsBlack = 0x2938;
            }
            namespace DT_PropVehiclePrisonerPod {
                constexpr uint32_t m_hPlayer = 0x1bd8;
                constexpr uint32_t m_bEnterAnimOn = 0x1be0;
                constexpr uint32_t m_bExitAnimOn = 0x1be1;
                constexpr uint32_t m_vecEyeExitEndpoint = 0x1be4;
                constexpr uint32_t m_bLimitView = 0x1be2;
                constexpr uint32_t m_bLocked = 0x1be3;
            }
            namespace DT_PropCrane {
                constexpr uint32_t m_hPlayer = 0x1bd0;
                constexpr uint32_t m_bMagnetOn = 0x1be8;
                constexpr uint32_t m_bEnterAnimOn = 0x1bd8;
                constexpr uint32_t m_bExitAnimOn = 0x1bd9;
                constexpr uint32_t m_vecEyeExitEndpoint = 0x1bdc;
            }
            namespace DT_PropAirboat {
                constexpr uint32_t m_bHeadlightIsOn = 0x1d3c;
                constexpr uint32_t m_nAmmoCount = 0x1d40;
                constexpr uint32_t m_nExactWaterLevel = 0x1d50;
                constexpr uint32_t m_nWaterLevel = 0x200;
                constexpr uint32_t m_vecPhysVelocity = 0x2238;
            }
            namespace DT_Flare {
                constexpr uint32_t m_flTimeBurnOut = 0x2a78;
                constexpr uint32_t m_flScale = 0x2a7c;
                constexpr uint32_t m_bLight = 0x2a80;
                constexpr uint32_t m_bSmoke = 0x2a81;
                constexpr uint32_t m_bPropFlare = 0x2a82;
            }
            namespace DT_TEConcussiveExplosion {
                constexpr uint32_t m_vecNormal = 0x30;
                constexpr uint32_t m_flScale = 0x3c;
                constexpr uint32_t m_nRadius = 0x40;
                constexpr uint32_t m_nMagnitude = 0x44;
            }
            namespace DT_NPC_Strider {
                constexpr uint32_t m_vecHitPos = 0x2998;
                constexpr uint32_t m_vecIKTarget[0] = 0x29a4;
                constexpr uint32_t m_vecIKTarget[1] = 0x29b0;
                constexpr uint32_t m_vecIKTarget[2] = 0x29bc;
                constexpr uint32_t m_vecIKTarget[3] = 0x29c8;
                constexpr uint32_t m_vecIKTarget[4] = 0x29d4;
                constexpr uint32_t m_vecIKTarget[5] = 0x29e0;
            }
            namespace DT_ScriptIntro {
                constexpr uint32_t m_vecCameraView = 0x1728;
                constexpr uint32_t m_vecCameraViewAngles = 0x1734;
                constexpr uint32_t m_iBlendMode = 0x1740;
                constexpr uint32_t m_iNextBlendMode = 0x1744;
                constexpr uint32_t m_flNextBlendTime = 0x1748;
                constexpr uint32_t m_flBlendStartTime = 0x1750;
                constexpr uint32_t m_bActive = 0x1758;
                constexpr uint32_t m_iFOV = 0x16b4;
                constexpr uint32_t m_iNextFOV = 0x16b0;
                constexpr uint32_t m_iStartFOV = 0x16bc;
                constexpr uint32_t m_flNextFOVBlendTime = 0x16c0;
                constexpr uint32_t m_flFOVBlendStartTime = 0x16c8;
                constexpr uint32_t m_bAlternateFOV = 0x16d0;
                constexpr uint32_t m_flFadeAlpha = 0x176c;
                constexpr uint32_t m_flFadeColor[0] = 0x1760;
                constexpr uint32_t m_flFadeColor = 0x0;
                constexpr uint32_t m_flFadeDuration = 0x1774;
                constexpr uint32_t m_hCameraEntity = 0x175c;
            }
            namespace DT_RotorWashEmitter {
                constexpr uint32_t m_flAltitude = 0x16b0;
            }
            namespace DT_PropCombineBall {
                constexpr uint32_t m_bEmit = 0x1bd4;
                constexpr uint32_t m_flRadius = 0x1bd8;
                constexpr uint32_t m_bHeld = 0x1bdc;
                constexpr uint32_t m_bLaunched = 0x1bdd;
            }
            namespace DT_PlasmaBeamNode {
                constexpr uint32_t m_vecVelocity = 0x150;
                constexpr uint32_t m_bSprayOn = 0x16b0;
            }
            namespace DT_RollerMine {
                constexpr uint32_t m_bIsOpen = 0x2930;
                constexpr uint32_t m_flActiveTime = 0x2934;
                constexpr uint32_t m_bHackedByAlyx = 0x2938;
                constexpr uint32_t m_bPowerDown = 0x2939;
            }
            namespace DT_NPC_Manhack {
                constexpr uint32_t m_nEnginePitch1 = 0x2948;
                constexpr uint32_t m_flEnginePitch1Time = 0x2950;
                constexpr uint32_t m_nEnginePitch2 = 0x294c;
                constexpr uint32_t m_flEnginePitch2Time = 0x2954;
            }
            namespace DT_CombineGunship {
                constexpr uint32_t m_vecHitPos = 0x2990;
            }
            namespace DT_NPC_AntlionGuard {
                constexpr uint32_t m_bCavernBreed = 0x2930;
                constexpr uint32_t m_bInCavern = 0x2931;
                constexpr uint32_t m_iBleedingLevel = 0x2940;
            }
            namespace DT_InfoTeleporterCountdown {
                constexpr uint32_t m_bCountdownStarted = 0x16b0;
                constexpr uint32_t m_bDisabled = 0x16b1;
                constexpr uint32_t m_flStartTime = 0x16b4;
                constexpr uint32_t m_flTimeRemaining = 0x16b8;
            }
            namespace DT_MortarShell {
                constexpr uint32_t m_flLifespan = 0x16c0;
                constexpr uint32_t m_flRadius = 0x16c4;
                constexpr uint32_t m_vecSurfaceNormal = 0x16cc;
            }
            namespace DT_EnvStarfield {
                constexpr uint32_t m_bOn = 0x16b8;
                constexpr uint32_t m_flDensity = 0x16bc;
            }
            namespace DT_EnvHeadcrabCanister {
                constexpr uint32_t m_flFlightSpeed = 0x1c04;
                constexpr uint32_t m_flLaunchTime = 0x1c08;
                constexpr uint32_t m_vecParabolaDirection = 0x1c20;
                constexpr uint32_t m_flFlightTime = 0x1c00;
                constexpr uint32_t m_flWorldEnterTime = 0x1c2c;
                constexpr uint32_t m_flInitialZSpeed = 0x1c10;
                constexpr uint32_t m_flZAcceleration = 0x1c14;
                constexpr uint32_t m_flHorizSpeed = 0x1c18;
                constexpr uint32_t m_bLaunchedFromWithinWorld = 0x1c1c;
                constexpr uint32_t m_vecStartPosition = 0x1bd0;
                constexpr uint32_t m_vecEnterWorldPosition = 0x1bdc;
                constexpr uint32_t m_vecDirection = 0x1be8;
                constexpr uint32_t m_vecStartAngles = 0x1bf4;
                constexpr uint32_t m_vecSkyboxOrigin = 0x1c30;
                constexpr uint32_t m_flSkyboxScale = 0x1c3c;
                constexpr uint32_t m_bInSkybox = 0x1c40;
                constexpr uint32_t m_bLanded = 0x1c48;
            }
            namespace DT_AlyxEmpEffect {
                constexpr uint32_t m_nState = 0x16b0;
                constexpr uint32_t m_flDuration = 0x16b4;
                constexpr uint32_t m_flStartTime = 0x16b8;
            }
            namespace DT_Corpse {
                constexpr uint32_t m_nReferencePlayer = 0x1bc8;
            }
            namespace DT_CitadelEnergyCore {
                constexpr uint32_t m_flScale = 0x16b0;
                constexpr uint32_t m_nState = 0x16b4;
                constexpr uint32_t m_flDuration = 0x16b8;
                constexpr uint32_t m_flStartTime = 0x16bc;
                constexpr uint32_t m_spawnflags = 0x16c0;
            }
            namespace DT_HL2_Player {
                constexpr uint32_t m_flSuitPower = 0x3550;
                constexpr uint32_t m_bZooming = 0x3561;
                constexpr uint32_t m_bitsActiveDevices = 0x3554;
                constexpr uint32_t m_iSquadMemberCount = 0x3558;
                constexpr uint32_t m_iSquadMedicCount = 0x355c;
                constexpr uint32_t m_fSquadInFollowMode = 0x3560;
                constexpr uint32_t m_bWeaponLowered = 0x3562;
                constexpr uint32_t m_hLadder = 0x3564;
                constexpr uint32_t m_bDisplayReticle = 0x3563;
                constexpr uint32_t m_fIsSprinting = 0x35a8;
            }
            namespace DT_BaseHLBludgeonWeapon {
            }
            namespace DT_HLSelectFireMachineGun {
            }
            namespace DT_HLMachineGun {
            }
            namespace DT_BaseHelicopter {
                constexpr uint32_t m_flStartupTime = 0x2930;
            }
            namespace DT_NPC_Barney {
            }
            namespace DT_Barnacle {
                constexpr uint32_t m_flAltitude = 0x2960;
                constexpr uint32_t m_vecRoot = 0x293c;
                constexpr uint32_t m_vecTip = 0x2948;
                constexpr uint32_t m_vecTipDrawOffset = 0x2954;
            }
            namespace DT_AR2Explosion {
                constexpr uint32_t m_szMaterialName = 0x17f8;
            }
            namespace DT_TEAntlionDust {
                constexpr uint32_t m_vecOrigin = 0x38;
                constexpr uint32_t m_vecAngles = 0x44;
                constexpr uint32_t m_bBlockedSpawner = 0x50;
            }
            namespace DT_BaseHLCombatWeapon {
            }
            namespace DT_WeaponShotgun_HL1 {
                constexpr uint32_t m_flPumpTime = 0x1c70;
                constexpr uint32_t m_fInSpecialReload = 0x1c74;
            }
            namespace DT_WeaponSatchel {
                constexpr uint32_t m_iRadioViewIndex = 0x1c70;
                constexpr uint32_t m_iRadioWorldIndex = 0x1c74;
                constexpr uint32_t m_iSatchelViewIndex = 0x1c78;
                constexpr uint32_t m_iSatchelWorldIndex = 0x1c7c;
                constexpr uint32_t m_iChargeReady = 0x1c80;
            }
            namespace DT_WeaponRPG_HL1 {
                constexpr uint32_t m_bIntialStateUpdate = 0x1c71;
                constexpr uint32_t m_bGuiding = 0x1c70;
                constexpr uint32_t m_bLaserDotSuspended = 0x1c72;
            }
            namespace DT_LaserDot_HL1 {
                constexpr uint32_t m_bIsOn = 0x16c9;
            }
            namespace DT_WeaponMP5 {
            }
            namespace DT_WeaponHgun {
                constexpr uint32_t m_flRechargeTime = 0x1c70;
                constexpr uint32_t m_iFirePhase = 0x1c74;
            }
            namespace DT_WeaponHandGrenade {
                constexpr uint32_t m_flStartThrow = 0x1c70;
                constexpr uint32_t m_flReleaseThrow = 0x1c74;
            }
            namespace DT_WeaponGlock {
            }
            namespace DT_WeaponGauss {
                constexpr uint32_t m_nAttackState = 0x1c70;
                constexpr uint32_t m_bPrimaryFire = 0x1c74;
                constexpr uint32_t m_flStartCharge = 0x1c78;
                constexpr uint32_t m_flAmmoStartCharge = 0x1c7c;
                constexpr uint32_t m_flPlayAftershock = 0x1c80;
                constexpr uint32_t m_flNextAmmoBurn = 0x1c88;
            }
            namespace DT_WeaponEgon {
            }
            namespace DT_WeaponCrossbow_HL1 {
                constexpr uint32_t m_fInZoom = 0x1c70;
            }
            namespace DT_Weapon357_HL1 {
                constexpr uint32_t m_fInZoom = 0x1c70;
            }
            namespace DT_BaseHL1MPCombatWeapon {
            }
            namespace DT_WeaponTripMine {
                constexpr uint32_t m_iGroundIndex = 0x1c70;
                constexpr uint32_t m_iPickedUpIndex = 0x1c74;
            }
            namespace DT_WeaponSnark {
                constexpr uint32_t m_bJustThrown = 0x1c70;
            }
            namespace DT_WeaponCrowbar_HL1 {
            }
            namespace DT_BaseHelicopter_HL1 {
            }
            namespace DT_RpgRocket {
            }
            namespace DT_BaseHL1CombatWeapon {
            }
            namespace DT_PredictedViewModel {
            }
            namespace DT_TriggerPlayerMovement {
            }
            namespace DT_BaseTrigger {
                constexpr uint32_t m_bClientSidePredicted = 0x16e0;
                constexpr uint32_t m_spawnflags = 0x92c;
            }
            namespace DT_SpatialEntity {
                constexpr uint32_t m_vecOrigin = 0x16b0;
                constexpr uint32_t m_minFalloff = 0x16bc;
                constexpr uint32_t m_maxFalloff = 0x16c0;
                constexpr uint32_t m_flCurWeight = 0x16c4;
                constexpr uint32_t m_bEnabled = 0x17cc;
            }
            namespace DT_PointWorldText {
                constexpr uint32_t m_szText = 0x16ea;
                constexpr uint32_t m_colTextColor = 0x17fc;
                constexpr uint32_t m_flTextSize = 0x17f0;
                constexpr uint32_t m_flTextSpacingX = 0x17f4;
                constexpr uint32_t m_flTextSpacingY = 0x17f8;
                constexpr uint32_t m_nOrientation = 0x1800;
                constexpr uint32_t m_bRainbow = 0x16e8;
                constexpr uint32_t m_bTextEnabled = 0x16e9;
            }
            namespace DT_EnvAmbientLight {
                constexpr uint32_t m_vecColor = 0x17d8;
            }
            namespace DT_BeamSpotlight {
                constexpr uint32_t m_nHaloIndex = 0x16b0;
                constexpr uint32_t m_bSpotlightOn = 0x16bc;
                constexpr uint32_t m_bHasDynamicLight = 0x16bd;
                constexpr uint32_t m_flSpotlightMaxLength = 0x16c0;
                constexpr uint32_t m_flSpotlightGoalWidth = 0x16c4;
                constexpr uint32_t m_flHDRColorScale = 0x16c8;
                constexpr uint32_t m_nRotationAxis = 0x16b4;
                constexpr uint32_t m_flRotationSpeed = 0x16b8;
            }
            namespace DT_BaseToggle {
                constexpr uint32_t m_vecFinalDest = 0x16c4;
                constexpr uint32_t m_movementType = 0x16d0;
                constexpr uint32_t m_flMoveTargetTime = 0x16d4;
            }
            namespace DT_SpriteTrail {
                constexpr uint32_t m_flLifeTime = 0x2758;
                constexpr uint32_t m_flStartWidth = 0x275c;
                constexpr uint32_t m_flEndWidth = 0x2760;
                constexpr uint32_t m_flStartWidthVariance = 0x2764;
                constexpr uint32_t m_flTextureRes = 0x2768;
                constexpr uint32_t m_flMinFadeLength = 0x276c;
                constexpr uint32_t m_vecSkyboxOrigin = 0x2770;
                constexpr uint32_t m_flSkyboxScale = 0x277c;
            }
            namespace DT_SpriteOriented {
            }
            namespace DT_Sprite {
                constexpr uint32_t m_hAttachedToEntity = 0x16c8;
                constexpr uint32_t m_nAttachment = 0x16cc;
                constexpr uint32_t m_flScaleTime = 0x16e8;
                constexpr uint32_t m_flSpriteScale = 0x16e4;
                constexpr uint32_t m_flSpriteFramerate = 0x16d0;
                constexpr uint32_t m_flGlowProxySize = 0x16f0;
                constexpr uint32_t m_flHDRColorScale = 0x16f4;
                constexpr uint32_t m_flFrame = 0x16d4;
                constexpr uint32_t m_flBrightnessTime = 0x16e0;
                constexpr uint32_t m_nBrightness = 0x16dc;
                constexpr uint32_t m_bWorldSpaceScale = 0x16ec;
            }
            namespace DT_Ragdoll_Attached {
                constexpr uint32_t m_boneIndexAttached = 0x2030;
                constexpr uint32_t m_ragdollAttachedObjectIndex = 0x202c;
                constexpr uint32_t m_attachmentPointBoneSpace = 0x2008;
                constexpr uint32_t m_attachmentPointRagdollSpace = 0x2020;
            }
            namespace DT_Ragdoll {
                constexpr uint32_t m_ragPos[ 0 ] = 0x1bc8;
                constexpr uint32_t m_ragPos[ 1 ] = 0x1bd4;
                constexpr uint32_t m_ragPos[ 2 ] = 0x1be0;
                constexpr uint32_t m_ragPos[ 3 ] = 0x1bec;
                constexpr uint32_t m_ragPos[ 4 ] = 0x1bf8;
                constexpr uint32_t m_ragPos[ 5 ] = 0x1c04;
                constexpr uint32_t m_ragPos[ 6 ] = 0x1c10;
                constexpr uint32_t m_ragPos[ 7 ] = 0x1c1c;
                constexpr uint32_t m_ragPos[ 8 ] = 0x1c28;
                constexpr uint32_t m_ragPos[ 9 ] = 0x1c34;
                constexpr uint32_t m_ragPos[ 10 ] = 0x1c40;
                constexpr uint32_t m_ragPos[ 11 ] = 0x1c4c;
                constexpr uint32_t m_ragPos[ 12 ] = 0x1c58;
                constexpr uint32_t m_ragPos[ 13 ] = 0x1c64;
                constexpr uint32_t m_ragPos[ 14 ] = 0x1c70;
                constexpr uint32_t m_ragPos[ 15 ] = 0x1c7c;
                constexpr uint32_t m_ragPos[ 16 ] = 0x1c88;
                constexpr uint32_t m_ragPos[ 17 ] = 0x1c94;
                constexpr uint32_t m_ragPos[ 18 ] = 0x1ca0;
                constexpr uint32_t m_ragPos[ 19 ] = 0x1cac;
                constexpr uint32_t m_ragPos[ 20 ] = 0x1cb8;
                constexpr uint32_t m_ragPos[ 21 ] = 0x1cc4;
                constexpr uint32_t m_ragPos[ 22 ] = 0x1cd0;
                constexpr uint32_t m_ragPos[ 23 ] = 0x1cdc;
                constexpr uint32_t m_ragPos[ 24 ] = 0x1ce8;
                constexpr uint32_t m_ragPos[ 25 ] = 0x1cf4;
                constexpr uint32_t m_ragPos[ 26 ] = 0x1d00;
                constexpr uint32_t m_ragPos[ 27 ] = 0x1d0c;
                constexpr uint32_t m_ragPos[ 28 ] = 0x1d18;
                constexpr uint32_t m_ragPos[ 29 ] = 0x1d24;
                constexpr uint32_t m_ragPos[ 30 ] = 0x1d30;
                constexpr uint32_t m_ragPos[ 31 ] = 0x1d3c;
                constexpr uint32_t m_ragAngles[ 0 ] = 0x1d48;
                constexpr uint32_t m_ragAngles[ 1 ] = 0x1d54;
                constexpr uint32_t m_ragAngles[ 2 ] = 0x1d60;
                constexpr uint32_t m_ragAngles[ 3 ] = 0x1d6c;
                constexpr uint32_t m_ragAngles[ 4 ] = 0x1d78;
                constexpr uint32_t m_ragAngles[ 5 ] = 0x1d84;
                constexpr uint32_t m_ragAngles[ 6 ] = 0x1d90;
                constexpr uint32_t m_ragAngles[ 7 ] = 0x1d9c;
                constexpr uint32_t m_ragAngles[ 8 ] = 0x1da8;
                constexpr uint32_t m_ragAngles[ 9 ] = 0x1db4;
                constexpr uint32_t m_ragAngles[ 10 ] = 0x1dc0;
                constexpr uint32_t m_ragAngles[ 11 ] = 0x1dcc;
                constexpr uint32_t m_ragAngles[ 12 ] = 0x1dd8;
                constexpr uint32_t m_ragAngles[ 13 ] = 0x1de4;
                constexpr uint32_t m_ragAngles[ 14 ] = 0x1df0;
                constexpr uint32_t m_ragAngles[ 15 ] = 0x1dfc;
                constexpr uint32_t m_ragAngles[ 16 ] = 0x1e08;
                constexpr uint32_t m_ragAngles[ 17 ] = 0x1e14;
                constexpr uint32_t m_ragAngles[ 18 ] = 0x1e20;
                constexpr uint32_t m_ragAngles[ 19 ] = 0x1e2c;
                constexpr uint32_t m_ragAngles[ 20 ] = 0x1e38;
                constexpr uint32_t m_ragAngles[ 21 ] = 0x1e44;
                constexpr uint32_t m_ragAngles[ 22 ] = 0x1e50;
                constexpr uint32_t m_ragAngles[ 23 ] = 0x1e5c;
                constexpr uint32_t m_ragAngles[ 24 ] = 0x1e68;
                constexpr uint32_t m_ragAngles[ 25 ] = 0x1e74;
                constexpr uint32_t m_ragAngles[ 26 ] = 0x1e80;
                constexpr uint32_t m_ragAngles[ 27 ] = 0x1e8c;
                constexpr uint32_t m_ragAngles[ 28 ] = 0x1e98;
                constexpr uint32_t m_ragAngles[ 29 ] = 0x1ea4;
                constexpr uint32_t m_ragAngles[ 30 ] = 0x1eb0;
                constexpr uint32_t m_ragAngles[ 31 ] = 0x1ebc;
                constexpr uint32_t m_hUnragdoll = 0x1ff0;
                constexpr uint32_t m_flBlendWeight = 0x1ff4;
                constexpr uint32_t m_nOverlaySequence = 0x1ffc;
            }
            namespace DT_PoseController {
                constexpr uint32_t m_bPoseValueParity = 0x16c4;
                constexpr uint32_t m_fPoseValue = 0x16c8;
                constexpr uint32_t m_fInterpolationTime = 0x16cc;
                constexpr uint32_t m_bInterpolationWrap = 0x16d0;
                constexpr uint32_t m_fCycleFrequency = 0x16d4;
                constexpr uint32_t m_nFModType = 0x16d8;
                constexpr uint32_t m_fFModTimeOffset = 0x16dc;
                constexpr uint32_t m_fFModRate = 0x16e0;
                constexpr uint32_t m_fFModAmplitude = 0x16e4;
            }
            namespace DT_GameRulesProxy {
            }
            namespace DT_InfoLadderDismount {
            }
            namespace DT_FuncLadder {
                constexpr uint32_t m_vecPlayerMountPositionTop = 0x16e0;
                constexpr uint32_t m_vecPlayerMountPositionBottom = 0x16ec;
                constexpr uint32_t m_vecLadderDir = 0x16b0;
                constexpr uint32_t m_bFakeLadder = 0x16f9;
            }
            namespace DT_DetailController {
                constexpr uint32_t m_flFadeStartDist = 0x16b0;
                constexpr uint32_t m_flFadeEndDist = 0x16b4;
            }
            namespace DT_World {
                constexpr uint32_t m_WorldMins = 0x16b0;
                constexpr uint32_t m_WorldMaxs = 0x16bc;
                constexpr uint32_t m_bStartDark = 0x16c8;
                constexpr uint32_t m_flMaxOccludeeArea = 0x16cc;
                constexpr uint32_t m_flMinOccluderArea = 0x16d0;
                constexpr uint32_t m_flMaxPropScreenSpaceWidth = 0x16d8;
                constexpr uint32_t m_flMinPropScreenSpaceWidth = 0x16d4;
                constexpr uint32_t m_iszDetailSpriteMaterial = 0x16dc;
            }
            namespace DT_WaterLODControl {
                constexpr uint32_t m_flCheapWaterStartDistance = 0x16b0;
                constexpr uint32_t m_flCheapWaterEndDistance = 0x16b4;
            }
            namespace DT_WaterBullet {
            }
            namespace DT_VGuiScreen {
                constexpr uint32_t m_flWidth = 0x16b8;
                constexpr uint32_t m_flHeight = 0x16bc;
                constexpr uint32_t m_fScreenFlags = 0x16e4;
                constexpr uint32_t m_nPanelName = 0x16c0;
                constexpr uint32_t m_nAttachmentIndex = 0x16dc;
                constexpr uint32_t m_nOverlayMaterial = 0x16e0;
                constexpr uint32_t m_hPlayerOwner = 0x1750;
            }
            namespace DT_PropJeep {
                constexpr uint32_t m_bHeadlightIsOn = 0x1d48;
            }
            namespace DT_PropVehicleChoreoGeneric {
                constexpr uint32_t m_hPlayer = 0x1c00;
                constexpr uint32_t m_bEnterAnimOn = 0x1c08;
                constexpr uint32_t m_bExitAnimOn = 0x1c09;
                constexpr uint32_t m_bForceEyesToAttachment = 0x1c18;
                constexpr uint32_t m_vecEyeExitEndpoint = 0x1c0c;
                constexpr uint32_t m_vehicleView.bClampEyeAngles = 0x1ca8;
                constexpr uint32_t m_vehicleView.flPitchCurveZero = 0x1cac;
                constexpr uint32_t m_vehicleView.flPitchCurveLinear = 0x1cb0;
                constexpr uint32_t m_vehicleView.flRollCurveZero = 0x1cb4;
                constexpr uint32_t m_vehicleView.flRollCurveLinear = 0x1cb8;
                constexpr uint32_t m_vehicleView.flFOV = 0x1cbc;
                constexpr uint32_t m_vehicleView.flYawMin = 0x1cc0;
                constexpr uint32_t m_vehicleView.flYawMax = 0x1cc4;
                constexpr uint32_t m_vehicleView.flPitchMin = 0x1cc8;
                constexpr uint32_t m_vehicleView.flPitchMax = 0x1ccc;
            }
            namespace DT_Tesla {
                constexpr uint32_t m_SoundName = 0x16e0;
                constexpr uint32_t m_iszSpriteName = 0x1720;
            }
            namespace DT_Team {
                constexpr uint32_t m_iTeamNum = 0x1704;
                constexpr uint32_t m_iScore = 0x16f0;
                constexpr uint32_t m_iRoundsWon = 0x16f4;
                constexpr uint32_t m_szTeamname = 0x16d0;
                constexpr uint32_t player_array_element = 0x0;
                constexpr uint32_t "player_array" = 0x0;
            }
            namespace DT_Sun {
                constexpr uint32_t m_clrRender = 0x90;
                constexpr uint32_t m_clrOverlay = 0x1860;
                constexpr uint32_t m_vDirection = 0x186c;
                constexpr uint32_t m_bOn = 0x1878;
                constexpr uint32_t m_nSize = 0x1864;
                constexpr uint32_t m_nOverlaySize = 0x1868;
                constexpr uint32_t m_nMaterial = 0x187c;
                constexpr uint32_t m_nOverlayMaterial = 0x1880;
                constexpr uint32_t HDRColorScale = 0x0;
            }
            namespace DT_ParticlePerformanceMonitor {
                constexpr uint32_t m_bMeasurePerf = 0x16b1;
                constexpr uint32_t m_bDisplayPerf = 0x16b0;
            }
            namespace DT_SpotlightEnd {
                constexpr uint32_t m_flLightScale = 0x16b0;
                constexpr uint32_t m_Radius = 0x16b4;
            }
            namespace DT_SlideshowDisplay {
                constexpr uint32_t m_bEnabled = 0x16b0;
                constexpr uint32_t m_szDisplayText = 0x16b1;
                constexpr uint32_t m_szSlideshowDirectory = 0x1731;
                constexpr uint32_t m_fMinSlideTime = 0x17f0;
                constexpr uint32_t m_fMaxSlideTime = 0x17f4;
                constexpr uint32_t m_iCycleType = 0x17fc;
                constexpr uint32_t m_bNoListRepeats = 0x1800;
            }
            namespace DT_ShadowControl {
                constexpr uint32_t m_shadowDirection = 0x16b0;
                constexpr uint32_t m_shadowColor = 0x16bc;
                constexpr uint32_t m_flShadowMaxDist = 0x16c0;
                constexpr uint32_t m_bDisableShadows = 0x16c4;
                constexpr uint32_t m_bEnableLocalLightShadows = 0x16c5;
            }
            namespace DT_SceneEntity {
                constexpr uint32_t m_nSceneStringIndex = 0x16c4;
                constexpr uint32_t m_bIsPlayingBack = 0x16b8;
                constexpr uint32_t m_bPaused = 0x16b9;
                constexpr uint32_t m_bMultiplayer = 0x16ba;
                constexpr uint32_t m_flForceClientTime = 0x16c0;
                constexpr uint32_t lengthprop16 = 0x0;
            }
            namespace DT_RopeKeyframe {
                constexpr uint32_t m_iRopeMaterialModelIndex = 0x16ec;
                constexpr uint32_t m_hStartPoint = 0x19dc;
                constexpr uint32_t m_hEndPoint = 0x19e0;
                constexpr uint32_t m_iStartAttachment = 0x19e4;
                constexpr uint32_t m_iEndAttachment = 0x19e6;
                constexpr uint32_t m_iStartBone = 0x1a9a;
                constexpr uint32_t m_iEndBone = 0x1a98;
                constexpr uint32_t m_vecStartOffset = 0x1a9c;
                constexpr uint32_t m_vecEndOffset = 0x1aa8;
                constexpr uint32_t m_clrRender = 0x90;
                constexpr uint32_t m_fLockedPoints = 0x19f8;
                constexpr uint32_t m_Slack = 0x19f0;
                constexpr uint32_t m_RopeLength = 0x19ec;
                constexpr uint32_t m_RopeFlags = 0x16e8;
                constexpr uint32_t m_TextureScale = 0x19f4;
                constexpr uint32_t m_nSegments = 0x19d8;
                constexpr uint32_t m_bConstrainBetweenEndpoints = 0x1a90;
                constexpr uint32_t m_Subdiv = 0x19e8;
                constexpr uint32_t m_Width = 0x19fc;
                constexpr uint32_t m_flScrollSpeed = 0x16e4;
                constexpr uint32_t m_vecOrigin = 0x438;
                constexpr uint32_t moveparent = 0x21c;
                constexpr uint32_t m_iParentAttachment = 0x1fe;
            }
            namespace DT_RagdollManager {
                constexpr uint32_t m_iCurrentMaxRagdollCount = 0x16b0;
            }
            namespace DT_PhysicsPropMultiplayer {
                constexpr uint32_t m_iPhysicsMode = 0x1bd8;
                constexpr uint32_t m_fMass = 0x1bdc;
                constexpr uint32_t m_collisionMins = 0x1be0;
                constexpr uint32_t m_collisionMaxs = 0x1bec;
            }
            namespace DT_PhysBoxMultiplayer {
                constexpr uint32_t m_iPhysicsMode = 0x16c0;
                constexpr uint32_t m_fMass = 0x16c4;
            }
            namespace DT_PropDoorRotating {
            }
            namespace DT_BasePropDoor {
                constexpr uint32_t m_bLocked = 0x1be9;
                constexpr uint32_t m_eDoorState = 0x1bec;
            }
            namespace DT_DynamicProp {
                constexpr uint32_t m_bUseHitboxesForRenderBox = 0x1bc8;
            }
            namespace DT_PointCamera {
                constexpr uint32_t m_FOV = 0x16b0;
                constexpr uint32_t m_Resolution = 0x16b4;
                constexpr uint32_t m_bFogEnable = 0x16b8;
                constexpr uint32_t m_FogColor = 0x16b9;
                constexpr uint32_t m_FogColorHDR = 0x16bd;
                constexpr uint32_t m_flFogStart = 0x16c4;
                constexpr uint32_t m_flFogEnd = 0x16c8;
                constexpr uint32_t m_flFogMaxDensity = 0x16cc;
                constexpr uint32_t m_bFogRadial = 0x16d0;
                constexpr uint32_t m_bActive = 0x16d1;
                constexpr uint32_t m_bUseScreenAspectRatio = 0x16d2;
                constexpr uint32_t m_bGlobalOverride = 0x16d3;
            }
            namespace DT_PlayerResource {
            }
            namespace DT_Plasma {
                constexpr uint32_t m_flStartScale = 0x16b0;
                constexpr uint32_t m_flScale = 0x16b4;
                constexpr uint32_t m_flScaleTime = 0x16b8;
                constexpr uint32_t m_nFlags = 0x16bc;
                constexpr uint32_t m_nPlasmaModelIndex = 0x16c0;
                constexpr uint32_t m_nPlasmaModelIndex2 = 0x16c4;
                constexpr uint32_t m_nGlowModelIndex = 0x16c8;
            }
            namespace DT_PhysMagnet {
            }
            namespace DT_PhysicsProp {
                constexpr uint32_t m_bAwake = 0x1bc8;
            }
            namespace DT_PhysBox {
                constexpr uint32_t m_mass = 0x16b0;
            }
            namespace DT_ParticleSystem {
                constexpr uint32_t m_vecOrigin = 0x438;
                constexpr uint32_t m_hOwnerEntity = 0x744;
                constexpr uint32_t moveparent = 0x21c;
                constexpr uint32_t m_iParentAttachment = 0x1fe;
                constexpr uint32_t m_angRotation = 0x444;
                constexpr uint32_t m_iEffectIndex = 0x16b0;
                constexpr uint32_t m_bActive = 0x16b4;
                constexpr uint32_t m_flStartTime = 0x16b8;
                constexpr uint32_t m_bWeatherEffect = 0x17f7;
            }
            namespace DT_MaterialModifyControl {
                constexpr uint32_t m_szMaterialName = 0x16b0;
                constexpr uint32_t m_szMaterialVar = 0x17af;
                constexpr uint32_t m_szMaterialVarValue = 0x18ae;
                constexpr uint32_t m_iFrameStart = 0x19bc;
                constexpr uint32_t m_iFrameEnd = 0x19c0;
                constexpr uint32_t m_bWrap = 0x19c4;
                constexpr uint32_t m_flFramerate = 0x19c8;
                constexpr uint32_t m_bNewAnimCommandsSemaphore = 0x19cc;
                constexpr uint32_t m_flFloatLerpStartValue = 0x19d0;
                constexpr uint32_t m_flFloatLerpEndValue = 0x19d4;
                constexpr uint32_t m_flFloatLerpTransitionTime = 0x19d8;
                constexpr uint32_t m_bFloatLerpWrap = 0x19dc;
                constexpr uint32_t m_nModifyMode = 0x19e8;
            }
            namespace DT_LightGlow {
                constexpr uint32_t m_clrRender = 0x90;
                constexpr uint32_t m_nHorizontalSize = 0x16b0;
                constexpr uint32_t m_nVerticalSize = 0x16b4;
                constexpr uint32_t m_nMinDist = 0x16b8;
                constexpr uint32_t m_nMaxDist = 0x16bc;
                constexpr uint32_t m_nOuterMaxDist = 0x16c0;
                constexpr uint32_t m_spawnflags = 0x16c4;
                constexpr uint32_t m_vecOrigin = 0x438;
                constexpr uint32_t m_angRotation = 0x444;
                constexpr uint32_t moveparent = 0x21c;
                constexpr uint32_t m_flGlowProxySize = 0x17c0;
                constexpr uint32_t HDRColorScale = 0x0;
            }
            namespace DT_InfoOverlayAccessor {
                constexpr uint32_t m_iTextureFrameIndex = 0x738;
                constexpr uint32_t m_iOverlayID = 0x16b0;
            }
            namespace DT_FuncTrackTrain {
            }
            namespace DT_FuncSmokeVolume {
                constexpr uint32_t m_Color1 = 0x17e8;
                constexpr uint32_t m_Color2 = 0x17ec;
                constexpr uint32_t m_MaterialName = 0x17f0;
                constexpr uint32_t m_ParticleDrawWidth = 0x18f0;
                constexpr uint32_t m_ParticleSpacingDistance = 0x18f4;
                constexpr uint32_t m_DensityRampSpeed = 0x18f8;
                constexpr uint32_t m_RotationSpeed = 0x18fc;
                constexpr uint32_t m_MovementSpeed = 0x1900;
                constexpr uint32_t m_Density = 0x1904;
                constexpr uint32_t m_spawnflags = 0x1908;
                constexpr uint32_t m_vecMinsPreScaled = 0x240;
                constexpr uint32_t m_vecMaxsPreScaled = 0x24c;
                constexpr uint32_t m_vecMins = 0x258;
                constexpr uint32_t m_vecMaxs = 0x264;
                constexpr uint32_t m_nSolidType = 0x279;
                constexpr uint32_t m_usSolidFlags = 0x274;
                constexpr uint32_t m_nSurroundType = 0x278;
                constexpr uint32_t m_triggerBloat = 0x27a;
                constexpr uint32_t m_vecSpecifiedSurroundingMinsPreScaled = 0x27c;
                constexpr uint32_t m_vecSpecifiedSurroundingMaxsPreScaled = 0x288;
                constexpr uint32_t m_vecSpecifiedSurroundingMins = 0x294;
                constexpr uint32_t m_vecSpecifiedSurroundingMaxs = 0x2a0;
            }
            namespace DT_FuncRotating {
                constexpr uint32_t m_vecOrigin = 0x438;
                constexpr uint32_t m_angRotation[0] = 0x444;
                constexpr uint32_t m_angRotation[1] = 0x448;
                constexpr uint32_t m_angRotation[2] = 0x44c;
                constexpr uint32_t m_flSimulationTime = 0xb0;
            }
            namespace DT_FuncReflectiveGlass {
            }
            namespace DT_FuncOccluder {
                constexpr uint32_t m_bActive = 0x16b4;
                constexpr uint32_t m_nOccluderIndex = 0x16b0;
            }
            namespace DT_FuncMonitor {
            }
            namespace DT_Func_LOD {
                constexpr uint32_t m_fDisappearMinDist = 0x16b0;
                constexpr uint32_t m_fDisappearMaxDist = 0x16b4;
            }
            namespace DT_TEDust {
                constexpr uint32_t m_flSize = 0x30;
                constexpr uint32_t m_flSpeed = 0x34;
                constexpr uint32_t m_vecDirection = 0x38;
            }
            namespace DT_Func_Dust {
                constexpr uint32_t m_Color = 0x16b0;
                constexpr uint32_t m_SpawnRate = 0x16b4;
                constexpr uint32_t m_flSizeMin = 0x16b8;
                constexpr uint32_t m_flSizeMax = 0x16bc;
                constexpr uint32_t m_LifetimeMin = 0x16c4;
                constexpr uint32_t m_LifetimeMax = 0x16c8;
                constexpr uint32_t m_DustFlags = 0x16d8;
                constexpr uint32_t m_SpeedMax = 0x16c0;
                constexpr uint32_t m_DistMax = 0x16cc;
                constexpr uint32_t m_nModelIndex = 0xd4;
                constexpr uint32_t m_FallSpeed = 0x16d0;
                constexpr uint32_t m_bAffectedByWind = 0x16d4;
                constexpr uint32_t m_vecMinsPreScaled = 0x240;
                constexpr uint32_t m_vecMaxsPreScaled = 0x24c;
                constexpr uint32_t m_vecMins = 0x258;
                constexpr uint32_t m_vecMaxs = 0x264;
                constexpr uint32_t m_nSolidType = 0x279;
                constexpr uint32_t m_usSolidFlags = 0x274;
                constexpr uint32_t m_nSurroundType = 0x278;
                constexpr uint32_t m_triggerBloat = 0x27a;
                constexpr uint32_t m_vecSpecifiedSurroundingMinsPreScaled = 0x27c;
                constexpr uint32_t m_vecSpecifiedSurroundingMaxsPreScaled = 0x288;
                constexpr uint32_t m_vecSpecifiedSurroundingMins = 0x294;
                constexpr uint32_t m_vecSpecifiedSurroundingMaxs = 0x2a0;
            }
            namespace DT_FuncConveyor {
                constexpr uint32_t m_flConveyorSpeed = 0x16b0;
            }
            namespace DT_BreakableSurface {
                constexpr uint32_t m_nNumWide = 0x16b8;
                constexpr uint32_t m_nNumHigh = 0x16bc;
                constexpr uint32_t m_flPanelWidth = 0x16c0;
                constexpr uint32_t m_flPanelHeight = 0x16c4;
                constexpr uint32_t m_vNormal = 0x16c8;
                constexpr uint32_t m_vCorner = 0x16d4;
                constexpr uint32_t m_bIsBroken = 0x16e0;
                constexpr uint32_t m_nSurfaceType = 0x16e4;
            }
            namespace DT_FuncAreaPortalWindow {
                constexpr uint32_t m_flFadeStartDist = 0x16b0;
                constexpr uint32_t m_flFadeDist = 0x16b4;
                constexpr uint32_t m_flTranslucencyLimit = 0x16b8;
                constexpr uint32_t m_iBackgroundModelIndex = 0x16bc;
            }
            namespace DT_CFish {
                constexpr uint32_t m_poolOrigin = 0x1c24;
                constexpr uint32_t m_x = 0x1c0c;
                constexpr uint32_t m_y = 0x1c10;
                constexpr uint32_t m_z = 0x1c14;
                constexpr uint32_t m_angle = 0x1c1c;
                constexpr uint32_t m_nModelIndex = 0xd4;
                constexpr uint32_t m_lifeState = 0xd7;
                constexpr uint32_t m_waterLevel = 0x1c30;
            }
            namespace DT_EntityFlame {
                constexpr uint32_t m_hEntAttached = 0x16b8;
            }
            namespace DT_FireSmoke {
                constexpr uint32_t m_flStartScale = 0x16b0;
                constexpr uint32_t m_flScale = 0x16b4;
                constexpr uint32_t m_flScaleTime = 0x16b8;
                constexpr uint32_t m_nFlags = 0x16bc;
                constexpr uint32_t m_nFlameModelIndex = 0x16c0;
                constexpr uint32_t m_nFlameFromAboveModelIndex = 0x16c4;
            }
            namespace DT_EnvTonemapController {
                constexpr uint32_t m_bUseCustomAutoExposureMin = 0x16b0;
                constexpr uint32_t m_bUseCustomAutoExposureMax = 0x16b1;
                constexpr uint32_t m_bUseCustomBloomScale = 0x16b2;
                constexpr uint32_t m_flCustomAutoExposureMin = 0x16b4;
                constexpr uint32_t m_flCustomAutoExposureMax = 0x16b8;
                constexpr uint32_t m_flCustomBloomScale = 0x16bc;
                constexpr uint32_t m_flCustomBloomScaleMinimum = 0x16c0;
            }
            namespace DT_EnvScreenEffect {
                constexpr uint32_t m_flDuration = 0x16b0;
                constexpr uint32_t m_nType = 0x16b4;
            }
            namespace DT_EnvScreenOverlay {
                constexpr uint32_t m_iszOverlayNames[0] = 0x16b0;
                constexpr uint32_t m_iszOverlayNames = 0x0;
                constexpr uint32_t m_flOverlayTimes[0] = 0x20a8;
                constexpr uint32_t m_flOverlayTimes = 0x0;
                constexpr uint32_t m_flStartTime = 0x20d0;
                constexpr uint32_t m_iDesiredOverlay = 0x20d4;
                constexpr uint32_t m_bIsActive = 0x20d8;
            }
            namespace DT_EnvProjectedTexture {
                constexpr uint32_t m_hTargetEntity = 0x16b4;
                constexpr uint32_t m_bState = 0x16b8;
                constexpr uint32_t m_flLightFOV = 0x16bc;
                constexpr uint32_t m_bEnableShadows = 0x16c0;
                constexpr uint32_t m_bLightOnlyTarget = 0x16c1;
                constexpr uint32_t m_bLightWorld = 0x16c2;
                constexpr uint32_t m_bCameraSpace = 0x16c3;
                constexpr uint32_t m_LinearFloatLightColor = 0x16c4;
                constexpr uint32_t m_SpotlightTextureName = 0x16d8;
                constexpr uint32_t m_nSpotlightTextureFrame = 0x17dc;
                constexpr uint32_t m_flNearZ = 0x16d0;
                constexpr uint32_t m_flFarZ = 0x16d4;
                constexpr uint32_t m_nShadowQuality = 0x17e0;
                constexpr uint32_t m_iStyle = 0x17e8;
            }
            namespace DT_EnvParticleScript {
                constexpr uint32_t m_flSequenceScale = 0x1cf8;
            }
            namespace DT_FogController {
                constexpr uint32_t m_fog.enable = 0x1700;
                constexpr uint32_t m_fog.blend = 0x1701;
                constexpr uint32_t m_fog.radial = 0x1702;
                constexpr uint32_t m_fog.dirPrimary = 0x16b8;
                constexpr uint32_t m_fog.colorPrimary = 0x16c4;
                constexpr uint32_t m_fog.colorSecondary = 0x16c8;
                constexpr uint32_t m_fog.colorPrimaryHDR = 0x16cc;
                constexpr uint32_t m_fog.colorSecondaryHDR = 0x16d0;
                constexpr uint32_t m_fog.start = 0x16dc;
                constexpr uint32_t m_fog.end = 0x16e0;
                constexpr uint32_t m_fog.farz = 0x16e4;
                constexpr uint32_t m_fog.maxdensity = 0x16e8;
                constexpr uint32_t m_fog.colorPrimaryLerpTo = 0x16d4;
                constexpr uint32_t m_fog.colorSecondaryLerpTo = 0x16d8;
                constexpr uint32_t m_fog.startLerpTo = 0x16ec;
                constexpr uint32_t m_fog.endLerpTo = 0x16f0;
                constexpr uint32_t m_fog.maxdensityLerpTo = 0x16f4;
                constexpr uint32_t m_fog.lerptime = 0x16f8;
                constexpr uint32_t m_fog.duration = 0x16fc;
                constexpr uint32_t m_fog.HDRColorScale = 0x1704;
            }
            namespace DT_EntityParticleTrail {
                constexpr uint32_t m_iMaterialName = 0x17e0;
                constexpr uint32_t m_flLifetime = 0x17f8;
                constexpr uint32_t m_flStartSize = 0x17fc;
                constexpr uint32_t m_flEndSize = 0x1800;
                constexpr uint32_t m_hConstraintEntity = 0x1808;
            }
            namespace DT_EntityDissolve {
                constexpr uint32_t m_flStartTime = 0x16b8;
                constexpr uint32_t m_flFadeOutStart = 0x16bc;
                constexpr uint32_t m_flFadeOutLength = 0x16c0;
                constexpr uint32_t m_flFadeOutModelStart = 0x16c4;
                constexpr uint32_t m_flFadeOutModelLength = 0x16c8;
                constexpr uint32_t m_flFadeInStart = 0x16cc;
                constexpr uint32_t m_flFadeInLength = 0x16d0;
                constexpr uint32_t m_nDissolveType = 0x16d4;
                constexpr uint32_t m_vDissolverOrigin = 0x16e8;
                constexpr uint32_t m_nMagnitude = 0x16f4;
            }
            namespace DT_DynamicLight {
                constexpr uint32_t m_Flags = 0x16b0;
                constexpr uint32_t m_LightStyle = 0x16b1;
                constexpr uint32_t m_Radius = 0x16b4;
                constexpr uint32_t m_Exponent = 0x16b8;
                constexpr uint32_t m_InnerAngle = 0x16bc;
                constexpr uint32_t m_OuterAngle = 0x16c0;
                constexpr uint32_t m_SpotRadius = 0x16c4;
            }
            namespace DT_ColorCorrectionVolume {
                constexpr uint32_t m_bEnabled = 0x16f8;
                constexpr uint32_t m_MaxWeight = 0x16fc;
                constexpr uint32_t m_FadeDuration = 0x1700;
                constexpr uint32_t m_Weight = 0x1704;
                constexpr uint32_t m_lookupFilename = 0x1708;
                constexpr uint32_t m_nModelIndex = 0xd4;
            }
            namespace DT_ColorCorrection {
                constexpr uint32_t m_vecOrigin = 0x16b0;
                constexpr uint32_t m_minFalloff = 0x16bc;
                constexpr uint32_t m_maxFalloff = 0x16c0;
                constexpr uint32_t m_flCurWeight = 0x16d0;
                constexpr uint32_t m_flMaxWeight = 0x16cc;
                constexpr uint32_t m_flFadeInDuration = 0x16c4;
                constexpr uint32_t m_flFadeOutDuration = 0x16c8;
                constexpr uint32_t m_netLookupFilename = 0x16d4;
                constexpr uint32_t m_bEnabled = 0x17d8;
                constexpr uint32_t m_bClientSide = 0x17d9;
                constexpr uint32_t m_bExclusive = 0x17da;
            }
            namespace DT_BreakableProp {
            }
            namespace DT_BasePlayer {
                constexpr uint32_t deadflag = 0x2c08;
                constexpr uint32_t m_hVehicle = 0x2c98;
                constexpr uint32_t m_hUseEntity = 0x2ca0;
                constexpr uint32_t m_lifeState = 0xd7;
                constexpr uint32_t m_hColorCorrectionCtrl = 0x34f0;
                constexpr uint32_t m_flMaxspeed = 0x2ca4;
                constexpr uint32_t m_fFlags = 0x450;
                constexpr uint32_t m_iObserverMode = 0x2c6c;
                constexpr uint32_t m_hObserverTarget = 0x2c70;
                constexpr uint32_t m_iFOV = 0x2c18;
                constexpr uint32_t m_iFOVStart = 0x2c1c;
                constexpr uint32_t m_flFOVTime = 0x2c20;
                constexpr uint32_t m_iDefaultFOV = 0x2c28;
                constexpr uint32_t m_hZoomOwner = 0x2c2c;
                constexpr uint32_t m_hViewModel[0] = 0x2d70;
                constexpr uint32_t m_hViewModel = 0x0;
                constexpr uint32_t m_bUseWeaponsInVehicle = 0x2d3b;
                constexpr uint32_t m_iHideHUD = 0x29c8;
                constexpr uint32_t m_flFOVRate = 0x29cc;
                constexpr uint32_t m_bDucked = 0x29d0;
                constexpr uint32_t m_bDucking = 0x29d1;
                constexpr uint32_t m_bInDuckJump = 0x29d2;
                constexpr uint32_t m_flDucktime = 0x29d4;
                constexpr uint32_t m_flDuckJumpTime = 0x29d8;
                constexpr uint32_t m_flJumpTime = 0x29dc;
                constexpr uint32_t m_flFallVelocity = 0x29e4;
                constexpr uint32_t m_vecPunchAngle = 0x29f8;
                constexpr uint32_t m_vecPunchAngleVel = 0x2a58;
                constexpr uint32_t m_bDrawViewmodel = 0x2ab8;
                constexpr uint32_t m_bWearingSuit = 0x2ab9;
                constexpr uint32_t m_bPoisoned = 0x2aba;
                constexpr uint32_t m_flStepSize = 0x2abc;
                constexpr uint32_t m_bAllowAutoMovement = 0x2abb;
                constexpr uint32_t m_skybox3d.scale = 0x2ac8;
                constexpr uint32_t m_skybox3d.origin = 0x2acc;
                constexpr uint32_t m_skybox3d.area = 0x2ad8;
                constexpr uint32_t m_skybox3d.fog.enable = 0x2b30;
                constexpr uint32_t m_skybox3d.fog.blend = 0x2b31;
                constexpr uint32_t m_skybox3d.fog.radial = 0x2b32;
                constexpr uint32_t m_skybox3d.fog.dirPrimary = 0x2ae8;
                constexpr uint32_t m_skybox3d.fog.colorPrimary = 0x2af4;
                constexpr uint32_t m_skybox3d.fog.colorSecondary = 0x2af8;
                constexpr uint32_t m_skybox3d.fog.colorPrimaryHDR = 0x2afc;
                constexpr uint32_t m_skybox3d.fog.colorSecondaryHDR = 0x2b00;
                constexpr uint32_t m_skybox3d.fog.start = 0x2b0c;
                constexpr uint32_t m_skybox3d.fog.end = 0x2b10;
                constexpr uint32_t m_skybox3d.fog.maxdensity = 0x2b18;
                constexpr uint32_t m_skybox3d.fog.HDRColorScale = 0x2b34;
                constexpr uint32_t m_PlayerFog.m_hCtrl = 0x2b40;
                constexpr uint32_t m_audio.localSound[0] = 0x2b68;
                constexpr uint32_t m_audio.localSound[1] = 0x2b74;
                constexpr uint32_t m_audio.localSound[2] = 0x2b80;
                constexpr uint32_t m_audio.localSound[3] = 0x2b8c;
                constexpr uint32_t m_audio.localSound[4] = 0x2b98;
                constexpr uint32_t m_audio.localSound[5] = 0x2ba4;
                constexpr uint32_t m_audio.localSound[6] = 0x2bb0;
                constexpr uint32_t m_audio.localSound[7] = 0x2bbc;
                constexpr uint32_t m_audio.soundscapeIndex = 0x2bc8;
                constexpr uint32_t m_audio.localBits = 0x2bcc;
                constexpr uint32_t m_audio.ent = 0x2bd0;
                constexpr uint32_t m_fSprintSpeed = 0x2bdc;
                constexpr uint32_t m_fWalkSpeed = 0x2be0;
                constexpr uint32_t m_fSlowWalkSpeed = 0x2be4;
                constexpr uint32_t m_fLadderSpeed = 0x2be8;
                constexpr uint32_t m_fCrouchedWalkSpeed = 0x2bec;
                constexpr uint32_t m_fDuckSpeed = 0x2bf0;
                constexpr uint32_t m_fUnDuckSpeed = 0x2bf4;
                constexpr uint32_t m_bDuckToggled = 0x2bd9;
                constexpr uint32_t m_vecViewOffset[0] = 0x144;
                constexpr uint32_t m_vecViewOffset[1] = 0x148;
                constexpr uint32_t m_vecViewOffset[2] = 0x14c;
                constexpr uint32_t m_flFriction = 0x318;
                constexpr uint32_t m_nTickBase = 0x2d28;
                constexpr uint32_t m_nNextThinkTick = 0xcc;
                constexpr uint32_t m_hLastWeapon = 0x2d48;
                constexpr uint32_t m_hGroundEntity = 0x30c;
                constexpr uint32_t m_vecBaseVelocity = 0x1d8;
                constexpr uint32_t m_hConstraintEntity = 0x2c50;
                constexpr uint32_t m_vecConstraintCenter = 0x2c54;
                constexpr uint32_t m_flConstraintRadius = 0x2c60;
                constexpr uint32_t m_flConstraintWidth = 0x2c64;
                constexpr uint32_t m_flConstraintSpeedFactor = 0x2c68;
                constexpr uint32_t m_flDeathTime = 0x2c94;
                constexpr uint32_t m_flLaggedMovementValue = 0x3318;
                constexpr uint32_t m_hTonemapController = 0x2bf8;
                constexpr uint32_t m_hViewEntity = 0x3514;
                constexpr uint32_t m_bDisableWorldClicking = 0x3505;
            }
            namespace DT_BaseFlex {
                constexpr uint32_t m_blinktoggle = 0x1e88;
                constexpr uint32_t m_viewtarget = 0x1c58;
                constexpr uint32_t m_vecViewOffset[0] = 0x144;
                constexpr uint32_t m_vecViewOffset[1] = 0x148;
                constexpr uint32_t m_vecViewOffset[2] = 0x14c;
                constexpr uint32_t m_vecLean = 0x2048;
                constexpr uint32_t m_vecShift = 0x20a8;
            }
            namespace DT_BaseEntity {
                constexpr uint32_t m_flAnimTime = 0xa0;
                constexpr uint32_t m_flSimulationTime = 0xb0;
                constexpr uint32_t m_ubInterpolationFrame = 0xc0;
                constexpr uint32_t m_vecOrigin = 0x438;
                constexpr uint32_t m_angRotation = 0x444;
                constexpr uint32_t m_nModelIndex = 0xd4;
                constexpr uint32_t m_fEffects = 0xc4;
                constexpr uint32_t m_nRenderMode = 0xc2;
                constexpr uint32_t m_nRenderFX = 0x8c;
                constexpr uint32_t m_clrRender = 0x90;
                constexpr uint32_t m_iTeamNum = 0xe4;
                constexpr uint32_t m_CollisionGroup = 0x454;
                constexpr uint32_t m_flElasticity = 0x300;
                constexpr uint32_t m_flShadowCastDistance = 0x304;
                constexpr uint32_t m_hOwnerEntity = 0x744;
                constexpr uint32_t m_hEffectEntity = 0x748;
                constexpr uint32_t moveparent = 0x21c;
                constexpr uint32_t m_iParentAttachment = 0x1fe;
                constexpr uint32_t movetype = 0x0;
                constexpr uint32_t movecollide = 0x0;
                constexpr uint32_t m_vecMinsPreScaled = 0x240;
                constexpr uint32_t m_vecMaxsPreScaled = 0x24c;
                constexpr uint32_t m_vecMins = 0x258;
                constexpr uint32_t m_vecMaxs = 0x264;
                constexpr uint32_t m_nSolidType = 0x279;
                constexpr uint32_t m_usSolidFlags = 0x274;
                constexpr uint32_t m_nSurroundType = 0x278;
                constexpr uint32_t m_triggerBloat = 0x27a;
                constexpr uint32_t m_vecSpecifiedSurroundingMinsPreScaled = 0x27c;
                constexpr uint32_t m_vecSpecifiedSurroundingMaxsPreScaled = 0x288;
                constexpr uint32_t m_vecSpecifiedSurroundingMins = 0x294;
                constexpr uint32_t m_vecSpecifiedSurroundingMaxs = 0x2a0;
                constexpr uint32_t m_iTextureFrameIndex = 0x738;
                constexpr uint32_t m_PredictableID = 0xe8;
                constexpr uint32_t m_bIsPlayerSimulated = 0x734;
                constexpr uint32_t m_bSimulatedEveryTick = 0x735;
                constexpr uint32_t m_bAnimatedEveryTick = 0x736;
                constexpr uint32_t m_bAlternateSorting = 0x737;
                constexpr uint32_t m_takedamage = 0xd6;
                constexpr uint32_t m_RealClassName = 0x780;
                constexpr uint32_t m_OverrideMaterial = 0x784;
                constexpr uint32_t m_OverrideSubMaterials[0] = 0x790;
                constexpr uint32_t m_OverrideSubMaterials = 0x0;
                constexpr uint32_t m_iHealth = 0xd8;
                constexpr uint32_t m_iMaxHealth = 0xdc;
                constexpr uint32_t m_spawnflags = 0x92c;
                constexpr uint32_t m_iGModFlags = 0x930;
                constexpr uint32_t m_bOnFire = 0x77a;
                constexpr uint32_t m_CreationTime = 0x77c;
                constexpr uint32_t m_vecVelocity[0] = 0x150;
                constexpr uint32_t m_vecVelocity[1] = 0x154;
                constexpr uint32_t m_vecVelocity[2] = 0x158;
                constexpr uint32_t m_GMOD_DataTable = 0x1638;
                constexpr uint32_t m_GMOD_String0 = 0xe38;
                constexpr uint32_t m_GMOD_String1 = 0x1038;
                constexpr uint32_t m_GMOD_String2 = 0x1238;
                constexpr uint32_t m_GMOD_String3 = 0x1438;
                constexpr uint32_t m_iCreationID = 0x16a4;
                constexpr uint32_t m_iMapCreatedID = 0x16a8;
            }
            namespace DT_BaseDoor {
            }
            namespace DT_BaseCombatCharacter {
                constexpr uint32_t m_flNextAttack = 0x2110;
                constexpr uint32_t m_hActiveWeapon = 0x291c;
                constexpr uint32_t m_bloodColor = 0x2118;
            }
            namespace DT_BaseAnimatingOverlay {
                constexpr uint32_t lengthprop15 = 0x0;
            }
            namespace DT_BoneFollower {
                constexpr uint32_t m_modelIndex = 0x16b0;
                constexpr uint32_t m_solidIndex = 0x16b4;
            }
            namespace DT_BaseAnimating {
                constexpr uint32_t m_nSequence = 0x19ec;
                constexpr uint32_t m_nForceBone = 0x1714;
                constexpr uint32_t m_vecForce = 0x1708;
                constexpr uint32_t m_nSkin = 0x16c0;
                constexpr uint32_t m_nBody = 0x16c4;
                constexpr uint32_t m_nHitboxSet = 0x16c8;
                constexpr uint32_t m_flModelScale = 0x1800;
                constexpr uint32_t m_flModelWidthScale = 0x1800;
                constexpr uint32_t m_flPlaybackRate = 0x16fc;
                constexpr uint32_t m_bClientSideAnimation = 0x19e9;
                constexpr uint32_t m_bClientSideFrameReset = 0x17a6;
                constexpr uint32_t m_nNewSequenceParity = 0x19c0;
                constexpr uint32_t m_nResetEventsParity = 0x19c4;
                constexpr uint32_t m_nMuzzleFlashParity = 0x1ac8;
                constexpr uint32_t m_hLightingOrigin = 0x1ac0;
                constexpr uint32_t m_hLightingOriginRelative = 0x1ac4;
                constexpr uint32_t m_flCycle = 0x19f0;
                constexpr uint32_t m_fadeMinDist = 0x1790;
                constexpr uint32_t m_fadeMaxDist = 0x1794;
                constexpr uint32_t m_flFadeScale = 0x1798;
                constexpr uint32_t m_pBoneManipulator = 0x1b74;
                constexpr uint32_t m_pFlexManipulator = 0x1b7c;
                constexpr uint32_t m_OverrideViewTarget = 0x1ae8;
            }
            namespace DT_InfoLightingRelative {
                constexpr uint32_t m_hLightingLandmark = 0x16b0;
            }
            namespace DT_AI_BaseNPC {
                constexpr uint32_t m_lifeState = 0xd7;
                constexpr uint32_t m_bPerformAvoidance = 0x2928;
                constexpr uint32_t m_bIsMoving = 0x2929;
                constexpr uint32_t m_bFadeCorpse = 0x292a;
                constexpr uint32_t m_iDeathPose = 0x2920;
                constexpr uint32_t m_iDeathFrame = 0x2924;
                constexpr uint32_t m_bImportanRagdoll = 0x292b;
            }
            namespace DT_Beam {
                constexpr uint32_t m_nBeamType = 0x16d0;
                constexpr uint32_t m_nBeamFlags = 0x16d4;
                constexpr uint32_t m_nNumBeamEnts = 0x16c4;
                constexpr uint32_t m_nHaloIndex = 0x16cc;
                constexpr uint32_t m_fHaloScale = 0x1734;
                constexpr uint32_t m_fWidth = 0x1728;
                constexpr uint32_t m_fEndWidth = 0x172c;
                constexpr uint32_t m_fFadeLength = 0x1730;
                constexpr uint32_t m_fAmplitude = 0x1738;
                constexpr uint32_t m_fStartFrame = 0x173c;
                constexpr uint32_t m_fSpeed = 0x1740;
                constexpr uint32_t m_flFrameRate = 0x16b0;
                constexpr uint32_t m_flHDRColorScale = 0x16b4;
                constexpr uint32_t m_clrRender = 0x90;
                constexpr uint32_t m_nRenderFX = 0x8c;
                constexpr uint32_t m_nRenderMode = 0xc2;
                constexpr uint32_t m_flFrame = 0x1748;
                constexpr uint32_t m_vecEndPos = 0x174c;
                constexpr uint32_t m_nModelIndex = 0xd4;
                constexpr uint32_t m_nMinDXLevel = 0x1744;
                constexpr uint32_t m_vecOrigin = 0x438;
                constexpr uint32_t moveparent = 0x21c;
                constexpr uint32_t m_PredictableID = 0xe8;
                constexpr uint32_t m_bIsPlayerSimulated = 0x734;
            }
            namespace DT_BaseViewModel {
                constexpr uint32_t m_nModelIndex = 0xd4;
                constexpr uint32_t m_nSkin = 0x16c0;
                constexpr uint32_t m_nBody = 0x16c4;
                constexpr uint32_t m_nSequence = 0x19ec;
                constexpr uint32_t m_nViewModelIndex = 0x1bdc;
                constexpr uint32_t m_flPlaybackRate = 0x16fc;
                constexpr uint32_t m_fEffects = 0xc4;
                constexpr uint32_t m_nAnimationParity = 0x1bf4;
                constexpr uint32_t m_hWeapon = 0x1c04;
                constexpr uint32_t m_hOwner = 0x1be0;
                constexpr uint32_t m_nNewSequenceParity = 0x19c0;
                constexpr uint32_t m_nResetEventsParity = 0x19c4;
                constexpr uint32_t m_nMuzzleFlashParity = 0x1ac8;
                constexpr uint32_t m_flPoseParameter[0] = 0x1804;
                constexpr uint32_t m_flPoseParameter = 0x0;
            }
            namespace DT_BaseParticleEntity {
            }
            namespace DT_BaseGrenade {
                constexpr uint32_t m_flDamage = 0x1be8;
                constexpr uint32_t m_DmgRadius = 0x1bcc;
                constexpr uint32_t m_bIsLive = 0x1bc9;
                constexpr uint32_t m_hThrower = 0x1bfc;
                constexpr uint32_t m_vecVelocity = 0x150;
                constexpr uint32_t m_fFlags = 0x450;
            }
            namespace DT_BaseCombatWeapon {
                constexpr uint32_t m_iClip1 = 0x1c28;
                constexpr uint32_t m_iClip2 = 0x1c2c;
                constexpr uint32_t m_iPrimaryAmmoType = 0x1c20;
                constexpr uint32_t m_iSecondaryAmmoType = 0x1c24;
                constexpr uint32_t m_nViewModelIndex = 0x1bd0;
                constexpr uint32_t m_bFlipViewModel = 0x1c30;
                constexpr uint32_t m_flNextPrimaryAttack = 0x1bd8;
                constexpr uint32_t m_flNextSecondaryAttack = 0x1be0;
                constexpr uint32_t m_nNextThinkTick = 0xcc;
                constexpr uint32_t m_flTimeWeaponIdle = 0x1be8;
                constexpr uint32_t m_iViewModelIndex = 0x1bf0;
                constexpr uint32_t m_iWorldModelIndex = 0x1bf4;
                constexpr uint32_t m_iState = 0x1c14;
                constexpr uint32_t m_hOwner = 0x1bc8;
            }
            namespace DT_WeaponPhysGun {
                constexpr uint32_t m_hPhysBeam = 0x1cac;
                constexpr uint32_t m_vHitPosLocal = 0x1cb0;
                constexpr uint32_t m_hGrabbedEntity = 0x1ca8;
            }
            namespace DT_PhysBeam {
                constexpr uint32_t m_hTargetEnt = 0x16e0;
                constexpr uint32_t m_HoldPos = 0x16d4;
                constexpr uint32_t m_bIsOn = 0x16e4;
                constexpr uint32_t m_iPhysBone = 0x16d0;
            }
            namespace DT_LuaNextBot {
                constexpr uint32_t m_strScriptName = 0x2958;
                constexpr uint32_t m_lifeState = 0xd7;
            }
            namespace DT_FlexManipulate {
                constexpr uint32_t m_flexScale = 0x1830;
                constexpr uint32_t m_EyesLocalTarget = 0x1834;
            }
            namespace DT_BoneManipulate {
            }
            namespace DT_WeaponSWEP {
                constexpr uint32_t m_strScriptName = 0x1cc0;
                constexpr uint32_t m_strHoldType = 0x1e20;
            }
            namespace DT_SENT_point {
                constexpr uint32_t m_strScriptName = 0x16c8;
            }
            namespace DT_SENT_anim {
                constexpr uint32_t m_strScriptName = 0x1c70;
            }
            namespace DT_SENT_AI {
                constexpr uint32_t m_strScriptName = 0x2948;
            }
            namespace DT_GMODGameRulesProxy {
                constexpr uint32_t m_fTimeScale = 0x40;
                constexpr uint32_t m_iSkillLevel = 0x44;
            }
            namespace DT_NextBot {
            }
            namespace DT_GMOD_Player {
                constexpr uint32_t m_iGModPlayerFlags = 0x36b0;
                constexpr uint32_t m_HoveredWidget = 0x3878;
                constexpr uint32_t m_PressedWidget = 0x387c;
                constexpr uint32_t m_Driving = 0x3880;
                constexpr uint32_t m_DrivingMode = 0x3884;
                constexpr uint32_t m_PlayerClass = 0x388c;
                constexpr uint32_t m_bCanZoom = 0x38ad;
                constexpr uint32_t m_bCanWalk = 0x38ae;
                constexpr uint32_t m_bIsTyping = 0x38af;
                constexpr uint32_t m_StepSize = 0x38b0;
                constexpr uint32_t m_JumpPower = 0x38b4;
                constexpr uint32_t m_ViewOffset = 0x38b8;
                constexpr uint32_t m_ViewOffsetDucked = 0x38c4;
                constexpr uint32_t m_fGestureEndTime = 0x38d0;
                constexpr uint32_t m_PlayerColor = 0x3894;
                constexpr uint32_t m_WeaponColor = 0x38a0;
                constexpr uint32_t m_Hands = 0x3888;
                constexpr uint32_t m_nWaterLevel = 0x200;
                constexpr uint32_t m_iMaxArmor = 0x3890;
                constexpr uint32_t m_flGravity = 0x1e4;
                constexpr uint32_t m_bSprintEnabled = 0x38ac;
            }
            namespace DT_FleshEffectTarget {
                constexpr uint32_t m_flRadius = 0x16b0;
                constexpr uint32_t m_flScaleTime = 0x16bc;
            }
            namespace DT_CPropJeepEpisodic {
                constexpr uint32_t m_iNumRadarContacts = 0x1d50;
                constexpr uint32_t m_vecRadarContactPos[0] = 0x1d54;
                constexpr uint32_t m_vecRadarContactPos = 0x0;
                constexpr uint32_t m_iRadarContactType[0] = 0x1e74;
                constexpr uint32_t m_iRadarContactType = 0x0;
            }
            namespace DT_PropScalable {
                constexpr uint32_t m_flScaleX = 0x1bc8;
                constexpr uint32_t m_flScaleY = 0x1bcc;
                constexpr uint32_t m_flScaleZ = 0x1bd0;
                constexpr uint32_t m_flLerpTimeX = 0x1bd4;
                constexpr uint32_t m_flLerpTimeY = 0x1bd8;
                constexpr uint32_t m_flLerpTimeZ = 0x1bdc;
                constexpr uint32_t m_flGoalTimeX = 0x1be0;
                constexpr uint32_t m_flGoalTimeY = 0x1be4;
                constexpr uint32_t m_flGoalTimeZ = 0x1be8;
            }
            namespace DT_NPC_Puppet {
                constexpr uint32_t m_hAnimationTarget = 0x2930;
                constexpr uint32_t m_nTargetAttachment = 0x2934;
            }
        }
    }

    namespace engine {
        constexpr uintptr_t Base = 0x7ffcf3e00000;
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

    namespace tier0 {
        constexpr uintptr_t Base = 0x7ffd23e20000;
    }

    namespace vstdlib {
        constexpr uintptr_t Base = 0x7ffd20410000;
        constexpr uintptr_t VProcessUtils001 = 0x12d10;
        constexpr uintptr_t EventSystem001 = 0xad40;
        constexpr uintptr_t VEngineCvar007 = 0x8d10;
    }

    namespace materialsystem {
        constexpr uintptr_t Base = 0x7ffcb2340000;
        constexpr uintptr_t ShaderDLL004 = 0x6d190;
        constexpr uintptr_t ShaderSystem002 = 0x4cc30;
        constexpr uintptr_t VMaterialSystemStub001 = 0x440a0;
        constexpr uintptr_t VEngineCvar007 = 0x1d980;
        constexpr uintptr_t MaterialSystemHardwareConfig012 = 0x1d900;
        constexpr uintptr_t VMaterialSystemConfig002 = 0x1d6c0;
        constexpr uintptr_t VMaterialSystem080 = 0x26120;
        constexpr uintptr_t COLORCORRECTION_VERSION_1 = 0xc800;
    }

    namespace studiorender {
        constexpr uintptr_t Base = 0x7ffcd4340000;
        constexpr uintptr_t VStudioRender025 = 0x65ed0;
    }

    namespace vphysics {
        constexpr uintptr_t Base = 0x7ffd16bf0000;
        constexpr uintptr_t VPhysicsSurfaceProps001 = 0x22720;
        constexpr uintptr_t VPhysicsCollision007 = 0x13ca0;
        constexpr uintptr_t VPhysics031 = 0xbff0;
    }

    namespace vguimatsurface {
        constexpr uintptr_t Base = 0x7ffd16a40000;
        constexpr uintptr_t VGUI_Surface030 = 0x1aa60;
    }

    namespace vgui2 {
        constexpr uintptr_t Base = 0x7ffd16890000;
        constexpr uintptr_t VGUI_Panel009 = 0x1cda0;
        constexpr uintptr_t VGUI_ivgui008 = 0x1b3d0;
        constexpr uintptr_t VGUI_System010 = 0x18e00;
        constexpr uintptr_t VGUI_Surface030 = 0x16750;
        constexpr uintptr_t VGUI_Scheme010 = 0xff60;
        constexpr uintptr_t VguiLocalize004 = 0xbe00;
        constexpr uintptr_t VGUI_InputInternal001 = 0x8760;
        constexpr uintptr_t VGUI_Input005 = 0x8760;
    }

    namespace inputsystem {
        constexpr uintptr_t Base = 0x7ffd1fcc0000;
        constexpr uintptr_t InputSystemVersion001 = 0x5010;
        constexpr uintptr_t InputStackSystemVersion001 = 0x1d20;
    }

    namespace lua_shared {
        constexpr uintptr_t Base = 0x7ffd0ad90000;
        constexpr uintptr_t LUASHARED003 = 0x14f20;
        constexpr uintptr_t LUACONVARS001 = 0x69b0;
    }

    namespace server {
        constexpr uintptr_t Base = 0x7ffcb0750000;
        constexpr uintptr_t VSERVERCHOREOTOOLS001 = 0x6ee650;
        constexpr uintptr_t VSERVERTOOLS002 = 0x6ee660;
        constexpr uintptr_t ServerGameTags001 = 0x6a8a10;
        constexpr uintptr_t ServerGameTags001 = 0x6a7e90;
        constexpr uintptr_t ServerGameTags001 = 0x6a7e60;
        constexpr uintptr_t GameMovement001 = 0x585690;
        constexpr uintptr_t ServerGameTags001 = 0x475360;
        constexpr uintptr_t ServerGameTags001 = 0x440800;
        constexpr uintptr_t PluginHelpersCheck001 = 0x3fa790;
        constexpr uintptr_t BotManager001 = 0x3f91e0;
        constexpr uintptr_t PlayerInfoManager002 = 0x3f91c0;
        constexpr uintptr_t PlayerInfoManager001 = 0x3f91d0;
        constexpr uintptr_t ServerGameTags001 = 0x3f1fb0;
        constexpr uintptr_t ServerGameTags001 = 0x391120;
        constexpr uintptr_t HLTVDirector001 = 0x383e20;
        constexpr uintptr_t VServerDllSharedAppSystems001 = 0x36c130;
        constexpr uintptr_t ServerGameClients004 = 0x36c140;
        constexpr uintptr_t ServerGameClients003 = 0x36c140;
        constexpr uintptr_t ServerGameEnts001 = 0x36c160;
        constexpr uintptr_t ServerGameDLL009 = 0x36c150;
        constexpr uintptr_t ServerGameDLL008 = 0x36c150;
        constexpr uintptr_t ServerGameTags001 = 0x36c170;
        constexpr uintptr_t IEffects001 = 0x3352b0;
        constexpr uintptr_t ServerGameTags001 = 0x289370;
        constexpr uintptr_t ServerGameTags001 = 0x16c400;
        constexpr uintptr_t ServerGameTags001 = 0x1206e0;
        constexpr uintptr_t ServerGameTags001 = 0xef750;
        constexpr uintptr_t ServerGameTags001 = 0xef740;
        constexpr uintptr_t ServerGameTags001 = 0xef6f0;
    }

    namespace datacache {
        constexpr uintptr_t Base = 0x7ffd19160000;
        constexpr uintptr_t VStudioDataCache005 = 0x13e90;
        constexpr uintptr_t MDLCache004 = 0x13e80;
        constexpr uintptr_t VDataCache003 = 0x9890;
    }

}
