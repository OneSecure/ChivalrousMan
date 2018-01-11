#include"FightLayer.h"
#include"Commen.h"
#include"Monster.h"

Scene* FightLayer::createFightScene(Monster* monster)
{
	FightLayer* pRet = new FightLayer;
	if (pRet&&pRet->init(monster))
	{
		pRet->autorelease();
		Scene* scene = Scene::create();
		scene->addChild(pRet);
		return scene;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool FightLayer::init(Monster* monster)
{
	if (Layer::init())
	{
		
		return true;
	}
	return false;
}