#include"BeginScene.h"
#include"BeginLayer.h"
#include"Commen.h"

bool BeginScene::init()
{
	if (Scene::init())
	{
		auto beginlayer = BeginLayer::create();
		this->addChild(beginlayer);
		return true;
	}
	return false;
}

