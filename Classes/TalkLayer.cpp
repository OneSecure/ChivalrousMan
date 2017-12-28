#include"TalkLayer.h"
#include"GameData.h"
#include"Commen.h"
#include"Npc.h"

#define ADD_TALK_TEXT()   \
talkText->setAnchorPoint(ccp(0, 0.5));   \
talkText->setColor(ccc3(0, 0, 0));   \
talkText->setHorizontalAlignment(CCTextAlignment::LEFT);   \
talkText->setPosition(m_talkPos);   \
talkText->setTag(1001);   \
this->addChild(talkText)


TalkLayer* TalkLayer::createWithNpc(Npc* npc)
{
	TalkLayer* pRet = new TalkLayer;
	if (pRet&& pRet->init(npc))
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

bool TalkLayer::init(Npc* npc)
{
	if (Layer::init())
	{
		m_npc = npc;
		auto size = SCREEN;
		auto  talk = Sprite::create(StringValue("TalkBg"));
		talk->setPosition(size.width*0.5, talk->getContentSize().height*0.5 + 10);
		this->addChild(talk);

		auto menu = Menu::create();
		menu->setPosition(0, 0);
		this->addChild(menu);
		auto nextBtn = MenuItemImage::create(StringValue("NextBtn"), StringValue("NextBtn"),
			this, menu_selector(TalkLayer::onNextCallBack));
		float  btnx = talk->getPositionX() + talk->getContentSize().width*0.5 - nextBtn->getContentSize().width - 30;
		float  btny = talk->getPositionY() - talk->getContentSize().height*0.5 + nextBtn->getContentSize().height + 30;
		nextBtn->setPosition(btnx, btny);
		menu->addChild(nextBtn);

		auto talkText = LabelTTF::create(m_npc->getNextTalkMsg(), "¿¬Ìå", 20);
		m_talkPos.x = talk->getPositionX() - talk->getContentSize().width*0.5 + 15;
		m_talkPos.y = talk->getPositionY() + talk->getContentSize().height*0.5 - talkText->getContentSize().height - 20;
		ADD_TALK_TEXT();

		return true;
	}
	return false;
}

void TalkLayer::onNextCallBack(cocos2d::CCObject* sender)
{
	ClickAction();
	std::string tmp = m_npc->getNextTalkMsg();
	if (tmp != "")
	{
		auto talkText = LabelTTF::create(tmp, "¿¬Ìå", 20);
		this->removeChildByTag(1001);
		ADD_TALK_TEXT();
	}
	else
	{
		getParent()->removeChild(this);
	}
}
