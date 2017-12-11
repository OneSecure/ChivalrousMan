#pragma once
#ifndef __SELECT_LAYER_H__
#define __SELECT_LAYER_H__
#include"PreProcess.h"

class SelectLayer :public cocos2d::Layer
{
	CLASS_ESSENTAIL(SelectLayer)
	CREATE_FUNC(SelectLayer)

	virtual bool init();

private:
	/*
	*moveArrow(float delay,cocos2d::Vec2 dest);
	*移动光标箭头目的地
	*@param delay：移动延迟
	*@param dest：目的地
	*/
	void moveArrow(float delay,cocos2d::Vec2 dest);

	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;

	/*
	*onMenuCallBack(cocos2d::CCObject* sender);
	*点击石台的回调函数
	*/
	void onMenuCallBack(cocos2d::CCObject* sender);

	/*
	*onConfirmCallBack(cocos2d::CCObject* sender);
	*点击确认按钮的回调函数
	*/
	void onConfirmCallBack(cocos2d::CCObject* sender);

	/*
	*onCancelCallBack(cocos2d::CCObject* sender);
	*点击取消按钮的回调函数
	*/
	void onCancelCallBack(cocos2d::CCObject* sender);

	cocos2d::Sprite* m_arrow;

	//标记选择哪个纪录
	int m_flag = 0;
};

#endif // !__SELECT_LAYER_H__

