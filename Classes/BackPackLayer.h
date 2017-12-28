#pragma once
#ifndef __BACK_PACK_LAYER_H__
#define  __BACK_PACK_LAYER_H__
#include"PreProcess.h"

/*
*class BackPackLayer
*显示主角背包
*/
class BackPackLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(BackPackLayer)
	CREATE_FUNC(BackPackLayer)
public:
	virtual bool init() override;

	/*
	*sellBtnCallback(cocos2d::CCObject* sender);
	*点击出售按钮回调函数
	*/
	void sellBtnCallback(cocos2d::CCObject* sender);

	/*
	*sortOutCallback(cocos2d::CCObject* sender);
	*点击整理按钮回调函数
	*/
	void sortOutCallback(cocos2d::CCObject* sender);
	
	/*
	*useBtnCallBack(cocos2d::CCObject* sender);
	*点击使用按钮回调函数
	*/
	void useBtnCallBack(cocos2d::CCObject* sender);
	
	/*
	*bp1BtnCallBack(cocos2d::CCObject* sender);
	*1号背包格按钮按下回调函数
	*/
	void bp1BtnCallBack(cocos2d::CCObject* sender);
	
	/*
	*bp2BtnCallBack(cocos2d::CCObject* sender);
	*2号背包格按钮按下回调函数
	*/
	void bp2BtnCallBack(cocos2d::CCObject* sender);

	/*
	*clickThingCallBack();
	*点击物品回调函数
	*/
	void clickThingCallBack();
private:
	cocos2d::Vec2 m_basePoint;
	cocos2d::Sprite* m_selector;
};

#endif // !__BACK_PACK_LAYER

