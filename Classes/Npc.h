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

	//�����ͼx����
	GettingAndSetting(float, m_x, X);
	//�����ͼy����
	GettingAndSetting(float, m_y, Y);
	//Npc����
	GettingAndSetting(cocos2d::Sprite*, m_face, Face);

	/*
	*collisionEvent();
	*������ײNpc�������¼�
	*/
	virtual void collisionEvent();

	/*
	*getNextTalkMsg()
	*��ȡ��һ���Ի���Ϣ
	*/
	virtual std::string getNextTalkMsg();

	/*
	*resetIndex();
	*����index
	*/
	virtual void resetIndex();
protected:
	std::vector<std::string> m_talkmsg;
	
	int index = 0;
};

#endif // !__NPC_H__

