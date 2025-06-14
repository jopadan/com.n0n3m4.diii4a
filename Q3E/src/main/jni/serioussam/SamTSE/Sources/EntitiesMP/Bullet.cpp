/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 17 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"

#include "EntitiesMP/StdH/StdH.h"

#include <EntitiesMP/Bullet.h>
#include <EntitiesMP/Bullet_tables.h>
CEntityEvent *EBulletInit::MakeCopy(void) { CEntityEvent *peeCopy = new EBulletInit(*this); return peeCopy;}
EBulletInit::EBulletInit() : CEntityEvent(EVENTCODE_EBulletInit) {;
 ClearToDefault(penOwner);
 ClearToDefault(fDamage);
};
#line 31 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"

void CBullet_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) 
{
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETSTAINSTONE);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETSTAINSAND);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETSTAINREDSAND);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETSTAINWATER);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETSTAINSTONENOSOUND);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETSTAINSANDNOSOUND);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETSTAINREDSANDNOSOUND);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETSTAINWATERNOSOUND);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BLOODSPILL);
  pdec->PrecacheClass(CLASS_BASIC_EFFECT, BET_BULLETTRAIL);
}

void CBullet::SetDefaultProperties(void) {
  m_penOwner = NULL;
  m_fDamage = 0.0f;
  m_vTarget = FLOAT3D(0 , 0 , 0);
  m_vTargetCopy = FLOAT3D(0 , 0 , 0);
  m_vHitPoint = FLOAT3D(0 , 0 , 0);
  m_iBullet = 0;
  m_EdtDamage = DMT_BULLET ;
  m_fBulletSize = 0.0f;
  CEntity::SetDefaultProperties();
}
  
#line 71 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
void CBullet::SetDamage(FLOAT fDamage) {
#line 72 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
m_fDamage  = fDamage ;
#line 73 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
  
#line 76 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
void CBullet::CalcTarget(FLOAT fRange) {
#line 78 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
AnglesToDirectionVector  (GetPlacement  () . pl_OrientationAngle  , m_vTarget );
#line 79 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
m_vTarget  *= fRange ;
#line 80 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
m_vTarget  += GetPlacement  () . pl_PositionVector ;
#line 81 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
m_vTargetCopy  = m_vTarget ;
#line 82 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
  
#line 84 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
void CBullet::CalcTarget(CEntity * pen,FLOAT fRange) {
#line 85 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT3D vTarget ;
#line 88 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
EntityInfo  * peiTarget  = (EntityInfo  *) (pen  -> GetEntityInfo  ());
#line 89 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
GetEntityInfoPosition  (pen  , peiTarget  -> vTargetCenter  , vTarget );
#line 92 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
m_vTarget  = (vTarget  - GetPlacement  () . pl_PositionVector ) . Normalize  ();
#line 93 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
m_vTarget  *= fRange ;
#line 94 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
m_vTarget  += GetPlacement  () . pl_PositionVector ;
#line 95 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
m_vTargetCopy  = m_vTarget ;
#line 96 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
  
#line 99 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
void CBullet::CalcJitterTarget(FLOAT fR) {
#line 100 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT3D vJitter ;
#line 111 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT fZ  = FRnd  () * 2.0f - 1.0f;
#line 112 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT fA  = FRnd  () * 360.0f;
#line 113 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT fT  = Sqrt  (1 - (fZ  * fZ ));
#line 114 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
vJitter  (1) = fT  * CosFast  (fA );
#line 115 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
vJitter  (2) = fT  * SinFast  (fA );
#line 116 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
vJitter  (3) = fZ ;
#line 117 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
vJitter  = vJitter  * fR  * FRnd  ();
#line 120 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
m_vTarget  = m_vTargetCopy  + vJitter ;
#line 121 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
  
#line 124 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
void CBullet::CalcJitterTargetFixed(FLOAT fX,FLOAT fY,FLOAT fJitter) {
#line 125 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT fRndX  = FRnd  () * 2.0f - 1.0f;
#line 126 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT fRndY  = FRnd  () * 2.0f - 1.0f;
#line 127 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT3D vX  , vY ;
#line 128 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
const FLOATmatrix3D & m  = GetRotationMatrix  ();
#line 129 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
vX  (1) = m  (1 , 1);vX  (2) = m  (2 , 1);vX  (3) = m  (3 , 1);
#line 130 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
vY  (1) = m  (1 , 2);vY  (2) = m  (2 , 2);vY  (3) = m  (3 , 2);
#line 132 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
m_vTarget  = m_vTargetCopy  + (vX  * (fX  + fRndX  * fJitter )) + (vY  * (fY  + fRndY  * fJitter ));
#line 133 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
  
#line 136 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
void CBullet::LaunchBullet(BOOL bSound,BOOL bTrail,BOOL bHitFX) 
#line 137 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
{
#line 139 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
CCastRay  crRay  (m_penOwner  , GetPlacement  () . pl_PositionVector  , m_vTarget );
#line 140 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
crRay  . cr_bHitPortals  = TRUE ;
#line 141 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
crRay  . cr_bHitTranslucentPortals  = TRUE ;
#line 142 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
crRay  . cr_ttHitModels  = CCastRay  :: TT_COLLISIONBOX ;
#line 143 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
crRay  . cr_bPhysical  = FALSE ;
#line 144 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
crRay  . cr_fTestR  = m_fBulletSize ;
#line 145 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT3D vHitDirection ;
#line 146 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
AnglesToDirectionVector  (GetPlacement  () . pl_OrientationAngle  , vHitDirection );
#line 148 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
INDEX ctCasts  = 0;
#line 149 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
while(ctCasts  < 10)
#line 150 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
{
#line 151 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
if(ctCasts  == 0)
#line 152 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
{
#line 154 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
GetWorld  () -> CastRay  (crRay );
#line 155 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 156 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
else 
#line 157 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
{
#line 159 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
GetWorld  () -> ContinueCast  (crRay );
#line 160 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 161 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
ctCasts  ++;
#line 164 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
if(crRay  . cr_penHit  == NULL )
#line 165 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
{
#line 166 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
break ;
#line 167 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 169 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
const FLOAT fDamageMul  = GetSeriousDamageMultiplier  (m_penOwner );
#line 170 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
InflictDirectDamage  (crRay  . cr_penHit  , m_penOwner  , m_EdtDamage  , m_fDamage  * fDamageMul  , 
#line 171 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
crRay  . cr_vHit  , vHitDirection );
#line 173 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
m_vHitPoint  = crRay  . cr_vHit ;
#line 176 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
if(crRay  . cr_penHit  -> GetRenderType  () == RT_BRUSH  && crRay  . cr_pbpoBrushPolygon  != NULL )
#line 177 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
{
#line 178 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
CBrushPolygon  * pbpo  = crRay  . cr_pbpoBrushPolygon ;
#line 179 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT3D vHitNormal  = FLOAT3D (pbpo  -> bpo_pbplPlane  -> bpl_plAbsolute );
#line 181 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
INDEX iSurfaceType  = pbpo  -> bpo_bppProperties  . bpp_ubSurfaceType ;
#line 182 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
BulletHitType  bhtType  = BHT_BRUSH_STONE ;
#line 184 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
INDEX iContent  = pbpo  -> bpo_pbscSector  -> GetContentType  ();
#line 185 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
CContentType  & ct  = GetWorld  () -> wo_actContentTypes  [ iContent  ];
#line 187 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
bhtType  = (BulletHitType ) GetBulletHitTypeForSurface  (iSurfaceType );
#line 189 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
if(ct  . ct_ulFlags  & CTF_BREATHABLE_GILLS )
#line 190 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
{
#line 192 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
if(iSurfaceType  == SURFACE_WATER )
#line 193 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
{
#line 194 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
vHitNormal  = - vHitNormal ;
#line 196 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
bhtType  = BHT_BRUSH_WATER ;
#line 197 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 199 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
else 
#line 200 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
{
#line 201 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
bhtType  = BHT_BRUSH_UNDER_WATER ;
#line 202 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 203 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 205 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
BOOL bPassable  = pbpo  -> bpo_ulFlags  & (BPOF_PASSABLE  | BPOF_SHOOTTHRU );
#line 206 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
if(! bPassable  || iSurfaceType  == SURFACE_WATER ){
#line 207 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
SpawnHitTypeEffect  (this  , bhtType  , bSound  , vHitNormal  , crRay  . cr_vHit  , vHitDirection  , FLOAT3D (0.0f , 0.0f , 0.0f));
#line 208 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 209 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
if(! bPassable ){
#line 210 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
break ;
#line 211 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 213 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}else {
#line 216 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
if(crRay  . cr_penHit  -> GetEntityInfo  () != NULL ){
#line 217 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
if(((EntityInfo  *) crRay  . cr_penHit  -> GetEntityInfo  ()) -> Eeibt  == EIBT_FLESH )
#line 218 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
{
#line 219 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
CEntity  * penOfFlesh  = crRay  . cr_penHit ;
#line 220 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT3D vHitNormal  = (GetPlacement  () . pl_PositionVector  - m_vTarget ) . Normalize  ();
#line 221 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT3D vOldHitPos  = crRay  . cr_vHit ;
#line 222 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT3D vDistance ;
#line 225 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
GetWorld  () -> ContinueCast  (crRay );
#line 226 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
if(crRay  . cr_penHit  != NULL  && crRay  . cr_pbpoBrushPolygon  != NULL  && 
#line 227 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
crRay  . cr_penHit  -> GetRenderType  () == RT_BRUSH )
#line 228 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
{
#line 229 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
vDistance  = crRay  . cr_vHit  - vOldHitPos ;
#line 230 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
vHitNormal  = FLOAT3D (crRay  . cr_pbpoBrushPolygon  -> bpo_pbplPlane  -> bpl_plAbsolute );
#line 231 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 232 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
else 
#line 233 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
{
#line 234 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
vDistance  = FLOAT3D (0.0f , 0.0f , 0.0f);
#line 235 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
vHitNormal  = FLOAT3D (0 , 0 , 0);
#line 236 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 238 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
if(IsOfClass  (penOfFlesh  , "Gizmo") || 
#line 239 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
IsOfClass  (penOfFlesh  , "Beast"))
#line 240 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
{
#line 242 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
SpawnHitTypeEffect  (this  , BHT_ACID  , bSound  , vHitNormal  , crRay  . cr_vHit  , vHitDirection  , vDistance );
#line 243 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 244 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
else 
#line 245 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
{
#line 247 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
SpawnHitTypeEffect  (this  , BHT_FLESH  , bSound  , vHitNormal  , crRay  . cr_vHit  , vHitDirection  , vDistance );
#line 248 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 249 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
break ;
#line 250 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 251 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 254 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
break ;
#line 255 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 256 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 260 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
if(crRay  . cr_penHit  == NULL  && m_vHitPoint  == FLOAT3D (0.0F , 0.0F , 0.0F)){
#line 261 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
bTrail  = FALSE ;
#line 262 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 264 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
if(bTrail )
#line 265 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
{
#line 266 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
SpawnTrail  ();
#line 267 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 268 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
  
#line 271 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
void CBullet::DestroyBullet(void) {
#line 272 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
Destroy  ();
#line 273 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
  
#line 281 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
void CBullet::SpawnTrail(void) 
#line 282 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
{
#line 284 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
const FLOAT3D & v0  = GetPlacement  () . pl_PositionVector ;
#line 285 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
const FLOAT3D & v1  = m_vHitPoint ;
#line 287 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT3D vD  = v1  - v0 ;
#line 288 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT fD  = vD  . Length  ();
#line 290 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
if(fD  < 1.0f){
#line 292 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
return ;
#line 293 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 296 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT fLen  = Min  (20.0f , fD );
#line 298 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT3D vPos ;
#line 299 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
if(fLen  < fD ){
#line 300 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
vPos  = Lerp  (v0  , v1  , FRnd  () * (fD  - fLen ) / fD );
#line 301 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}else {
#line 302 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
vPos  = v0 ;
#line 303 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
#line 305 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
ESpawnEffect  ese ;
#line 306 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
UBYTE  ubRndH  = UBYTE  (8 + FRnd  () * 32);
#line 307 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
UBYTE  ubRndS  = UBYTE  (8 + FRnd  () * 32);
#line 308 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
UBYTE  ubRndV  = UBYTE  (224 + FRnd  () * 32);
#line 309 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
UBYTE  ubRndA  = UBYTE  (32 + FRnd  () * 128);
#line 310 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
ese  . colMuliplier  = HSVToColor  (ubRndH  , ubRndS  , ubRndV ) | ubRndA ;
#line 311 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
ese  . betType  = BET_BULLETTRAIL ;
#line 312 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
ese  . vNormal  = vD  / fD ;
#line 313 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
ese  . vStretch  = FLOAT3D (0.1f , fLen  , 1.0f);
#line 316 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
FLOAT3D vBulletIncommingDirection ;
#line 317 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
vBulletIncommingDirection  = (m_vTarget  - GetPlacement  () . pl_PositionVector ) . Normalize  ();
#line 318 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
CPlacement3D plHit  = CPlacement3D (vPos  - vBulletIncommingDirection  * 0.1f , GetPlacement  () . pl_OrientationAngle );
#line 319 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
CEntityPointer penHit  = CreateEntity  (plHit  , CLASS_BASIC_EFFECT );
#line 320 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
penHit  -> Initialize  (ese );
#line 321 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
}
BOOL CBullet::
#line 325 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBullet_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EBulletInit, "CBullet::Main expects 'EBulletInit' as input!");  const EBulletInit &eInit = (const EBulletInit &)__eeInput;
#line 328 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
ASSERT  (eInit  . penOwner  != NULL );
#line 329 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
m_penOwner  = eInit  . penOwner ;
#line 330 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
m_fDamage  = eInit  . fDamage ;
#line 332 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
InitAsVoid  ();
#line 333 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 334 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 337 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
m_iBullet  = 0;
#line 338 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
Return(STATE_CURRENT,EVoid());
#line 338 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Bullet.es"
return TRUE; ASSERT(FALSE); return TRUE;};