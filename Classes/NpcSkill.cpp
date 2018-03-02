#include"NpcSkill.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"GameScene.h"
#include"GameLogicLayer.h"
#include"DealLayer.h"
#include"Commen.h"

DEF_REFLECT_FUNC(NpcSkill)

NpcSkill::NpcSkill()
{
	INIT_TALK_IN_NPC(NpcSkill);
	m_name = "NpcSkill";
} 

NpcSkill::~NpcSkill()
{

}

void NpcSkill::collisionEvent()
{
	Npc::collisionEvent();
}

void NpcSkill::talkEndEvent()
{
	Npc::talkEndEvent();
	auto gs = CurGameScene();
	gs->getLogicLayer()->pauseSchedulerAndActions();
	auto dealLayer = DealLayer::createWithType(SKILL, StringValue("DealSkill"));
	gs->addChild(dealLayer);
}
