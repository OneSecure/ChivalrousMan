#pragma once
#ifndef __EXCESSIVE_SCENE_H__
#define __EXCESSIVE_SCENE_H__
#include"PreProcess.h"
#include<functional>

class ExcessiveScene Inherit(cocos2d::Scene)
{
	CLASS_ESSENTAIL(ExcessiveScene)
public:
	/*
	*���ɵ�ָ����ͼ
	*/
	static ExcessiveScene* createExcessice(int level, std::function<bool(void)>& callfunc, float delay);

	/*
	*���ɵ�ָ������
	*/
	static ExcessiveScene* createExcessice(cocos2d::Scene* reScene, std::function<bool(void)>& callEvent, float delay);

	bool init(cocos2d::Scene* reScene, std::function<bool(void)>& callEvent, float delay);
private:
	/*
	*OnExcessiveCallBack(float dx);
	*�������ɻص�����
	*/
	void OnExcessiveCallBack(float dx);

	//Ҫ���ȵ��ĳ���
	cocos2d::Scene* m_reScene;

	//�����ӳ�
	float m_delay;

	//�ٹ��ȹ�����ִ�е��¼�
	std::function<bool(void)> m_exssiveEvent;
};

#endif // !

