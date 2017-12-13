#include"BeginScene.h"
#include"GameData.h"
#include"Login.h"
#include"SignOn.h"
#include"Commen.h"
#include"GameDynamicData.h"

bool BeginScene::init()
{
	if (Scene::init())
	{
		Size size = SCREEN;
		auto back = Sprite::create(StringValue("LoginBg"), Rect{ 0,0,size.width,size.height });
		back->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(back);

		auto loginBtn = MenuItemLabel::create(Label::create(StringValue("LoginGame"), "����", 45)
			, this, menu_selector(BeginScene::onLoginCallBack));
		loginBtn->setPosition(size.width*0.5, size.height*0.55);
		auto sigonBtn = MenuItemLabel::create(Label::create(StringValue("SigOn"), "����", 45)
			, this, menu_selector(BeginScene::onSigonCallBack));
		sigonBtn->setPosition(size.width*0.5, size.height*0.45);
		loginBtn->setColor(Color3B::BLACK);
		sigonBtn->setColor(Color3B::BLACK);

		auto menuTrunOn = MenuItemImage::create(StringValue("TrunOn"), StringValue("TrunOn"));
		auto menuTrunOff = MenuItemImage::create(StringValue("TrunOff"), StringValue("TrunOff"));
		auto toggle = MenuItemToggle::createWithCallback(CC_CALLBACK_1(BeginScene::onMusicOnOrOffCallBack, this), menuTrunOn, menuTrunOff, NULL);
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

		auto musicLabel = LabelTTF::create(StringValue("MusicText"), "����", 30);
		musicLabel->setColor(ccc3(88, 16, 148));
		musicLabel->setPosition(size.width*0.8, size.height*0.9);
		this->addChild(musicLabel);
		
		return true;
	}
	return false;
}

void BeginScene::onLoginCallBack(cocos2d::CCObject* sender)
{
	auto loginScene = Login::create();
	auto reScene = CCTransitionProgressInOut::create(1.0, loginScene);
	CCDirector::sharedDirector()->replaceScene(reScene);
}

void BeginScene::onSigonCallBack(cocos2d::CCObject* sender)
{
	auto sigScene = SignOn::create();
	auto reScene = CCTransitionProgressInOut::create(1.0, sigScene);
	Director::getInstance()->replaceScene(reScene);
}

void BeginScene::onMusicOnOrOffCallBack(cocos2d::CCObject* sender)
{
	ToggleMusic();
}