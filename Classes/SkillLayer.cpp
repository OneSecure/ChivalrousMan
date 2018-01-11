#include"SkillLayer.h"
#include"GameData.h"
#include"Commen.h"

bool SkillLayer::init()
{
	if (Layer::init())
	{
		auto size = SCREEN;
		auto back = Sprite::create(StringValue("SkillBg"));
		back->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(back);

		auto title = LabelTTF::create(StringValue("SkillText"), "¿¬Ìå", 35);
		title->setColor(ccc3(63, 72, 204));
		title->setPosition(size.width*0.5, size.height*0.5 + 120);
		this->addChild(title);

		auto backGrid = Sprite::create(StringValue("SkillGrid"));
		backGrid->setPosition(size.width*0.5, size.height*0.5 + 50);
		this->addChild(backGrid);
		
		auto menu = Menu::create();
		menu->setPosition(0, 0);
		this->addChild(menu);

		//Éý¼¶°´Å¥
		auto btnUp = MenuItemImage::create(StringValue("BtnUp"),
			StringValue("BtnUp"), this, menu_selector(SkillLayer::onBtnUpClickCallback));
		btnUp->setPosition(size.width*0.5+230,size.height*0.5-140);
		menu->addChild(btnUp);

		auto btnAllUp = MenuItemImage::create(StringValue("BtnAllUp"),
			StringValue("BtnAllUp"), this, menu_selector(SkillLayer::onBtnAllUpClickCallBack));
		btnAllUp->setPosition(size.width*0.5 + 120, size.height*0.5 - 140);
		menu->addChild(btnAllUp);

		return true;
	}
	return false;
}

void SkillLayer::onBtnUpClickCallback(cocos2d::CCObject* sender)
{
	ClickAction();
}

void SkillLayer::onBtnAllUpClickCallBack(cocos2d::CCObject* sender)
{
	ClickAction();
}