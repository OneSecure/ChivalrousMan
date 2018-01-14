#pragma once
#ifndef  __FIGHT_LAYER_H__
#define __FIGHT_LAYER_H__
#include"PreProcess.h"
#include<string>
#include<vector>

class Monster;

/*
*class FightLayer
*ս����
*/
class FightLayer Inherit(cocos2d::Layer)
{
public:
	FightLayer();
	~FightLayer();
	/*
	*���ݹ������ƴ���ս������
	*@param name������
	*/
	static cocos2d::Scene* createFightScene(const std::string& name);

	bool init(const std::string& name);
private:
	/*
	*calcActionOrder();
	*�����ж�˳��
	*/
	void calcActionOrder();

	void update(float dt);

	/*
	*ѡ���Զ������ֶ�
	*/
	void onToggleAutoAndHand(cocos2d::CCObject* sender);

	/*
	*ҩƷ��ť����ص�����
	*/
	void onMedicationClickCallBack(cocos2d::CCObject* sender);

	/*
	*���ܰ�ť����ص�����
	*/
	void onSkillClickCallBack(cocos2d::CCObject* sender);

	/*
	*���ܰ�ť����ص�����
	*/
	void onRunClickCallBack(cocos2d::CCObject* sender);

	/*
	*��ͨ������ť����ص�����
	*/
	void onAttackClickCallBack(cocos2d::CCObject* sender);
		
	/*
	*randomNumMonster();
	*������������Ĺ���
	*/
	void randomNumMonster(const std::string& name);

	//���������Ϣ����
	std::vector<Monster*> m_monsterList;
	
	//�����������
	cocos2d::Sprite* m_player;
};

#endif // ! __FIGHT_LAYER_HH__

