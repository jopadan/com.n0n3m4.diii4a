/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#ifndef _EntitiesMP_Ship_INCLUDED
#define _EntitiesMP_Ship_INCLUDED 1
#include <EntitiesMP/ShipMarker.h>
#define EVENTCODE_EHarbor 0x00670000
class DECL_DLL EHarbor : public CEntityEvent {
public:
EHarbor();
CEntityEvent *MakeCopy(void);
};
DECL_DLL inline void ClearToDefault(EHarbor &e) { e = EHarbor(); } ;
extern "C" DECL_DLL CDLLEntityClass CShip_DLLClass;
class CShip : public CMovableBrushEntity {
public:
virtual const CTString &GetName(void) const { return m_strName; };
virtual BOOL IsTargetable(void) const { return TRUE; };
  DECL_DLL virtual void SetDefaultProperties(void);
  CTString m_strName;
  CTString m_strDescription;
  CEntityPointer m_penTarget;
  FLOAT m_fSpeed;
  FLOAT m_fRotation;
  FLOAT m_fRockingV;
  FLOAT m_fRockingA;
  FLOAT m_fAcceleration;
  BOOL m_bMoving;
  FLOAT m_fRockSign;
  FLOAT m_fLastTargetDistance;
  CEntityPointer m_penSail;
  ANIMATION m_iSailUpAnim;
  ANIMATION m_iSailDownAnim;
  ANIMATION m_iSailSailAnim;
  ANIMATION m_iSailWaveingAnim;
  FLOAT m_fOriginalRockingV;
  FLOAT m_fOriginalRockingA;
  FLOAT m_fNextRockingV;
  FLOAT m_fNextRockingA;
  FLOAT m_tmRockingChange;
  FLOAT m_tmRockingChangeStart;
   
#line 73 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Ship.es"
BOOL MovesByTargetedRoute(CTString & strTargetProperty)const;
   
#line 78 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Ship.es"
BOOL DropsMarker(CTFileName & fnmMarkerClass,CTString & strTargetProperty)const;
   
#line 83 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Ship.es"
const CTString & GetDescription(void)const;
   
#line 91 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Ship.es"
CAnimData * GetAnimData(SLONG slPropertyOffset);
   
#line 105 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Ship.es"
void SetMovingSpeeds(void);
   
#line 147 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Ship.es"
ANGLE GetRockingSpeed(void);
   
#line 177 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Ship.es"
void NextMarker(void);
   
#line 235 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Ship.es"
void StartSailing();
   
#line 242 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Ship.es"
void StopSailing(void);
   
#line 250 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Ship.es"
void PreMoving(void);
#define  STATE_CShip_Sail 0x00670001
  BOOL 
#line 257 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Ship.es"
Sail(const CEntityEvent &__eeInput);
  BOOL H0x00670002_Sail_01(const CEntityEvent &__eeInput);
  BOOL H0x00670003_Sail_02(const CEntityEvent &__eeInput);
  BOOL H0x00670004_Sail_03(const CEntityEvent &__eeInput);
  BOOL H0x00670005_Sail_04(const CEntityEvent &__eeInput);
  BOOL H0x00670006_Sail_05(const CEntityEvent &__eeInput);
  BOOL H0x00670007_Sail_06(const CEntityEvent &__eeInput);
#define  STATE_CShip_Harbor 0x00670008
  BOOL 
#line 291 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Ship.es"
Harbor(const CEntityEvent &__eeInput);
  BOOL H0x00670009_Harbor_01(const CEntityEvent &__eeInput);
  BOOL H0x0067000a_Harbor_02(const CEntityEvent &__eeInput);
#define  STATE_CShip_Main 1
  BOOL 
#line 305 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/Ship.es"
Main(const CEntityEvent &__eeInput);
  BOOL H0x0067000b_Main_01(const CEntityEvent &__eeInput);
  BOOL H0x0067000c_Main_02(const CEntityEvent &__eeInput);
  BOOL H0x0067000d_Main_03(const CEntityEvent &__eeInput);
  BOOL H0x0067000e_Main_04(const CEntityEvent &__eeInput);
};
#endif // _EntitiesMP_Ship_INCLUDED
