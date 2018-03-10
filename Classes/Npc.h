#pragma once
#ifndef __NPC_H__
#define __NPC_H__
#include"PreProcess.h"
#include"ReflectNpc.h"
#include<initializer_list>
#include<fstream>
#include<vector>
#include<string>

/*
*class Npc
*Npc的基类
*/
class Npc
{
public:
	Npc();
	~Npc();

	//世界地图x坐标
	GettingAndSetting(float, m_x, X);
	//世界地图y坐标
	GettingAndSetting(float, m_y, Y);
	
	cocos2d::Sprite* getFace() { return m_face; }

	void setFace(cocos2d::Sprite* face) { m_face = face; m_face->setAnchorPoint(cocos2d::ccp(0.5, 0.1)); }

	/*
	*collisionEvent();
	*主角碰撞Npc触发的事件
	*/
	virtual void  collisionEvent();

	/*
	*endCollisionEvent();
	*主角结束碰撞Npc
	*/
	virtual void endCollisionEvent();

	/*
	*getNextTalkMsg()
	*获取下一跳对话信息
	*/
	virtual std::string getNextTalkMsg();
	
	/*
	*talkEndEvent();
	*对话结束事件
	*/
	virtual void talkEndEvent();

	/*
	*resetIndex();
	*重设index
	*/
	virtual void resetIndex();

	/*
	*changeState(int state);
	*改变Npc的状态
	*@param state：将要改到的状态
	*@param index：任务索引
	*/
	void changeState(int state, int index);

	/*
	*initMissTaskTalk();
	*初始化未接任务对话
	*/
	void initMissTaskTalk();

	/*
	*initEndTaskTalk();
	*初始化已完成任务的对话
	*/
	void initEndTaskTalk();

	/*
	*initNoEndTaskTalk();
	*初始化未完成任务的对话
	*/
	void initNoEndTaskTalk();
	
	void initTaskTalk(const std::string& filename);
protected:
	//Npc表象
	cocos2d::Sprite* m_face;
	std::vector<std::string> m_talkmsg;
	std::vector<std::string> m_tmptalk;
	
	int index = 0;
	bool pickup = true;
	
	PROPERTY__REF(int, m_taskindex, TaskIndex)
	PROPERTY__REF(int,m_state,State)
	PROPERTY__REF(std::string,m_name,Name)
	PROPERTY__REF(bool,m_isCollision,IsCollision)
};

#endif // !__NPC_H__

