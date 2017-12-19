#include"SigOnLayer.h"
#include"GameData.h"
#include"BeginScene.h"
#include"StartMenu.h"
#include"Commen.h"
#include"Model.h"
#include"DBDao.h"
#include<sstream>

bool SigOnLayer::init()
{
	if (Layer::init())
	{
		LISTEN_TOUCH(SigOnLayer);
		auto back = Sprite::create(StringValue("SigOnBg"), Rect{ 0,0,SCREEN.width,SCREEN.height });
		back->setPosition(SCREEN.width*0.5, SCREEN.height*0.5);
		this->addChild(back);

		ADD_EDIT(m_tfUserName,"tfUserName", ccp(SCREEN.width*0.3, SCREEN.height*0.7), "UserName", "EditBg", false, this, this);
		ADD_EDIT(m_tfPasswd,"tfPasswd", ccp(SCREEN.width*0.3, SCREEN.height*0.55), "Passwd", "EditBg", true, this, this);
		ADD_EDIT(m_tfSurePasswd,"tfPasswd", ccp(SCREEN.width*0.3, SCREEN.height*0.4), "SurePasswd", "EditBg", true, this, this);

		COMMEN_BTN(this, SigOnLayer::AffirmBtnCallBack,
			SigOnLayer::GoBackBtnCallBack);

		return true;
	}
	return false;
}

void SigOnLayer::AffirmBtnCallBack(cocos2d::CCObject* obj)
{
	std::string playername = m_tfUserName->getString();
	std::string playerpsw = m_tfPasswd->getString();
	std::string surepsw = m_tfSurePasswd->getString();
	if (playername == "")
	{
		MessageBox("用户名不能为空!", "提示");
		return;
	}
	if (playerpsw == "")
	{
		MessageBox("密码不能为空", "提示");
		return;
	}
	if (surepsw == "")
	{
		MessageBox("确认密码不能为空", "提示");
		return;
	}
	if (playerpsw != surepsw)
	{
		MessageBox("两次密码不一致", "提示");
		return;
	}
	DBDao<Player> dao;
	Player player;
	player[1] = playername;
	player[2] = playerpsw;
	std::stringstream ss;
	int i = 0;
	ss << i;
	ss >> player[3];
	dao.setModel(player);
	if (dao.insertModel())
	{
		MessageBox("注册成功", "提示");
	}
	else
	{
		MessageBox("注册失败", "提示");
	}
	GO_BACK_BEGIN();
}

void SigOnLayer::GoBackBtnCallBack(cocos2d::CCObject* obj)
{
	GO_BACK_BEGIN();
}

bool SigOnLayer::onTextFieldAttachWithIME(TextFieldTTF * sender)
{
	sender->setScale(1.1);
	sender->setTextColor(ccc4(13, 203, 17, 255));
	sender->setColorSpaceHolder(ccc4(255, 128, 0, 255));
	return TextFieldDelegate::onTextFieldAttachWithIME(sender);
}

bool SigOnLayer::onTextFieldDetachWithIME(TextFieldTTF * sender)
{
	sender->setScale(1.0);
	sender->setTextColor(ccc4(131, 3, 92, 255));
	sender->setColorSpaceHolder(ccc3(73, 214, 23));
	return TextFieldDelegate::onTextFieldDetachWithIME(sender);
}

void SigOnLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
	Vec2 pos = touch->getLocation();
	bool res;
	ATTACH_OR_DETACH(m_tfUserName, pos, res);
	ATTACH_OR_DETACH(m_tfPasswd, pos, res);
	ATTACH_OR_DETACH(m_tfSurePasswd, pos, res);
}