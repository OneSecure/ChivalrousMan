#pragma once
#ifndef __SKILL_LAYER_H__
#define __SKILL_LAYER_H__
#include"PreProcess.h"
#include<vector>

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
	*initSkillIcon()
	*初始化技能图标
	*/
	void initSkillIcon();

	/*
	*onSkillCkickCallBack(cocos2d::CCObject* sender);
	*技能图标点击回调函数
	*/
	void onSkillCkickCallBack(cocos2d::CCObject* sender);

	/*
	*升级技能按钮点击回调函数
	*/
	void onBtnUpClickCallback(cocos2d::CCObject* sender);

	cocos2d::Menu* m_menu;
	cocos2d::Vec2 m_basePos;
	cocos2d::Sprite* m_selector;
	cocos2d::CCObject* m_selectedSkill;
	std::vector<cocos2d::LabelTTF*> m_gradelabels;
	std::vector<cocos2d::LabelTTF*> m_upskillGlods;
};

#endif // !__SKILL_LAYER_H__

