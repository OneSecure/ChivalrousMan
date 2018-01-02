#pragma once
#ifndef __BEGIN_LAYER_H__
#define __BEGIN_LAYER_H__
#include"PreProcess.h"

/*
*class BeginLayer
*游戏的开始界面层
*/
class BeginLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(BeginLayer);
	CREATE_FUNC(BeginLayer);
public:
	bool init() override;

	/*
	*登录按钮回调函数
	*/
	void onLoginCallBack(cocos2d::CCObject* sender);

	/*
	*注册按钮回调函数
	*/
	void onSigonCallBack(cocos2d::CCObject* sender);

	/*
	*背景音乐开关回调函数
	*/
	void onMusicOnOrOffCallBack(cocos2d::CCObject* sender);
};

#endif // !__BEGIN_LAYER_H__

