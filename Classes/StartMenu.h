#pragma once
#ifndef __START_MENU_H__
#define __START_MENU_H__
#include"PreProcess.h"

/*
*class StartMenu
*登录后进入的主场景
*/
class StartMenu:public cocos2d::Scene
{
public:
	CLASS_ESSENTAIL(StartMenu)
	CREATE_FUNC(StartMenu)

	virtual bool init();
private:
	/*
	*音乐开关按钮回调函数
	*/
	void onMusicOnOrOffCallBack(cocos2d::CCObject* sender);

	/*
	*新建角色按钮回调函数
	*/
	void NewBtnCallBack(cocos2d::CCObject* obj);

	/*
	*进入角色选择界面回调函数
	*/
	void EntryCallBack(cocos2d::CCObject* obj);
	
	/*
	*退出按钮回调函数
	*/
	void QuitCallBack(cocos2d::CCObject* obj);
};

#endif // !__START_MENU_H__

