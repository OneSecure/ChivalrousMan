#pragma once
#ifndef __EXCESSIVE_SCENE_H__
#define __EXCESSIVE_SCENE_H__
#include"PreProcess.h"
#include<functional>

class ExcessiveScene Inherit(cocos2d::Scene)
{
	CLASS_ESSENTAIL(ExcessiveScene)
public:
	/*
	*过渡到指定地图
	*/
	static ExcessiveScene* createExcessice(int level, std::function<bool(void)>& callfunc, float delay);

	/*
	*过渡到指定场景
	*/
	static ExcessiveScene* createExcessice(cocos2d::Scene* reScene, std::function<bool(void)>& callEvent, float delay);

	bool init(cocos2d::Scene* reScene, std::function<bool(void)>& callEvent, float delay);
private:
	/*
	*OnExcessiveCallBack(float dx);
	*场景过渡回调函数
	*/
	void OnExcessiveCallBack(float dx);

	//要过度到的场景
	cocos2d::Scene* m_reScene;

	//过度延迟
	float m_delay;

	//再过度过程中执行的事件
	std::function<bool(void)> m_exssiveEvent;
};

#endif // !

