#pragma once
#ifndef __GAME_LOGIC_LAYER_H__
#define __GAME_LOGIC_LAYER_H__
#include"PreProcess.h"

class GameLogicLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(GameLogicLayer)
	CREATE_FUNC(GameLogicLayer)
public:
	virtual bool init();

	void onTouchEnded(cocos2d::Touch *touch,cocos2d::Event *unused_event);

	void update(float dt);

	/*
	*generateUserInterface(); 
	*生成用户界面
	*/
	void generateUserInterface(); 
private:
	void onHeadClickCallBack(cocos2d::CCObject* sender);

	cocos2d::ProgressTimer* m_bloodBar;           //血条
	cocos2d::ProgressTimer* m_manaBar;           //魔条
	cocos2d::MenuItemImage* m_head;              //头像
 	cocos2d::LabelTTF* m_name;                         //角色名
	cocos2d::LabelTTF* m_grade;                         //等级
	cocos2d::MenuItemImage* m_task;               //任务
	cocos2d::MenuItemImage* m_worldMap;     //世界地图
	cocos2d::MenuItemImage* m_backpack;       //背包
	cocos2d::MenuItemImage* m_skill;                //技能
	cocos2d::Sprite* m_bloodbar;    //血条
	cocos2d::Sprite* m_manabar;    //蓝条
};

#endif // !__GAME_LOGIC_LAYER_H__

