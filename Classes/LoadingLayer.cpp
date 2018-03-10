#include"LoadingLayer.h"
#include"Commen.h"
#include"GameData.h"

LoadingLayer* LoadingLayer::create(const std::string& tip, const std::string& progressname,bool haveBg)
{
	LoadingLayer* pRet = new LoadingLayer;
	if (pRet&&pRet->init(tip,progressname,haveBg))
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

bool LoadingLayer::init(const std::string& tip, const std::string& progressname,bool haveBg)
{
	if (Layer::init())
	{
		auto size = SCREEN;
		if (haveBg)
		{
			auto back = Sprite::create(StringValue("LoadBg"), Rect{ 0,0,size.width,size.height });
			back->setPosition(size.width*0.5, size.height*0.5);
			this->addChild(back);
		}

		auto loadingIcon = Sprite::create(progressname);
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