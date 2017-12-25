#include"GameMenuLayer.h"
#include"Commen.h"
#include"GameDynamicData.h"
#include"GameData.h"
#include"GameScene.h"
#include"StartMenu.h"

bool GameMenuLayer::init()
{
	if (Layer::init())
	{
		this->setOpacity(0.5);
		auto size = SCREEN;
		auto back = Sprite::create(StringValue("MenuBg"));
		back->setContentSize(Size{ size.width*0.6f,size.height*0.6f });
		back->setPosition(size.width*0.35, size.height*0.45);
		this->addChild(back);
		
		auto menu = Menu::create();
		menu->setPosition(0, 0);
		this->addChild(menu);

		auto label = LabelTTF::create(StringValue("MusicText"), "楷体", 40);
		label->setColor(ccc3(0, 0, 0));
		label->setPosition(size.width*0.5, size.height*0.7);
		this->addChild(label);
		auto menuTrunOn = MenuItemImage::create(StringValue("TrunOn"), StringValue("TrunOn"));
		auto menuTrunOff = MenuItemImage::create(StringValue("TrunOff"), StringValue("TrunOff"));
		auto toggle = MenuItemToggle::createWithCallback(CC_CALLBACK_1(GameMenuLayer::onMusicCallBack, this), menuTrunOn, menuTrunOff, NULL);
		toggle->setPosition(label->getPosition().x + label->getContentSize().width*0.5 + 20, label->getPosition().y);
		menu->addChild(toggle);
		if (GetIntData("BgMusic") == 1)
			toggle->setSelectedIndex(1);
		else
			toggle->setSelectedIndex(0);

		auto backGame = MenuItemLabel::create(Label::create(StringValue("BackGame"), "楷体", 40),
			this, menu_selector(GameMenuLayer::onBackGameCallBack));
		backGame->setColor(ccc3(0, 0, 0));
		backGame->setPosition(size.width*0.5, size.height*0.6);
		menu->addChild(backGame);

		auto func = [this](cocos2d::CCObject*) 
		{
			GO_BACK_START_MENU();
		};
		auto backMainMenu = MenuItemLabel::create(Label::create(StringValue("BackMainMenu"), "楷体", 40), func);
		backMainMenu->setPosition(size.width*0.5, size.height*0.5);
		backMainMenu->setColor(ccc3(0, 0, 0));
		menu->addChild(backMainMenu);

		auto changeCount = MenuItemLabel::create(Label::create(StringValue("ChangeCount"), "楷体", 40));
		changeCount->setColor(ccc3(0, 0, 0));
		changeCount->setPosition(size.width*0.5, size.height*0.4);
		menu->addChild(changeCount);
		
		return true;
	}
	return false;
}

void GameMenuLayer::onMusicCallBack(cocos2d::CCObject* sender)
{
	ToggleMusic();
}

void GameMenuLayer::onBackGameCallBack(cocos2d::CCObject* sender)
{
	((GameScene*)(this->getParent()->getParent()))->resumeAllActions(this->getParent()->getParent());
	this->getParent()->removeChild(this);
}