#include"Npc.h"
#include"GameScene.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"TalkLayer.h"
#include"Commen.h"
#include"TaskSystem.h"
#include"PickupTaskLayer.h"

Npc::Npc()
{
	m_name = "Npc";
	m_isCollision = false;
	m_state = NS_FREE;
}

Npc::~Npc()
{

}

void Npc::collisionEvent()
{
	m_isCollision = true;
	resetIndex();
	auto gs = CurGameScene();
	switch (m_state)
	{
	case NS_WSTASK:
		initNoEndTaskTalk();
		break;
	case NS_HTASK:
		initMissTaskTalk();
		break;
	case NS_STASK:
		initEndTaskTalk();
		break;
	default:
		break;
	}
	auto talkLayer = TalkLayer::createWithNpc(this);
	talkLayer->setName("talkLayer");
	gs->addChild(talkLayer);
}

void Npc::endCollisionEvent()
{
	m_isCollision = false;
	auto gs = CurGameScene();
	gs->removeChildByName("talkLayer");
	gs->removeChildByName("pklayer");
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

void Npc::changeState(int state,int index)
{
	if(m_state == state&&pickup)
	{
		return;
	}
	m_state = state;
	m_taskindex = index;
	m_face->removeChildByName("TaskState");
	switch (m_state)
	{
	case NS_HTASK:
	{
		auto taskicon = Sprite::create(StringValue("Taskh"));
		taskicon->setName("TaskState");
		taskicon->setPosition(40, 150);
		m_face->addChild(taskicon);
	}
		break;
	case NS_WSTASK:
	{
		auto taskicon = Sprite::create(StringValue("Taskw"));
		taskicon->setName("TaskState");
		taskicon->setPosition(40, 150);
		m_face->addChild(taskicon);
		pickup = false;
	}
		break;
	case NS_STASK:
	{
		auto taskicon = Sprite::create(StringValue("Tasks"));
		taskicon->setName("TaskState");
		taskicon->setPosition(40, 150);
		m_face->addChild(taskicon);
		pickup = false;
	}
		break;
	default:
		break;
	}
}

void  Npc::talkEndEvent()
{
	switch (m_state)
	{
	case NS_STASK:
		TaskSystem::getInstance()->submitTask(CurGameScene(), m_taskindex);
		changeState(NS_FREE, 0);
		m_talkmsg.clear();
		m_talkmsg = m_tmptalk;
		pickup = true;
		break;
	case NS_HTASK:
	{
		PickupTaskLayer* pklayer = PickupTaskLayer::create(this);
		pklayer->setName("pklayer");
		CurGameScene()->addChild(pklayer);
		m_talkmsg.clear();
		m_talkmsg = m_tmptalk;
	}
		break;
	case NS_WSTASK:
		m_talkmsg.clear();
		m_talkmsg = m_tmptalk;
		break;
	default:
		break;
	}
}

void Npc::resetIndex()
{
	index = 0;
}

void Npc::initMissTaskTalk()
{
	initTaskTalk("Task/Task" + NTS(m_taskindex) + ".tk");
}

void Npc::initEndTaskTalk()
{
	initTaskTalk("Task/EndTask.tk");
}

void Npc::initNoEndTaskTalk()
{
	initTaskTalk("Task/NoEndTask.tk");
}

void Npc::initTaskTalk(const std::string& filename)
{
	m_tmptalk.clear();
	m_tmptalk = m_talkmsg;
	m_talkmsg.clear();
	std::ifstream fin(filename, std::ios::in);
	if (fin.fail())
	{
		return;
	}
	std::string str;
	while (!fin.eof())
	{
		fin >> str;
		m_talkmsg.push_back(str);
	}
	std::string dest;
	if (TaskSystem::getInstance()->checkTask(m_taskindex, dest) == T_ACCESS)
	{
		m_talkmsg[0] += dest;
		m_talkmsg[0] += "?";
	}
	fin.close();
}