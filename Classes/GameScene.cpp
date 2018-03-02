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
		SetCurGameScene(this);
		char mapname[40] = { 0 };
		sprintf_s(mapname, "map%d", level);
		SetIntData("CurMap", level);
		m_mapLayer = GameMapLayer::create();
		m_mapLayer->loadMapTexture(mapname);
		m_mapLayer->drawMap(0, 0);
		this->addChild(m_mapLayer);

		m_objectLayer = ObjectLayer::createWithLevel(level);
		this->addChild(m_objectLayer);

		char name[40] = { 0 };
		sprintf_s(name, "%sWaitDown", GetStringData("PlayerType").c_str());
		auto player = Sprite::create(StringValue(name));
		this->addChild(player);
		SetPlayerVelocity(FloatValue("PlayerSpeed"));
		SetPlayerFace(player);
		InitPlayerState(level);

		m_logicLayer = GameLogicLayer::create();
		this->addChild(m_logicLayer);

		auto UILayer = GameUILayer::create();
		this->addChild(UILayer);
		SetIntData("Save", 1);
		return true;
	}
	return false;
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