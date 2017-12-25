#include"SelectLayer.h"
#include"StartMenu.h"
#include"GameScene.h"
#include"GameData.h"
#include"Commen.h"
#include"GameDynamicData.h"
#include"DBDao.h"
#include"GameScene.h"
#include<functional>
#include"ExcessiveScene.h"

#define ARROW_H 0.28

bool SelectLayer::init()
{
	if (Layer::init())
	{
		auto back = Sprite::create(StringValue("StartBg"), Rect{ 0,0,SCREEN.width,SCREEN.height });
		back->setPosition(SCREEN.width*0.5, SCREEN.height*0.5);
		this->addChild(back);

		LISTEN_TOUCH(SelectLayer);

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

void SelectLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{

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
	auto startmap = GameScene::createWithLevel(LEVEL_ONE);
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