#include"Npc.h"
#include"GameScene.h"
#include"GameDynamicData.h"
#include"TalkLayer.h"
#include"Commen.h"

Npc::Npc()
{

}

Npc::~Npc()
{

}

void Npc::collisionEvent()
{
	resetIndex();
	auto gs = CurGameScene();
	auto talkLayer = TalkLayer::createWithNpc(this);
	talkLayer->setName("talkLayer");
	gs->addChild(talkLayer);
}

std::string Npc::getNextTalkMsg()
{
	if (index == m_talkmsg.size())
	{
		return "";
	}
	std::string tmp = m_talkmsg[index];
	++index;
	return tmp;
}

void Npc::resetIndex()
{
	index = 0;
}
