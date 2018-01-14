#include"FightLayer.h"
#include"Commen.h"
#include"Monster.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include<random>

FightLayer::FightLayer()
{
	
}

FightLayer::~FightLayer()
{

}

Scene* FightLayer::createFightScene(const std::string& name)
{
	FightLayer* pRet = new FightLayer;
	if (pRet&&pRet->init(name))
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

bool FightLayer::init(const std::string& name)
{
	if (Layer::init())
	{
		auto size = SCREEN;
		auto back = Sprite::create(StringValue("FightBg"));
		back->setPosition(size.width * 0.5, size.height*0.5);
		this->addChild(back);

		std::string playertype = GetStringData("PlayerType");
		playertype += "WaitLeft";
		m_player = Sprite::create(StringValue(playertype));
		m_player->setPosition(size.width - 80, size.height*0.5 - 100);
		this->addChild(m_player);
		randomNumMonster(name);
		scheduleUpdate();
		return true;
	}
	return false;
}

void FightLayer::randomNumMonster(const std::string& name)
{
	std::random_device  rnd;
	int num = rnd() % 4 + 1;
	Vec2 basePos;
	basePos.x = 80;
	basePos.y = SCREEN.height*0.5 - 100;
	for (int i = 0; i < num; ++i)
	{
		Monster* monster = Monster::createWithName(name);
		float x = i % 2;
		float y = i / 2;
		monster->setPosition(140 * x + basePos.x, y * 200 + basePos.y);
		m_monsterList.push_back(monster);
		this->addChild(monster);
	}
}

void FightLayer::update(float dt)
{
	
}
