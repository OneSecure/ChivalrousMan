#include"StartMenu.h"
#include"Commen.h"
#include"GameData.h"
#include"SelectScene.h"
#include"EndScene.h"
#include"NewGameScene.h"

bool StartMenu::init()
{
	if (Scene::init())
	{
		auto bgSprite = Sprite::create(StringValue("StartBg"),Rect{ 0,0,SCREEN.width, SCREEN.height });
		bgSprite->setPosition(SCREEN.width*0.5, SCREEN.height*0.5);
		
		auto Gmenu = Menu::create();
		auto NewBtn = MenuItemLabel::create(Label::create(
			StringValue("NewGame"), "¿¬Ìå", 45),
			this, menu_selector(StartMenu::NewBtnCallBack));
		auto EntryBtn = MenuItemLabel::create(Label::create(
			StringValue("EntryGame"), "¿¬Ìå", 45),
			this, menu_selector(StartMenu::EntryCallBack));
		auto QuitBtn = MenuItemLabel::create(Label::create(
			StringValue("QuitGame"), "¿¬Ìå", 45),
			this, menu_selector(StartMenu::QuitCallBack));
		
		NewBtn->setColor(Color3B::BLACK);
		EntryBtn->setColor(Color3B::BLACK);
		QuitBtn->setColor(Color3B::BLACK);
		NewBtn->setPosition(SCREEN.width*0.5, SCREEN.height*0.6);
		EntryBtn->setPosition(SCREEN.width*0.5, SCREEN.height*0.5);
		QuitBtn->setPosition(ccp(SCREEN.width*0.5, SCREEN.height*0.4));
		
		Gmenu->addChild(NewBtn);
		Gmenu->addChild(EntryBtn);
		Gmenu->addChild(QuitBtn);
		Gmenu->setPosition(ccp(0, 0));
		this->addChild(bgSprite);
		this->addChild(Gmenu);
		return true;
	}
	return false;
}

void StartMenu::NewBtnCallBack(cocos2d::CCObject* obj)
{
	auto ngScene = NewGameScene::create();
	auto reScene = CCTransitionTurnOffTiles::create(1.0, ngScene);
	Director::getInstance()->replaceScene(reScene);
}

void StartMenu::EntryCallBack(cocos2d::CCObject* obj)
{
	auto stScene = SelectScene::create();
	auto rpScene = CCTransitionFadeDown::create(1.0f, stScene);
	Director::getInstance()->replaceScene(rpScene);
}

void StartMenu::QuitCallBack(cocos2d::CCObject* obj)
{
	auto endScene = EndScene::create();
	auto reScene = CCTransitionMoveInL::create(1.0, endScene);
	Director::getInstance()->replaceScene(reScene);
}