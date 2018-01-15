#include"FightLayer.h"
#include"Commen.h"
#include"Monster.h"
#include"GameData.h"
#include"GameScene.h"
#include"GameDynamicData.h"
#include"CameraPlayer.h"
#include"Medication.h"
#include"Skill.h"
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

		m_menu = Menu::create();
		m_menu->setPosition(0, 0);
		this->addChild(m_menu);

		auto AutoBtn = MenuItemImage::create(StringValue("AutoBtn"),
			StringValue("AutoBtn"));
		auto UseHandBtn = MenuItemImage::create(StringValue("UseHandBtn"),
			StringValue("UseHandBtn"));
		auto toggle = MenuItemToggle::createWithCallback(CC_CALLBACK_1(FightLayer::onToggleAutoAndHand, this),UseHandBtn, AutoBtn, NULL);
		toggle->setPosition(size.width - 35, 35);
		m_menu->addChild(toggle);
		
		auto MeBtn = MenuItemImage::create(StringValue("MeNormalBtn"),
			StringValue("MePressedBtn"), this,
			menu_selector(FightLayer::onMedicationClickCallBack));
		MeBtn->setPosition(size.width - 35, 35 + 45);
		m_menu->addChild(MeBtn);

		auto SkillBtn = MenuItemImage::create(StringValue("SkillNormalBtn"),
			StringValue("SkillPressedBtn"), this,
			menu_selector(FightLayer::onSkillClickCallBack));
		SkillBtn->setPosition(size.width - 35, 35 + 90);
		m_menu->addChild(SkillBtn);

		auto RunBtn = MenuItemImage::create(StringValue("RunNormalBtn"),
			StringValue("RunPressedBtn"), this,
			menu_selector(FightLayer::onRunClickCallBack));
		RunBtn->setPosition(size.width - 35, 35 + 135);
		m_menu->addChild(RunBtn);

		auto AttackBtn = MenuItemImage::create(StringValue("AttackNormalBtn"),
			StringValue("AttackPressedBtn"), this,
			menu_selector(FightLayer::onAttackClickCallBack));
		AttackBtn->setPosition(size.width - 35, 35 + 180);
		m_menu->addChild(AttackBtn);

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
	Vec2 basePos = dynamic_cast<MenuItemImage*>(sender)->getPosition();
	if (!m_clickMedication)
	{
		if (m_medications.size() == 0)
		{
			std::string names[] = { "BlueMedication","RedMedication","DontMedication" };
			for (int i = 0; i < 3; ++i)
			{
				auto medication = Medication::createWithImage(StringValue(names[i]));
				medication->setPosition(basePos);
				Vec2 Pos = ccp(basePos.x - 50 * (i + 1), basePos.y);
				medication->setPosition(basePos);
				medication->setTarget(this, menu_selector(FightLayer::onItemClickCallBack));
				auto move = MoveTo::create(0.1*(i + 1), Pos);
				m_menu->addChild(medication);
				medication->runAction(move);
				m_medications.push_back(medication);
			}
		}
		else
		{
			for (int i = 0; i < m_medications.size(); ++i)
			{
				Vec2 Pos = ccp(basePos.x - 50 * (i + 1), basePos.y);
				auto move = MoveTo::create(0.1*(i + 1), Pos);
				m_medications[i]->setVisible(true);
				m_medications[i]->runAction(move);
			}
		}
		m_clickMedication = true;
	}
	else
	{
		for (auto it : m_medications)
		{
			it->setPosition(basePos);
			it->setVisible(false);
		}
		m_clickMedication = false;
	}
}

void FightLayer::onSkillClickCallBack(cocos2d::CCObject * sender)
{
	Vec2 basePos = dynamic_cast<MenuItemImage*>(sender)->getPosition();
	if (!m_clickskill)
	{
		if (m_skills.size() == 0)
		{
			std::string names[] = { "CrackIt","Dante","DragonRoar" };
			for (int i = 0; i < 3; ++i)
			{
				std::string realname = StringValue(names[i]);
				realname += names[i];
				realname += ".png";
				auto skill = Skill::createWithImage(realname);
				skill->setPosition(basePos);
				skill->setTarget(this, menu_selector(FightLayer::onItemClickCallBack));
				m_menu->addChild(skill);
				m_skills.push_back(skill);
				Vec2 pos = ccp(basePos.x - 50 * (i + 1), basePos.y);
				auto Move = MoveTo::create(0.1*(i + 1), pos);
				skill->runAction(Move);
			}
		}
		else
		{
			for (int i = 0; i < m_skills.size(); ++i)
			{
				m_skills[i]->setVisible(true);
				Vec2 pos = ccp(basePos.x - 50 * (i + 1), basePos.y);
				auto move = MoveTo::create(0.1*(i + 1), pos);
				m_skills[i]->runAction(move);
			}
		}
		m_clickskill = true;
	}
	else
	{
		for (int i = 0; i < m_skills.size(); ++i)
		{
			m_skills[i]->setPosition(basePos);
			m_skills[i]->setVisible(false);
		}
		m_clickskill = false;
	}
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

void FightLayer::onItemClickCallBack(cocos2d::CCObject* sender)
{
	ClickAction();
}