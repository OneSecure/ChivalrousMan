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
	
	cocos2d::Sprite* getFace() { return m_face; }

	void setFace(cocos2d::Sprite* face) { m_face = face; m_face->setAnchorPoint(cocos2d::ccp(0.5, 0.1)); }

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

	/*
	*changeState(int state);
	*�ı�Npc��״̬
	*@param state����Ҫ�ĵ���״̬
	*@param index����������
	*/
	void changeState(int state, int index);

	/*
	*initMissTaskTalk();
	*��ʼ��δ������Ի�
	*/
	void initMissTaskTalk();

	/*
	*initEndTaskTalk();
	*��ʼ�����������ĶԻ�
	*/
	void initEndTaskTalk();

	/*
	*initNoEndTaskTalk();
	*��ʼ��δ�������ĶԻ�
	*/
	void initNoEndTaskTalk();
	
	void initTaskTalk(const std::string& filename);
protected:
	//Npc����
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

