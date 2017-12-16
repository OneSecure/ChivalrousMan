#include"GameScene.h"
#include"GameData.h"
#include"GameMapLayer.h"
#include"GameLogicLayer.h"
#include"CameraPlayer.h"
#include"LoadingLayer.h"
#include"GameUILayer.h"
#include"Commen.h"

bool GameScene::init()
{
	if (Scene::init())
	{
		m_mapLayer = GameMapLayer::create();
		m_mapLayer->loadMapTexture("map1");
		m_mapLayer->drawMap(0, 0);
		this->addChild(m_mapLayer);

		auto player = Sprite::create();
		this->addChild(player);
		SetPlayerVelocity(4);
		SetPlayerFace(player);

		m_logicLayer = GameLogicLayer::create();
		this->addChild(m_logicLayer);

		auto UILayer = GameUILayer::create();
		this->addChild(UILayer);
		return true;
	}
	return false;
}