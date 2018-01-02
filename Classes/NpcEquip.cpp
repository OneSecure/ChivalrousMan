#include"NpcEquip.h"
#include"GameData.h"
#include"DealLayer.h"
#include"GameDynamicData.h"
#include"GameScene.h"
#include"GameLogicLayer.h"
#include"Commen.h"

DEF_REFLECT_FUNC(NpcEquip)

NpcEquip::NpcEquip()
{
	INIT_TALK_IN_NPC(NpcEquip);
}
  
NpcEquip::~NpcEquip()
{

}

void NpcEquip::collisionEvent()
{
	Npc::collisionEvent();
}

void NpcEquip::talkEndEvent()
{
	Npc::talkEndEvent();
	auto gs = CurGameScene();
	gs->getLogicLayer()->pauseSchedulerAndActions();
	auto dealLayer = DealLayer::createWithType(EQUIPMENT, StringValue("DealEquipMent"));
	gs->addChild(dealLayer);
}