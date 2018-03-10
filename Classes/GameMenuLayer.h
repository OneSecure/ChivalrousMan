#pragma once
#ifndef __GAME_MENU_LAYER_H__
#define __GAME_MENU_LAYER_H__
#include"PreProcess.h"

/*
*class GameMenuLayer
*游戏菜单层，用于显示游戏菜单
*/
class GameMenuLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(GameMenuLayer)
	CREATE_FUNC(GameMenuLayer)
public:
	bool init();

private:
	/*
	*音乐按钮回调函数
	*/
	void onMusicCallBack(cocos2d::CCObject* sender);

	/*
	*返回游戏按钮回调函数
	*/
	void onBackGameCallBack(cocos2d::CCObject* sender);

	/*
	*返回主菜单按钮回调函数
	*/
	void onBackMainMenu(cocos2d::CCObject* sender);

	/*
	*切换账号按钮回调函数
	*/
	void onChangeCountClick(cocos2d::CCObject* sender);
};


#endif // !__GAME_MENU_LAYER_H__

