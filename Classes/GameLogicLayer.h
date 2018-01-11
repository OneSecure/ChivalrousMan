#pragma once
#ifndef __GAME_LOGIC_LAYER_H__
#define __GAME_LOGIC_LAYER_H__
#include"PreProcess.h"
#include<string>

/*
*class GameLogicLayer
*��Ϸ�߼��㣬������Ϸ�еĴ󲿷��߼�
*/
class GameLogicLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(GameLogicLayer)
	CREATE_FUNC(GameLogicLayer)
public:
	virtual bool init();

	void update(float dt);
private:
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	/*
	*CheckEntryDoor();
	*����Ƿ�������ڣ���������Ӧ�¼�
	*/
	void checkEntryDoor();

	/*
	*checkCollisionNpc();
	*����Ƿ�������Npc��������Ӧ���¼�
	*/
	void checkCollisionNpc();

	/*
	*gotoDestMap
	*�л���Ŀ���ͼ
	*@param dest��Ŀ����
	*/
	void gotoDestMap(const std::string& dest);

	/*
	*randomMeetMonster();
	*��Ұ���������������
	*/
	void randomMeetMonster();
};

#endif // !__GAME_LOGIC_LAYER_H__

