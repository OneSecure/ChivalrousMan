#pragma once
#ifndef __SKILL_LAYER_H__
#define __SKILL_LAYER_H__
#include"PreProcess.h"

/**
*class SkillLayer
*显示玩家技能
*/
class SkillLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(SkillLayer)
	CREATE_FUNC(SkillLayer)
public:
 	virtual bool init() override;

private:
	/*
	*升级技能按钮点击回调函数
	*/
	void onBtnUpClickCallback(cocos2d::CCObject* sender);

	/*
	*一键升级按钮点击回调函数
	*/
	void onBtnAllUpClickCallBack(cocos2d::CCObject* sender);
};

#endif // !__SKILL_LAYER_H__

