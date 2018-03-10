#include"PrivateTalkLayer.h"
#include"Commen.h"
#include"GameData.h"
#include"CMClient.h"
#include<functional>

PrivateTalkLayer* PrivateTalkLayer::create(const int& fd)
{
	auto pRet = new PrivateTalkLayer;
	if (pRet&&pRet->init(fd))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool PrivateTalkLayer::init(const int& fd)
{
	if (Layer::init())
	{
		m_fd = fd;
		LISTEN_TOUCH(PrivateTalkLayer);
		auto size = SCREEN;
		auto bg = Sprite::create(StringValue("PTBg"));
		bg->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(bg);
		setName("PrivateTalkLayer");
		
		auto info = CMClient::getInstance()->findPlayerInfoByFd(fd);
		auto namelabel = LabelTTF::create(info.rolename, "楷体", 30);
		namelabel->setColor(Color3B::ORANGE);
		namelabel->setPosition(size.width*0.5, size.height*0.5 + bg->getContentSize().height*0.5 - 23);
		this->addChild(namelabel);

		auto menu = Menu::create();
		menu->setPosition(0, 0);
		this->addChild(menu);
		auto editBg = Sprite::create(StringValue("PTEditFrame"));
		editBg->setPosition(bg->getPositionX() - 40, size.height*0.5 - bg->getContentSize().height*0.5 + 35);
		editBg->setScaleY(1.2);
		this->addChild(editBg);
		m_editFrame = TextFieldTTF::textFieldWithPlaceHolder(StringValue("TalkEditECHO"), "楷体", 16);
		m_editFrame->setColor(ccc3(195, 195, 195));
		m_editFrame->setContentSize(editBg->getContentSize());
		m_editFrame->setPosition(editBg->getPosition());
		m_editFrame->setWidth(350);
		m_editFrame->setDelegate(this);
		this->addChild(m_editFrame);
		auto sendbtn = MenuItemImage::create(StringValue("SendMsgBtn1"), StringValue("SendMsgBtn2"),
			this, menu_selector(PrivateTalkLayer::onSendBtnClick));
		sendbtn->setPosition(editBg->getPositionX() + editBg->getContentSize().width*0.5 + 35, editBg->getPositionY());
		menu->addChild(sendbtn);

		auto closeBtn = MenuItemImage::create(StringValue("DelBtn"), StringValue("DelBtn"),
			this, menu_selector(PrivateTalkLayer::onCloseBtnClick));
		closeBtn->setPosition(size.width*0.5 + bg->getContentSize().width*0.5 - 20, size.height*0.5 + bg->getContentSize().height*0.5 - 20);
		menu->addChild(closeBtn);
		m_basePos = bg->getPosition();
		m_basePos.x = m_basePos.x - bg->getContentSize().width*0.5 + 52;
		m_basePos.y = m_basePos.y - bg->getContentSize().height*0.5 + 85;
		initMsgList();
		return true;
	}
	return false;
}

void PrivateTalkLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	auto pos = touch->getLocation();
	bool res;
	ATTACH_OR_DETACH(m_editFrame, pos, res);
}

bool PrivateTalkLayer::onTextFieldAttachWithIME(cocos2d::TextFieldTTF * sender)
{
	sender->setScale(1.1);
	sender->setColor(ccc3(255, 255, 255));
	return TextFieldDelegate::onTextFieldAttachWithIME(sender);
}

bool PrivateTalkLayer::onTextFieldDetachWithIME(cocos2d::TextFieldTTF * sender)
{
	sender->setScale(1.0);
	sender->setColor(ccc3(195, 195, 195));
	return TextFieldDelegate::onTextFieldDetachWithIME(sender);
}

void PrivateTalkLayer::onSendBtnClick(cocos2d::CCObject* sender)
{
	PrivateTalk_Msg msg;
	msg.type = M_PrivateTalk;
	msg.fd = -1;
	msg.dest = m_fd;
	strcpy_s(msg.msg, m_editFrame->getString().c_str());
	CMClient::getInstance()->SendMsg((char*)&msg, sizeof(msg));
	CMClient::getInstance()->addPrivateTalkMsg(&msg);
	m_editFrame->setString("");
}

void PrivateTalkLayer::onCloseBtnClick(cocos2d::CCObject* sender)
{
	ClickAction(sender);
	std::function<void(float)> func = [this](float) {
		auto MLlayer = this->getParent()->getChildByName("MsgListLayer");
		auto PLlayer = this->getParent()->getChildByName("PlayerListLayer");
		if (MLlayer != nullptr)
			MLlayer->setVisible(true);
		if (PLlayer != nullptr)
			PLlayer->setVisible(true);
		this->getParent()->removeChild(this);
	};
	scheduleOnce(func, 0.1, "key");
}

void PrivateTalkLayer::initMsgList()
{
	if (CMClient::getInstance()->getPrivateMsgs().find(m_fd) == CMClient::getInstance()->getPrivateMsgs().end())
		return;
	int index = 0;
	for (auto var = CMClient::getInstance()->getPrivateMsgs()[m_fd].rbegin(); var != CMClient::getInstance()->getPrivateMsgs()[m_fd].rend(); ++var)
	{
		auto msglabel = LabelTTF::create(var->rolename + ":" + var->msg, "楷体", 20);
		msglabel->setAnchorPoint(ccp(0, 0.5));
		msglabel->setPosition(m_basePos.x, m_basePos.y + index * 22);
		this->addChild(msglabel);
		m_msgList.push_back(msglabel);
		++index;
	}
}

void PrivateTalkLayer::addMsg(std::string who,std::string msg)
{
	for (auto var : m_msgList)
	{
		auto move = MoveBy::create(0.1, ccp(0, 22));
		var->runAction(move);
	}
	auto msglabel = LabelTTF::create(who + ":" + msg, "楷体", 20);
	msglabel->setAnchorPoint(ccp(0, 0.5));
	msglabel->setPosition(m_basePos);
	m_msgList.push_back(msglabel);
	this->addChild(msglabel);
	if (m_msgList.size() > 18)
	{
		this->removeChild(m_msgList.front());
		m_msgList.pop_front();
	}
}