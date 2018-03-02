#include"FightLayer.h"
#include"Commen.h"
#include"Monster.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"GameScene.h"
#include"GameDynamicData.h"
#include"CameraPlayer.h"
#include"Medication.h"
#include"Skill.h"
#include"TipLayer.h"
#include"BackPackManager.h"
#include"SkillManager.h"
#include<random>
#include<functional>
#include<algorithm>

#define NoAction()   \
auto tiplayer = TipLayer::createTipLayer(StringValue("NoAction"));  \
this->addChild(tiplayer)

#define NoTarget()   \
TipLayer* tiplayer = TipLayer::createTipLayer(StringValue("NoTarget"));   \
this->addChild(tiplayer)
 
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

		m_menu = Menu::create();
		m_menu->setPosition(0, 0);
		this->addChild(m_menu);

		std::string playertype = GetStringData("PlayerType");
		playertype += "WaitLeft";
		m_player = Sprite::create(StringValue(playertype));
		m_player->setPosition(size.width - 80, size.height*0.5 - 140);
		SetPlayerFace(m_player);
		GetPlayerData().setcurblood(GetPlayerData().getblood());
		GetPlayerData().setcurmana(GetPlayerData().getmana());
		this->addChild(m_player);
		randomNumMonster(name);

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

		m_arrow = Sprite::create(StringValue("Arrow1"));
		auto move1 = MoveBy::create(0.2, ccp(0, 10));
		auto move2 = MoveBy::create(0.2, ccp(0, -10));
		auto sequece = Sequence::createWithTwoActions(move1, move2);
		m_arrow->runAction(RepeatForever::create(sequece));
		m_arrow->setPosition(m_monsterList[0]->getPositionX(),
			m_monsterList[0]->getPositionY() + 80);
		m_selectedMonster = m_monsterList[0];
		this->addChild(m_arrow);

		auto bloodBg = Sprite::create(StringValue("BarBg"));
		bloodBg->setPosition(size.width - bloodBg->getContentSize().width, size.height - bloodBg->getContentSize().height);
		auto manaBg = Sprite::create(StringValue("BarBg"));
		manaBg->setPosition(bloodBg->getPositionX(), bloodBg->getPositionY() - manaBg->getContentSize().height - 10);
		auto bloodBar = Sprite::create(StringValue("BloodBar"));
		m_playerBlood = ProgressTimer::create(bloodBar);
		m_playerBlood->setType(ProgressTimer::Type::BAR);
		m_playerBlood->setMidpoint(ccp(0, 0));
		m_playerBlood->setBarChangeRate(ccp(1, 0));
		m_playerBlood->setPercentage(100);
		m_playerBlood->setPosition(bloodBg->getPosition());
		auto manaBar = Sprite::create(StringValue("ManaBar"));
		m_playerMana = ProgressTimer::create(manaBar);
		m_playerMana->setType(ProgressTimer::Type::BAR);
		m_playerMana->setMidpoint(ccp(0, 0));
		m_playerMana->setBarChangeRate(ccp(1, 0));
		m_playerMana->setPercentage(100);
		m_playerMana->setPosition(manaBg->getPosition());
		this->addChild(bloodBg);
		this->addChild(m_playerBlood);
		this->addChild(manaBg);
		this->addChild(m_playerMana);
		
		schedule(schedule_selector(FightLayer::onTimer), 1);
		scheduleUpdate();
		if (GetIntData("IsAuto")==1)
		{
			toggle->setSelectedIndex(0);
			onToggleAutoAndHand(toggle);
		}
		else
		{
			toggle->setSelectedIndex(1);
			onToggleAutoAndHand(toggle);
		}

		m_timeLabel = LabelTTF::create(m_time, "楷体", 25);
		m_timeLabel->setColor(Color3B::YELLOW);
		m_timeLabel->setPosition(size.width*0.5, size.height - 30);
		this->addChild(m_timeLabel);
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
		auto monsterItem = MenuItem::create(this, menu_selector(FightLayer::onClickMonsterCallBack));
		monsterItem->setPosition(monster->getPosition());
		monsterItem->setTag(i);
		monsterItem->setContentSize(Size{ 140,180 });
		m_menu->addChild(monsterItem);
		this->addChild(monster);
		m_monsterList.push_back(monster);
	}
}

void FightLayer::update(float dt)
{
	if (!m_isPlayer&&m_isPlayerEnd)
	{
		if (m_lastMonsterEnd)
		{
			monsterAttackPlayer(m_curMonster++);
		}
	}
	if (GetPlayerData().getcurblood() <= 0)
	{
		EndFight("FightFailed");
	}
	else if (checkSuccess())
	{
		EndFight("FightSuccess");
	}
	updateBloodAndMana();
}

void FightLayer::calcActionOrder()
{
	
}

void FightLayer::onToggleAutoAndHand(cocos2d::CCObject* sender)
{
	if(dynamic_cast<MenuItemToggle*>(sender)->getSelectedIndex()==0)
	{
		m_time = "2";
		SetIntData("IsAuto", 1);
	}
	else
	{
		m_time = "10";
		SetIntData("IsAuto", 0);
	}
}

void FightLayer::onMedicationClickCallBack(cocos2d::CCObject* sender)
{
	Vec2 basePos = dynamic_cast<MenuItemImage*>(sender)->getPosition();
	if (!m_clickMedication)
	{
		if (m_medications.size() == 0)
		{
			int flag = 0;
			for (auto it = BackPackMap().begin(); it != BackPackMap().end(); ++it)
			{
				if (it->type == MEDICATION)
				{
					auto medication = Medication::createWithImage(it->name + ".png");
					medication->setPosition(basePos);
					medication->setTag(it->nums);    //使用tag存储药品数量
					medication->setName(NumberToString(flag));       //使用Name存储索引
					Vec2 Pos = ccp(basePos.x - 50 * (flag + 1), basePos.y);
					medication->setPosition(basePos);
					medication->setTarget(this, menu_selector(FightLayer::onMedication));
					auto move1 = MoveTo::create(0.1*(flag + 1), Pos);
					auto move2 = MoveTo::create(0.1*(flag + 1), Pos);
					m_menu->addChild(medication);
					medication->runAction(move1);
					LabelTTF* numlabel = LabelTTF::create(NumberToString(it->nums), "楷体", 20);
					numlabel->setPosition(medication->getPosition());
					numlabel->setColor(ccc3(255, 242, 0));
					this->addChild(numlabel);
					numlabel->runAction(move2);
					m_medicationNums.push_back(numlabel);
					m_medications.push_back(medication);
					++flag;
				}
			}
		}
		else
		{
			for (int i = 0; i < m_medications.size(); ++i)
			{
				Vec2 Pos = ccp(basePos.x - 50 * (i + 1), basePos.y);
				auto move = MoveTo::create(0.1*(i + 1), Pos);
				auto move1 = MoveTo::create(0.1*(i + 1), Pos);
				m_medications[i]->setVisible(true);
				m_medications[i]->runAction(move);
				m_medicationNums[i]->setVisible(true);
				m_medicationNums[i]->runAction(move1);
			}
		}
		m_clickMedication = true;
	}
	else
	{
		for (int i = 0; i < m_medications.size(); ++i)
		{
			m_medications[i]->setPosition(basePos);
			m_medications[i]->setVisible(false);
			m_medicationNums[i]->setPosition(basePos);
			m_medicationNums[i]->setVisible(false);
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
			int index = 0;
			for (auto var: SkillManager::getInstance()->getSkillMap())
			{
				std::string realname = StringValue(var.first);
				realname += var.first;
				realname += ".png";
				auto skill = Skill::createWithImage(realname);
				skill->setgrade(var.second);
				skill->setPosition(basePos);
				skill->setTarget(this, menu_selector(FightLayer::onSkill));
				m_menu->addChild(skill);
				m_skills.push_back(skill);
				Vec2 pos = ccp(basePos.x - 50 * (index + 1), basePos.y);
				auto Move = MoveTo::create(0.1*(index + 1), pos);
				skill->runAction(Move);
				++index;
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
	if (m_isPlayer)
	{
		std::random_device rand;
		m_isPlayer = false;
		if (rand() % 100 < 40)
		{
			unscheduleUpdate();
			auto gs = GameScene::createWithLevel(GetIntData("CurMap"));
			auto reScene = TransitionFadeDown::create(1, gs);
			Director::sharedDirector()->replaceScene(reScene);
		}
		else
		{
			auto tiplayer = TipLayer::createTipLayer(StringValue("RunFailed"));
			this->addChild(tiplayer);
			m_isPlayerEnd = true;
			m_timeLabel->setVisible(false);
			m_arrow->setVisible(false);
		}
	}
	else
	{
		NoAction();
	}
}

void FightLayer::onAttackClickCallBack(cocos2d::CCObject * sender)
{
	if (m_isPlayer) 
	{
		if (!m_selectedMonster->isDie())
		{
			playerAttackMonster();
		}
		else
		{
			NoTarget();
		}
	}
	else
	{
		NoAction();
	}
}

void FightLayer::onClickMonsterCallBack(cocos2d::CCObject* sender)
{
	auto dest = dynamic_cast<MenuItem*>(sender)->getPosition();
	dest.y += 80;
	auto moveto = MoveTo::create(0.3, dest);
	m_arrow->runAction(moveto);
	int i = dynamic_cast<MenuItem*>(sender)->getTag();
	m_selectedMonster = m_monsterList[i];
}

void FightLayer::onTimer(float dt)
{
	if (m_isPlayer)
	{
		std::string time = m_timeLabel->getString();
		float ftime = std::stof(time) - 1;
		if (ftime == 0)
		{
			if (m_selectedMonster->isDie())
				reSelectMonster();
			playerAttackMonster();
		}
		m_timeLabel->setString(NumberToString(ftime));
	}
}

void FightLayer::playerAttackMonster()
{
	m_isPlayer = false;
	m_isPlayerEnd = false;
	Vec2 pos = m_player->getPosition();
	Vec2 dest = m_selectedMonster->getPosition();
	dest.x += 20;
	dest.y -= 40;
	m_player->runAction(MoveTo::create(0.5, dest));
	std::function<void(float)> func = [this,pos](float dt) {
		this->m_selectedMonster->beAttack(GetPlayerData().getattack());
		this->m_player->runAction(MoveTo::create(0.5, pos));
	};
	scheduleOnce(func, 0.7, "player");
	std::function<void(float)> func2 = [this](float) {
		this->m_isPlayerEnd = true;
	};
	scheduleOnce(func2, 1.4, "reset");
	m_timeLabel->setVisible(false);
	m_arrow->setVisible(false);
}

void FightLayer::monsterAttackPlayer(int index)
{
	if (index >= m_monsterList.size())
	{
		this->m_isPlayer = true;
		this->m_timeLabel->setVisible(true);
		this->m_arrow->setVisible(true);
		this->m_timeLabel->setString(this->m_time);
		this->m_curMonster = 0;
		return;
	}
	if (!m_monsterList[index]->isDie())
	{
		m_lastMonsterEnd = false;
		Vec2 pos = m_monsterList[index]->getPosition();
		Vec2 dest = m_player->getPosition();
		dest.x -= 20;
		dest.y += 40;
		m_monsterList[index]->runAction(MoveTo::create(0.5, dest));
		std::function<void(float)> func = [this, pos, index](float) {
			AttackPlayer(this->m_monsterList[index]->getattack());
			this->m_monsterList[index]->runAction(MoveTo::create(0.5, pos));
		};
		scheduleOnce(func, 0.7, "monster");
		std::function<void(float)> func2 = [this](float) {
			this->m_lastMonsterEnd = true;
		};
		scheduleOnce(func2, 1.4, "reset");
	}
}

void FightLayer::EndFight(std::string tip)
{
	pauseSchedulerAndActions();
	auto tipLayer = TipLayer::createTipLayer(StringValue(tip));
	this->addChild(tipLayer);
	endFunc(0.0);
}

void FightLayer::endFunc(float dt)
{
	std::string tip = StringValue("Glod") + "+" + NumberToString(m_settlementGlod) +
		"," + StringValue("Exp") + "+" + NumberToString(m_settlementExp);
	TipLayer* tiplayer = TipLayer::createTipLayer(tip);
	GetPlayerData().addGlod(m_settlementGlod);
	GetPlayerData().addExp(m_settlementExp);
	auto gs = GameScene::createWithLevel(GetIntData("CurMap"));
	gs->addChild(tiplayer);
	auto reScene = TransitionFadeDown::create(1, gs);
	Director::sharedDirector()->replaceScene(reScene);
}

void FightLayer::updateBloodAndMana()
{
	float perb = GetPlayerData().getcurblood() / GetPlayerData().getblood();
	float perm = GetPlayerData().getcurmana() / GetPlayerData().getmana();
	m_playerBlood->setPercentage(perb * 100);
	m_playerMana->setPercentage(perm * 100);
}

void FightLayer::removeMonster(Monster* monster)
{
	m_settlementGlod += monster->getglod();
	m_settlementExp += monster->getexp();
	monster->setVisible(false);
}

bool FightLayer::checkSuccess()
{
	for (auto var : m_monsterList)
	{
		if (!var->isDie())
		{
			return false;
		}
	}
	return true;
}

void FightLayer::onMedication(cocos2d::CCObject* sender)
{
	if (m_isPlayer)
	{
		auto pth = dynamic_cast<Thing*>(sender);
		if (pth->getTag() > 0)
		{
			float delay = pth->beUse(this);
			m_isPlayer = false;
			m_isPlayerEnd = true;
			m_timeLabel->setVisible(false);
			m_arrow->setVisible(false);
			pth->setTag(pth->getTag() - 1);
			BackPackManager::getInstance()->removeBackPackThing(pth->getname());
			m_medicationNums[std::stoi(pth->getName())]->setString(NumberToString(pth->getTag()));
		}
		else
		{
			TipLayer* tiplayer = TipLayer::createTipLayer(StringValue("LackNums"));
			this->addChild(tiplayer);
		}
	}
}

void FightLayer::onSkill(cocos2d::CCObject* sender)
{
	if (m_isPlayer)
	{
		ClickAction(sender);
		if (m_selectedMonster->isDie())
		{
			NoTarget();
			return;
		}
		float delay = dynamic_cast<Thing*>(sender)->beUse(this);
		if (delay!= -1)
		{
			m_isPlayer = false;
			m_isPlayerEnd = false;
			std::function<void(float)> func = [this](float) {
				this->m_isPlayerEnd = true;
			};
			scheduleOnce(func, delay + 0.5, "item");
			m_timeLabel->setVisible(false);
			m_arrow->setVisible(false);
		}
	}
	else
	{
		NoAction();
	}
}

void FightLayer::reSelectMonster()
{
	for (auto var : m_monsterList)
	{
		if (!var->isDie())
		{
			m_selectedMonster = var;
			m_arrow->setPosition(var->getPositionX(), var->getPositionY() + 80);
		}
	}
}