#include"FightLayer.h"
#include"Commen.h"
#include"Monster.h"
#include"GameData.h"
#include"GameScene.h"
#include"GameDynamicData.h"
#include"CameraPlayer.h"
#include<random>
#include<algorithm>

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

		auto menu = Menu::create();
		menu->setPosition(0, 0);
		this->addChild(menu);

		auto AutoBtn = MenuItemImage::create(StringValue("AutoBtn"),
			StringValue("AutoBtn"));
		auto UseHandBtn = MenuItemImage::create(StringValue("UseHandBtn"),
			StringValue("UseHandBtn"));
		auto toggle = MenuItemToggle::createWithCallback(CC_CALLBACK_1(FightLayer::onToggleAutoAndHand, this),UseHandBtn, AutoBtn, NULL);
		toggle->setPosition(size.width - 35, 35);
		menu->addChild(toggle);
		
		auto MeBtn = MenuItemImage::create(StringValue("MeNormalBtn"),
			StringValue("MePressedBtn"), this,
			menu_selector(FightLayer::onMedicationClickCallBack));
		MeBtn->setPosition(size.width - 35, 35 + 45);
		menu->addChild(MeBtn);

		auto SkillBtn = MenuItemImage::create(StringValue("SkillNormalBtn"),
			StringValue("SkillPressedBtn"), this,
			menu_selector(FightLayer::onSkillClickCallBack));
		SkillBtn->setPosition(size.width - 35, 35 + 90);
		menu->addChild(SkillBtn);

		auto RunBtn = MenuItemImage::create(StringValue("RunNormalBtn"),
			StringValue("RunPressedBtn"), this,
			menu_selector(FightLayer::onRunClickCallBack));
		RunBtn->setPosition(size.width - 35, 35 + 135);
		menu->addChild(RunBtn);

		auto AttackBtn = MenuItemImage::create(StringValue("AttackNormalBtn"),
			StringValue("AttackPressedBtn"), this,
			menu_selector(FightLayer::onAttackClickCallBack));
		AttackBtn->setPosition(size.width - 35, 35 + 180);
		menu->addChild(AttackBtn);

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

void FightLayer::calcActionOrder()
{
}

void FightLayer::onToggleAutoAndHand(cocos2d::CCObject* sender)
{

}

void FightLayer::onMedicationClickCallBack(cocos2d::CCObject* sender)
{
	
}

void FightLayer::onSkillClickCallBack(cocos2d::CCObject * sender)
{
	
}

void FightLayer::onRunClickCallBack(cocos2d::CCObject * sender)
{
	unscheduleUpdate();
	auto gs = GameScene::createWithLevel(GetIntData("CurMap"));
	auto reScene = TransitionFadeDown::create(1, gs);
	Director::sharedDirector()->replaceScene(reScene);
}

void FightLayer::onAttackClickCallBack(cocos2d::CCObject * sender)
{
	
}

