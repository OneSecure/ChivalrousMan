#include"BeginScene.h"
#include"GameData.h"
#include"Login.h"
#include"SignOn.h"
#include"Commen.h"

bool BeginScene::init()
{
	if (Scene::init())
	{
		Size size = SCREEN;
		auto back = Sprite::create(StringValue("LoginBg"), Rect{ 0,0,size.width,size.height });
		back->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(back);

		auto loginBtn = MenuItemLabel::create(Label::create(StringValue("LoginGame"), "¿¬Ìå", 45)
			, this, menu_selector(BeginScene::onLoginCallBack));
		loginBtn->setPosition(size.width*0.5, size.height*0.55);
		auto sigonBtn = MenuItemLabel::create(Label::create(StringValue("SigOn"), "¿¬Ìå", 45)
			, this, menu_selector(BeginScene::onSigonCallBack));
		sigonBtn->setPosition(size.width*0.5, size.height*0.45);
		loginBtn->setColor(Color3B::BLACK);
		sigonBtn->setColor(Color3B::BLACK);
		auto Gmenu = Menu::create();
		Gmenu->addChild(loginBtn);
		Gmenu->addChild(sigonBtn);
		Gmenu->setPosition(0, 0);
		this->addChild(Gmenu);
		return true;
	}
	return false;
}

void BeginScene::onLoginCallBack(cocos2d::CCObject* sender)
{
	auto loginScene = Login::create();
	auto reScene = CCTransitionTurnOffTiles::create(1.0, loginScene);
	CCDirector::sharedDirector()->replaceScene(reScene);
}

void BeginScene::onSigonCallBack(cocos2d::CCObject* sender)
{
	auto sigScene = SignOn::create();
	auto reScene = CCTransitionProgressInOut::create(1.0, sigScene);
	Director::getInstance()->replaceScene(reScene);
}