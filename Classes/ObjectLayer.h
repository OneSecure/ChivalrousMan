#pragma once
#ifndef __OBJECT_LAYER_H__
#define __OBJECT_LAYER_H__
#include"PreProcess.h"
#include"Npc.h"
#include<vector>
#include<string>

/*
*class ObjectLayer
*��Ϸ�����,���ڻ��Ƴ���������������Ϸ����
*/
class ObjectLayer Inherit(cocos2d::Layer)
{
public:
	ObjectLayer();
	~ObjectLayer();

	/*
	*createWithLevel(const int& level);
	*���ݵ�ͼ���������
	*@param level:��ͼ����
	*/
	static ObjectLayer* createWithLevel(const int& level);

	bool init(const int& level);

	void update(float dt);

	inline std::vector<Npc*>& getNpcList() { return m_npcList; }
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

