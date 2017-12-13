#include"LoadingLayer.h"
#include"Commen.h"
#include"GameData.h"

LoadingLayer* LoadingLayer::create(const std::string& tip)
{
	LoadingLayer* pRet = new LoadingLayer;
	if (pRet&&pRet->init(tip))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
	}
}

bool LoadingLayer::init(const std::string& tip)
{
	if (Layer::init())
	{
		auto size = SCREEN;
		auto back = Sprite::create(StringValue("LoadBg"), Rect{ 0,0,size.width,size.height });
		back->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(back);

		auto loadingIcon = Sprite::create(StringValue("LoadingIcon"));
		loadingIcon->setPosition(size.width*0.5, size.height*0.5);
		auto rotate=RotateBy::create(0.5, 359);
		loadingIcon->runAction(RepeatForever::create(rotate));
		this->addChild(loadingIcon);

		auto loadingLabel = LabelTTF::create(tip, "¿¬Ìå", 25);
		loadingLabel->setColor(ccc3(247, 99, 0));
		loadingLabel->setPosition(size.width*0.5, size.height*0.4);
		this->addChild(loadingLabel);

		return true;
	}
	return false;
}