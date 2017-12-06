#include"LoginLayer.h"
#include"StartMenu.h"
#include"GameData.h"
#include"Commen.h"
#include"BeginScene.h"
#include<string>
        
LoginLayer::~LoginLayer()
{
	int a = 5;
	int b = 10;
	int c = a + b;
}
 
bool LoginLayer::init()
{
	if (Layer::init())
	{
		LISTEN_TOUCH(LoginLayer);
		auto back = Sprite::create(StringValue("LoginBg"), Rect{ 0,0,SCREEN.width,SCREEN.height });
		back->setPosition(ccp(SCREEN.width*0.5, SCREEN.height*0.5));
		this->addChild(back);

		Vec2 vec1{ SCREEN.width*0.3f,SCREEN.height*0.7f };
		ADD_EDIT(tfUserName,"tfUserName",vec1, "UserName", "EditBg", false, this, this);

		Vec2 vec2{ SCREEN.width*0.3f,SCREEN.height*0.5f };
		ADD_EDIT(tfPasswd,"tfPasswd", vec2, "Passwd", "EditBg", true, this, this);

		auto btnLogin = MenuItemImage::create(StringValue("EntryBtn"), StringValue("EntryBtn1"),
			this, menu_selector(LoginLayer::LoginCallback));
		btnLogin->setPosition(ccp(SCREEN.width*0.35f, SCREEN.height*0.2f));
		btnLogin->setScaleY(1.2);
		auto btnCancel = MenuItemImage::create(StringValue("BackBtn"),
			StringValue("BackBtn1"), this,
			menu_selector(LoginLayer::CancelCallBack));
		btnCancel->setPosition(ccp(SCREEN.width*0.65f, SCREEN.height*0.2f));
		btnCancel->setScaleY(1.2);
		auto Gmenu = Menu::create();
		Gmenu->addChild(btnLogin);
		Gmenu->addChild(btnCancel);
		Gmenu->setPosition(ccp(0, 0));

		this->addChild(Gmenu);
		
		return true;
	}
	return false;
}

bool LoginLayer::onTextFieldAttachWithIME(TextFieldTTF * sender)
{
	sender->setScale(1.1);
	sender->setTextColor(ccc4(13, 203, 17, 255));
	sender->setColorSpaceHolder(ccc4(255, 128, 0, 255));
	return CCTextFieldDelegate::onTextFieldAttachWithIME(sender);
}

bool LoginLayer::onTextFieldDetachWithIME(TextFieldTTF * sender)
{
	sender->setScale(1.0);
	sender->setTextColor(ccc4(131, 3, 92, 255));
	sender->setColorSpaceHolder(ccc3(73, 214, 23));
	return CCTextFieldDelegate::onTextFieldDetachWithIME(sender);
}

void LoginLayer::LoginCallback(CCObject* obj)
{
	GO_BACK_START_MENU();
}

void LoginLayer::CancelCallBack(CCObject* obj)
{
	GO_BACK_BEGIN();
}

void LoginLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	Vec2 thPos = touch->getLocation();
	bool res;
	ATTACH_OR_DETACH(tfUserName, thPos, res);
	ATTACH_OR_DETACH(tfPasswd, thPos, res);
}

bool LoginLayer::isEntryUserName(Vec2 pos)
{
	bool res;
	CONTAIN_POINT(tfUserName, pos, res);
	return res;
}

bool LoginLayer::isEntryPasswd(Vec2 pos)
{
	bool res;
	CONTAIN_POINT(tfPasswd, pos, res);
	return res;
}
