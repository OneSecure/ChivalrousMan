#include"ExcessiveScene.h"
#include"GameData.h"
#include"GameScene.h"
#include"LoadingLayer.h"
#include"Commen.h"

ExcessiveScene* ExcessiveScene::createExcessice(int level, std::function<bool(void)>& callfunc, float delay)
{
	auto gc = GameScene::createWithLevel(level);
	CC_SAFE_RETAIN(gc);
	return createExcessice(gc, callfunc, delay);
}

 ExcessiveScene* ExcessiveScene::createExcessice(cocos2d::Scene* reScene, std::function<bool(void)>& callEvent, float delay)
{
	 auto EvScene = new ExcessiveScene;
	 if (EvScene&&EvScene->init(reScene,callEvent,delay))
	 {
		 EvScene->autorelease();
		 return EvScene;
	 }
	 else
	 {
		 delete EvScene;
		 EvScene = nullptr;
		 return nullptr;
	 }
}

bool ExcessiveScene::init(cocos2d::Scene* reScene, std::function<bool(void)>& callEvent, float delay)
{
	if (Scene::init())
	{
		auto size = SCREEN;
		m_reScene = reScene;
		m_exssiveEvent = callEvent;
		m_delay = delay;
		auto loadingLayer = LoadingLayer::create(StringValue("LoadingText"), StringValue("LoadingIcon"));
		this->addChild(loadingLayer);

		this->scheduleOnce(schedule_selector(ExcessiveScene::OnExcessiveCallBack), m_delay);
		return true;
	}
	return false;
}

void ExcessiveScene::OnExcessiveCallBack(float dx)
{
	m_exssiveEvent();
	auto reScene = CCTransitionFadeDown::create(1.0f, m_reScene);
	Director::getInstance()->replaceScene(reScene);
}

