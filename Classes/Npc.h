#pragma once
#ifndef __NPC_H__
#define __NPC_H__
#include"PreProcess.h"
#include"ReflectNpc.h"
#include<initializer_list>
#include<fstream>
#include<vector>
#include<string>

class Npc
{
public:
	Npc();
	~Npc();
	static Npc* CreateClassNpc() { return (new Npc); }

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
	virtual void collisionEvent();

	/*
	*getNextTalkMsg()
	*获取下一跳对话信息
	*/
	virtual std::string getNextTalkMsg();

	/*
	*resetIndex();
	*重设index
	*/
	virtual void resetIndex();
protected:
	std::vector<std::string> m_talkmsg;
	
	int index = 0;
};

#endif // !__NPC_H__

