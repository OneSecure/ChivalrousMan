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
	*���ݹ������ʹ���ս������
	*@param monster������
	*/
	static cocos2d::Scene* createFightScene(const std::string& name);

	bool init(const std::string& name);
private:
	void update(float dt);
		
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

