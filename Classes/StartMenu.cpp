#include"StartMenu.h"
#include"Commen.h"
#include"GameData.h"
#include"SelectScene.h"
#include"EndScene.h"
#include"GameDynamicData.h"
#include"NewGameScene.h"

bool StartMenu::init()
{
	if (Scene::init())
	{
		auto size = SCREEN;
		auto bgSprite = Sprite::create(StringValue("StartBg"),Rect{ 0,0,size.width, size.height });
		bgSprite->setPosition(size.width*0.5, size.height*0.5);
		
		auto Gmenu = Menu::create();
		auto NewBtn = MenuItemLabel::create(Label::create(
			StringValue("NewGame"), "楷体", 45),
			this, menu_selector(StartMenu::NewBtnCallBack));
		auto EntryBtn = MenuItemLabel::create(Label::create(
			StringValue("EntryGame"), "楷体", 45),
			this, menu_selector(StartMenu::EntryCallBack));
		auto QuitBtn = MenuItemLabel::create(Label::create(
			StringValue("QuitGame"), "楷体", 45),
			this, menu_selector(StartMenu::QuitCallBack));
		
		NewBtn->setColor(Color3B::BLACK);
		EntryBtn->setColor(Color3B::BLACK);
		QuitBtn->setColor(Color3B::BLACK);
		NewBtn->setPosition(size.width*0.5, size.height*0.6);
		EntryBtn->setPosition(size.width*0.5, size.height*0.5);
		QuitBtn->setPosition(ccp(size.width*0.5, size.height*0.4));
		
		auto menuTrunOn = MenuItemImage::create(StringValue("TrunOn"), StringValue("TrunOn"));
		auto menuTrunOff = MenuItemImage::create(StringValue("TrunOff"), StringValue("TrunOff"));
		auto toggle = MenuItemToggle::createWithCallback(CC_CALLBACK_1(StartMenu::onMusicOnOrOffCallBack, this), menuTrunOn, menuTrunOff, NULL);
		toggle->setPosition(size.width*0.9, size.height*0.9);
		if (GetIntData("BgMusic") == 1)
			toggle->setSelectedIndex(1);
		else
			toggle->setSelectedIndex(0);

		Gmenu->addChild(NewBtn);
		Gmenu->addChild(EntryBtn);
		Gmenu->addChild(QuitBtn);
		Gmenu->addChild(toggle);
		Gmenu->setPosition(ccp(0, 0));
		this->addChild(bgSprite);
		this->addChild(Gmenu);

		auto musicLabel = LabelTTF::create(StringValue("MusicText"), "楷体", 30);
		musicLabel->setColor(ccc3(88, 16, 148));
		musicLabel->setPosition(size.width*0.8, size.height*0.9);
		this->addChild(musicLabel);
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

void StartMenu::onMusicOnOrOffCallBack(cocos2d::CCObject* sender)
{
	ToggleMusic();
}