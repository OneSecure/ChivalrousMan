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
*Npc�Ļ���
*/
class Npc
{
public:
	Npc();
	~Npc();

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
	virtual void  collisionEvent();

	/*
	*endCollisionEvent();
	*���ǽ�����ײNpc
	*/
	virtual void endCollisionEvent();

	/*
	*getNextTalkMsg()
	*��ȡ��һ���Ի���Ϣ
	*/
	virtual std::string getNextTalkMsg();
	
	/*
	*talkEndEvent();
	*�Ի������¼�
	*/
	virtual void talkEndEvent();

	/*
	*resetIndex();
	*����index
	*/
	virtual void resetIndex();
protected:
	std::vector<std::string> m_talkmsg;
	
	int index = 0;

	PROPERTY__REF(bool,m_isCollision,IsCollision)
};

#endif // !__NPC_H__

