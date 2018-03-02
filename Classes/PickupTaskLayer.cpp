#include"PickupTaskLayer.h"
#include"Commen.h"
#include"Npc.h"
#include"GameData.h"
#include"TaskSystem.h"

PickupTaskLayer* PickupTaskLayer::create(Npc* npc)
{
	PickupTaskLayer* pRet = new PickupTaskLayer;
	if (pRet&&pRet->init(npc))
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

bool PickupTaskLayer::init(Npc* npc)
{
	if (Layer::init())
	{
		m_npc = npc;
		auto size = SCREEN;
		auto bg = Sprite::create(StringValue("PickTaskBg"));
		bg->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(bg);

		auto menu = Menu::create();
		menu->setPosition(0, 0);
		this->addChild(menu);

		LabelTTF* labeltext = LabelTTF::create(StringValue("PickTaskText"), "¿¬Ìå", 25);
		labeltext->setPosition(size.width*0.5, size.height*0.5 + 40);
		labeltext->setColor(ccc3(34, 177, 76));
		this->addChild(labeltext);

		auto okbtn = MenuItemImage::create(StringValue("SureBtn"), StringValue("SureBtn1"), this, menu_selector(PickupTaskLayer::onOkBtnClickCallback));
		okbtn->setPosition(size.width*0.5 - 80, size.height*0.5 - 45);
		menu->addChild(okbtn);

		auto cancelbtn = MenuItemImage::create(StringValue("BackBtn"), StringValue("BackBtn1"), this, menu_selector(PickupTaskLayer::onCancelClickCallback));
		cancelbtn->setPosition(size.width*0.5 + 80, size.height*0.5 - 45);
		menu->addChild(cancelbtn);
		return true;
	}
	return false;
}

void PickupTaskLayer::onOkBtnClickCallback(cocos2d::CCObject* sender)
{
	TaskSystem::getInstance()->pickupTask(m_npc->getTaskIndex());
	m_npc->changeState(NS_FREE, 0);
	getParent()->removeChild(this);
}

void PickupTaskLayer::onCancelClickCallback(cocos2d::CCObject* sender)
{
	getParent()->removeChild(this);
}