#include"GameScene.h"
#include"GameData.h"
#include"MapLayer.h"
#include"Commen.h"

bool GameScene::init()
{
	if (Scene::init())
	{
		auto map = MapLayer::create();
		map->initMapTexture(StringValue("map1"));
		this->addChild(map);
		return true;
	}
	return false;
}