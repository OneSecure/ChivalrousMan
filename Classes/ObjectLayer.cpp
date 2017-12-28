#include"ObjectLayer.h"
#include"Commen.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"CameraPlayer.h"
#include"ReflectNpc.h"
#include"MapInfo.h"
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
	static float Time = 0;
	Time += dt * 360;
	if (Time >= 1)
	{
		updateObjectScreenPos();
		Time = 0;
	}
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

void  ObjectLayer::updateObjectScreenPos()
{
	Vec2 pos;
	for (int i = 0; i < m_npcList.size(); ++i)
	{
		pos.x =PlayerFacePos().x+(m_npcList[i]->getX() - PlayerPos.x);
		pos.y = PlayerFacePos().y + (m_npcList[i]->getY() - PlayerPos.y);
		m_npcList[i]->getFace()->setPosition(pos);
	}
}

void ObjectLayer::clearObjectLayer()
{
	for (int i = 0; i < m_npcList.size(); ++i)
	{
		RELEASE_NULL(m_npcList[i]);
	}
	m_npcList.clear();
}