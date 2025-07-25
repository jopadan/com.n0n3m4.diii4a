/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#define ENTITYCLASS CEnemyRunInto

CEntityProperty CEnemyRunInto_properties[] = {
 CEntityProperty(CEntityProperty::EPT_ENTITYPTR, NULL, (0x00000138<<8)+1, _offsetof(CEnemyRunInto, m_penLastTouched), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000138<<8)+2, _offsetof(CEnemyRunInto, m_fLastTouchedTime), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x00000138<<8)+3, _offsetof(CEnemyRunInto, m_bWhileLoop), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000138<<8)+5, _offsetof(CEnemyRunInto, m_fMassKicked), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000138<<8)+7, _offsetof(CEnemyRunInto, m_fInertionRunTime), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000138<<8)+8, _offsetof(CEnemyRunInto, m_fStopApproachDistance), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000138<<8)+9, _offsetof(CEnemyRunInto, m_fChargeDistance), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_BOOL, NULL, (0x00000138<<8)+10, _offsetof(CEnemyRunInto, m_bUseChargeAnimation), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_ANGLE, NULL, (0x00000138<<8)+20, _offsetof(CEnemyRunInto, m_fAttackRotateRunInto), "", 0, 0, 0),
};
#define CEnemyRunInto_propertiesct ARRAYCOUNT(CEnemyRunInto_properties)

CEntityComponent CEnemyRunInto_components[] = {
#define CLASS_BASE ((0x00000138<<8)+1)
 CEntityComponent(ECT_CLASS, CLASS_BASE, "EFNM" "Classes\\EnemyBase.ecl"),
};
#define CEnemyRunInto_componentsct ARRAYCOUNT(CEnemyRunInto_components)

CEventHandlerEntry CEnemyRunInto_handlers[] = {
 {0x01380000, STATE_CEnemyBase_Fire, CEntity::pEventHandler(&CEnemyRunInto::
#line 79 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/EnemyRunInto.es"
Fire),DEBUGSTRING("CEnemyRunInto::Fire")},
 {0x01380001, -1, CEntity::pEventHandler(&CEnemyRunInto::
#line 87 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/EnemyRunInto.es"
RotateToEnemy),DEBUGSTRING("CEnemyRunInto::RotateToEnemy")},
 {0x01380002, -1, CEntity::pEventHandler(&CEnemyRunInto::H0x01380002_RotateToEnemy_01), DEBUGSTRING("CEnemyRunInto::H0x01380002_RotateToEnemy_01")},
 {0x01380003, -1, CEntity::pEventHandler(&CEnemyRunInto::H0x01380003_RotateToEnemy_02), DEBUGSTRING("CEnemyRunInto::H0x01380003_RotateToEnemy_02")},
 {0x01380004, -1, CEntity::pEventHandler(&CEnemyRunInto::H0x01380004_RotateToEnemy_03), DEBUGSTRING("CEnemyRunInto::H0x01380004_RotateToEnemy_03")},
 {0x01380005, -1, CEntity::pEventHandler(&CEnemyRunInto::H0x01380005_RotateToEnemy_04), DEBUGSTRING("CEnemyRunInto::H0x01380005_RotateToEnemy_04")},
 {0x01380006, -1, CEntity::pEventHandler(&CEnemyRunInto::
#line 189 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/EnemyRunInto.es"
RunIntoEnemy),DEBUGSTRING("CEnemyRunInto::RunIntoEnemy")},
 {0x01380007, -1, CEntity::pEventHandler(&CEnemyRunInto::H0x01380007_RunIntoEnemy_01), DEBUGSTRING("CEnemyRunInto::H0x01380007_RunIntoEnemy_01")},
 {0x01380008, -1, CEntity::pEventHandler(&CEnemyRunInto::H0x01380008_RunIntoEnemy_02), DEBUGSTRING("CEnemyRunInto::H0x01380008_RunIntoEnemy_02")},
 {0x01380009, -1, CEntity::pEventHandler(&CEnemyRunInto::H0x01380009_RunIntoEnemy_03), DEBUGSTRING("CEnemyRunInto::H0x01380009_RunIntoEnemy_03")},
 {0x0138000a, -1, CEntity::pEventHandler(&CEnemyRunInto::H0x0138000a_RunIntoEnemy_04), DEBUGSTRING("CEnemyRunInto::H0x0138000a_RunIntoEnemy_04")},
 {0x0138000b, -1, CEntity::pEventHandler(&CEnemyRunInto::
#line 257 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/EnemyRunInto.es"
RunAwayFromEnemy),DEBUGSTRING("CEnemyRunInto::RunAwayFromEnemy")},
 {0x0138000c, -1, CEntity::pEventHandler(&CEnemyRunInto::H0x0138000c_RunAwayFromEnemy_01), DEBUGSTRING("CEnemyRunInto::H0x0138000c_RunAwayFromEnemy_01")},
 {0x0138000d, -1, CEntity::pEventHandler(&CEnemyRunInto::H0x0138000d_RunAwayFromEnemy_02), DEBUGSTRING("CEnemyRunInto::H0x0138000d_RunAwayFromEnemy_02")},
 {0x0138000e, -1, CEntity::pEventHandler(&CEnemyRunInto::H0x0138000e_RunAwayFromEnemy_03), DEBUGSTRING("CEnemyRunInto::H0x0138000e_RunAwayFromEnemy_03")},
 {0x0138000f, -1, CEntity::pEventHandler(&CEnemyRunInto::H0x0138000f_RunAwayFromEnemy_04), DEBUGSTRING("CEnemyRunInto::H0x0138000f_RunAwayFromEnemy_04")},
 {0x01380010, -1, CEntity::pEventHandler(&CEnemyRunInto::
#line 295 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/EnemyRunInto.es"
PostRunAwayFromEnemy),DEBUGSTRING("CEnemyRunInto::PostRunAwayFromEnemy")},
 {0x01380011, STATE_CEnemyBase_MainLoop, CEntity::pEventHandler(&CEnemyRunInto::
#line 300 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/EnemyRunInto.es"
MainLoop),DEBUGSTRING("CEnemyRunInto::MainLoop")},
 {1, -1, CEntity::pEventHandler(&CEnemyRunInto::
#line 305 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/EnemyRunInto.es"
Main),DEBUGSTRING("CEnemyRunInto::Main")},
};
#define CEnemyRunInto_handlersct ARRAYCOUNT(CEnemyRunInto_handlers)

CEntity *CEnemyRunInto_New(void) { return new CEnemyRunInto; };
void CEnemyRunInto_OnInitClass(void) {};
void CEnemyRunInto_OnEndClass(void) {};
void CEnemyRunInto_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CEnemyRunInto_OnWorldEnd(CWorld *pwo) {};
void CEnemyRunInto_OnWorldInit(CWorld *pwo) {};
void CEnemyRunInto_OnWorldTick(CWorld *pwo) {};
void CEnemyRunInto_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CEnemyRunInto, CEnemyBase, "Enemy Run Into", "", 0x00000138);
DECLARE_CTFILENAME(_fnmCEnemyRunInto_tbn, "");
