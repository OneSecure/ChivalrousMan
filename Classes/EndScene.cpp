#include"EndScene.h"
#include"GameData.h"
#include"Commen.h"

bool EndScene::init()
{
	if (Scene::init())
	{
		auto back = Sprite::create(StringValue("StartBg"));
		back->setPosition(SCREEN.width*0.5, SCREEN.height*0.5);
		this->addChild(back);

		scheduleOnce(schedule_selector(EndScene::EndCallBack), 1.4f);
		return true;
	}
	return false;
}

void EndScene::EndCallBack(float dv)
{
	Director::getInstance()->end();
}