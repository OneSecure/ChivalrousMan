#pragma once
#ifndef __GAME_MENU_LAYER_H__
#define __GAME_MENU_LAYER_H__
#include"PreProcess.h"

/*
*class GameMenuLayer
*��Ϸ�˵��㣬������ʾ��Ϸ�˵�
*/
class GameMenuLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(GameMenuLayer)
	CREATE_FUNC(GameMenuLayer)
public:
	bool init();

private:
	/*
	*���ְ�ť�ص�����
	*/
	void onMusicCallBack(cocos2d::CCObject* sender);

	/*
	*������Ϸ��ť�ص�����
	*/
	void onBackGameCallBack(cocos2d::CCObject* sender);

	/*
	*�������˵���ť�ص�����
	*/
	void onBackMainMenu(cocos2d::CCObject* sender);

	/*
	*�л��˺Ű�ť�ص�����
	*/
	void onChangeCountClick(cocos2d::CCObject* sender);
};


#endif // !__GAME_MENU_LAYER_H__

