#include"SelectScene.h"
#include"Commen.h"
#include"SelectLayer.h"
#include"GameData.h"

bool SelectScene::init()
{
	if (Scene::init())
	{
		auto stLayer = SelectLayer::create();
		this->addChild(stLayer);
		return true;
	}
	
	return false;
}