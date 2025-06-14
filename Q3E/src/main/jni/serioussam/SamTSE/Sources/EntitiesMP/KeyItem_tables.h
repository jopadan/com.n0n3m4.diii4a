/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

EP_ENUMBEG(KeyItemType)
  EP_ENUMVALUE(KIT_BOOKOFWISDOM, "Book of wisdom"),
  EP_ENUMVALUE(KIT_CROSSWOODEN, "Wooden cross"),
  EP_ENUMVALUE(KIT_CROSSMETAL, "Silver cross"),
  EP_ENUMVALUE(KIT_CROSSGOLD, "Gold cross"),
  EP_ENUMVALUE(KIT_JAGUARGOLDDUMMY, "Gold jaguar"),
  EP_ENUMVALUE(KIT_HAWKWINGS01DUMMY, "Hawk wings - part 1"),
  EP_ENUMVALUE(KIT_HAWKWINGS02DUMMY, "Hawk wings - part 2"),
  EP_ENUMVALUE(KIT_HOLYGRAIL, "Holy grail"),
  EP_ENUMVALUE(KIT_TABLESDUMMY, "Tablet of wisdom"),
  EP_ENUMVALUE(KIT_WINGEDLION, "Winged lion"),
  EP_ENUMVALUE(KIT_ELEPHANTGOLD, "Gold elephant"),
  EP_ENUMVALUE(KIT_STATUEHEAD01, "Seriously scary ceremonial mask"),
  EP_ENUMVALUE(KIT_STATUEHEAD02, "Hilariously happy ceremonial mask"),
  EP_ENUMVALUE(KIT_STATUEHEAD03, "Ix Chel mask"),
  EP_ENUMVALUE(KIT_KINGSTATUE, "Statue of King Tilmun"),
  EP_ENUMVALUE(KIT_CRYSTALSKULL, "Crystal Skull"),
EP_ENUMEND(KeyItemType);

#define ENTITYCLASS CKeyItem

CEntityProperty CKeyItem_properties[] = {
 CEntityProperty(CEntityProperty::EPT_ENUM, &KeyItemType_enum, (0x00000325<<8)+1, _offsetof(CKeyItem, m_kitType), "Type", 'Y', 0x7F0000FFUL, 0),
 CEntityProperty(CEntityProperty::EPT_INDEX, NULL, (0x00000325<<8)+3, _offsetof(CKeyItem, m_iSoundComponent), "", 0, 0, 0),
 CEntityProperty(CEntityProperty::EPT_FLOAT, NULL, (0x00000325<<8)+5, _offsetof(CKeyItem, m_fSize), "Size", 0, 0x7F0000FFUL, 0),
};
#define CKeyItem_propertiesct ARRAYCOUNT(CKeyItem_properties)

CEntityComponent CKeyItem_components[] = {
#define CLASS_BASE ((0x00000325<<8)+0)
 CEntityComponent(ECT_CLASS, CLASS_BASE, "EFNM" "Classes\\Item.ecl"),
#define MODEL_BOOKOFWISDOM ((0x00000325<<8)+1)
 CEntityComponent(ECT_MODEL, MODEL_BOOKOFWISDOM, "EFNM" "ModelsMP\\Items\\Keys\\BookOfWisdom\\Book.mdl"),
#define TEXTURE_BOOKOFWISDOM ((0x00000325<<8)+2)
 CEntityComponent(ECT_TEXTURE, TEXTURE_BOOKOFWISDOM, "EFNM" "ModelsMP\\Items\\Keys\\BookOfWisdom\\Book.tex"),
#define MODEL_CROSSWOODEN ((0x00000325<<8)+5)
 CEntityComponent(ECT_MODEL, MODEL_CROSSWOODEN, "EFNM" "ModelsMP\\Items\\Keys\\Cross\\Cross.mdl"),
#define TEXTURE_CROSSWOODEN ((0x00000325<<8)+6)
 CEntityComponent(ECT_TEXTURE, TEXTURE_CROSSWOODEN, "EFNM" "ModelsMP\\Items\\Keys\\Cross\\CrossWooden.tex"),
#define MODEL_CROSSMETAL ((0x00000325<<8)+7)
 CEntityComponent(ECT_MODEL, MODEL_CROSSMETAL, "EFNM" "ModelsMP\\Items\\Keys\\Cross\\Cross.mdl"),
#define TEXTURE_CROSSMETAL ((0x00000325<<8)+8)
 CEntityComponent(ECT_TEXTURE, TEXTURE_CROSSMETAL, "EFNM" "ModelsMP\\Items\\Keys\\Cross\\CrossMetal.tex"),
#define MODEL_CROSSGOLD ((0x00000325<<8)+10)
 CEntityComponent(ECT_MODEL, MODEL_CROSSGOLD, "EFNM" "ModelsMP\\Items\\Keys\\GoldCross\\Cross.mdl"),
#define TEXTURE_CROSSGOLD ((0x00000325<<8)+11)
 CEntityComponent(ECT_TEXTURE, TEXTURE_CROSSGOLD, "EFNM" "ModelsMP\\Items\\Keys\\GoldCross\\Cross.tex"),
#define MODEL_JAGUARGOLD ((0x00000325<<8)+15)
 CEntityComponent(ECT_MODEL, MODEL_JAGUARGOLD, "EFNM" "ModelsMP\\Items\\Keys\\GoldJaguar\\Jaguar.mdl"),
#define MODEL_HAWKWINGS01 ((0x00000325<<8)+20)
 CEntityComponent(ECT_MODEL, MODEL_HAWKWINGS01, "EFNM" "ModelsMP\\Items\\Keys\\HawkWings\\WingRight.mdl"),
#define MODEL_HAWKWINGS02 ((0x00000325<<8)+21)
 CEntityComponent(ECT_MODEL, MODEL_HAWKWINGS02, "EFNM" "ModelsMP\\Items\\Keys\\HawkWings\\WingLeft.mdl"),
#define TEXTURE_HAWKWINGS ((0x00000325<<8)+22)
 CEntityComponent(ECT_TEXTURE, TEXTURE_HAWKWINGS, "EFNM" "ModelsMP\\Items\\Keys\\HawkWings\\Wings.tex"),
#define MODEL_HOLYGRAIL ((0x00000325<<8)+30)
 CEntityComponent(ECT_MODEL, MODEL_HOLYGRAIL, "EFNM" "ModelsMP\\Items\\Keys\\HolyGrail\\Grail.mdl"),
#define TEXTURE_HOLYGRAIL ((0x00000325<<8)+31)
 CEntityComponent(ECT_TEXTURE, TEXTURE_HOLYGRAIL, "EFNM" "ModelsMP\\Items\\Keys\\HolyGrail\\Grail.tex"),
#define MODEL_TABLESOFWISDOM ((0x00000325<<8)+35)
 CEntityComponent(ECT_MODEL, MODEL_TABLESOFWISDOM, "EFNM" "ModelsMP\\Items\\Keys\\TablesOfWisdom\\Tables.mdl"),
#define TEXTURE_TABLESOFWISDOM ((0x00000325<<8)+36)
 CEntityComponent(ECT_TEXTURE, TEXTURE_TABLESOFWISDOM, "EFNM" "ModelsMP\\Items\\Keys\\TablesOfWisdom\\Tables.tex"),
#define MODEL_WINGEDLION ((0x00000325<<8)+40)
 CEntityComponent(ECT_MODEL, MODEL_WINGEDLION, "EFNM" "ModelsMP\\Items\\Keys\\WingLion\\WingLion.mdl"),
#define MODEL_ELEPHANTGOLD ((0x00000325<<8)+45)
 CEntityComponent(ECT_MODEL, MODEL_ELEPHANTGOLD, "EFNM" "ModelsMP\\Items\\Keys\\GoldElephant\\Elephant.mdl"),
#define MODEL_STATUEHEAD01 ((0x00000325<<8)+50)
 CEntityComponent(ECT_MODEL, MODEL_STATUEHEAD01, "EFNM" "ModelsMP\\Items\\Keys\\Statue01\\Statue.mdl"),
#define TEXTURE_STATUEHEAD01 ((0x00000325<<8)+51)
 CEntityComponent(ECT_TEXTURE, TEXTURE_STATUEHEAD01, "EFNM" "ModelsMP\\Items\\Keys\\Statue01\\Statue.tex"),
#define MODEL_STATUEHEAD02 ((0x00000325<<8)+52)
 CEntityComponent(ECT_MODEL, MODEL_STATUEHEAD02, "EFNM" "ModelsMP\\Items\\Keys\\Statue02\\Statue.mdl"),
#define TEXTURE_STATUEHEAD02 ((0x00000325<<8)+53)
 CEntityComponent(ECT_TEXTURE, TEXTURE_STATUEHEAD02, "EFNM" "ModelsMP\\Items\\Keys\\Statue02\\Statue.tex"),
#define MODEL_STATUEHEAD03 ((0x00000325<<8)+54)
 CEntityComponent(ECT_MODEL, MODEL_STATUEHEAD03, "EFNM" "ModelsMP\\Items\\Keys\\Statue03\\Statue.mdl"),
#define TEXTURE_STATUEHEAD03 ((0x00000325<<8)+55)
 CEntityComponent(ECT_TEXTURE, TEXTURE_STATUEHEAD03, "EFNM" "ModelsMP\\Items\\Keys\\Statue03\\Statue.tex"),
#define MODEL_KINGSTATUE ((0x00000325<<8)+58)
 CEntityComponent(ECT_MODEL, MODEL_KINGSTATUE, "EFNM" "ModelsMP\\Items\\Keys\\ManStatue\\Statue.mdl"),
#define MODEL_CRYSTALSKULL ((0x00000325<<8)+60)
 CEntityComponent(ECT_MODEL, MODEL_CRYSTALSKULL, "EFNM" "ModelsMP\\Items\\Keys\\CrystalSkull\\Skull.mdl"),
#define TEXTURE_CRYSTALSKULL ((0x00000325<<8)+61)
 CEntityComponent(ECT_TEXTURE, TEXTURE_CRYSTALSKULL, "EFNM" "ModelsMP\\Items\\Keys\\CrystalSkull\\Skull.tex"),
#define TEXTURE_FLARE ((0x00000325<<8)+250)
 CEntityComponent(ECT_TEXTURE, TEXTURE_FLARE, "EFNM" "ModelsMP\\Items\\Flares\\Flare.tex"),
#define MODEL_FLARE ((0x00000325<<8)+251)
 CEntityComponent(ECT_MODEL, MODEL_FLARE, "EFNM" "ModelsMP\\Items\\Flares\\Flare.mdl"),
#define TEX_REFL_GOLD01 ((0x00000325<<8)+252)
 CEntityComponent(ECT_TEXTURE, TEX_REFL_GOLD01, "EFNM" "ModelsMP\\ReflectionTextures\\Gold01.tex"),
#define TEX_REFL_METAL01 ((0x00000325<<8)+253)
 CEntityComponent(ECT_TEXTURE, TEX_REFL_METAL01, "EFNM" "ModelsMP\\ReflectionTextures\\LightMetal01.tex"),
#define TEX_SPEC_MEDIUM ((0x00000325<<8)+254)
 CEntityComponent(ECT_TEXTURE, TEX_SPEC_MEDIUM, "EFNM" "ModelsMP\\SpecularTextures\\Medium.tex"),
#define TEX_SPEC_STRONG ((0x00000325<<8)+255)
 CEntityComponent(ECT_TEXTURE, TEX_SPEC_STRONG, "EFNM" "ModelsMP\\SpecularTextures\\Strong.tex"),
#define SOUND_KEY ((0x00000325<<8)+300)
 CEntityComponent(ECT_SOUND, SOUND_KEY, "EFNM" "Sounds\\Items\\Key.wav"),
};
#define CKeyItem_componentsct ARRAYCOUNT(CKeyItem_components)

CEventHandlerEntry CKeyItem_handlers[] = {
 {0x03250001, STATE_CItem_ItemCollected, CEntity::pEventHandler(&CKeyItem::
#line 333 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/KeyItem.es"
ItemCollected),DEBUGSTRING("CKeyItem::ItemCollected")},
 {1, -1, CEntity::pEventHandler(&CKeyItem::
#line 351 "/data/data/com.termux/files/home/doom3/SeriousSamClassic-1.10.7/SamTSE/Sources/EntitiesMP/KeyItem.es"
Main),DEBUGSTRING("CKeyItem::Main")},
};
#define CKeyItem_handlersct ARRAYCOUNT(CKeyItem_handlers)

CEntity *CKeyItem_New(void) { return new CKeyItem; };
void CKeyItem_OnInitClass(void) {};
void CKeyItem_OnEndClass(void) {};
void CKeyItem_OnPrecache(CDLLEntityClass *pdec, INDEX iUser) {};
void CKeyItem_OnWorldEnd(CWorld *pwo) {};
void CKeyItem_OnWorldInit(CWorld *pwo) {};
void CKeyItem_OnWorldTick(CWorld *pwo) {};
void CKeyItem_OnWorldRender(CWorld *pwo) {};
ENTITY_CLASSDEFINITION(CKeyItem, CItem, "KeyItem", "Thumbnails\\KeyItem.tbn", 0x00000325);
DECLARE_CTFILENAME(_fnmCKeyItem_tbn, "Thumbnails\\KeyItem.tbn");
