#pragma once
#ifndef __ROLEINFOLAYER_H__
#define __ROLEINFOLAYER_H__
#include"PreProcess.h"

class RoleInfoLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(RoleInfoLayer)
	CREATE_FUNC(RoleInfoLayer)
public:
	virtual bool init() override;

private:
	void update(float dt);

	//升级按钮点击回调函数
	void onUpBtnClick(cocos2d::CCObject* sender);

	//拆卸按钮点击回调函数
	void onDisassembleBtnClick(cocos2d::CCObject* sender);

	//点击装备回调函数
	void onEquipmentClickCallback(cocos2d::CCObject* sender);

	//显示角色装备
	void initRoleEquipment();

	cocos2d::ProgressTimer* m_bloodBar;          //血条
	cocos2d::ProgressTimer* m_manaBar;           //魔条
	cocos2d::ProgressTimer* m_expBar;               //经验
	cocos2d::LabelTTF* bloodvalue;
	cocos2d::LabelTTF* manavalue;
	cocos2d::LabelTTF* attacklabel;
	cocos2d::LabelTTF* defenselabel;
	cocos2d::CCObject* m_curSel = nullptr;         
	cocos2d::Sprite* m_selector;
	cocos2d::Vec2 m_centerP; 
	cocos2d::Menu* m_menu;
};

#endif // !__ROLEINFOLAYER_H__

