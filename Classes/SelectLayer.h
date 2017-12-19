#pragma once
#ifndef __SELECT_LAYER_H__
#define __SELECT_LAYER_H__
#include"PreProcess.h"
#include"Model.h"

class SelectLayer :public cocos2d::Layer
{
	CLASS_ESSENTAIL(SelectLayer)
	CREATE_FUNC(SelectLayer)

	virtual bool init();

private:
	/*
	*moveArrow(float delay,cocos2d::Vec2 dest);
	*�ƶ�����ͷĿ�ĵ�
	*@param delay���ƶ��ӳ�
	*@param dest��Ŀ�ĵ�
	*/
	void moveArrow(float delay,cocos2d::Vec2 dest);

	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;

	/*
	*onMenuCallBack(cocos2d::CCObject* sender);
	*���ʯ̨�Ļص�����
	*/
	void onMenuCallBack(cocos2d::CCObject* sender);

	/*
	*onConfirmCallBack(cocos2d::CCObject* sender);
	*���ȷ�ϰ�ť�Ļص�����
	*/
	void onConfirmCallBack(cocos2d::CCObject* sender);

	/*
	*onCancelCallBack(cocos2d::CCObject* sender);
	*���ȡ����ť�Ļص�����
	*/
	void onCancelCallBack(cocos2d::CCObject* sender);
	
	/*
	*initPlayerView();
	*��ʼ��ʯ̨��ɫ����
	*/
	void initPlayerView();

	cocos2d::Sprite* m_arrow;

	//���ѡ���ĸ���¼
	int m_flag = 0;
	
	std::vector<PlayerInfo> m_roleList;
};

#endif // !__SELECT_LAYER_H__

