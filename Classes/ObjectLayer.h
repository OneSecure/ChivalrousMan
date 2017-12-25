#pragma once
#ifndef __OBJECT_LAYER_H__
#define __OBJECT_LAYER_H__
#include"PreProcess.h"
#include"Npc.h"
#include<vector>
#include<string>

class ObjectLayer Inherit(cocos2d::Layer)
{
public:
	ObjectLayer();
	~ObjectLayer();

	static ObjectLayer* createWithLevel(const int& level);

	bool init(const int& level);

	void update(float dt);
private:
	/*
	*updateNpcPos();
	*�����Ϊ��׼�������������λ����Ϣ
	*/
	void updateObjectScreenPos();

	/*
	*initLevelObject(const int& level)
	*��ʼ����������
	*/
	void initLevelObject(const int& level);

	/*
	*releaseNpc();
	*��������
	*/
	void clearObjectLayer();

	std::vector<Npc*> m_npcList;
};

#endif // !__OBJECT_LAYER_H__

