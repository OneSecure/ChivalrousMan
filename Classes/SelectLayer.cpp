#include"SelectLayer.h"
#include"StartMenu.h"
#include"GameScene.h"
#include"GameData.h"
#include"Commen.h"
#include"GameDynamicData.h"
#include"DBDao.h"
#include"GameScene.h"
#include"CameraPlayer.h"
#include"ExcessiveScene.h"
#include"BackPackManager.h"
#include"SkillManager.h"
#include"EquipmentManager.h"
#include"TaskSystem.h"
#include"CMClient.h"
#include<functional>

#define ARROW_H 0.28

bool SelectLayer::init()
{
	if (Layer::init())
	{
		auto back = Sprite::create(StringValue("StartBg"), Rect{ 0,0,SCREEN.width,SCREEN.height });
		back->setPosition(SCREEN.width*0.5, SCREEN.height*0.5);
		this->addChild(back);
		STONE_STATION(0.25, 0.4, SelectLayer::onMenuCallBack, this);
		initPlayerView();
		m_arrow = Sprite::create(StringValue("Arrow"));
		m_arrow->setPosition(SCREEN.width*0.25, SCREEN.height*ARROW_H);
		this->addChild(m_arrow);                                                                                                                    

		COMMEN_BTN(this, SelectLayer::onConfirmCallBack,
			SelectLayer::onCancelCallBack);
		return true;
	}

	return false;
}

void SelectLayer::onMenuCallBack(cocos2d::CCObject* sender)
{
	switch(dynamic_cast<MenuItemImage*>(sender)->getTag())
	{
	case 101:
		m_flag = 0;
		moveArrow(0.5,ccp(SCREEN.width*0.25, SCREEN.height*ARROW_H));
		break;
	case 102:
		m_flag = 1;
		moveArrow(0.5,ccp(SCREEN.width*0.25 * 2, SCREEN.height*ARROW_H));
		break;
	case 103:
		m_flag = 2;
		moveArrow(0.5,ccp(SCREEN.width*0.25 * 3, SCREEN.height*ARROW_H));
		break;
	default:
		break;
	}
}

void SelectLayer::moveArrow(float delay,cocos2d::Vec2 dest)
{
	auto move = MoveTo::create(delay, dest);
	m_arrow->runAction(move);
}

void SelectLayer::onConfirmCallBack(cocos2d::CCObject* sender)
{
	if (m_flag > m_roleList.size() - 1)
	{
		MessageBox("请选择有效角色", "提示");
		return;
	}
	SetStringData("rolename", m_roleList[m_flag].getroleName());
	SetStringData("PlayerType", m_roleList[m_flag].getroleType());
	SetFloatData("DestX", std::stof(m_roleList[m_flag].getdestx()));;
	SetFloatData("DestY", std::stof(m_roleList[m_flag].getdesty()));
	SetIntData("CurMap", std::stoi(m_roleList[m_flag].getlevel()));
	initPlayerData(m_roleList[m_flag]);
	auto startmap = GameScene::createWithLevel(GetIntData("CurMap"));
	CC_SAFE_RETAIN(startmap);
	std::function<bool(void)> func = [] {  return true; };
	auto excessive = ExcessiveScene::createExcessice(startmap, func, 1);
	Director::getInstance()->replaceScene(excessive);
}

void SelectLayer::onCancelCallBack(cocos2d::CCObject* sender)
{
	GO_BACK_START_MENU();
}

void SelectLayer::initPlayerView()
{
	DBDao<PlayerInfo> dao;
	PlayerInfo playerinfo;
	playerinfo.setplayerName(GetStringData("playername"));
	dao.setModel(playerinfo);
	std::vector<PlayerInfo> list = dao.queryModel();
	char name[40] = { 0 };
	for (int i = 0; i < list.size(); ++i)
	{
		m_roleList.push_back(list[i]);
		sprintf_s(name, "%sRunDown", list[i].getroleType().c_str());
		auto playerAnimation = AnimationCache::getInstance()->getAnimation(name);
		auto playerAnimate = Animate::create(playerAnimation);
		sprintf_s(name, "%sWaitDown", list[i].getroleType().c_str());
		auto player = Sprite::create(StringValue(name));
		player->setPosition(SCREEN.width*(0.25 + i*0.25), SCREEN.height*0.525);
		player->runAction(RepeatForever::create(playerAnimate));
		this->addChild(player);
	}
}
void  SelectLayer::initPlayerData(PlayerInfo& info)
{
	GetPlayerData().setattack(std::stof(info.getattack()));
	GetPlayerData().setblood(std::stof(info.getblood()));
	GetPlayerData().setdefense(std::stof(info.getdefense()));
	GetPlayerData().setexp(std::stof(info.getexp()));
	GetPlayerData().setglod(std::stof(info.getglod()));
	GetPlayerData().setgrade(std::stof(info.getgrade()));
	GetPlayerData().setmana(std::stof(info.getmana()));
	GetPlayerData().setmaxExp(std::stof(info.getmaxExp()));
	GetPlayerData().setspeed(std::stof(info.getspeed()));
	BackPackManager::getInstance()->readBackpackInfo();
	EquipmentManager::getInstance()->readEquipmentInfo();
	SkillManager::getInstance()->readSkillInfo();
	CMClient::getInstance()->SendEntryMsg();
}
