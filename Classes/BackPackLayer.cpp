#include"BackPackLayer.h"
#include"GameData.h"
#include"Commen.h"

bool BackPackLayer::init()
{
	if (Layer::init())
	{
		auto size = SCREEN;
		auto backpackGrid = Sprite::create(StringValue("BackpackGrid"));
		backpackGrid->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(backpackGrid);
		m_basePoint.x = backpackGrid->getPositionX() - backpackGrid->getContentSize().width*0.5 + 45;
		m_basePoint.y = backpackGrid->getPositionY() + backpackGrid->getContentSize().height*0.5 - 118;
		
		auto menu = Menu::create();
		menu->setPosition(0, 0);
		this->addChild(menu);

		auto sellBtn = MenuItemImage::create(StringValue("SellBtn"), StringValue("SellBtn"),
			this, menu_selector(BackPackLayer::sellBtnCallback));
		float sellX = backpackGrid->getPositionX() + backpackGrid->getContentSize().width*0.5 - sellBtn->getContentSize().width;
		float sellY = backpackGrid->getPositionY() - backpackGrid->getContentSize().height*0.5 + sellBtn->getContentSize().height;
		sellBtn->setPosition(sellX, sellY);
		menu->addChild(sellBtn);

		auto sortOutBtn = MenuItemImage::create(StringValue("SortOutBtn"),
			StringValue("SortOutBtn"), this, menu_selector(BackPackLayer::sortOutCallback));
		float sortx = sellBtn->getPositionX() - sellBtn->getContentSize().width - 20;
		float sorty = sellBtn->getPositionY();
		sortOutBtn->setPosition(sortx, sorty);
		menu->addChild(sortOutBtn);

		auto useBtn = MenuItemImage::create(StringValue("UseBtn"),
			StringValue("UseBtn"), this,
			menu_selector(BackPackLayer::useBtnCallBack));
		float usex = sortOutBtn->getPositionX() - sortOutBtn->getContentSize().width - 20;
		float usey = sortOutBtn->getPositionY();
		useBtn->setPosition(usex, usey);
		menu->addChild(useBtn);

		auto bp1Btn = MenuItemImage::create(StringValue("Bp1Btn"),
			StringValue("Bp1SBtn"));
		float bp1x = m_basePoint.x + 20;
		float bp1y = m_basePoint.y + 60;
		bp1Btn->setPosition(bp1x, bp1y);
		menu->addChild(bp1Btn);
		auto bp2Btn = MenuItemImage::create(StringValue("Bp2Btn"),
			StringValue("Bp2SBtn"));
		bp2Btn->setPosition(bp1x + bp2Btn->getContentSize().width+10, bp1y);
		menu->addChild(bp2Btn);

		m_selector = Sprite::create(StringValue("Selector"));
		m_selector->setContentSize(Size{ 40,40 });
		m_selector->setPosition(m_basePoint);
		this->addChild(m_selector);

		return true;
	}
	return false;
}

void BackPackLayer::sellBtnCallback(cocos2d::CCObject* sender)
{
	ClickAction();
}

void BackPackLayer::sortOutCallback(cocos2d::CCObject* sender)
{
	ClickAction();
}

void BackPackLayer::useBtnCallBack(cocos2d::CCObject* sender)
{
	ClickAction();
}

void BackPackLayer::bp1BtnCallBack(cocos2d::CCObject* sender)
{

}

void BackPackLayer::bp2BtnCallBack(cocos2d::CCObject* sender)
{

}