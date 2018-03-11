#include"ObjectLayer.h"
#include"Commen.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"CameraPlayer.h"
#include"ReflectNpc.h"
#include"MapInfo.h"
#include"TaskSystem.h"
#include"Player.h"
#include"CMClient.h"
#include"FindRoad.h"
#include<fstream>

ObjectLayer::ObjectLayer()
{

}
  
ObjectLayer::~ObjectLayer()
{
	clearNpcObjectLayer();
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
		initNpcObject(level);
		initOtherPlayer();
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

void ObjectLayer::initNpcObject(const int& level)
{
	clearNpcObjectLayer();
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

void ObjectLayer::initOtherPlayer()
{
	for (auto var : CMClient::getInstance()->getPlayerList())
	{
		if (var.curmap == GetIntData("CurMap"))
		{
			auto player = XGamePlayer::create(var);
			m_playerlist.push_back(player);
			this->addChild(player);
		}
	}
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
	updateOtherPlayerScreenPos();
}

void ObjectLayer::updateNpcScreenPos()
{
	Vec2 pos;
	for (auto it : m_npcList)
	{
		pos.x = PlayerFacePos().x + (it->getX() - PlayerPos.x);
		pos.y = PlayerFacePos().y + (it->getY() - PlayerPos.y);
		it->getFace()->setPosition(pos);
		float zorder = 100.0f - (it->getY() / MapWidth) * 100;
		it->getFace()->setZOrder(zorder);
	}
}

void ObjectLayer::updateOtherPlayerScreenPos()
{
	Vec2 pos;
	for (auto var : m_playerlist)
	{
		pos.x = PlayerFacePos().x + (var->getWorldPos().x - PlayerPos.x);
		pos.y = PlayerFacePos().y + (var->getWorldPos().y - PlayerPos.y);  //»æÖÆÎó²î
		var->setPosition(pos);
		float zorder = 100.0f - (var->getWorldPos().y / MapWidth) * 100;
		var->setZOrder(zorder);
	}
}

void ObjectLayer::clearNpcObjectLayer()
{
	for (auto it : m_npcList)
	{
		RELEASE_NULL(it);
	}
	m_npcList.clear();
}

void ObjectLayer::addPlayer(Player_Info pinfo)
{
	if (GetIntData("CurMap") == pinfo.curmap)
	{
		auto it = existPlayer(pinfo.playername, pinfo.rolename);
		if (it != m_playerlist.end())
		{
			(*it)->setWorldPos(Vec2{ pinfo.x,pinfo.y });
		}
		else
		{
			auto player = XGamePlayer::create(pinfo);
			m_playerlist.push_back(player);
			this->addChild(player);
		}
	}
	else
	{
		auto it = existPlayer(pinfo.playername, pinfo.rolename);
		if (it != m_playerlist.end())
		{
			this->removeChild(*it);
			m_playerlist.erase(it);
		}
	}
}

void ObjectLayer::removePlayer(const std::string& playername, const std::string& rolename)
{
	for (auto it = m_playerlist.begin(); it != m_playerlist.end(); ++it)
	{
		if ((*it)->getPlayerName() == playername && (*it)->getRoleName() == rolename)
		{
			this->removeChild(*it);
			m_playerlist.erase(it);
			return;
		}
	}
}

std::list<XGamePlayer*>::iterator ObjectLayer::existPlayer(const std::string& playername, const std::string& rolename)
{
	for (auto it = m_playerlist.begin(); it != m_playerlist.end(); ++it)
	{
		if ((*it)->getPlayerName() == playername && (*it)->getRoleName() == rolename)
		{
			return it;
		}
	}
	return m_playerlist.end();
}

void ObjectLayer::verifyPlayerPos(const std::string& playername, const std::string& rolename, const cocos2d::Vec2& pos)
{
	for (auto var : m_playerlist)
	{
		if (var->getPlayerName() == playername&&var->getRoleName() == rolename)
		{
			var->setWorldPos(pos);
			return;
		}
	}
}

void ObjectLayer::updatePlayerData(const std::string& playername, const std::string& rolename, UpdateData_Msg msg)
{
	for (auto var : m_playerlist)
	{
		if (var->getPlayerName() == playername&&var->getRoleName() == rolename)
		{
			var->setAttack(msg.attack);
			var->setBlood(msg.blood);
			var->setDefense(msg.defense);
			var->setMana(msg.mana);
			return;
		}
	}
}

void ObjectLayer::moveOtherPlayer(const std::string& playername, const std::string& rolename, const cocos2d::Vec2& target,int less)
{
	for (auto var : m_playerlist)
	{
		if (var->getPlayerName() == playername&&var->getRoleName() == rolename)
		{
			var->moveTo(target, less);
		}
	}
}