#include"HurtValueLayer.h"
#include"Commen.h"
#include"GameData.h"

HurtsValueLayer* HurtsValueLayer::createWithInfo(Vec2 pos, float hurt)
{
	HurtsValueLayer* pRet = new HurtsValueLayer;
	if (pRet&&pRet->init(pos, hurt))
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

bool  HurtsValueLayer::init(Vec2 pos, float hurt)
{
	if (Layer::init())
	{
		auto label = LabelTTF::create("-" + NumberToString(hurt), "¿¬Ìå", 25);
		label->setPosition(pos);
		label->setColor(Color3B::RED);
		this->addChild(label);
		scheduleOnce(schedule_selector(HurtsValueLayer::dead), 1);
		return true;
	}
	return false;
}

void HurtsValueLayer::dead(float dt)
{
	this->getParent()->removeChild(this);
}