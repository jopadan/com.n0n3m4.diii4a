/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#define ENTITYCLASS CMeteorShower

CEntityProperty CMeteorShower_properties[] = {
 CEntityProperty(CEntityProperty::EPT_STRING, NULL, (0x00000267<<8)+1, _offsetof(CMeteorShower, m_strName), "Name", 'N', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_ANGLE3D, NULL, (0x00000267<<8)+10, _offsetof(CMeteorShower, m_aAngle), "Shoot Angle", 'S', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_INDEX, NULL, (0x00000267<<8)+11, _offsetof(CMeteorShower, m_iPerTickLaunchChance), "Density (1-100)", 'D', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000267<<8)+15, _offsetof(CMeteorShower, m_fMinStretch), "Min. Stretch", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000267<<8)+16, _offsetof(CMeteorShower, m_fMaxStretch), "Max. Stretch", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_RANGE, NULL, (0x00000267<<8)+19, _offsetof(CMeteorShower, m_rSafeArea), "Safe Area", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_RANGE, NULL, (0x00000267<<8)+20, _offsetof(CMeteorShower, m_rArea), "Area", 0, 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000267<<8)+30, _offsetof(CMeteorShower, m_fSpeed), "Speed", 'P', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000267<<8)+40, _offsetof(CMeteorShower, m_fLaunchDistance), "Launch distance", 'L', 0x7F0000FFUL, 0),
};
#define CMeteorShower_propertiesct ARRAYCOUNT(CMeteorShower_properties)

CEntityComponent CMeteorShower_components[] = {
#define MODEL_MARKER ((0x00000267<<8)+1)
 CEntityComponent(ECT_MODEL, MODEL_MARKER, "EFNM" "ModelsMP\\Editor\\EffectMarker.mdl"),
#define TEXTURE_MARKER ((0x00000267<<8)+2)
 CEntityComponent(ECT_TEXTURE, TEXTURE_MARKER, "EFNM" "ModelsMP\\Editor\\EffectMarker.tex"),
#define CLASS_PROJECTILE ((0x00000267<<8)+5)
 CEntityComponent(ECT_CLASS, CLASS_PROJECTILE, "EFNM" "Classes\\Projectile.ecl"),
};
#define CMeteorShower_componentsct ARRAYCOUNT(CMeteorShower_components)

CEventHandlerEntry CMeteorShower_handlers[] = {
 {0x02670000, -1, CEntity::pEventHandler(&CMeteorShower::
#line 99 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/MeteorShower.es"
Active),DEBUGSTRING("CMeteorShower::Active")},
 {0x02670001, -1, CEntity::pEventHandler(&CMeteorShower::H0x02670001_Active_01), DEBUGSTRING("CMeteorShower::H0x02670001_Active_01")},
 {0x02670002, -1, CEntity::pEventHandler(&CMeteorShower::H0x02670002_Active_02), DEBUGSTRING("CMeteorShower::H0x02670002_Active_02")},
 {0x02670003, -1, CEntity::pEventHandler(&CMeteorShower::H0x02670003_Active_03), DEBUGSTRING("CMeteorShower::H0x02670003_Active_03")},
 {0x02670004, -1, CEntity::pEventHandler(&CMeteorShower::H0x02670004_Active_04), DEBUGSTRING("CMeteorShower::H0x02670004_Active_04")},
 {0x02670005, -1, CEntity::pEventHandler(&CMeteorShower::
#line 120 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/MeteorShower.es"
Inactive),DEBUGSTRING("CMeteorShower::Inactive")},
 {0x02670006, -1, CEntity::pEventHandler(&CMeteorShower::H0x02670006_Inactive_01), DEBUGSTRING("CMeteorShower::H0x02670006_Inactive_01")},
 {0x02670007, -1, CEntity::pEventHandler(&CMeteorShower::H0x02670007_Inactive_02), DEBUGSTRING("CMeteorShower::H0x02670007_Inactive_02")},
 {1, -1, CEntity::pEventHandler(&CMeteorShower::
#line 129 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/MeteorShower.es"
Main),DEBUGSTRING("CMeteorShower::Main")},
 {0x02670008, -1, CEntity::pEventHandler(&CMeteorShower::H0x02670008_Main_01), DEBUGSTRING("CMeteorShower::H0x02670008_Main_01")},
 {0x02670009, -1, CEntity::pEventHandler(&CMeteorShower::H0x02670009_Main_02), DEBUGSTRING("CMeteorShower::H0x02670009_Main_02")},
};
#define CMeteorShower_handlersct ARRAYCOUNT(CMeteorShower_handlers)

CEntity *CMeteorShower_New(void) { return new CMeteorShower; };
void CMeteorShower_OnInitClass(void) {};
void CMeteorShower_OnEndClass(void) {};
void CMeteorShower_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CMeteorShower_OnWorldEnd(CWorld *pwo) {};
void CMeteorShower_OnWorldInit(CWorld *pwo) {};
void CMeteorShower_OnWorldTick(CWorld *pwo) {};
void CMeteorShower_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CMeteorShower, CRationalEntity, "MeteorShower", "Thumbnails\\Eruptor.tbn", 0x00000267);
DECLARE_CTFILENAME(_fnmCMeteorShower_tbn, "Thumbnails\\Eruptor.tbn");
