#include"SelectLayer.h"
#include"StartMenu.h"
#include"GameScene.h"
#include"GameData.h"
#include"Commen.h"

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

		auto playerAnimation = AnimationCache::getInstance()->getAnimation("Player1");
		auto playerAnimate = Animate::create(playerAnimation);
		auto player = Sprite::create(StringValue("Player1"));
		player->setPosition(SCREEN.width*0.24, SCREEN.height*0.525);
		player->runAction(RepeatForever::create(playerAnimate));
		this->addChild(player);

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
		moveArrow(0.5,ccp(SCREEN.width*0.25, SCREEN.height*ARROW_H));
		break;
	case 102:
		moveArrow(0.5,ccp(SCREEN.width*0.25 * 2, SCREEN.height*ARROW_H));
		break;
	case 103:
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
	auto startmap = GameScene::create();
	auto reScene = CCTransitionFadeDown::create(1.0f, startmap);
	Director::getInstance()->replaceScene(reScene);
}

void SelectLayer::onCancelCallBack(cocos2d::CCObject* sender)
{
	GO_BACK_START_MENU();
}