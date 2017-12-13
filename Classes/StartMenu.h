#pragma once
#ifndef __START_MENU_H__
#define __START_MENU_H__
#include"PreProcess.h"

class StartMenu:public cocos2d::Scene
{
public:
	CLASS_ESSENTAIL(StartMenu)
	CREATE_FUNC(StartMenu)

	virtual bool init();
private:
	void onMusicOnOrOffCallBack(cocos2d::CCObject* sender);

	void NewBtnCallBack(cocos2d::CCObject* obj);

	void EntryCallBack(cocos2d::CCObject* obj);
	
	void QuitCallBack(cocos2d::CCObject* obj);
};

#endif // !__START_MENU_H__

