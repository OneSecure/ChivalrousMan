#pragma once
#ifndef __START_MENU_H__
#define __START_MENU_H__
#include"PreProcess.h"

/*
*class StartMenu
*��¼������������
*/
class StartMenu:public cocos2d::Scene
{
public:
	CLASS_ESSENTAIL(StartMenu)
	CREATE_FUNC(StartMenu)

	virtual bool init();
private:
	/*
	*���ֿ��ذ�ť�ص�����
	*/
	void onMusicOnOrOffCallBack(cocos2d::CCObject* sender);

	/*
	*�½���ɫ��ť�ص�����
	*/
	void NewBtnCallBack(cocos2d::CCObject* obj);

	/*
	*�����ɫѡ�����ص�����
	*/
	void EntryCallBack(cocos2d::CCObject* obj);
	
	/*
	*�˳���ť�ص�����
	*/
	void QuitCallBack(cocos2d::CCObject* obj);
};

#endif // !__START_MENU_H__

