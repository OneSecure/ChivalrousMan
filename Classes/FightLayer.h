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
	friend class Skill;
	friend class CrackIt;
	friend class Dante;
	friend class DragonRoar;
	friend class LightStrike;
	friend class Long;
	friend class RecallCounterMand;
	friend class SealOfTheBlade;
	friend class XBArrow;
	FightLayer();
	~FightLayer();

	/*
	*根据怪物名称创建战斗场景
	*@param name：怪物
	*/
	static cocos2d::Scene* createFightScene(const std::string& name);

	bool init(const std::string& name);

	/*
	*移除怪物
	*/
	void removeMonster(Monster* monster);

	bool checkSuccess();
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
	*使用药品
	*/
	void onMedication(cocos2d::CCObject* sender);

	/*
	*使用技能
	*/
	void onSkill(cocos2d::CCObject* sender);
		
	/*
	*randomNumMonster();
	*生成随机数量的怪物
	*/
	void randomNumMonster(const std::string& name);

	/*
	*选择怪物点击回调函数
	*/
	void onClickMonsterCallBack(cocos2d::CCObject* sender);
	
	/*
	*playerAttackMonster();
	*玩家对怪物进行普通攻击
	*/
	void playerAttackMonster();
	
	/*
	*monsterAttackPlayer();
	*怪物攻击玩家
	*@param index：攻击玩家的怪物
	*/
	void monsterAttackPlayer(int index);

	/*
	*计时器回调函数
	*/
	void onTimer(float dt);

	/*
	* EndFight(std::string tip);
	*结束战斗
	*@param tip：结束战斗的提示语
	*/
	void EndFight(std::string tip);

	void endFunc(float dt);
	
	/*
	*更新玩家血量和魔量UI
	*/
	void updateBloodAndMana();

	void reSelectMonster();
	
	std::string m_time = "10";   //行动时间
	std::vector<Monster*> m_monsterList; 	//保存怪物信息链表
	cocos2d::Sprite* m_player; 	//绘制玩家形象
	cocos2d::Menu* m_menu;
	bool m_clickMedication = false;
	std::vector<Medication*> m_medications;    //保存药品
	std::vector<cocos2d::LabelTTF*> m_medicationNums;    //显示数量
	bool m_clickskill = false;
	std::vector<Skill*> m_skills;
	bool m_clickAuto = false;
	cocos2d::Sprite* m_arrow;
	Monster* m_selectedMonster;   //当前选中的怪物
	cocos2d::ProgressTimer* m_playerBlood;
	cocos2d::ProgressTimer* m_playerMana;
	cocos2d::LabelTTF* m_timeLabel;
	bool m_isPlayer = true;     //是否轮到玩家攻击
	bool m_isPlayerEnd = false;  //玩家进攻是否结束
	int m_curMonster = 0;     //当前进攻玩家的怪物索引
	bool m_lastMonsterEnd = true;   //上一个怪物是否攻击结束
	float m_settlementGlod = 0;    //结算金币
	float m_settlementExp = 0;      //结算经验
	int m_mmor = 1;                      //纪录回合数
	cocos2d::CCObject* sender;     //选中的技能
	std::vector<Node*> m_otherPlayers;
};

#endif // ! __FIGHT_LAYER_HH_