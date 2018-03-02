#include"ObjectLayer.h"
#include"Commen.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"CameraPlayer.h"
#include"ReflectNpc.h"
#include"MapInfo.h"
#include"TaskSystem.h"
#include<fstream>

ObjectLayer::ObjectLayer()
{

}
  
ObjectLayer::~ObjectLayer()
{
	clearObjectLayer();
}

ObjectLayer* ObjectLayer::createWithLevel(const int& level)
{
	ObjectLayer* pRet = new ObjectLayer;
	if (pRet&&pRet->init(level))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool ObjectLayer::init(const int& level)
{
	if (Layer::init())
	{
		initLevelObject(level);
		this->scheduleUpdate();
		return true;
	}
	return false;
}

void ObjectLayer::update(float dt)
{
	checkmissedTask();
	checkpickedupTask();
	updateObjectScreenPos();
}

void ObjectLayer::initLevelObject(const int& level)
{
	clearObjectLayer();
	char filename[40] = { 0 };
	sprintf_s(filename, "LevelObject/Level%d.lobject", level);
	std::ifstream fin;
	fin.open(filename, std::ios::in);
	if (fin.fail())
	{
		return;
	}
	std::string objname;
	std::string x;
	std::string y;
	fin >> objname;
	do
	{
		fin >> objname;
		fin >> x;
		fin >> y;
		Npc* npc = GET_REFLECT_OBJECT(objname);
		npc->setX(std::stof(x)*MapGridW);
		npc->setY(std::stof(y)*MapGridH);
		Sprite* face = Sprite::create(StringValue(objname));		
		npc->setFace(face);
		m_npcList.push_back(npc);
		this->addChild(face);
	} while (!fin.eof());
	fin.close();
}

void  ObjectLayer::checkmissedTask()
{
	for (auto var : m_npcList)
	{
		int index = TaskSystem::getInstance()->haveMissedTask(var->getName());
		if (index)
		{
			var->changeState(NS_HTASK, index);
		}
	}
}

void ObjectLayer::checkpickedupTask()
{
	for (auto var : m_npcList)
	{
		int index = TaskSystem::getInstance()->havePickedupTask(var->getName());
		if (index)
		{
			var->changeState(index > 0 ? NS_STASK : NS_WSTASK, abs(index));
		}
	}
}

void  ObjectLayer::updateObjectScreenPos()
{
	updateNpcScreenPos();
}

void ObjectLayer::updateNpcScreenPos()
{
	Vec2 pos;
	for (auto it : m_npcList)
	{
		pos.x = PlayerFacePos().x + (it->getX() - PlayerPos.x);
		pos.y = PlayerFacePos().y + (it->getY() - PlayerPos.y);
		it->getFace()->setPosition(pos);
	}
}

void ObjectLayer::clearObjectLayer()
{
	for (auto it : m_npcList)
	{
		RELEASE_NULL(it);
	}
	m_npcList.clear();
}