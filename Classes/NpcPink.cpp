#include"NpcPink.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"GameScene.h"
#include"GameLogicLayer.h"
#include"DealLayer.h"
#include"Commen.h"

DEF_REFLECT_FUNC(NpcPink)
 
NpcPink::NpcPink()
{
	INIT_TALK_IN_NPC(NpcPink);
	m_name = "NpcPink";
}

NpcPink::~NpcPink()
{

}

void NpcPink::collisionEvent()
{
	Npc::collisionEvent();
}

void NpcPink::endCollisionEvent()
{
	Npc::endCollisionEvent();
	CurGameScene()->removeChildByName("DealLayer");
}

void NpcPink::talkEndEvent()
{
	Npc::talkEndEvent();
	auto gs = CurGameScene();
	gs->getLogicLayer()->pauseSchedulerAndActions();
	auto dealLayer = DealLayer::createWithType(MEDICATION, StringValue("DealMedication"));
	dealLayer->setName("DealLayer");
	gs->addChild(dealLayer);
}