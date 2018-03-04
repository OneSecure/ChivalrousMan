#include"BeginLayer.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"Login.h"
#include"SignOn.h"
#include"Commen.h"

bool BeginLayer::init()
{
	if (Layer::init())
	{
		Size size = SCREEN;
		auto back = Sprite::create(StringValue("LoginBg"), Rect{ 0,0,size.width,size.height });
		back->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(back);

		loginBtn = MenuItemLabel::create(Label::create(StringValue("LoginGame"), "¿¬Ìå", 45)
			, this, menu_selector(BeginLayer::onLoginCallBack));
		loginBtn->setPosition(size.width*0.5, size.height*0.55);
		sigonBtn = MenuItemLabel::create(Label::create(StringValue("SigOn"), "¿¬Ìå", 45)
			, this, menu_selector(BeginLayer::onSigonCallBack));
		sigonBtn->setPosition(size.width*0.5, size.height*0.45);
		loginBtn->setColor(Color3B::BLACK);
		sigonBtn->setColor(Color3B::BLACK);
		loginBtn->setVisible(false);
		sigonBtn->setVisible(false);

		auto menuTrunOn = MenuItemImage::create(StringValue("TrunOn"), StringValue("TrunOn"));
		auto menuTrunOff = MenuItemImage::create(StringValue("TrunOff"), StringValue("TrunOff"));
		auto toggle = MenuItemToggle::createWithCallback(CC_CALLBACK_1(BeginLayer::onMusicOnOrOffCallBack, this), menuTrunOn, menuTrunOff, NULL);
		toggle->setPosition(size.width*0.9, size.height*0.9);
		if (GetIntData("BgMusic") == 1)
			toggle->setSelectedIndex(1);
		else
			toggle->setSelectedIndex(0);
		auto Gmenu = Menu::create();
		Gmenu->addChild(loginBtn);
		Gmenu->addChild(sigonBtn);
		Gmenu->addChild(toggle);
		Gmenu->setPosition(0, 0);
		this->addChild(Gmenu);

		auto musicLabel = LabelTTF::create(StringValue("MusicText"), "¿¬Ìå", 30);
		musicLabel->setColor(ccc3(88, 16, 148));
		musicLabel->setPosition(size.width*0.8, size.height*0.9);
		this->addChild(musicLabel);
		return true;
	}
	return false;
}

void BeginLayer::onLoginCallBack(cocos2d::CCObject* sender)
{
	auto loginScene = Login::create();
	auto reScene = CCTransitionProgressInOut::create(1.0, loginScene);
	CCDirector::sharedDirector()->replaceScene(reScene);
}

void BeginLayer::onSigonCallBack(cocos2d::CCObject* sender)
{
	auto sigScene = SignOn::create();
	auto reScene = CCTransitionProgressInOut::create(1.0, sigScene);
	Director::getInstance()->replaceScene(reScene);
}

void  BeginLayer::onMusicOnOrOffCallBack(cocos2d::CCObject* sender)
{
	ToggleMusic();
}

void BeginLayer::showBtn()
{
	loginBtn->setVisible(true);
	sigonBtn->setVisible(true);
}