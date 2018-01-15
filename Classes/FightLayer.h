#pragma once
#ifndef  __FIGHT_LAYER_H__
#define __FIGHT_LAYER_H__
#include"PreProcess.h"
#include<string>
#include<vector>

class Monster;
class Medication;
class Skill;

/*
*class FightLayer
*战斗层
*/
class FightLayer Inherit(cocos2d::Layer)
{
public:
	FightLayer();
	~FightLayer();
	/*
	*根据怪物名称创建战斗场景
	*@param name：怪物
	*/
	static cocos2d::Scene* createFightScene(const std::string& name);

	bool init(const std::string& name);
private:
	/*
	*calcActionOrder();
	*计算行动顺序
	*/
	void calcActionOrder();

	void update(float dt);

	/*
	*选择自动还是手动
	*/
	void onToggleAutoAndHand(cocos2d::CCObject* sender);

	/*
	*药品按钮点击回调函数
	*/
	void onMedicationClickCallBack(cocos2d::CCObject* sender);

	/*
	*技能按钮点击回调函数
	*/
	void onSkillClickCallBack(cocos2d::CCObject* sender);

	/*
	*逃跑按钮点击回调函数
	*/
	void onRunClickCallBack(cocos2d::CCObject* sender);

	/*
	*普通攻击按钮点击回调函数
	*/
	void onAttackClickCallBack(cocos2d::CCObject* sender);

	/*
	*使用药品点击回调函数
	*/
	void onItemClickCallBack(cocos2d::CCObject* sender);
		
	/*
	*randomNumMonster();
	*生成随机数量的怪物
	*/
	void randomNumMonster(const std::string& name);

	//保存怪物信息链表
	std::vector<Monster*> m_monsterList;
	
	//绘制玩家形象
	cocos2d::Sprite* m_player;
	cocos2d::Menu* m_menu;
	bool m_clickMedication = false;
	std::vector<Medication*> m_medications;
	bool m_clickskill = false;
	std::vector<Skill*> m_skills;
	bool m_clickAuto = false;
};

#endif // ! __FIGHT_LAYER_HH__

