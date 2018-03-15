#include"GameScene.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"GameMapLayer.h"
#include"GameLogicLayer.h"
#include"CameraPlayer.h"
#include"LoadingLayer.h"
#include"GameUILayer.h"
#include"ObjectLayer.h"
#include"Commen.h"
#include"CMClient.h"

GameScene*  GameScene::createWithLevel(const int& level)
{
	GameScene* pRet = new GameScene;
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

bool GameScene::init(const int& level)
{
	if (Scene::init())
	{
		m_level = level;
		SetCurGameScene(this);
		setName("GameScene");
		initScene();
		return true;
	}
	return false;
}

void GameScene::initScene()
{
	char mapname[40] = { 0 };
	sprintf_s(mapname, "map%d", m_level);
	SetIntData("CurMap", m_level);
	m_mapLayer = GameMapLayer::create();
	m_mapLayer->loadMapTexture(mapname);
	m_mapLayer->drawMap(0, 0);
	this->addChild(m_mapLayer);

	m_objectLayer = ObjectLayer::createWithLevel(m_level);
	this->addChild(m_objectLayer);

	char name[40] = { 0 };
	sprintf_s(name, "%sWaitDown", GetStringData("PlayerType").c_str());
	auto player = Sprite::create(StringValue(name));
	player->setName("GamePlayer");
	m_objectLayer->addChild(player);
	SetPlayerVelocity(FloatValue("PlayerSpeed"));
	SetPlayerFace(player);
	InitPlayerState(m_level);

	m_logicLayer = GameLogicLayer::create();
	this->addChild(m_logicLayer);

	m_uiLayer = GameUILayer::create();
	this->addChild(m_uiLayer);
	SetIntData("Save", 1);
	SetIntData("IsHaveGameScene", 1);
	CMClient::getInstance()->SendInitPos();
}

void GameScene::pauseAllActions(cocos2d::Node* hoster,cocos2d::Node* except)
{
	hoster->pauseSchedulerAndActions();
	auto NodeArray = hoster->getChildren();
	if (NodeArray.size() > 0)
	{
		for (auto it : NodeArray)
		{
			if (it != except)
				pauseAllActions(it);
		}
	}
}

void GameScene::resumeAllActions(cocos2d::Node* hoster)
{
	hoster->resumeSchedulerAndActions();
	auto NodeArray = hoster->getChildren();
	if (NodeArray.size() > 0)
	{
		for (auto it : NodeArray)
		{
			resumeAllActions(it);
		}
	}
}

void GameScene::pauseOrResumeLogicLayer(bool b)
{
	if (b)
	{
		m_logicLayer->pauseSchedulerAndActions();
	}
	else
	{
		m_logicLayer->resumeSchedulerAndActions();
	}
}

void GameScene::resetGamePlayer()
{
	SetPlayerFace((Sprite*)m_objectLayer->getChildByName("GamePlayer"));
}

void GameScene::pauseOrResumeAllLayer(bool b)
{
	if (b)
	{
		m_logicLayer->pauseSchedulerAndActions();
		m_mapLayer->pauseSchedulerAndActions();
		m_objectLayer->pauseSchedulerAndActions();
		m_objectLayer->clearOtherPlayer();
		m_uiLayer->pauseSchedulerAndActions();
	}
	else
	{
		m_logicLayer->resumeSchedulerAndActions();
		m_mapLayer->resumeSchedulerAndActions();
		m_objectLayer->resumeSchedulerAndActions();
		m_uiLayer->resumeSchedulerAndActions();
	}
}