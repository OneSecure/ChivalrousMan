#include"Npc.h"
#include"GameScene.h"
#include"GameDynamicData.h"
#include"TalkLayer.h"
#include"Commen.h"

Npc::Npc()
{
	m_isCollision = false;
}

Npc::~Npc()
{

}

void Npc::collisionEvent()
{
	m_isCollision = true;
	resetIndex();
	auto gs = CurGameScene();
	auto talkLayer = TalkLayer::createWithNpc(this);
	talkLayer->setName("talkLayer");
	gs->addChild(talkLayer);
}

void Npc::endCollisionEvent()
{
	m_isCollision = false;
	auto gs = CurGameScene();
	gs->removeChildByName("talkLayer");
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

void  Npc::talkEndEvent()
{

}

void Npc::resetIndex()
{
	index = 0;
}
