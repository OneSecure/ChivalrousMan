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
	//Npc表象
	GettingAndSetting(cocos2d::Sprite*, m_face, Face);

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
protected:
	std::vector<std::string> m_talkmsg;
	
	int index = 0;

	PROPERTY__REF(bool,m_isCollision,IsCollision)
};

#endif // !__NPC_H__

