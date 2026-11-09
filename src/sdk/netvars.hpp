// Auto-generated GMod x64 SDK — netvars.hpp
#pragma once
#include <cstdint>
#include "usercmd.hpp"

#define NETVAR(type, func_name, offset) \
    inline type& func_name() { return *reinterpret_cast<type*>(reinterpret_cast<uintptr_t>(this) + offset); }

#define NETVAR_PTR(type, func_name, offset) \
    inline type* func_name() { return reinterpret_cast<type*>(reinterpret_cast<uintptr_t>(this) + offset); }

namespace SDK {
    namespace Entities {
        class DT_TEWorldDecal {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x20);
            NETVAR(int32_t     , m_nIndex                        , 0x2c);
        };

        class DT_TESpriteSpray {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x20);
            NETVAR(Vector3D    , m_vecDirection                  , 0x2c);
            NETVAR(int32_t     , m_nModelIndex                   , 0x38);
            NETVAR(float       , m_fNoise                        , 0x40);
            NETVAR(int32_t     , m_nCount                        , 0x44);
            NETVAR(int32_t     , m_nSpeed                        , 0x3c);
        };

        class DT_TESprite {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x20);
            NETVAR(int32_t     , m_nModelIndex                   , 0x2c);
            NETVAR(float       , m_fScale                        , 0x30);
            NETVAR(int32_t     , m_nBrightness                   , 0x34);
        };

        class DT_TESparks {
        public:
            NETVAR(int32_t     , m_nMagnitude                    , 0x30);
            NETVAR(int32_t     , m_nTrailLength                  , 0x34);
            NETVAR(Vector3D    , m_vecDir                        , 0x38);
        };

        class DT_TESmoke {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x20);
            NETVAR(int32_t     , m_nModelIndex                   , 0x2c);
            NETVAR(float       , m_fScale                        , 0x30);
            NETVAR(int32_t     , m_nFrameRate                    , 0x34);
        };

        class DT_TEShowLine {
        public:
            NETVAR(Vector3D    , m_vecEnd                        , 0x30);
        };

        class DT_TEProjectedDecal {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x20);
            NETVAR(Vector3D    , m_angRotation                   , 0x2c);
            NETVAR(float       , m_flDistance                    , 0x38);
            NETVAR(int32_t     , m_nIndex                        , 0x3c);
        };

        class DT_TEPlayerDecal {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x24);
            NETVAR(int32_t     , m_nEntity                       , 0x30);
            NETVAR(int32_t     , m_nPlayer                       , 0x20);
        };

        class DT_TEPhysicsProp {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x20);
            NETVAR(float       , m_angRotation_0_                , 0x2c);
            NETVAR(float       , m_angRotation_1_                , 0x30);
            NETVAR(float       , m_angRotation_2_                , 0x34);
            NETVAR(Vector3D    , m_vecVelocity                   , 0x38);
            NETVAR(int32_t     , m_nModelIndex                   , 0x44);
            NETVAR(int32_t     , m_nFlags                        , 0x4c);
            NETVAR(int32_t     , m_nSkin                         , 0x48);
            NETVAR(int32_t     , m_nEffects                      , 0x50);
            NETVAR(int32_t     , m_clrRender                     , 0x54);
            NETVAR(float       , m_fModelScale                   , 0x58);
        };

        class DT_TEParticleSystem {
        public:
            NETVAR(float       , m_vecOrigin_0_                  , 0x20);
            NETVAR(float       , m_vecOrigin_1_                  , 0x24);
            NETVAR(float       , m_vecOrigin_2_                  , 0x28);
        };

        class DT_TEMuzzleFlash {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x20);
            NETVAR(Vector3D    , m_vecAngles                     , 0x2c);
            NETVAR(float       , m_flScale                       , 0x38);
            NETVAR(int32_t     , m_nType                         , 0x3c);
        };

        class DT_TELargeFunnel {
        public:
            NETVAR(int32_t     , m_nReversed                     , 0x30);
        };

        class DT_TEKillPlayerAttachments {
        public:
            NETVAR(int32_t     , m_nPlayer                       , 0x20);
        };

        class DT_TEGlowSprite {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x20);
            NETVAR(int32_t     , m_nModelIndex                   , 0x2c);
            NETVAR(float       , m_fScale                        , 0x30);
            NETVAR(float       , m_fLife                         , 0x34);
            NETVAR(int32_t     , m_nBrightness                   , 0x38);
        };

        class DT_TEShatterSurface {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x20);
            NETVAR(Vector3D    , m_vecAngles                     , 0x2c);
            NETVAR(Vector3D    , m_vecForce                      , 0x38);
            NETVAR(Vector3D    , m_vecForcePos                   , 0x44);
            NETVAR(float       , m_flWidth                       , 0x50);
            NETVAR(float       , m_flHeight                      , 0x54);
            NETVAR(float       , m_flShardSize                   , 0x58);
            NETVAR(int32_t     , m_nSurfaceType                  , 0x5c);
            NETVAR(int32_t     , m_uchFrontColor_0_              , 0x60);
            NETVAR(int32_t     , m_uchFrontColor_1_              , 0x61);
            NETVAR(int32_t     , m_uchFrontColor_2_              , 0x62);
            NETVAR(int32_t     , m_uchBackColor_0_               , 0x63);
            NETVAR(int32_t     , m_uchBackColor_1_               , 0x64);
            NETVAR(int32_t     , m_uchBackColor_2_               , 0x65);
        };

        class DT_TEFootprintDecal {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x20);
            NETVAR(Vector3D    , m_vecDirection                  , 0x2c);
            NETVAR(int32_t     , m_nEntity                       , 0x44);
            NETVAR(int32_t     , m_nIndex                        , 0x48);
        };

        class DT_TEFizz {
        public:
            NETVAR(int32_t     , m_nEntity                       , 0x20);
            NETVAR(int32_t     , m_nModelIndex                   , 0x24);
            NETVAR(int32_t     , m_nDensity                      , 0x28);
            NETVAR(int32_t     , m_nCurrent                      , 0x2c);
        };

        class DT_TEExplosion {
        public:
            NETVAR(float       , m_fScale                        , 0x30);
            NETVAR(int32_t     , m_nFlags                        , 0x34);
            NETVAR(int32_t     , m_nRadius                       , 0x38);
            NETVAR(int32_t     , m_nMagnitude                    , 0x3c);
        };

        class DT_TEEnergySplash {
        public:
            NETVAR(Vector3D    , m_vecPos                        , 0x20);
            NETVAR(Vector3D    , m_vecDir                        , 0x2c);
            NETVAR(int32_t     , m_bExplosive                    , 0x38);
        };

        class DT_TEEffectDispatch {
        public:
            NETVAR(float       , m_vOrigin_0_                    , 0x20);
            NETVAR(float       , m_vOrigin_1_                    , 0x24);
            NETVAR(float       , m_vOrigin_2_                    , 0x28);
            NETVAR(float       , m_vStart_0_                     , 0x2c);
            NETVAR(float       , m_vStart_1_                     , 0x30);
            NETVAR(float       , m_vStart_2_                     , 0x34);
            NETVAR(Vector3D    , m_vAngles                       , 0x44);
            NETVAR(Vector3D    , m_vNormal                       , 0x38);
            NETVAR(int32_t     , m_fFlags                        , 0x50);
            NETVAR(float       , m_flMagnitude                   , 0x5c);
            NETVAR(float       , m_flScale                       , 0x58);
            NETVAR(int32_t     , m_nAttachmentIndex              , 0x64);
            NETVAR(int32_t     , m_nSurfaceProp                  , 0x68);
            NETVAR(int32_t     , m_iEffectName                   , 0xac);
            NETVAR(int32_t     , m_nMaterial                     , 0x6c);
            NETVAR(int32_t     , m_nDamageType                   , 0x70);
            NETVAR(int32_t     , m_nHitBox                       , 0x74);
            NETVAR(int32_t     , entindex                        , 0x20);
            NETVAR(int32_t     , m_nColor                        , 0x78);
            NETVAR(float       , m_flRadius                      , 0x60);
            NETVAR(int32_t     , m_bCustomColors                 , 0x79);
            NETVAR(Vector3D    , m_CustomColors_m_vecColor1      , 0x7c);
            NETVAR(Vector3D    , m_CustomColors_m_vecColor2      , 0x88);
            NETVAR(int32_t     , m_bControlPoint1                , 0x94);
            NETVAR(int32_t     , m_ControlPoint1_m_eParticleAttachment, 0x98);
            NETVAR(float       , m_ControlPoint1_m_vecOffset_0_  , 0x9c);
            NETVAR(float       , m_ControlPoint1_m_vecOffset_1_  , 0xa0);
            NETVAR(float       , m_ControlPoint1_m_vecOffset_2_  , 0xa4);
            NETVAR(int32_t     , m_bAllowOverride                , 0xa8);
        };

        class DT_TEDynamicLight {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x20);
            NETVAR(int32_t     , r                               , 0x30);
            NETVAR(int32_t     , g                               , 0x34);
            NETVAR(int32_t     , b                               , 0x38);
            NETVAR(int32_t     , exponent                        , 0x3c);
            NETVAR(float       , m_fRadius                       , 0x2c);
            NETVAR(float       , m_fTime                         , 0x40);
            NETVAR(float       , m_fDecay                        , 0x44);
        };

        class DT_TEDecal {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x20);
            NETVAR(Vector3D    , m_vecStart                      , 0x2c);
            NETVAR(int32_t     , m_nEntity                       , 0x38);
            NETVAR(int32_t     , m_nHitbox                       , 0x3c);
            NETVAR(int32_t     , m_nIndex                        , 0x40);
        };

        class DT_TEClientProjectile {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x20);
            NETVAR(Vector3D    , m_vecVelocity                   , 0x2c);
            NETVAR(int32_t     , m_nModelIndex                   , 0x38);
            NETVAR(int32_t     , m_nLifeTime                     , 0x3c);
            NETVAR(int32_t     , m_hOwner                        , 0x40);
        };

        class DT_TEBubbleTrail {
        public:
            NETVAR(Vector3D    , m_vecMins                       , 0x20);
            NETVAR(Vector3D    , m_vecMaxs                       , 0x2c);
            NETVAR(int32_t     , m_nModelIndex                   , 0x3c);
            NETVAR(float       , m_flWaterZ                      , 0x38);
            NETVAR(int32_t     , m_nCount                        , 0x40);
            NETVAR(float       , m_fSpeed                        , 0x44);
        };

        class DT_TEBubbles {
        public:
            NETVAR(Vector3D    , m_vecMins                       , 0x20);
            NETVAR(Vector3D    , m_vecMaxs                       , 0x2c);
            NETVAR(int32_t     , m_nModelIndex                   , 0x3c);
            NETVAR(float       , m_fHeight                       , 0x38);
            NETVAR(int32_t     , m_nCount                        , 0x40);
            NETVAR(float       , m_fSpeed                        , 0x44);
        };

        class DT_TEBSPDecal {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x20);
            NETVAR(int32_t     , m_nEntity                       , 0x2c);
            NETVAR(int32_t     , m_nIndex                        , 0x30);
        };

        class DT_TEBreakModel {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x20);
            NETVAR(float       , m_angRotation_0_                , 0x2c);
            NETVAR(float       , m_angRotation_1_                , 0x30);
            NETVAR(float       , m_angRotation_2_                , 0x34);
            NETVAR(Vector3D    , m_vecSize                       , 0x38);
            NETVAR(Vector3D    , m_vecVelocity                   , 0x44);
            NETVAR(int32_t     , m_nModelIndex                   , 0x54);
            NETVAR(int32_t     , m_nRandomization                , 0x50);
            NETVAR(int32_t     , m_nCount                        , 0x58);
            NETVAR(float       , m_fTime                         , 0x5c);
            NETVAR(int32_t     , m_nFlags                        , 0x60);
        };

        class DT_TEBloodStream {
        public:
            NETVAR(Vector3D    , m_vecDirection                  , 0x30);
            NETVAR(int32_t     , r                               , 0x3c);
            NETVAR(int32_t     , g                               , 0x40);
            NETVAR(int32_t     , b                               , 0x44);
            NETVAR(int32_t     , a                               , 0x48);
            NETVAR(int32_t     , m_nAmount                       , 0x4c);
        };

        class DT_TEBloodSprite {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x20);
            NETVAR(Vector3D    , m_vecDirection                  , 0x2c);
            NETVAR(int32_t     , r                               , 0x38);
            NETVAR(int32_t     , g                               , 0x3c);
            NETVAR(int32_t     , b                               , 0x40);
            NETVAR(int32_t     , a                               , 0x44);
            NETVAR(int32_t     , m_nSize                         , 0x48);
        };

        class DT_TEBeamSpline {
        public:
            NETVAR(int32_t     , m_nPoints                       , 0xe0);
            NETVAR(Vector3D    , m_vecPoints_0_                  , 0x20);
            NETVAR(uintptr_t   , m_vecPoints                     , 0x0);
        };

        class DT_TEBeamRingPoint {
        public:
            NETVAR(Vector3D    , m_vecCenter                     , 0x60);
            NETVAR(float       , m_flStartRadius                 , 0x6c);
            NETVAR(float       , m_flEndRadius                   , 0x70);
        };

        class DT_TEBeamRing {
        public:
            NETVAR(int32_t     , m_nStartEntity                  , 0x60);
            NETVAR(int32_t     , m_nEndEntity                    , 0x64);
        };

        class DT_TEBeamPoints {
        public:
            NETVAR(Vector3D    , m_vecStartPoint                 , 0x60);
            NETVAR(Vector3D    , m_vecEndPoint                   , 0x6c);
        };

        class DT_TEBeamLaser {
        public:
            NETVAR(int32_t     , m_nStartEntity                  , 0x60);
            NETVAR(int32_t     , m_nEndEntity                    , 0x64);
        };

        class DT_TEBeamFollow {
        public:
            NETVAR(int32_t     , m_iEntIndex                     , 0x60);
        };

        class DT_TEBeamEnts {
        public:
            NETVAR(int32_t     , m_nStartEntity                  , 0x60);
            NETVAR(int32_t     , m_nEndEntity                    , 0x64);
        };

        class DT_TEBeamEntPoint {
        public:
            NETVAR(int32_t     , m_nStartEntity                  , 0x60);
            NETVAR(int32_t     , m_nEndEntity                    , 0x64);
            NETVAR(Vector3D    , m_vecStartPoint                 , 0x68);
            NETVAR(Vector3D    , m_vecEndPoint                   , 0x74);
        };

        class DT_BaseBeam {
        public:
            NETVAR(int32_t     , m_nModelIndex                   , 0x20);
            NETVAR(int32_t     , m_nHaloIndex                    , 0x24);
            NETVAR(int32_t     , m_nStartFrame                   , 0x28);
            NETVAR(int32_t     , m_nFrameRate                    , 0x2c);
            NETVAR(float       , m_fLife                         , 0x30);
            NETVAR(float       , m_fWidth                        , 0x34);
            NETVAR(float       , m_fEndWidth                     , 0x38);
            NETVAR(int32_t     , m_nFadeLength                   , 0x3c);
            NETVAR(float       , m_fAmplitude                    , 0x40);
            NETVAR(int32_t     , m_nSpeed                        , 0x54);
            NETVAR(int32_t     , r                               , 0x44);
            NETVAR(int32_t     , g                               , 0x48);
            NETVAR(int32_t     , b                               , 0x4c);
            NETVAR(int32_t     , a                               , 0x50);
            NETVAR(int32_t     , m_nFlags                        , 0x58);
        };

        class DT_TEArmorRicochet {
        public:
        };

        class DT_TEMetalSparks {
        public:
            NETVAR(Vector3D    , m_vecPos                        , 0x20);
            NETVAR(Vector3D    , m_vecDir                        , 0x2c);
        };

        class DT_SteamJet {
        public:
            NETVAR(float       , m_SpreadSpeed                   , 0x17e8);
            NETVAR(float       , m_Speed                         , 0x17ec);
            NETVAR(float       , m_StartSize                     , 0x17f0);
            NETVAR(float       , m_EndSize                       , 0x17f4);
            NETVAR(float       , m_Rate                          , 0x17f8);
            NETVAR(float       , m_JetLength                     , 0x17fc);
            NETVAR(int32_t     , m_bEmit                         , 0x1800);
            NETVAR(int32_t     , m_bFaceLeft                     , 0x1808);
            NETVAR(int32_t     , m_nType                         , 0x1804);
            NETVAR(int32_t     , m_spawnflags                    , 0x180c);
            NETVAR(float       , m_flRollSpeed                   , 0x1810);
        };

        class DT_SmokeStack {
        public:
            NETVAR(float       , m_SpreadSpeed                   , 0x1840);
            NETVAR(float       , m_Speed                         , 0x1844);
            NETVAR(float       , m_StartSize                     , 0x1848);
            NETVAR(float       , m_EndSize                       , 0x184c);
            NETVAR(float       , m_Rate                          , 0x1850);
            NETVAR(float       , m_JetLength                     , 0x1854);
            NETVAR(int32_t     , m_bEmit                         , 0x1858);
            NETVAR(float       , m_flBaseSpread                  , 0x185c);
            NETVAR(float       , m_flTwist                       , 0x18b0);
            NETVAR(float       , m_flRollSpeed                   , 0x18f8);
            NETVAR(int32_t     , m_iMaterialModel                , 0x18b4);
            NETVAR(Vector3D    , m_AmbientLight_m_vPos           , 0x1860);
            NETVAR(Vector3D    , m_AmbientLight_m_vColor         , 0x186c);
            NETVAR(float       , m_AmbientLight_m_flIntensity    , 0x1878);
            NETVAR(Vector3D    , m_DirLight_m_vPos               , 0x187c);
            NETVAR(Vector3D    , m_DirLight_m_vColor             , 0x1888);
            NETVAR(float       , m_DirLight_m_flIntensity        , 0x1894);
            NETVAR(Vector3D    , m_vWind                         , 0x18a4);
        };

        class DT_DustTrail {
        public:
            NETVAR(float       , m_SpawnRate                     , 0x17e8);
            NETVAR(Vector3D    , m_Color                         , 0x17ec);
            NETVAR(float       , m_ParticleLifetime              , 0x17fc);
            NETVAR(float       , m_StopEmitTime                  , 0x1804);
            NETVAR(float       , m_MinSpeed                      , 0x1808);
            NETVAR(float       , m_MaxSpeed                      , 0x180c);
            NETVAR(float       , m_MinDirectedSpeed              , 0x1810);
            NETVAR(float       , m_MaxDirectedSpeed              , 0x1814);
            NETVAR(float       , m_StartSize                     , 0x1818);
            NETVAR(float       , m_EndSize                       , 0x181c);
            NETVAR(float       , m_SpawnRadius                   , 0x1820);
            NETVAR(int32_t     , m_bEmit                         , 0x1830);
            NETVAR(float       , m_Opacity                       , 0x17f8);
        };

        class DT_FireTrail {
        public:
            NETVAR(int32_t     , m_nAttachment                   , 0x17e8);
            NETVAR(float       , m_flLifetime                    , 0x17ec);
        };

        class DT_SporeTrail {
        public:
            NETVAR(float       , m_flSpawnRate                   , 0x17ec);
            NETVAR(Vector3D    , m_vecEndColor                   , 0x17e0);
            NETVAR(float       , m_flParticleLifetime            , 0x17f0);
            NETVAR(float       , m_flStartSize                   , 0x17f4);
            NETVAR(float       , m_flEndSize                     , 0x17f8);
            NETVAR(float       , m_flSpawnRadius                 , 0x17fc);
            NETVAR(int32_t     , m_bEmit                         , 0x180c);
        };

        class DT_SporeExplosion {
        public:
            NETVAR(float       , m_flSpawnRate                   , 0x17e8);
            NETVAR(float       , m_flParticleLifetime            , 0x17ec);
            NETVAR(float       , m_flStartSize                   , 0x17f0);
            NETVAR(float       , m_flEndSize                     , 0x17f4);
            NETVAR(float       , m_flSpawnRadius                 , 0x17f8);
            NETVAR(int32_t     , m_bEmit                         , 0x1800);
            NETVAR(int32_t     , m_bDontRemove                   , 0x1801);
        };

        class DT_RocketTrail {
        public:
            NETVAR(float       , m_SpawnRate                     , 0x17e8);
            NETVAR(Vector3D    , m_StartColor                    , 0x17ec);
            NETVAR(Vector3D    , m_EndColor                      , 0x17f8);
            NETVAR(float       , m_ParticleLifetime              , 0x1808);
            NETVAR(float       , m_StopEmitTime                  , 0x180c);
            NETVAR(float       , m_MinSpeed                      , 0x1810);
            NETVAR(float       , m_MaxSpeed                      , 0x1814);
            NETVAR(float       , m_StartSize                     , 0x1818);
            NETVAR(float       , m_EndSize                       , 0x181c);
            NETVAR(float       , m_SpawnRadius                   , 0x1820);
            NETVAR(int32_t     , m_bEmit                         , 0x1830);
            NETVAR(int32_t     , m_nAttachment                   , 0x1834);
            NETVAR(float       , m_Opacity                       , 0x1804);
            NETVAR(int32_t     , m_bDamaged                      , 0x1831);
            NETVAR(float       , m_flFlareScale                  , 0x1844);
        };

        class DT_SmokeTrail {
        public:
            NETVAR(float       , m_SpawnRate                     , 0x17e8);
            NETVAR(Vector3D    , m_StartColor                    , 0x17ec);
            NETVAR(Vector3D    , m_EndColor                      , 0x17f8);
            NETVAR(float       , m_ParticleLifetime              , 0x1808);
            NETVAR(float       , m_StopEmitTime                  , 0x180c);
            NETVAR(float       , m_MinSpeed                      , 0x1810);
            NETVAR(float       , m_MaxSpeed                      , 0x1814);
            NETVAR(float       , m_MinDirectedSpeed              , 0x1818);
            NETVAR(float       , m_MaxDirectedSpeed              , 0x181c);
            NETVAR(float       , m_StartSize                     , 0x1820);
            NETVAR(float       , m_EndSize                       , 0x1824);
            NETVAR(float       , m_SpawnRadius                   , 0x1828);
            NETVAR(int32_t     , m_bEmit                         , 0x1838);
            NETVAR(int32_t     , m_nAttachment                   , 0x183c);
            NETVAR(float       , m_Opacity                       , 0x1804);
        };

        class DT_PropVehicleDriveable {
        public:
            NETVAR(int32_t     , m_hPlayer                       , 0x1bd0);
            NETVAR(int32_t     , m_nSpeed                        , 0x1bd4);
            NETVAR(int32_t     , m_nRPM                          , 0x1bd8);
            NETVAR(float       , m_flThrottle                    , 0x1bdc);
            NETVAR(int32_t     , m_nBoostTimeLeft                , 0x1be0);
            NETVAR(int32_t     , m_nHasBoost                     , 0x1be4);
            NETVAR(int32_t     , m_bEnterAnimOn                  , 0x1c04);
            NETVAR(int32_t     , m_bExitAnimOn                   , 0x1c05);
            NETVAR(int32_t     , m_bUnableToFire                 , 0x1c75);
            NETVAR(Vector3D    , m_vecEyeExitEndpoint            , 0x1c68);
            NETVAR(int32_t     , m_bHasGun                       , 0x1c74);
            NETVAR(Vector3D    , m_vecGunCrosshair               , 0x1c0c);
            NETVAR(int32_t     , m_bLocked                       , 0x1d00);
        };

        class DT_ParticleSmokeGrenade {
        public:
            NETVAR(float       , m_flSpawnTime                   , 0x17f8);
            NETVAR(float       , m_FadeStartTime                 , 0x17fc);
            NETVAR(float       , m_FadeEndTime                   , 0x1800);
            NETVAR(int32_t     , m_CurrentStage                  , 0x17e8);
        };

        class DT_MovieExplosion {
        public:
        };

        class DT_TEGaussExplosion {
        public:
            NETVAR(int32_t     , m_nType                         , 0x30);
            NETVAR(Vector3D    , m_vecDirection                  , 0x34);
        };

        class DT_QuadraticBeam {
        public:
            NETVAR(Vector3D    , m_targetPosition                , 0x16b0);
            NETVAR(Vector3D    , m_controlPosition               , 0x16bc);
            NETVAR(float       , m_scrollRate                    , 0x16c8);
            NETVAR(float       , m_flWidth                       , 0x16cc);
        };

        class DT_Embers {
        public:
            NETVAR(int32_t     , m_nDensity                      , 0x16b0);
            NETVAR(int32_t     , m_nLifetime                     , 0x16b4);
            NETVAR(int32_t     , m_nSpeed                        , 0x16b8);
            NETVAR(int32_t     , m_bEmit                         , 0x16bc);
        };

        class DT_EnvWind {
        public:
            NETVAR(int32_t     , m_iMinWind                      , 0x16c0);
            NETVAR(int32_t     , m_iMaxWind                      , 0x16c4);
            NETVAR(int32_t     , m_iMinGust                      , 0x16cc);
            NETVAR(int32_t     , m_iMaxGust                      , 0x16d0);
            NETVAR(float       , m_flMinGustDelay                , 0x16d4);
            NETVAR(float       , m_flMaxGustDelay                , 0x16d8);
            NETVAR(int32_t     , m_iGustDirChange                , 0x16e0);
            NETVAR(int32_t     , m_iWindSeed                     , 0x16bc);
            NETVAR(int32_t     , m_iInitialWindDir               , 0x1720);
            NETVAR(float       , m_flInitialWindSpeed            , 0x1724);
            NETVAR(float       , m_flStartTime                   , 0x16b8);
            NETVAR(float       , m_flGustDuration                , 0x16dc);
            NETVAR(int32_t     , m_windRadius                    , 0x16c8);
        };

        class DT_Precipitation {
        public:
            NETVAR(int32_t     , m_nPrecipType                   , 0x16dc);
            NETVAR(char*       , m_sParticleNameClose            , 0x17ca);
            NETVAR(char*       , m_sParticleNameInner            , 0x184a);
            NETVAR(char*       , m_sParticleNameOuter            , 0x18ca);
            NETVAR(float       , m_flParticleDist                , 0x194c);
        };

        class DT_PrecipitationBlocker {
        public:
        };

        class DT_BaseTempEntity {
        public:
        };

        class DT_PropEnergyBall {
        public:
            NETVAR(int32_t     , m_bIsInfiniteLife               , 0x1bf8);
            NETVAR(float       , m_fTimeTillDeath                , 0x1bfc);
        };

        class DT_NPC_RocketTurret {
        public:
            NETVAR(int32_t     , m_iLaserState                   , 0x2934);
            NETVAR(int32_t     , m_nSiteHalo                     , 0x2938);
            NETVAR(Vector3D    , m_vecCurrentAngles              , 0x2940);
        };

        class DT_NPC_Portal_FloorTurret {
        public:
            NETVAR(int32_t     , m_bOutOfAmmo                    , 0x2934);
            NETVAR(int32_t     , m_bLaserOn                      , 0x2935);
            NETVAR(int32_t     , m_sLaserHaloSprite              , 0x2938);
        };

        class DT_WeaponStunStick {
        public:
            NETVAR(int32_t     , m_bActive                       , 0x1cfc);
        };

        class DT_WeaponSMG1 {
        public:
        };

        class DT_Weapon_SLAM {
        public:
            NETVAR(int32_t     , m_tSlamState                    , 0x1ca8);
            NETVAR(int32_t     , m_bDetonatorArmed               , 0x1cac);
            NETVAR(int32_t     , m_bNeedDetonatorDraw            , 0x1cad);
            NETVAR(int32_t     , m_bNeedDetonatorHolster         , 0x1cae);
            NETVAR(int32_t     , m_bNeedReload                   , 0x1caf);
            NETVAR(int32_t     , m_bClearReload                  , 0x1cb0);
            NETVAR(int32_t     , m_bThrowSatchel                 , 0x1cb1);
            NETVAR(int32_t     , m_bAttachSatchel                , 0x1cb2);
            NETVAR(int32_t     , m_bAttachTripmine               , 0x1cb3);
        };

        class DT_WeaponShotgun {
        public:
            NETVAR(int32_t     , m_bNeedPump                     , 0x1ca8);
            NETVAR(int32_t     , m_bDelayedFire1                 , 0x1ca9);
            NETVAR(int32_t     , m_bDelayedFire2                 , 0x1caa);
            NETVAR(int32_t     , m_bDelayedReload                , 0x1cab);
        };

        class DT_WeaponRPG {
        public:
            NETVAR(int32_t     , m_bInitialStateUpdate           , 0x1cc0);
            NETVAR(int32_t     , m_bGuiding                      , 0x1cc1);
            NETVAR(int32_t     , m_bHideGuiding                  , 0x1cc2);
            NETVAR(int32_t     , m_hMissile                      , 0x1cc4);
            NETVAR(Vector3D    , m_vecLaserDot                   , 0x1cc8);
        };

        class DT_LaserDot {
        public:
        };

        class DT_WeaponPistol {
        public:
            NETVAR(float       , m_flSoonestPrimaryAttack        , 0x1cb8);
            NETVAR(float       , m_flLastAttackTime              , 0x1cc0);
            NETVAR(float       , m_flAccuracyPenalty             , 0x1cc8);
            NETVAR(int32_t     , m_nNumShotsFired                , 0x1ccc);
        };

        class DT_WeaponPhysCannon {
        public:
            NETVAR(int32_t     , m_bActive                       , 0x2148);
            NETVAR(int32_t     , m_hAttachedObject               , 0x1cc0);
            NETVAR(Vector3D    , m_attachedPositionObjectSpace   , 0x1cb4);
            NETVAR(float       , m_attachedAnglesPlayerSpace_0_  , 0x1ca8);
            NETVAR(float       , m_attachedAnglesPlayerSpace_1_  , 0x1cac);
            NETVAR(float       , m_attachedAnglesPlayerSpace_2_  , 0x1cb0);
            NETVAR(int32_t     , m_EffectState                   , 0x214c);
            NETVAR(int32_t     , m_bOpen                         , 0x2150);
            NETVAR(int32_t     , m_bPhyscannonState              , 0x2151);
        };

        class DT_BaseHL2MPCombatWeapon {
        public:
        };

        class DT_BaseHL2MPBludgeonWeapon {
        public:
        };

        class DT_HL2MPMachineGun {
        public:
            NETVAR(int32_t     , m_nShotsFired                   , 0x1ca8);
        };

        class DT_WeaponHL2MPBase {
        public:
        };

        class DT_WeaponFrag {
        public:
            NETVAR(int32_t     , m_bRedraw                       , 0x1ca8);
            NETVAR(int32_t     , m_fDrawbackFinished             , 0x1cb0);
            NETVAR(int32_t     , m_AttackPaused                  , 0x1cac);
        };

        class DT_WeaponCrowbar {
        public:
        };

        class DT_WeaponCrossbow {
        public:
            NETVAR(int32_t     , m_bInZoom                       , 0x1cac);
            NETVAR(int32_t     , m_bMustReload                   , 0x1cad);
        };

        class DT_WeaponAR2 {
        public:
        };

        class DT_Weapon357 {
        public:
        };

        class DT_HL2MPGameRulesProxy {
        public:
            NETVAR(int32_t     , m_bTeamPlayEnabled              , 0x38);
        };

        class DT_TEHL2MPFireBullets {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x24);
            NETVAR(Vector3D    , m_vecDir                        , 0x30);
            NETVAR(int32_t     , m_iAmmoID                       , 0x3c);
            NETVAR(int32_t     , m_iSeed                         , 0x44);
            NETVAR(int32_t     , m_iShots                        , 0x4c);
            NETVAR(int32_t     , m_iPlayer                       , 0x20);
            NETVAR(int32_t     , m_iWeaponIndex                  , 0x40);
            NETVAR(float       , m_flSpread                      , 0x48);
            NETVAR(int32_t     , m_bDoImpacts                    , 0x50);
            NETVAR(int32_t     , m_bDoTracers                    , 0x51);
            NETVAR(char*       , m_TracerType                    , 0x58);
            NETVAR(float       , m_flSpreadY                     , 0x54);
        };

        class DT_TEPlayerAnimEvent {
        public:
            NETVAR(int32_t     , m_hPlayer                       , 0x20);
            NETVAR(int32_t     , m_iEvent                        , 0x24);
            NETVAR(int32_t     , m_nData                         , 0x28);
        };

        class DT_HL2MPRagdoll {
        public:
            NETVAR(Vector3D    , m_vecRagdollOrigin              , 0x1c60);
            NETVAR(int32_t     , m_hPlayer                       , 0x1c50);
            NETVAR(int32_t     , m_nModelIndex                   , 0xd4);
            NETVAR(int32_t     , m_nForceBone                    , 0x1714);
            NETVAR(Vector3D    , m_vecForce                      , 0x1708);
            NETVAR(Vector3D    , m_vecRagdollVelocity            , 0x1c54);
        };

        class DT_HL2MP_Player {
        public:
            NETVAR(Vector3D, m_vecOrigin, 0x438);
            NETVAR(float, m_angEyeAngles_0_, 0x35d8);
            NETVAR(float, m_angEyeAngles_1_, 0x35dc);
            NETVAR(int32_t, m_hRagdoll, 0x3638);
            NETVAR(int32_t, m_iSpawnInterpCounter, 0x367c);
            NETVAR(int32_t, m_fIsWalking, 0x3654);
        };

        class DT_WeaponBugBait {
        public:
            NETVAR(int32_t     , m_bRedraw                       , 0x1ca9);
            NETVAR(int32_t     , m_bDrawBackFinished             , 0x1ca8);
        };

        class DT_CrossbowBolt {
        public:
        };

        class DT_WeaponOldManHarpoon {
        public:
        };

        class DT_WeaponCitizenSuitcase {
        public:
        };

        class DT_WeaponCitizenPackage {
        public:
        };

        class DT_WeaponAlyxGun {
        public:
        };

        class DT_WeaponCubemap {
        public:
        };

        class DT_WeaponAnnabelle {
        public:
        };

        class DT_WeaponCycler {
        public:
        };

        class DT_VortigauntEffectDispel {
        public:
            NETVAR(int32_t     , m_bFadeOut                      , 0x16c0);
        };

        class DT_VortigauntChargeToken {
        public:
            NETVAR(int32_t     , m_bFadeOut                      , 0x16b8);
        };

        class DT_NPC_Vortigaunt {
        public:
            NETVAR(float       , m_flBlueEndFadeTime             , 0x2934);
            NETVAR(int32_t     , m_bIsBlue                       , 0x2930);
            NETVAR(int32_t     , m_bIsBlack                      , 0x2938);
        };

        class DT_PropVehiclePrisonerPod {
        public:
            NETVAR(int32_t     , m_hPlayer                       , 0x1bd8);
            NETVAR(int32_t     , m_bEnterAnimOn                  , 0x1be0);
            NETVAR(int32_t     , m_bExitAnimOn                   , 0x1be1);
            NETVAR(Vector3D    , m_vecEyeExitEndpoint            , 0x1be4);
            NETVAR(int32_t     , m_bLimitView                    , 0x1be2);
            NETVAR(int32_t     , m_bLocked                       , 0x1be3);
        };

        class DT_PropCrane {
        public:
            NETVAR(int32_t     , m_hPlayer                       , 0x1bd0);
            NETVAR(int32_t     , m_bMagnetOn                     , 0x1be8);
            NETVAR(int32_t     , m_bEnterAnimOn                  , 0x1bd8);
            NETVAR(int32_t     , m_bExitAnimOn                   , 0x1bd9);
            NETVAR(Vector3D    , m_vecEyeExitEndpoint            , 0x1bdc);
        };

        class DT_PropAirboat {
        public:
            NETVAR(int32_t     , m_bHeadlightIsOn                , 0x1d3c);
            NETVAR(int32_t     , m_nAmmoCount                    , 0x1d40);
            NETVAR(int32_t     , m_nExactWaterLevel              , 0x1d50);
            NETVAR(int32_t     , m_nWaterLevel                   , 0x200);
            NETVAR(Vector3D    , m_vecPhysVelocity               , 0x2238);
        };

        class DT_Flare {
        public:
            NETVAR(float       , m_flTimeBurnOut                 , 0x2a78);
            NETVAR(float       , m_flScale                       , 0x2a7c);
            NETVAR(int32_t     , m_bLight                        , 0x2a80);
            NETVAR(int32_t     , m_bSmoke                        , 0x2a81);
            NETVAR(int32_t     , m_bPropFlare                    , 0x2a82);
        };

        class DT_TEConcussiveExplosion {
        public:
            NETVAR(Vector3D    , m_vecNormal                     , 0x30);
            NETVAR(float       , m_flScale                       , 0x3c);
            NETVAR(int32_t     , m_nRadius                       , 0x40);
            NETVAR(int32_t     , m_nMagnitude                    , 0x44);
        };

        class DT_NPC_Strider {
        public:
            NETVAR(Vector3D    , m_vecHitPos                     , 0x2998);
            NETVAR(Vector3D    , m_vecIKTarget_0_                , 0x29a4);
            NETVAR(Vector3D    , m_vecIKTarget_1_                , 0x29b0);
            NETVAR(Vector3D    , m_vecIKTarget_2_                , 0x29bc);
            NETVAR(Vector3D    , m_vecIKTarget_3_                , 0x29c8);
            NETVAR(Vector3D    , m_vecIKTarget_4_                , 0x29d4);
            NETVAR(Vector3D    , m_vecIKTarget_5_                , 0x29e0);
        };

        class DT_ScriptIntro {
        public:
            NETVAR(Vector3D    , m_vecCameraView                 , 0x1728);
            NETVAR(Vector3D    , m_vecCameraViewAngles           , 0x1734);
            NETVAR(int32_t     , m_iBlendMode                    , 0x1740);
            NETVAR(int32_t     , m_iNextBlendMode                , 0x1744);
            NETVAR(float       , m_flNextBlendTime               , 0x1748);
            NETVAR(float       , m_flBlendStartTime              , 0x1750);
            NETVAR(int32_t     , m_bActive                       , 0x1758);
            NETVAR(int32_t     , m_iFOV                          , 0x16b4);
            NETVAR(int32_t     , m_iNextFOV                      , 0x16b0);
            NETVAR(int32_t     , m_iStartFOV                     , 0x16bc);
            NETVAR(float       , m_flNextFOVBlendTime            , 0x16c0);
            NETVAR(float       , m_flFOVBlendStartTime           , 0x16c8);
            NETVAR(int32_t     , m_bAlternateFOV                 , 0x16d0);
            NETVAR(float       , m_flFadeAlpha                   , 0x176c);
            NETVAR(float       , m_flFadeColor_0_                , 0x1760);
            NETVAR(uintptr_t   , m_flFadeColor                   , 0x0);
            NETVAR(float       , m_flFadeDuration                , 0x1774);
            NETVAR(int32_t     , m_hCameraEntity                 , 0x175c);
        };

        class DT_RotorWashEmitter {
        public:
            NETVAR(float       , m_flAltitude                    , 0x16b0);
        };

        class DT_PropCombineBall {
        public:
            NETVAR(int32_t     , m_bEmit                         , 0x1bd4);
            NETVAR(float       , m_flRadius                      , 0x1bd8);
            NETVAR(int32_t     , m_bHeld                         , 0x1bdc);
            NETVAR(int32_t     , m_bLaunched                     , 0x1bdd);
        };

        class DT_PlasmaBeamNode {
        public:
            NETVAR(Vector3D    , m_vecVelocity                   , 0x150);
            NETVAR(int32_t     , m_bSprayOn                      , 0x16b0);
        };

        class DT_RollerMine {
        public:
            NETVAR(int32_t     , m_bIsOpen                       , 0x2930);
            NETVAR(float       , m_flActiveTime                  , 0x2934);
            NETVAR(int32_t     , m_bHackedByAlyx                 , 0x2938);
            NETVAR(int32_t     , m_bPowerDown                    , 0x2939);
        };

        class DT_NPC_Manhack {
        public:
            NETVAR(int32_t     , m_nEnginePitch1                 , 0x2948);
            NETVAR(float       , m_flEnginePitch1Time            , 0x2950);
            NETVAR(int32_t     , m_nEnginePitch2                 , 0x294c);
            NETVAR(float       , m_flEnginePitch2Time            , 0x2954);
        };

        class DT_CombineGunship {
        public:
            NETVAR(Vector3D    , m_vecHitPos                     , 0x2990);
        };

        class DT_NPC_AntlionGuard {
        public:
            NETVAR(int32_t     , m_bCavernBreed                  , 0x2930);
            NETVAR(int32_t     , m_bInCavern                     , 0x2931);
            NETVAR(int32_t     , m_iBleedingLevel                , 0x2940);
        };

        class DT_InfoTeleporterCountdown {
        public:
            NETVAR(int32_t     , m_bCountdownStarted             , 0x16b0);
            NETVAR(int32_t     , m_bDisabled                     , 0x16b1);
            NETVAR(float       , m_flStartTime                   , 0x16b4);
            NETVAR(float       , m_flTimeRemaining               , 0x16b8);
        };

        class DT_MortarShell {
        public:
            NETVAR(float       , m_flLifespan                    , 0x16c0);
            NETVAR(float       , m_flRadius                      , 0x16c4);
            NETVAR(Vector3D    , m_vecSurfaceNormal              , 0x16cc);
        };

        class DT_EnvStarfield {
        public:
            NETVAR(int32_t     , m_bOn                           , 0x16b8);
            NETVAR(float       , m_flDensity                     , 0x16bc);
        };

        class DT_EnvHeadcrabCanister {
        public:
            NETVAR(float       , m_flFlightSpeed                 , 0x1c04);
            NETVAR(float       , m_flLaunchTime                  , 0x1c08);
            NETVAR(Vector3D    , m_vecParabolaDirection          , 0x1c20);
            NETVAR(float       , m_flFlightTime                  , 0x1c00);
            NETVAR(float       , m_flWorldEnterTime              , 0x1c2c);
            NETVAR(float       , m_flInitialZSpeed               , 0x1c10);
            NETVAR(float       , m_flZAcceleration               , 0x1c14);
            NETVAR(float       , m_flHorizSpeed                  , 0x1c18);
            NETVAR(int32_t     , m_bLaunchedFromWithinWorld      , 0x1c1c);
            NETVAR(Vector3D    , m_vecStartPosition              , 0x1bd0);
            NETVAR(Vector3D    , m_vecEnterWorldPosition         , 0x1bdc);
            NETVAR(Vector3D    , m_vecDirection                  , 0x1be8);
            NETVAR(Vector3D    , m_vecStartAngles                , 0x1bf4);
            NETVAR(Vector3D    , m_vecSkyboxOrigin               , 0x1c30);
            NETVAR(float       , m_flSkyboxScale                 , 0x1c3c);
            NETVAR(int32_t     , m_bInSkybox                     , 0x1c40);
            NETVAR(int32_t     , m_bLanded                       , 0x1c48);
        };

        class DT_AlyxEmpEffect {
        public:
            NETVAR(int32_t     , m_nState                        , 0x16b0);
            NETVAR(float       , m_flDuration                    , 0x16b4);
            NETVAR(float       , m_flStartTime                   , 0x16b8);
        };

        class DT_Corpse {
        public:
            NETVAR(int32_t     , m_nReferencePlayer              , 0x1bc8);
        };

        class DT_CitadelEnergyCore {
        public:
            NETVAR(float       , m_flScale                       , 0x16b0);
            NETVAR(int32_t     , m_nState                        , 0x16b4);
            NETVAR(float       , m_flDuration                    , 0x16b8);
            NETVAR(float       , m_flStartTime                   , 0x16bc);
            NETVAR(int32_t     , m_spawnflags                    , 0x16c0);
        };

        class DT_HL2_Player {
        public:
            NETVAR(float       , m_flSuitPower                   , 0x3550);
            NETVAR(int32_t     , m_bZooming                      , 0x3561);
            NETVAR(int32_t     , m_bitsActiveDevices             , 0x3554);
            NETVAR(int32_t     , m_iSquadMemberCount             , 0x3558);
            NETVAR(int32_t     , m_iSquadMedicCount              , 0x355c);
            NETVAR(int32_t     , m_fSquadInFollowMode            , 0x3560);
            NETVAR(int32_t     , m_bWeaponLowered                , 0x3562);
            NETVAR(int32_t     , m_hLadder                       , 0x3564);
            NETVAR(int32_t     , m_bDisplayReticle               , 0x3563);
            NETVAR(int32_t     , m_fIsSprinting                  , 0x35a8);
        };

        class DT_BaseHLBludgeonWeapon {
        public:
        };

        class DT_HLSelectFireMachineGun {
        public:
        };

        class DT_HLMachineGun {
        public:
        };

        class DT_BaseHelicopter {
        public:
            NETVAR(float       , m_flStartupTime                 , 0x2930);
        };

        class DT_NPC_Barney {
        public:
        };

        class DT_Barnacle {
        public:
            NETVAR(float       , m_flAltitude                    , 0x2960);
            NETVAR(Vector3D    , m_vecRoot                       , 0x293c);
            NETVAR(Vector3D    , m_vecTip                        , 0x2948);
            NETVAR(Vector3D    , m_vecTipDrawOffset              , 0x2954);
        };

        class DT_AR2Explosion {
        public:
            NETVAR(char*       , m_szMaterialName                , 0x17f8);
        };

        class DT_TEAntlionDust {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x38);
            NETVAR(Vector3D    , m_vecAngles                     , 0x44);
            NETVAR(int32_t     , m_bBlockedSpawner               , 0x50);
        };

        class DT_BaseHLCombatWeapon {
        public:
        };

        class DT_WeaponShotgun_HL1 {
        public:
            NETVAR(float       , m_flPumpTime                    , 0x1c70);
            NETVAR(int32_t     , m_fInSpecialReload              , 0x1c74);
        };

        class DT_WeaponSatchel {
        public:
            NETVAR(int32_t     , m_iRadioViewIndex               , 0x1c70);
            NETVAR(int32_t     , m_iRadioWorldIndex              , 0x1c74);
            NETVAR(int32_t     , m_iSatchelViewIndex             , 0x1c78);
            NETVAR(int32_t     , m_iSatchelWorldIndex            , 0x1c7c);
            NETVAR(int32_t     , m_iChargeReady                  , 0x1c80);
        };

        class DT_WeaponRPG_HL1 {
        public:
            NETVAR(int32_t     , m_bIntialStateUpdate            , 0x1c71);
            NETVAR(int32_t     , m_bGuiding                      , 0x1c70);
            NETVAR(int32_t     , m_bLaserDotSuspended            , 0x1c72);
        };

        class DT_LaserDot_HL1 {
        public:
            NETVAR(int32_t     , m_bIsOn                         , 0x16c9);
        };

        class DT_WeaponMP5 {
        public:
        };

        class DT_WeaponHgun {
        public:
            NETVAR(float       , m_flRechargeTime                , 0x1c70);
            NETVAR(int32_t     , m_iFirePhase                    , 0x1c74);
        };

        class DT_WeaponHandGrenade {
        public:
            NETVAR(float       , m_flStartThrow                  , 0x1c70);
            NETVAR(float       , m_flReleaseThrow                , 0x1c74);
        };

        class DT_WeaponGlock {
        public:
        };

        class DT_WeaponGauss {
        public:
            NETVAR(int32_t     , m_nAttackState                  , 0x1c70);
            NETVAR(int32_t     , m_bPrimaryFire                  , 0x1c74);
            NETVAR(float       , m_flStartCharge                 , 0x1c78);
            NETVAR(float       , m_flAmmoStartCharge             , 0x1c7c);
            NETVAR(float       , m_flPlayAftershock              , 0x1c80);
            NETVAR(float       , m_flNextAmmoBurn                , 0x1c88);
        };

        class DT_WeaponEgon {
        public:
        };

        class DT_WeaponCrossbow_HL1 {
        public:
            NETVAR(int32_t     , m_fInZoom                       , 0x1c70);
        };

        class DT_Weapon357_HL1 {
        public:
            NETVAR(float       , m_fInZoom                       , 0x1c70);
        };

        class DT_BaseHL1MPCombatWeapon {
        public:
        };

        class DT_WeaponTripMine {
        public:
            NETVAR(float       , m_iGroundIndex                  , 0x1c70);
            NETVAR(float       , m_iPickedUpIndex                , 0x1c74);
        };

        class DT_WeaponSnark {
        public:
            NETVAR(int32_t     , m_bJustThrown                   , 0x1c70);
        };

        class DT_WeaponCrowbar_HL1 {
        public:
        };

        class DT_BaseHelicopter_HL1 {
        public:
        };

        class DT_RpgRocket {
        public:
        };

        class DT_BaseHL1CombatWeapon {
        public:
        };

        class DT_PredictedViewModel {
        public:
        };

        class DT_TriggerPlayerMovement {
        public:
        };

        class DT_BaseTrigger {
        public:
            NETVAR(int32_t     , m_bClientSidePredicted          , 0x16e0);
            NETVAR(int32_t     , m_spawnflags                    , 0x92c);
        };

        class DT_SpatialEntity {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x16b0);
            NETVAR(float       , m_minFalloff                    , 0x16bc);
            NETVAR(float       , m_maxFalloff                    , 0x16c0);
            NETVAR(float       , m_flCurWeight                   , 0x16c4);
            NETVAR(int32_t     , m_bEnabled                      , 0x17cc);
        };

        class DT_PointWorldText {
        public:
            NETVAR(char*       , m_szText                        , 0x16ea);
            NETVAR(int32_t     , m_colTextColor                  , 0x17fc);
            NETVAR(float       , m_flTextSize                    , 0x17f0);
            NETVAR(float       , m_flTextSpacingX                , 0x17f4);
            NETVAR(float       , m_flTextSpacingY                , 0x17f8);
            NETVAR(int32_t     , m_nOrientation                  , 0x1800);
            NETVAR(int32_t     , m_bRainbow                      , 0x16e8);
            NETVAR(int32_t     , m_bTextEnabled                  , 0x16e9);
        };

        class DT_EnvAmbientLight {
        public:
            NETVAR(Vector3D    , m_vecColor                      , 0x17d8);
        };

        class DT_BeamSpotlight {
        public:
            NETVAR(int32_t     , m_nHaloIndex                    , 0x16b0);
            NETVAR(int32_t     , m_bSpotlightOn                  , 0x16bc);
            NETVAR(int32_t     , m_bHasDynamicLight              , 0x16bd);
            NETVAR(float       , m_flSpotlightMaxLength          , 0x16c0);
            NETVAR(float       , m_flSpotlightGoalWidth          , 0x16c4);
            NETVAR(float       , m_flHDRColorScale               , 0x16c8);
            NETVAR(int32_t     , m_nRotationAxis                 , 0x16b4);
            NETVAR(float       , m_flRotationSpeed               , 0x16b8);
        };

        class DT_BaseToggle {
        public:
            NETVAR(Vector3D    , m_vecFinalDest                  , 0x16c4);
            NETVAR(int32_t     , m_movementType                  , 0x16d0);
            NETVAR(float       , m_flMoveTargetTime              , 0x16d4);
        };

        class DT_SpriteTrail {
        public:
            NETVAR(float       , m_flLifeTime                    , 0x2758);
            NETVAR(float       , m_flStartWidth                  , 0x275c);
            NETVAR(float       , m_flEndWidth                    , 0x2760);
            NETVAR(float       , m_flStartWidthVariance          , 0x2764);
            NETVAR(float       , m_flTextureRes                  , 0x2768);
            NETVAR(float       , m_flMinFadeLength               , 0x276c);
            NETVAR(Vector3D    , m_vecSkyboxOrigin               , 0x2770);
            NETVAR(float       , m_flSkyboxScale                 , 0x277c);
        };

        class DT_SpriteOriented {
        public:
        };

        class DT_Sprite {
        public:
            NETVAR(int32_t     , m_hAttachedToEntity             , 0x16c8);
            NETVAR(int32_t     , m_nAttachment                   , 0x16cc);
            NETVAR(float       , m_flScaleTime                   , 0x16e8);
            NETVAR(float       , m_flSpriteScale                 , 0x16e4);
            NETVAR(float       , m_flSpriteFramerate             , 0x16d0);
            NETVAR(float       , m_flGlowProxySize               , 0x16f0);
            NETVAR(float       , m_flHDRColorScale               , 0x16f4);
            NETVAR(float       , m_flFrame                       , 0x16d4);
            NETVAR(float       , m_flBrightnessTime              , 0x16e0);
            NETVAR(int32_t     , m_nBrightness                   , 0x16dc);
            NETVAR(int32_t     , m_bWorldSpaceScale              , 0x16ec);
        };

        class DT_Ragdoll_Attached {
        public:
            NETVAR(int32_t     , m_boneIndexAttached             , 0x2030);
            NETVAR(int32_t     , m_ragdollAttachedObjectIndex    , 0x202c);
            NETVAR(Vector3D    , m_attachmentPointBoneSpace      , 0x2008);
            NETVAR(Vector3D    , m_attachmentPointRagdollSpace   , 0x2020);
        };

        class DT_Ragdoll {
        public:
            NETVAR(Vector3D    , m_ragPos__0__                   , 0x1bc8);
            NETVAR(Vector3D    , m_ragPos__1__                   , 0x1bd4);
            NETVAR(Vector3D    , m_ragPos__2__                   , 0x1be0);
            NETVAR(Vector3D    , m_ragPos__3__                   , 0x1bec);
            NETVAR(Vector3D    , m_ragPos__4__                   , 0x1bf8);
            NETVAR(Vector3D    , m_ragPos__5__                   , 0x1c04);
            NETVAR(Vector3D    , m_ragPos__6__                   , 0x1c10);
            NETVAR(Vector3D    , m_ragPos__7__                   , 0x1c1c);
            NETVAR(Vector3D    , m_ragPos__8__                   , 0x1c28);
            NETVAR(Vector3D    , m_ragPos__9__                   , 0x1c34);
            NETVAR(Vector3D    , m_ragPos__10__                  , 0x1c40);
            NETVAR(Vector3D    , m_ragPos__11__                  , 0x1c4c);
            NETVAR(Vector3D    , m_ragPos__12__                  , 0x1c58);
            NETVAR(Vector3D    , m_ragPos__13__                  , 0x1c64);
            NETVAR(Vector3D    , m_ragPos__14__                  , 0x1c70);
            NETVAR(Vector3D    , m_ragPos__15__                  , 0x1c7c);
            NETVAR(Vector3D    , m_ragPos__16__                  , 0x1c88);
            NETVAR(Vector3D    , m_ragPos__17__                  , 0x1c94);
            NETVAR(Vector3D    , m_ragPos__18__                  , 0x1ca0);
            NETVAR(Vector3D    , m_ragPos__19__                  , 0x1cac);
            NETVAR(Vector3D    , m_ragPos__20__                  , 0x1cb8);
            NETVAR(Vector3D    , m_ragPos__21__                  , 0x1cc4);
            NETVAR(Vector3D    , m_ragPos__22__                  , 0x1cd0);
            NETVAR(Vector3D    , m_ragPos__23__                  , 0x1cdc);
            NETVAR(Vector3D    , m_ragPos__24__                  , 0x1ce8);
            NETVAR(Vector3D    , m_ragPos__25__                  , 0x1cf4);
            NETVAR(Vector3D    , m_ragPos__26__                  , 0x1d00);
            NETVAR(Vector3D    , m_ragPos__27__                  , 0x1d0c);
            NETVAR(Vector3D    , m_ragPos__28__                  , 0x1d18);
            NETVAR(Vector3D    , m_ragPos__29__                  , 0x1d24);
            NETVAR(Vector3D    , m_ragPos__30__                  , 0x1d30);
            NETVAR(Vector3D    , m_ragPos__31__                  , 0x1d3c);
            NETVAR(Vector3D    , m_ragAngles__0__                , 0x1d48);
            NETVAR(Vector3D    , m_ragAngles__1__                , 0x1d54);
            NETVAR(Vector3D    , m_ragAngles__2__                , 0x1d60);
            NETVAR(Vector3D    , m_ragAngles__3__                , 0x1d6c);
            NETVAR(Vector3D    , m_ragAngles__4__                , 0x1d78);
            NETVAR(Vector3D    , m_ragAngles__5__                , 0x1d84);
            NETVAR(Vector3D    , m_ragAngles__6__                , 0x1d90);
            NETVAR(Vector3D    , m_ragAngles__7__                , 0x1d9c);
            NETVAR(Vector3D    , m_ragAngles__8__                , 0x1da8);
            NETVAR(Vector3D    , m_ragAngles__9__                , 0x1db4);
            NETVAR(Vector3D    , m_ragAngles__10__               , 0x1dc0);
            NETVAR(Vector3D    , m_ragAngles__11__               , 0x1dcc);
            NETVAR(Vector3D    , m_ragAngles__12__               , 0x1dd8);
            NETVAR(Vector3D    , m_ragAngles__13__               , 0x1de4);
            NETVAR(Vector3D    , m_ragAngles__14__               , 0x1df0);
            NETVAR(Vector3D    , m_ragAngles__15__               , 0x1dfc);
            NETVAR(Vector3D    , m_ragAngles__16__               , 0x1e08);
            NETVAR(Vector3D    , m_ragAngles__17__               , 0x1e14);
            NETVAR(Vector3D    , m_ragAngles__18__               , 0x1e20);
            NETVAR(Vector3D    , m_ragAngles__19__               , 0x1e2c);
            NETVAR(Vector3D    , m_ragAngles__20__               , 0x1e38);
            NETVAR(Vector3D    , m_ragAngles__21__               , 0x1e44);
            NETVAR(Vector3D    , m_ragAngles__22__               , 0x1e50);
            NETVAR(Vector3D    , m_ragAngles__23__               , 0x1e5c);
            NETVAR(Vector3D    , m_ragAngles__24__               , 0x1e68);
            NETVAR(Vector3D    , m_ragAngles__25__               , 0x1e74);
            NETVAR(Vector3D    , m_ragAngles__26__               , 0x1e80);
            NETVAR(Vector3D    , m_ragAngles__27__               , 0x1e8c);
            NETVAR(Vector3D    , m_ragAngles__28__               , 0x1e98);
            NETVAR(Vector3D    , m_ragAngles__29__               , 0x1ea4);
            NETVAR(Vector3D    , m_ragAngles__30__               , 0x1eb0);
            NETVAR(Vector3D    , m_ragAngles__31__               , 0x1ebc);
            NETVAR(int32_t     , m_hUnragdoll                    , 0x1ff0);
            NETVAR(float       , m_flBlendWeight                 , 0x1ff4);
            NETVAR(int32_t     , m_nOverlaySequence              , 0x1ffc);
        };

        class DT_PoseController {
        public:
            NETVAR(int32_t     , m_bPoseValueParity              , 0x16c4);
            NETVAR(float       , m_fPoseValue                    , 0x16c8);
            NETVAR(float       , m_fInterpolationTime            , 0x16cc);
            NETVAR(int32_t     , m_bInterpolationWrap            , 0x16d0);
            NETVAR(float       , m_fCycleFrequency               , 0x16d4);
            NETVAR(int32_t     , m_nFModType                     , 0x16d8);
            NETVAR(float       , m_fFModTimeOffset               , 0x16dc);
            NETVAR(float       , m_fFModRate                     , 0x16e0);
            NETVAR(float       , m_fFModAmplitude                , 0x16e4);
        };

        class DT_GameRulesProxy {
        public:
        };

        class DT_InfoLadderDismount {
        public:
        };

        class DT_FuncLadder {
        public:
            NETVAR(Vector3D    , m_vecPlayerMountPositionTop     , 0x16e0);
            NETVAR(Vector3D    , m_vecPlayerMountPositionBottom  , 0x16ec);
            NETVAR(Vector3D    , m_vecLadderDir                  , 0x16b0);
            NETVAR(int32_t     , m_bFakeLadder                   , 0x16f9);
        };

        class DT_DetailController {
        public:
            NETVAR(float       , m_flFadeStartDist               , 0x16b0);
            NETVAR(float       , m_flFadeEndDist                 , 0x16b4);
        };

        class DT_World {
        public:
            NETVAR(Vector3D    , m_WorldMins                     , 0x16b0);
            NETVAR(Vector3D    , m_WorldMaxs                     , 0x16bc);
            NETVAR(int32_t     , m_bStartDark                    , 0x16c8);
            NETVAR(float       , m_flMaxOccludeeArea             , 0x16cc);
            NETVAR(float       , m_flMinOccluderArea             , 0x16d0);
            NETVAR(float       , m_flMaxPropScreenSpaceWidth     , 0x16d8);
            NETVAR(float       , m_flMinPropScreenSpaceWidth     , 0x16d4);
            NETVAR(char*       , m_iszDetailSpriteMaterial       , 0x16dc);
        };

        class DT_WaterLODControl {
        public:
            NETVAR(float       , m_flCheapWaterStartDistance     , 0x16b0);
            NETVAR(float       , m_flCheapWaterEndDistance       , 0x16b4);
        };

        class DT_WaterBullet {
        public:
        };

        class DT_VGuiScreen {
        public:
            NETVAR(float       , m_flWidth                       , 0x16b8);
            NETVAR(float       , m_flHeight                      , 0x16bc);
            NETVAR(int32_t     , m_fScreenFlags                  , 0x16e4);
            NETVAR(int32_t     , m_nPanelName                    , 0x16c0);
            NETVAR(int32_t     , m_nAttachmentIndex              , 0x16dc);
            NETVAR(int32_t     , m_nOverlayMaterial              , 0x16e0);
            NETVAR(int32_t     , m_hPlayerOwner                  , 0x1750);
        };

        class DT_PropJeep {
        public:
            NETVAR(int32_t     , m_bHeadlightIsOn                , 0x1d48);
        };

        class DT_PropVehicleChoreoGeneric {
        public:
            NETVAR(int32_t     , m_hPlayer                       , 0x1c00);
            NETVAR(int32_t     , m_bEnterAnimOn                  , 0x1c08);
            NETVAR(int32_t     , m_bExitAnimOn                   , 0x1c09);
            NETVAR(int32_t     , m_bForceEyesToAttachment        , 0x1c18);
            NETVAR(Vector3D    , m_vecEyeExitEndpoint            , 0x1c0c);
            NETVAR(int32_t     , m_vehicleView_bClampEyeAngles   , 0x1ca8);
            NETVAR(float       , m_vehicleView_flPitchCurveZero  , 0x1cac);
            NETVAR(float       , m_vehicleView_flPitchCurveLinear, 0x1cb0);
            NETVAR(float       , m_vehicleView_flRollCurveZero   , 0x1cb4);
            NETVAR(float       , m_vehicleView_flRollCurveLinear , 0x1cb8);
            NETVAR(float       , m_vehicleView_flFOV             , 0x1cbc);
            NETVAR(float       , m_vehicleView_flYawMin          , 0x1cc0);
            NETVAR(float       , m_vehicleView_flYawMax          , 0x1cc4);
            NETVAR(float       , m_vehicleView_flPitchMin        , 0x1cc8);
            NETVAR(float       , m_vehicleView_flPitchMax        , 0x1ccc);
        };

        class DT_Tesla {
        public:
            NETVAR(char*       , m_SoundName                     , 0x16e0);
            NETVAR(char*       , m_iszSpriteName                 , 0x1720);
        };

        class DT_Team {
        public:
            NETVAR(int32_t     , m_iTeamNum                      , 0x1704);
            NETVAR(int32_t     , m_iScore                        , 0x16f0);
            NETVAR(int32_t     , m_iRoundsWon                    , 0x16f4);
            NETVAR(char*       , m_szTeamname                    , 0x16d0);
            NETVAR(int32_t     , player_array_element            , 0x0);
        };

        class DT_Sun {
        public:
            NETVAR(int32_t     , m_clrRender                     , 0x90);
            NETVAR(int32_t     , m_clrOverlay                    , 0x1860);
            NETVAR(Vector3D    , m_vDirection                    , 0x186c);
            NETVAR(int32_t     , m_bOn                           , 0x1878);
            NETVAR(int32_t     , m_nSize                         , 0x1864);
            NETVAR(int32_t     , m_nOverlaySize                  , 0x1868);
            NETVAR(int32_t     , m_nMaterial                     , 0x187c);
            NETVAR(int32_t     , m_nOverlayMaterial              , 0x1880);
            NETVAR(float       , HDRColorScale                   , 0x0);
        };

        class DT_ParticlePerformanceMonitor {
        public:
            NETVAR(int32_t     , m_bMeasurePerf                  , 0x16b1);
            NETVAR(int32_t     , m_bDisplayPerf                  , 0x16b0);
        };

        class DT_SpotlightEnd {
        public:
            NETVAR(float       , m_flLightScale                  , 0x16b0);
            NETVAR(float       , m_Radius                        , 0x16b4);
        };

        class DT_SlideshowDisplay {
        public:
            NETVAR(int32_t     , m_bEnabled                      , 0x16b0);
            NETVAR(char*       , m_szDisplayText                 , 0x16b1);
            NETVAR(char*       , m_szSlideshowDirectory          , 0x1731);
            NETVAR(float       , m_fMinSlideTime                 , 0x17f0);
            NETVAR(float       , m_fMaxSlideTime                 , 0x17f4);
            NETVAR(int32_t     , m_iCycleType                    , 0x17fc);
            NETVAR(int32_t     , m_bNoListRepeats                , 0x1800);
        };

        class DT_ShadowControl {
        public:
            NETVAR(Vector3D    , m_shadowDirection               , 0x16b0);
            NETVAR(int32_t     , m_shadowColor                   , 0x16bc);
            NETVAR(float       , m_flShadowMaxDist               , 0x16c0);
            NETVAR(int32_t     , m_bDisableShadows               , 0x16c4);
            NETVAR(int32_t     , m_bEnableLocalLightShadows      , 0x16c5);
        };

        class DT_SceneEntity {
        public:
            NETVAR(int32_t     , m_nSceneStringIndex             , 0x16c4);
            NETVAR(int32_t     , m_bIsPlayingBack                , 0x16b8);
            NETVAR(int32_t     , m_bPaused                       , 0x16b9);
            NETVAR(int32_t     , m_bMultiplayer                  , 0x16ba);
            NETVAR(float       , m_flForceClientTime             , 0x16c0);
            NETVAR(int32_t     , lengthprop16                    , 0x0);
        };

        class DT_RopeKeyframe {
        public:
            NETVAR(int32_t     , m_iRopeMaterialModelIndex       , 0x16ec);
            NETVAR(int32_t     , m_hStartPoint                   , 0x19dc);
            NETVAR(int32_t     , m_hEndPoint                     , 0x19e0);
            NETVAR(int32_t     , m_iStartAttachment              , 0x19e4);
            NETVAR(int32_t     , m_iEndAttachment                , 0x19e6);
            NETVAR(int32_t     , m_iStartBone                    , 0x1a9a);
            NETVAR(int32_t     , m_iEndBone                      , 0x1a98);
            NETVAR(Vector3D    , m_vecStartOffset                , 0x1a9c);
            NETVAR(Vector3D    , m_vecEndOffset                  , 0x1aa8);
            NETVAR(int32_t     , m_clrRender                     , 0x90);
            NETVAR(int32_t     , m_fLockedPoints                 , 0x19f8);
            NETVAR(int32_t     , m_Slack                         , 0x19f0);
            NETVAR(int32_t     , m_RopeLength                    , 0x19ec);
            NETVAR(int32_t     , m_RopeFlags                     , 0x16e8);
            NETVAR(float       , m_TextureScale                  , 0x19f4);
            NETVAR(int32_t     , m_nSegments                     , 0x19d8);
            NETVAR(int32_t     , m_bConstrainBetweenEndpoints    , 0x1a90);
            NETVAR(int32_t     , m_Subdiv                        , 0x19e8);
            NETVAR(float       , m_Width                         , 0x19fc);
            NETVAR(float       , m_flScrollSpeed                 , 0x16e4);
            NETVAR(Vector3D    , m_vecOrigin                     , 0x438);
            NETVAR(int32_t     , moveparent                      , 0x21c);
            NETVAR(int32_t     , m_iParentAttachment             , 0x1fe);
        };

        class DT_RagdollManager {
        public:
            NETVAR(int32_t     , m_iCurrentMaxRagdollCount       , 0x16b0);
        };

        class DT_PhysicsPropMultiplayer {
        public:
            NETVAR(int32_t     , m_iPhysicsMode                  , 0x1bd8);
            NETVAR(float       , m_fMass                         , 0x1bdc);
            NETVAR(Vector3D    , m_collisionMins                 , 0x1be0);
            NETVAR(Vector3D    , m_collisionMaxs                 , 0x1bec);
        };

        class DT_PhysBoxMultiplayer {
        public:
            NETVAR(int32_t     , m_iPhysicsMode                  , 0x16c0);
            NETVAR(float       , m_fMass                         , 0x16c4);
        };

        class DT_PropDoorRotating {
        public:
        };

        class DT_BasePropDoor {
        public:
            NETVAR(int32_t     , m_bLocked                       , 0x1be9);
            NETVAR(int32_t     , m_eDoorState                    , 0x1bec);
        };

        class DT_DynamicProp {
        public:
            NETVAR(int32_t     , m_bUseHitboxesForRenderBox      , 0x1bc8);
        };

        class DT_PointCamera {
        public:
            NETVAR(float       , m_FOV                           , 0x16b0);
            NETVAR(float       , m_Resolution                    , 0x16b4);
            NETVAR(int32_t     , m_bFogEnable                    , 0x16b8);
            NETVAR(int32_t     , m_FogColor                      , 0x16b9);
            NETVAR(int32_t     , m_FogColorHDR                   , 0x16bd);
            NETVAR(float       , m_flFogStart                    , 0x16c4);
            NETVAR(float       , m_flFogEnd                      , 0x16c8);
            NETVAR(float       , m_flFogMaxDensity               , 0x16cc);
            NETVAR(int32_t     , m_bFogRadial                    , 0x16d0);
            NETVAR(int32_t     , m_bActive                       , 0x16d1);
            NETVAR(int32_t     , m_bUseScreenAspectRatio         , 0x16d2);
            NETVAR(int32_t     , m_bGlobalOverride               , 0x16d3);
        };

        class DT_PlayerResource {
        public:
        };

        class DT_Plasma {
        public:
            NETVAR(float       , m_flStartScale                  , 0x16b0);
            NETVAR(float       , m_flScale                       , 0x16b4);
            NETVAR(float       , m_flScaleTime                   , 0x16b8);
            NETVAR(int32_t     , m_nFlags                        , 0x16bc);
            NETVAR(int32_t     , m_nPlasmaModelIndex             , 0x16c0);
            NETVAR(int32_t     , m_nPlasmaModelIndex2            , 0x16c4);
            NETVAR(int32_t     , m_nGlowModelIndex               , 0x16c8);
        };

        class DT_PhysMagnet {
        public:
        };

        class DT_PhysicsProp {
        public:
            NETVAR(int32_t     , m_bAwake                        , 0x1bc8);
        };

        class DT_PhysBox {
        public:
            NETVAR(float       , m_mass                          , 0x16b0);
        };

        class DT_ParticleSystem {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x438);
            NETVAR(int32_t     , m_hOwnerEntity                  , 0x744);
            NETVAR(int32_t     , moveparent                      , 0x21c);
            NETVAR(int32_t     , m_iParentAttachment             , 0x1fe);
            NETVAR(Vector3D    , m_angRotation                   , 0x444);
            NETVAR(int32_t     , m_iEffectIndex                  , 0x16b0);
            NETVAR(int32_t     , m_bActive                       , 0x16b4);
            NETVAR(float       , m_flStartTime                   , 0x16b8);
            NETVAR(int32_t     , m_bWeatherEffect                , 0x17f7);
        };

        class DT_MaterialModifyControl {
        public:
            NETVAR(char*       , m_szMaterialName                , 0x16b0);
            NETVAR(char*       , m_szMaterialVar                 , 0x17af);
            NETVAR(char*       , m_szMaterialVarValue            , 0x18ae);
            NETVAR(int32_t     , m_iFrameStart                   , 0x19bc);
            NETVAR(int32_t     , m_iFrameEnd                     , 0x19c0);
            NETVAR(int32_t     , m_bWrap                         , 0x19c4);
            NETVAR(float       , m_flFramerate                   , 0x19c8);
            NETVAR(int32_t     , m_bNewAnimCommandsSemaphore     , 0x19cc);
            NETVAR(float       , m_flFloatLerpStartValue         , 0x19d0);
            NETVAR(float       , m_flFloatLerpEndValue           , 0x19d4);
            NETVAR(float       , m_flFloatLerpTransitionTime     , 0x19d8);
            NETVAR(int32_t     , m_bFloatLerpWrap                , 0x19dc);
            NETVAR(int32_t     , m_nModifyMode                   , 0x19e8);
        };

        class DT_LightGlow {
        public:
            NETVAR(int32_t     , m_clrRender                     , 0x90);
            NETVAR(int32_t     , m_nHorizontalSize               , 0x16b0);
            NETVAR(int32_t     , m_nVerticalSize                 , 0x16b4);
            NETVAR(int32_t     , m_nMinDist                      , 0x16b8);
            NETVAR(int32_t     , m_nMaxDist                      , 0x16bc);
            NETVAR(int32_t     , m_nOuterMaxDist                 , 0x16c0);
            NETVAR(int32_t     , m_spawnflags                    , 0x16c4);
            NETVAR(Vector3D    , m_vecOrigin                     , 0x438);
            NETVAR(Vector3D    , m_angRotation                   , 0x444);
            NETVAR(int32_t     , moveparent                      , 0x21c);
            NETVAR(float       , m_flGlowProxySize               , 0x17c0);
            NETVAR(float       , HDRColorScale                   , 0x0);
        };

        class DT_InfoOverlayAccessor {
        public:
            NETVAR(int32_t     , m_iTextureFrameIndex            , 0x738);
            NETVAR(int32_t     , m_iOverlayID                    , 0x16b0);
        };

        class DT_FuncTrackTrain {
        public:
        };

        class DT_FuncSmokeVolume {
        public:
            NETVAR(int32_t     , m_Color1                        , 0x17e8);
            NETVAR(int32_t     , m_Color2                        , 0x17ec);
            NETVAR(char*       , m_MaterialName                  , 0x17f0);
            NETVAR(float       , m_ParticleDrawWidth             , 0x18f0);
            NETVAR(float       , m_ParticleSpacingDistance       , 0x18f4);
            NETVAR(float       , m_DensityRampSpeed              , 0x18f8);
            NETVAR(float       , m_RotationSpeed                 , 0x18fc);
            NETVAR(float       , m_MovementSpeed                 , 0x1900);
            NETVAR(float       , m_Density                       , 0x1904);
            NETVAR(int32_t     , m_spawnflags                    , 0x1908);
            NETVAR(Vector3D    , m_vecMinsPreScaled              , 0x240);
            NETVAR(Vector3D    , m_vecMaxsPreScaled              , 0x24c);
            NETVAR(Vector3D    , m_vecMins                       , 0x258);
            NETVAR(Vector3D    , m_vecMaxs                       , 0x264);
            NETVAR(int32_t     , m_nSolidType                    , 0x279);
            NETVAR(int32_t     , m_usSolidFlags                  , 0x274);
            NETVAR(int32_t     , m_nSurroundType                 , 0x278);
            NETVAR(int32_t     , m_triggerBloat                  , 0x27a);
            NETVAR(Vector3D    , m_vecSpecifiedSurroundingMinsPreScaled, 0x27c);
            NETVAR(Vector3D    , m_vecSpecifiedSurroundingMaxsPreScaled, 0x288);
            NETVAR(Vector3D    , m_vecSpecifiedSurroundingMins   , 0x294);
            NETVAR(Vector3D    , m_vecSpecifiedSurroundingMaxs   , 0x2a0);
        };

        class DT_FuncRotating {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x438);
            NETVAR(float       , m_angRotation_0_                , 0x444);
            NETVAR(float       , m_angRotation_1_                , 0x448);
            NETVAR(float       , m_angRotation_2_                , 0x44c);
            NETVAR(int32_t     , m_flSimulationTime              , 0xb0);
        };

        class DT_FuncReflectiveGlass {
        public:
        };

        class DT_FuncOccluder {
        public:
            NETVAR(int32_t     , m_bActive                       , 0x16b4);
            NETVAR(int32_t     , m_nOccluderIndex                , 0x16b0);
        };

        class DT_FuncMonitor {
        public:
        };

        class DT_Func_LOD {
        public:
            NETVAR(float       , m_fDisappearMinDist             , 0x16b0);
            NETVAR(float       , m_fDisappearMaxDist             , 0x16b4);
        };

        class DT_TEDust {
        public:
            NETVAR(float       , m_flSize                        , 0x30);
            NETVAR(float       , m_flSpeed                       , 0x34);
            NETVAR(Vector3D    , m_vecDirection                  , 0x38);
        };

        class DT_Func_Dust {
        public:
            NETVAR(int32_t     , m_Color                         , 0x16b0);
            NETVAR(int32_t     , m_SpawnRate                     , 0x16b4);
            NETVAR(float       , m_flSizeMin                     , 0x16b8);
            NETVAR(float       , m_flSizeMax                     , 0x16bc);
            NETVAR(int32_t     , m_LifetimeMin                   , 0x16c4);
            NETVAR(int32_t     , m_LifetimeMax                   , 0x16c8);
            NETVAR(int32_t     , m_DustFlags                     , 0x16d8);
            NETVAR(int32_t     , m_SpeedMax                      , 0x16c0);
            NETVAR(int32_t     , m_DistMax                       , 0x16cc);
            NETVAR(int32_t     , m_nModelIndex                   , 0xd4);
            NETVAR(float       , m_FallSpeed                     , 0x16d0);
            NETVAR(int32_t     , m_bAffectedByWind               , 0x16d4);
            NETVAR(Vector3D    , m_vecMinsPreScaled              , 0x240);
            NETVAR(Vector3D    , m_vecMaxsPreScaled              , 0x24c);
            NETVAR(Vector3D    , m_vecMins                       , 0x258);
            NETVAR(Vector3D    , m_vecMaxs                       , 0x264);
            NETVAR(int32_t     , m_nSolidType                    , 0x279);
            NETVAR(int32_t     , m_usSolidFlags                  , 0x274);
            NETVAR(int32_t     , m_nSurroundType                 , 0x278);
            NETVAR(int32_t     , m_triggerBloat                  , 0x27a);
            NETVAR(Vector3D    , m_vecSpecifiedSurroundingMinsPreScaled, 0x27c);
            NETVAR(Vector3D    , m_vecSpecifiedSurroundingMaxsPreScaled, 0x288);
            NETVAR(Vector3D    , m_vecSpecifiedSurroundingMins   , 0x294);
            NETVAR(Vector3D    , m_vecSpecifiedSurroundingMaxs   , 0x2a0);
        };

        class DT_FuncConveyor {
        public:
            NETVAR(float       , m_flConveyorSpeed               , 0x16b0);
        };

        class DT_BreakableSurface {
        public:
            NETVAR(int32_t     , m_nNumWide                      , 0x16b8);
            NETVAR(int32_t     , m_nNumHigh                      , 0x16bc);
            NETVAR(float       , m_flPanelWidth                  , 0x16c0);
            NETVAR(float       , m_flPanelHeight                 , 0x16c4);
            NETVAR(Vector3D    , m_vNormal                       , 0x16c8);
            NETVAR(Vector3D    , m_vCorner                       , 0x16d4);
            NETVAR(int32_t     , m_bIsBroken                     , 0x16e0);
            NETVAR(int32_t     , m_nSurfaceType                  , 0x16e4);
        };

        class DT_FuncAreaPortalWindow {
        public:
            NETVAR(float       , m_flFadeStartDist               , 0x16b0);
            NETVAR(float       , m_flFadeDist                    , 0x16b4);
            NETVAR(float       , m_flTranslucencyLimit           , 0x16b8);
            NETVAR(int32_t     , m_iBackgroundModelIndex         , 0x16bc);
        };

        class DT_CFish {
        public:
            NETVAR(Vector3D    , m_poolOrigin                    , 0x1c24);
            NETVAR(float       , m_x                             , 0x1c0c);
            NETVAR(float       , m_y                             , 0x1c10);
            NETVAR(float       , m_z                             , 0x1c14);
            NETVAR(float       , m_angle                         , 0x1c1c);
            NETVAR(int32_t     , m_nModelIndex                   , 0xd4);
            NETVAR(int32_t     , m_lifeState                     , 0xd7);
            NETVAR(float       , m_waterLevel                    , 0x1c30);
        };

        class DT_EntityFlame {
        public:
            NETVAR(int32_t     , m_hEntAttached                  , 0x16b8);
        };

        class DT_FireSmoke {
        public:
            NETVAR(float       , m_flStartScale                  , 0x16b0);
            NETVAR(float       , m_flScale                       , 0x16b4);
            NETVAR(float       , m_flScaleTime                   , 0x16b8);
            NETVAR(int32_t     , m_nFlags                        , 0x16bc);
            NETVAR(int32_t     , m_nFlameModelIndex              , 0x16c0);
            NETVAR(int32_t     , m_nFlameFromAboveModelIndex     , 0x16c4);
        };

        class DT_EnvTonemapController {
        public:
            NETVAR(int32_t     , m_bUseCustomAutoExposureMin     , 0x16b0);
            NETVAR(int32_t     , m_bUseCustomAutoExposureMax     , 0x16b1);
            NETVAR(int32_t     , m_bUseCustomBloomScale          , 0x16b2);
            NETVAR(float       , m_flCustomAutoExposureMin       , 0x16b4);
            NETVAR(float       , m_flCustomAutoExposureMax       , 0x16b8);
            NETVAR(float       , m_flCustomBloomScale            , 0x16bc);
            NETVAR(float       , m_flCustomBloomScaleMinimum     , 0x16c0);
        };

        class DT_EnvScreenEffect {
        public:
            NETVAR(float       , m_flDuration                    , 0x16b0);
            NETVAR(int32_t     , m_nType                         , 0x16b4);
        };

        class DT_EnvScreenOverlay {
        public:
            NETVAR(char*       , m_iszOverlayNames_0_            , 0x16b0);
            NETVAR(uintptr_t   , m_iszOverlayNames               , 0x0);
            NETVAR(float       , m_flOverlayTimes_0_             , 0x20a8);
            NETVAR(uintptr_t   , m_flOverlayTimes                , 0x0);
            NETVAR(float       , m_flStartTime                   , 0x20d0);
            NETVAR(int32_t     , m_iDesiredOverlay               , 0x20d4);
            NETVAR(int32_t     , m_bIsActive                     , 0x20d8);
        };

        class DT_EnvProjectedTexture {
        public:
            NETVAR(int32_t     , m_hTargetEntity                 , 0x16b4);
            NETVAR(int32_t     , m_bState                        , 0x16b8);
            NETVAR(float       , m_flLightFOV                    , 0x16bc);
            NETVAR(int32_t     , m_bEnableShadows                , 0x16c0);
            NETVAR(int32_t     , m_bLightOnlyTarget              , 0x16c1);
            NETVAR(int32_t     , m_bLightWorld                   , 0x16c2);
            NETVAR(int32_t     , m_bCameraSpace                  , 0x16c3);
            NETVAR(Vector3D    , m_LinearFloatLightColor         , 0x16c4);
            NETVAR(char*       , m_SpotlightTextureName          , 0x16d8);
            NETVAR(int32_t     , m_nSpotlightTextureFrame        , 0x17dc);
            NETVAR(float       , m_flNearZ                       , 0x16d0);
            NETVAR(float       , m_flFarZ                        , 0x16d4);
            NETVAR(int32_t     , m_nShadowQuality                , 0x17e0);
            NETVAR(int32_t     , m_iStyle                        , 0x17e8);
        };

        class DT_EnvParticleScript {
        public:
            NETVAR(float       , m_flSequenceScale               , 0x1cf8);
        };

        class DT_FogController {
        public:
            NETVAR(int32_t     , m_fog_enable                    , 0x1700);
            NETVAR(int32_t     , m_fog_blend                     , 0x1701);
            NETVAR(int32_t     , m_fog_radial                    , 0x1702);
            NETVAR(Vector3D    , m_fog_dirPrimary                , 0x16b8);
            NETVAR(int32_t     , m_fog_colorPrimary              , 0x16c4);
            NETVAR(int32_t     , m_fog_colorSecondary            , 0x16c8);
            NETVAR(int32_t     , m_fog_colorPrimaryHDR           , 0x16cc);
            NETVAR(int32_t     , m_fog_colorSecondaryHDR         , 0x16d0);
            NETVAR(float       , m_fog_start                     , 0x16dc);
            NETVAR(float       , m_fog_end                       , 0x16e0);
            NETVAR(float       , m_fog_farz                      , 0x16e4);
            NETVAR(float       , m_fog_maxdensity                , 0x16e8);
            NETVAR(int32_t     , m_fog_colorPrimaryLerpTo        , 0x16d4);
            NETVAR(int32_t     , m_fog_colorSecondaryLerpTo      , 0x16d8);
            NETVAR(float       , m_fog_startLerpTo               , 0x16ec);
            NETVAR(float       , m_fog_endLerpTo                 , 0x16f0);
            NETVAR(float       , m_fog_maxdensityLerpTo          , 0x16f4);
            NETVAR(float       , m_fog_lerptime                  , 0x16f8);
            NETVAR(float       , m_fog_duration                  , 0x16fc);
            NETVAR(float       , m_fog_HDRColorScale             , 0x1704);
        };

        class DT_EntityParticleTrail {
        public:
            NETVAR(int32_t     , m_iMaterialName                 , 0x17e0);
            NETVAR(float       , m_flLifetime                    , 0x17f8);
            NETVAR(float       , m_flStartSize                   , 0x17fc);
            NETVAR(float       , m_flEndSize                     , 0x1800);
            NETVAR(int32_t     , m_hConstraintEntity             , 0x1808);
        };

        class DT_EntityDissolve {
        public:
            NETVAR(float       , m_flStartTime                   , 0x16b8);
            NETVAR(float       , m_flFadeOutStart                , 0x16bc);
            NETVAR(float       , m_flFadeOutLength               , 0x16c0);
            NETVAR(float       , m_flFadeOutModelStart           , 0x16c4);
            NETVAR(float       , m_flFadeOutModelLength          , 0x16c8);
            NETVAR(float       , m_flFadeInStart                 , 0x16cc);
            NETVAR(float       , m_flFadeInLength                , 0x16d0);
            NETVAR(int32_t     , m_nDissolveType                 , 0x16d4);
            NETVAR(Vector3D    , m_vDissolverOrigin              , 0x16e8);
            NETVAR(int32_t     , m_nMagnitude                    , 0x16f4);
        };

        class DT_DynamicLight {
        public:
            NETVAR(int32_t     , m_Flags                         , 0x16b0);
            NETVAR(int32_t     , m_LightStyle                    , 0x16b1);
            NETVAR(float       , m_Radius                        , 0x16b4);
            NETVAR(int32_t     , m_Exponent                      , 0x16b8);
            NETVAR(float       , m_InnerAngle                    , 0x16bc);
            NETVAR(float       , m_OuterAngle                    , 0x16c0);
            NETVAR(float       , m_SpotRadius                    , 0x16c4);
        };

        class DT_ColorCorrectionVolume {
        public:
            NETVAR(int32_t     , m_bEnabled                      , 0x16f8);
            NETVAR(float       , m_MaxWeight                     , 0x16fc);
            NETVAR(float       , m_FadeDuration                  , 0x1700);
            NETVAR(float       , m_Weight                        , 0x1704);
            NETVAR(char*       , m_lookupFilename                , 0x1708);
            NETVAR(int32_t     , m_nModelIndex                   , 0xd4);
        };

        class DT_ColorCorrection {
        public:
            NETVAR(Vector3D    , m_vecOrigin                     , 0x16b0);
            NETVAR(float       , m_minFalloff                    , 0x16bc);
            NETVAR(float       , m_maxFalloff                    , 0x16c0);
            NETVAR(float       , m_flCurWeight                   , 0x16d0);
            NETVAR(float       , m_flMaxWeight                   , 0x16cc);
            NETVAR(float       , m_flFadeInDuration              , 0x16c4);
            NETVAR(float       , m_flFadeOutDuration             , 0x16c8);
            NETVAR(char*       , m_netLookupFilename             , 0x16d4);
            NETVAR(int32_t     , m_bEnabled                      , 0x17d8);
            NETVAR(int32_t     , m_bClientSide                   , 0x17d9);
            NETVAR(int32_t     , m_bExclusive                    , 0x17da);
        };

        class DT_BreakableProp {
        public:
        };

        class DT_BasePlayer {
        public:
            NETVAR(int32_t     , deadflag                        , 0x2c08);
            NETVAR(int32_t     , m_hVehicle                      , 0x2c98);
            NETVAR(int32_t     , m_hUseEntity                    , 0x2ca0);
            NETVAR(int32_t     , m_lifeState                     , 0xd7);
            NETVAR(int32_t     , m_hColorCorrectionCtrl          , 0x34f0);
            NETVAR(float       , m_flMaxspeed                    , 0x2ca4);
            NETVAR(int32_t     , m_fFlags                        , 0x450);
            NETVAR(int32_t     , m_iObserverMode                 , 0x2c6c);
            NETVAR(int32_t     , m_hObserverTarget               , 0x2c70);
            NETVAR(float       , m_iFOV                          , 0x2c18);
            NETVAR(float       , m_iFOVStart                     , 0x2c1c);
            NETVAR(float       , m_flFOVTime                     , 0x2c20);
            NETVAR(float       , m_iDefaultFOV                   , 0x2c28);
            NETVAR(int32_t     , m_hZoomOwner                    , 0x2c2c);
            NETVAR(int32_t     , m_hViewModel_0_                 , 0x2d70);
            NETVAR(uintptr_t   , m_hViewModel                    , 0x0);
            NETVAR(int32_t     , m_bUseWeaponsInVehicle          , 0x2d3b);
            NETVAR(int32_t     , m_iHideHUD                      , 0x29c8);
            NETVAR(float       , m_flFOVRate                     , 0x29cc);
            NETVAR(int32_t     , m_bDucked                       , 0x29d0);
            NETVAR(int32_t     , m_bDucking                      , 0x29d1);
            NETVAR(int32_t     , m_bInDuckJump                   , 0x29d2);
            NETVAR(float       , m_flDucktime                    , 0x29d4);
            NETVAR(float       , m_flDuckJumpTime                , 0x29d8);
            NETVAR(float       , m_flJumpTime                    , 0x29dc);
            NETVAR(float       , m_flFallVelocity                , 0x29e4);
            NETVAR(Vector3D    , m_vecPunchAngle                 , 0x29f8);
            NETVAR(Vector3D    , m_vecPunchAngleVel              , 0x2a58);
            NETVAR(int32_t     , m_bDrawViewmodel                , 0x2ab8);
            NETVAR(int32_t     , m_bWearingSuit                  , 0x2ab9);
            NETVAR(int32_t     , m_bPoisoned                     , 0x2aba);
            NETVAR(float       , m_flStepSize                    , 0x2abc);
            NETVAR(int32_t     , m_bAllowAutoMovement            , 0x2abb);
            NETVAR(int32_t     , m_skybox3d_scale                , 0x2ac8);
            NETVAR(Vector3D    , m_skybox3d_origin               , 0x2acc);
            NETVAR(int32_t     , m_skybox3d_area                 , 0x2ad8);
            NETVAR(int32_t     , m_skybox3d_fog_enable           , 0x2b30);
            NETVAR(int32_t     , m_skybox3d_fog_blend            , 0x2b31);
            NETVAR(int32_t     , m_skybox3d_fog_radial           , 0x2b32);
            NETVAR(Vector3D    , m_skybox3d_fog_dirPrimary       , 0x2ae8);
            NETVAR(int32_t     , m_skybox3d_fog_colorPrimary     , 0x2af4);
            NETVAR(int32_t     , m_skybox3d_fog_colorSecondary   , 0x2af8);
            NETVAR(int32_t     , m_skybox3d_fog_colorPrimaryHDR  , 0x2afc);
            NETVAR(int32_t     , m_skybox3d_fog_colorSecondaryHDR, 0x2b00);
            NETVAR(float       , m_skybox3d_fog_start            , 0x2b0c);
            NETVAR(float       , m_skybox3d_fog_end              , 0x2b10);
            NETVAR(float       , m_skybox3d_fog_maxdensity       , 0x2b18);
            NETVAR(float       , m_skybox3d_fog_HDRColorScale    , 0x2b34);
            NETVAR(int32_t     , m_PlayerFog_m_hCtrl             , 0x2b40);
            NETVAR(Vector3D    , m_audio_localSound_0_           , 0x2b68);
            NETVAR(Vector3D    , m_audio_localSound_1_           , 0x2b74);
            NETVAR(Vector3D    , m_audio_localSound_2_           , 0x2b80);
            NETVAR(Vector3D    , m_audio_localSound_3_           , 0x2b8c);
            NETVAR(Vector3D    , m_audio_localSound_4_           , 0x2b98);
            NETVAR(Vector3D    , m_audio_localSound_5_           , 0x2ba4);
            NETVAR(Vector3D    , m_audio_localSound_6_           , 0x2bb0);
            NETVAR(Vector3D    , m_audio_localSound_7_           , 0x2bbc);
            NETVAR(int32_t     , m_audio_soundscapeIndex         , 0x2bc8);
            NETVAR(int32_t     , m_audio_localBits               , 0x2bcc);
            NETVAR(int32_t     , m_audio_ent                     , 0x2bd0);
            NETVAR(float       , m_fSprintSpeed                  , 0x2bdc);
            NETVAR(float       , m_fWalkSpeed                    , 0x2be0);
            NETVAR(float       , m_fSlowWalkSpeed                , 0x2be4);
            NETVAR(float       , m_fLadderSpeed                  , 0x2be8);
            NETVAR(float       , m_fCrouchedWalkSpeed            , 0x2bec);
            NETVAR(float       , m_fDuckSpeed                    , 0x2bf0);
            NETVAR(float       , m_fUnDuckSpeed                  , 0x2bf4);
            NETVAR(int32_t     , m_bDuckToggled                  , 0x2bd9);
            NETVAR(float       , m_vecViewOffset_0_              , 0x144);
            NETVAR(float       , m_vecViewOffset_1_              , 0x148);
            NETVAR(float       , m_vecViewOffset_2_              , 0x14c);
            NETVAR(float       , m_flFriction                    , 0x318);
            NETVAR(int32_t     , m_nTickBase                     , 0x2d28);
            NETVAR(int32_t     , m_nNextThinkTick                , 0xcc);
            NETVAR(int32_t     , m_hLastWeapon                   , 0x2d48);
            NETVAR(int32_t     , m_hGroundEntity                 , 0x30c);
            NETVAR(Vector3D    , m_vecBaseVelocity               , 0x1d8);
            NETVAR(int32_t     , m_hConstraintEntity             , 0x2c50);
            NETVAR(Vector3D    , m_vecConstraintCenter           , 0x2c54);
            NETVAR(float       , m_flConstraintRadius            , 0x2c60);
            NETVAR(float       , m_flConstraintWidth             , 0x2c64);
            NETVAR(float       , m_flConstraintSpeedFactor       , 0x2c68);
            NETVAR(float       , m_flDeathTime                   , 0x2c94);
            NETVAR(float       , m_flLaggedMovementValue         , 0x3318);
            NETVAR(int32_t     , m_hTonemapController            , 0x2bf8);
            NETVAR(int32_t     , m_hViewEntity                   , 0x3514);
            NETVAR(int32_t     , m_bDisableWorldClicking         , 0x3505);
        };

        class DT_BaseFlex {
        public:
            NETVAR(int32_t     , m_blinktoggle                   , 0x1e88);
            NETVAR(Vector3D    , m_viewtarget                    , 0x1c58);
            NETVAR(float       , m_vecViewOffset_0_              , 0x144);
            NETVAR(float       , m_vecViewOffset_1_              , 0x148);
            NETVAR(float       , m_vecViewOffset_2_              , 0x14c);
            NETVAR(Vector3D    , m_vecLean                       , 0x2048);
            NETVAR(Vector3D    , m_vecShift                      , 0x20a8);
        };

        class DT_BaseEntity {
        public:
            NETVAR(int32_t     , m_flAnimTime                    , 0xa0);
            NETVAR(int32_t     , m_flSimulationTime              , 0xb0);
            NETVAR(int32_t     , m_ubInterpolationFrame          , 0xc0);
            NETVAR(Vector3D    , m_vecOrigin                     , 0x438);
            NETVAR(Vector3D    , m_angRotation                   , 0x444);
            NETVAR(int32_t     , m_nModelIndex                   , 0xd4);
            NETVAR(int32_t     , m_fEffects                      , 0xc4);
            NETVAR(int32_t     , m_nRenderMode                   , 0xc2);
            NETVAR(int32_t     , m_nRenderFX                     , 0x8c);
            NETVAR(int32_t     , m_clrRender                     , 0x90);
            NETVAR(int32_t     , m_iTeamNum                      , 0xe4);
            NETVAR(int32_t     , m_CollisionGroup                , 0x454);
            NETVAR(float       , m_flElasticity                  , 0x300);
            NETVAR(float       , m_flShadowCastDistance          , 0x304);
            NETVAR(int32_t     , m_hOwnerEntity                  , 0x744);
            NETVAR(int32_t     , m_hEffectEntity                 , 0x748);
            NETVAR(int32_t     , moveparent                      , 0x21c);
            NETVAR(int32_t     , m_iParentAttachment             , 0x1fe);
            NETVAR(int32_t     , movetype                        , 0x0);
            NETVAR(int32_t     , movecollide                     , 0x0);
            NETVAR(Vector3D    , m_vecMinsPreScaled              , 0x240);
            NETVAR(Vector3D    , m_vecMaxsPreScaled              , 0x24c);
            NETVAR(Vector3D    , m_vecMins                       , 0x258);
            NETVAR(Vector3D    , m_vecMaxs                       , 0x264);
            NETVAR(int32_t     , m_nSolidType                    , 0x279);
            NETVAR(int32_t     , m_usSolidFlags                  , 0x274);
            NETVAR(int32_t     , m_nSurroundType                 , 0x278);
            NETVAR(int32_t     , m_triggerBloat                  , 0x27a);
            NETVAR(Vector3D    , m_vecSpecifiedSurroundingMinsPreScaled, 0x27c);
            NETVAR(Vector3D    , m_vecSpecifiedSurroundingMaxsPreScaled, 0x288);
            NETVAR(Vector3D    , m_vecSpecifiedSurroundingMins   , 0x294);
            NETVAR(Vector3D    , m_vecSpecifiedSurroundingMaxs   , 0x2a0);
            NETVAR(int32_t     , m_iTextureFrameIndex            , 0x738);
            NETVAR(int32_t     , m_PredictableID                 , 0xe8);
            NETVAR(int32_t     , m_bIsPlayerSimulated            , 0x734);
            NETVAR(int32_t     , m_bSimulatedEveryTick           , 0x735);
            NETVAR(int32_t     , m_bAnimatedEveryTick            , 0x736);
            NETVAR(int32_t     , m_bAlternateSorting             , 0x737);
            NETVAR(int32_t     , m_takedamage                    , 0xd6);
            NETVAR(int32_t     , m_RealClassName                 , 0x780);
            NETVAR(int32_t     , m_OverrideMaterial              , 0x784);
            NETVAR(int32_t     , m_OverrideSubMaterials_0_       , 0x790);
            NETVAR(uintptr_t   , m_OverrideSubMaterials          , 0x0);
            NETVAR(int32_t     , m_iHealth                       , 0xd8);
            NETVAR(int32_t     , m_iMaxHealth                    , 0xdc);
            NETVAR(int32_t     , m_spawnflags                    , 0x92c);
            NETVAR(int32_t     , m_iGModFlags                    , 0x930);
            NETVAR(int32_t     , m_bOnFire                       , 0x77a);
            NETVAR(float       , m_CreationTime                  , 0x77c);
            NETVAR(float       , m_vecVelocity_0_                , 0x150);
            NETVAR(float       , m_vecVelocity_1_                , 0x154);
            NETVAR(float       , m_vecVelocity_2_                , 0x158);
            NETVAR(int64_t     , m_GMOD_DataTable                , 0x1638);
            NETVAR(char*       , m_GMOD_String0                  , 0xe38);
            NETVAR(char*       , m_GMOD_String1                  , 0x1038);
            NETVAR(char*       , m_GMOD_String2                  , 0x1238);
            NETVAR(char*       , m_GMOD_String3                  , 0x1438);
            NETVAR(int32_t     , m_iCreationID                   , 0x16a4);
            NETVAR(int32_t     , m_iMapCreatedID                 , 0x16a8);
        };

        class DT_BaseDoor {
        public:
        };

        class DT_BaseCombatCharacter {
        public:
            NETVAR(float       , m_flNextAttack                  , 0x2110);
            NETVAR(int32_t     , m_hActiveWeapon                 , 0x291c);
            NETVAR(int32_t     , m_bloodColor                    , 0x2118);
        };

        class DT_BaseAnimatingOverlay {
        public:
            NETVAR(int32_t     , lengthprop15                    , 0x0);
        };

        class DT_BoneFollower {
        public:
            NETVAR(int32_t     , m_modelIndex                    , 0x16b0);
            NETVAR(int32_t     , m_solidIndex                    , 0x16b4);
        };

        class DT_BaseAnimating {
        public:
            NETVAR(int32_t     , m_nSequence                     , 0x19ec);
            NETVAR(int32_t     , m_nForceBone                    , 0x1714);
            NETVAR(Vector3D    , m_vecForce                      , 0x1708);
            NETVAR(int32_t     , m_nSkin                         , 0x16c0);
            NETVAR(int32_t     , m_nBody                         , 0x16c4);
            NETVAR(int32_t     , m_nHitboxSet                    , 0x16c8);
            NETVAR(float       , m_flModelScale                  , 0x1800);
            NETVAR(float       , m_flModelWidthScale             , 0x1800);
            NETVAR(float       , m_flPlaybackRate                , 0x16fc);
            NETVAR(int32_t     , m_bClientSideAnimation          , 0x19e9);
            NETVAR(int32_t     , m_bClientSideFrameReset         , 0x17a6);
            NETVAR(int32_t     , m_nNewSequenceParity            , 0x19c0);
            NETVAR(int32_t     , m_nResetEventsParity            , 0x19c4);
            NETVAR(int32_t     , m_nMuzzleFlashParity            , 0x1ac8);
            NETVAR(int32_t     , m_hLightingOrigin               , 0x1ac0);
            NETVAR(int32_t     , m_hLightingOriginRelative       , 0x1ac4);
            NETVAR(float       , m_flCycle                       , 0x19f0);
            NETVAR(float       , m_fadeMinDist                   , 0x1790);
            NETVAR(float       , m_fadeMaxDist                   , 0x1794);
            NETVAR(float       , m_flFadeScale                   , 0x1798);
            NETVAR(int32_t     , m_pBoneManipulator              , 0x1b74);
            NETVAR(int32_t     , m_pFlexManipulator              , 0x1b7c);
            NETVAR(Vector3D    , m_OverrideViewTarget            , 0x1ae8);
        };

        class DT_InfoLightingRelative {
        public:
            NETVAR(int32_t     , m_hLightingLandmark             , 0x16b0);
        };

        class DT_AI_BaseNPC {
        public:
            NETVAR(int32_t     , m_lifeState                     , 0xd7);
            NETVAR(int32_t     , m_bPerformAvoidance             , 0x2928);
            NETVAR(int32_t     , m_bIsMoving                     , 0x2929);
            NETVAR(int32_t     , m_bFadeCorpse                   , 0x292a);
            NETVAR(int32_t     , m_iDeathPose                    , 0x2920);
            NETVAR(int32_t     , m_iDeathFrame                   , 0x2924);
            NETVAR(int32_t     , m_bImportanRagdoll              , 0x292b);
        };

        class DT_Beam {
        public:
            NETVAR(int32_t     , m_nBeamType                     , 0x16d0);
            NETVAR(int32_t     , m_nBeamFlags                    , 0x16d4);
            NETVAR(int32_t     , m_nNumBeamEnts                  , 0x16c4);
            NETVAR(int32_t     , m_nHaloIndex                    , 0x16cc);
            NETVAR(float       , m_fHaloScale                    , 0x1734);
            NETVAR(float       , m_fWidth                        , 0x1728);
            NETVAR(float       , m_fEndWidth                     , 0x172c);
            NETVAR(float       , m_fFadeLength                   , 0x1730);
            NETVAR(float       , m_fAmplitude                    , 0x1738);
            NETVAR(float       , m_fStartFrame                   , 0x173c);
            NETVAR(float       , m_fSpeed                        , 0x1740);
            NETVAR(float       , m_flFrameRate                   , 0x16b0);
            NETVAR(float       , m_flHDRColorScale               , 0x16b4);
            NETVAR(int32_t     , m_clrRender                     , 0x90);
            NETVAR(int32_t     , m_nRenderFX                     , 0x8c);
            NETVAR(int32_t     , m_nRenderMode                   , 0xc2);
            NETVAR(float       , m_flFrame                       , 0x1748);
            NETVAR(Vector3D    , m_vecEndPos                     , 0x174c);
            NETVAR(int32_t     , m_nModelIndex                   , 0xd4);
            NETVAR(int32_t     , m_nMinDXLevel                   , 0x1744);
            NETVAR(Vector3D    , m_vecOrigin                     , 0x438);
            NETVAR(int32_t     , moveparent                      , 0x21c);
            NETVAR(int32_t     , m_PredictableID                 , 0xe8);
            NETVAR(int32_t     , m_bIsPlayerSimulated            , 0x734);
        };

        class DT_BaseViewModel {
        public:
            NETVAR(int32_t     , m_nModelIndex                   , 0xd4);
            NETVAR(int32_t     , m_nSkin                         , 0x16c0);
            NETVAR(int32_t     , m_nBody                         , 0x16c4);
            NETVAR(int32_t     , m_nSequence                     , 0x19ec);
            NETVAR(int32_t     , m_nViewModelIndex               , 0x1bdc);
            NETVAR(float       , m_flPlaybackRate                , 0x16fc);
            NETVAR(int32_t     , m_fEffects                      , 0xc4);
            NETVAR(int32_t     , m_nAnimationParity              , 0x1bf4);
            NETVAR(int32_t     , m_hWeapon                       , 0x1c04);
            NETVAR(int32_t     , m_hOwner                        , 0x1be0);
            NETVAR(int32_t     , m_nNewSequenceParity            , 0x19c0);
            NETVAR(int32_t     , m_nResetEventsParity            , 0x19c4);
            NETVAR(int32_t     , m_nMuzzleFlashParity            , 0x1ac8);
            NETVAR(float       , m_flPoseParameter_0_            , 0x1804);
            NETVAR(uintptr_t   , m_flPoseParameter               , 0x0);
        };

        class DT_BaseParticleEntity {
        public:
        };

        class DT_BaseGrenade {
        public:
            NETVAR(float       , m_flDamage                      , 0x1be8);
            NETVAR(float       , m_DmgRadius                     , 0x1bcc);
            NETVAR(int32_t     , m_bIsLive                       , 0x1bc9);
            NETVAR(int32_t     , m_hThrower                      , 0x1bfc);
            NETVAR(Vector3D    , m_vecVelocity                   , 0x150);
            NETVAR(int32_t     , m_fFlags                        , 0x450);
        };

        class DT_BaseCombatWeapon {
        public:
            NETVAR(int32_t     , m_iClip1                        , 0x1c28);
            NETVAR(int32_t     , m_iClip2                        , 0x1c2c);
            NETVAR(int32_t     , m_iPrimaryAmmoType              , 0x1c20);
            NETVAR(int32_t     , m_iSecondaryAmmoType            , 0x1c24);
            NETVAR(int32_t     , m_nViewModelIndex               , 0x1bd0);
            NETVAR(int32_t     , m_bFlipViewModel                , 0x1c30);
            NETVAR(float       , m_flNextPrimaryAttack           , 0x1bd8);
            NETVAR(float       , m_flNextSecondaryAttack         , 0x1be0);
            NETVAR(int32_t     , m_nNextThinkTick                , 0xcc);
            NETVAR(float       , m_flTimeWeaponIdle              , 0x1be8);
            NETVAR(int32_t     , m_iViewModelIndex               , 0x1bf0);
            NETVAR(int32_t     , m_iWorldModelIndex              , 0x1bf4);
            NETVAR(int32_t     , m_iState                        , 0x1c14);
            NETVAR(int32_t     , m_hOwner                        , 0x1bc8);
        };

        class DT_WeaponPhysGun {
        public:
            NETVAR(int32_t     , m_hPhysBeam                     , 0x1cac);
            NETVAR(Vector3D    , m_vHitPosLocal                  , 0x1cb0);
            NETVAR(int32_t     , m_hGrabbedEntity                , 0x1ca8);
        };

        class DT_PhysBeam {
        public:
            NETVAR(int32_t     , m_hTargetEnt                    , 0x16e0);
            NETVAR(Vector3D    , m_HoldPos                       , 0x16d4);
            NETVAR(int32_t     , m_bIsOn                         , 0x16e4);
            NETVAR(int32_t     , m_iPhysBone                     , 0x16d0);
        };

        class DT_LuaNextBot {
        public:
            NETVAR(char*       , m_strScriptName                 , 0x2958);
            NETVAR(int32_t     , m_lifeState                     , 0xd7);
        };

        class DT_FlexManipulate {
        public:
            NETVAR(float       , m_flexScale                     , 0x1830);
            NETVAR(Vector3D    , m_EyesLocalTarget               , 0x1834);
        };

        class DT_BoneManipulate {
        public:
        };

        class DT_WeaponSWEP {
        public:
            NETVAR(char*       , m_strScriptName                 , 0x1cc0);
            NETVAR(char*       , m_strHoldType                   , 0x1e20);
        };

        class DT_SENT_point {
        public:
            NETVAR(char*       , m_strScriptName                 , 0x16c8);
        };

        class DT_SENT_anim {
        public:
            NETVAR(char*       , m_strScriptName                 , 0x1c70);
        };

        class DT_SENT_AI {
        public:
            NETVAR(char*       , m_strScriptName                 , 0x2948);
        };

        class DT_GMODGameRulesProxy {
        public:
            NETVAR(float       , m_fTimeScale                    , 0x40);
            NETVAR(int32_t     , m_iSkillLevel                   , 0x44);
        };

        class DT_NextBot {
        public:
        };

        class DT_GMOD_Player {
        public:
            NETVAR(int32_t     , m_iGModPlayerFlags              , 0x36b0);
            NETVAR(int32_t     , m_HoveredWidget                 , 0x3878);
            NETVAR(int32_t     , m_PressedWidget                 , 0x387c);
            NETVAR(int32_t     , m_Driving                       , 0x3880);
            NETVAR(int32_t     , m_DrivingMode                   , 0x3884);
            NETVAR(int32_t     , m_PlayerClass                   , 0x388c);
            NETVAR(int32_t     , m_bCanZoom                      , 0x38ad);
            NETVAR(int32_t     , m_bCanWalk                      , 0x38ae);
            NETVAR(int32_t     , m_bIsTyping                     , 0x38af);
            NETVAR(float       , m_StepSize                      , 0x38b0);
            NETVAR(float       , m_JumpPower                     , 0x38b4);
            NETVAR(Vector3D    , m_ViewOffset                    , 0x38b8);
            NETVAR(Vector3D    , m_ViewOffsetDucked              , 0x38c4);
            NETVAR(float       , m_fGestureEndTime               , 0x38d0);
            NETVAR(Vector3D    , m_PlayerColor                   , 0x3894);
            NETVAR(Vector3D    , m_WeaponColor                   , 0x38a0);
            NETVAR(int32_t     , m_Hands                         , 0x3888);
            NETVAR(int32_t     , m_nWaterLevel                   , 0x200);
            NETVAR(int32_t     , m_iMaxArmor                     , 0x3890);
            NETVAR(float       , m_flGravity                     , 0x1e4);
            NETVAR(int32_t     , m_bSprintEnabled                , 0x38ac);
        };

        class DT_FleshEffectTarget {
        public:
            NETVAR(float       , m_flRadius                      , 0x16b0);
            NETVAR(float       , m_flScaleTime                   , 0x16bc);
        };

        class DT_CPropJeepEpisodic {
        public:
            NETVAR(int32_t     , m_iNumRadarContacts             , 0x1d50);
            NETVAR(Vector3D    , m_vecRadarContactPos_0_         , 0x1d54);
            NETVAR(uintptr_t   , m_vecRadarContactPos            , 0x0);
            NETVAR(int32_t     , m_iRadarContactType_0_          , 0x1e74);
            NETVAR(uintptr_t   , m_iRadarContactType             , 0x0);
        };

        class DT_PropScalable {
        public:
            NETVAR(float       , m_flScaleX                      , 0x1bc8);
            NETVAR(float       , m_flScaleY                      , 0x1bcc);
            NETVAR(float       , m_flScaleZ                      , 0x1bd0);
            NETVAR(float       , m_flLerpTimeX                   , 0x1bd4);
            NETVAR(float       , m_flLerpTimeY                   , 0x1bd8);
            NETVAR(float       , m_flLerpTimeZ                   , 0x1bdc);
            NETVAR(float       , m_flGoalTimeX                   , 0x1be0);
            NETVAR(float       , m_flGoalTimeY                   , 0x1be4);
            NETVAR(float       , m_flGoalTimeZ                   , 0x1be8);
        };

        class DT_NPC_Puppet {
        public:
            NETVAR(int32_t     , m_hAnimationTarget              , 0x2930);
            NETVAR(int32_t     , m_nTargetAttachment             , 0x2934);
        };

    }
}
