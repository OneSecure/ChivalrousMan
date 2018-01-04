#include"DetailLayer.h"
#include"GameData.h"
#include"Commen.h"

DetailLayer* DetailLayer::createWithThing(Thing* th)
{
	DetailLayer* pRet = new DetailLayer;
	if (pRet&&pRet->init(th))
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

bool DetailLayer::init(Thing* th)
{
	if (Layer::init())
	{
		auto size = SCREEN;
		auto back = Sprite::create(StringValue("DetailBg"));
		back->setPosition(back->getContentSize().width*0.5+10, size.height*0.5);
		this->addChild(back);
		int n = th->getDetails().size();
		for (int i=0;i<n;++i)
		{
			auto detail = LabelTTF::create(th->getDetails()[i], "����", 20);
			detail->setPosition(back->getPositionX(), back->getPositionY() + back->getContentSize().height*0.5 - 60 - detail->getContentSize().height*i);
			this->addChild(detail);
		}

		auto menu = Menu::create();
		menu->setPosition(0, 0);
		this->addChild(menu);

		auto closeBtn = MenuItemImage::create(StringValue("CloseBtn"), StringValue("CloseBtn"),
			this, menu_selector(DetailLayer::onCloseClickCallBack));
		float btnx = back->getPositionX();
		float btny = back->getPositionY() - back->getContentSize().height*0.5 + 40;
		closeBtn->setPosition(btnx, btny);
		menu->addChild(closeBtn);
		return true;
	}
	return false;
}

void DetailLayer::onCloseClickCallBack(cocos2d::CCObject* sender)
{
	ClickAction();
	getParent()->removeChild(this);
}