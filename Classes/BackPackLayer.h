#pragma once
#ifndef __BACK_PACK_LAYER_H__
#define  __BACK_PACK_LAYER_H__
#include"PreProcess.h"
#include<vector>

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
	*onClickThingCallBack(cocos2d::CCObject* sender);
	*点击背包按钮回调函数
	*/
	void onClickThingCallBack(cocos2d::CCObject* sender);

	/*
	*clickThingCallBack();
	*点击物品回调函数
	*/
	void clickThingCallBack();
private:
	/*
	*initBackPackThing()
	*初始化背包物品
	*/
	void initBackPackThing();

	cocos2d::Vec2 m_basePoint;
	cocos2d::Sprite* m_selector;
	cocos2d::CCObject* m_curSel;
	std::vector<cocos2d::LabelTTF*> m_numlabels;   
	cocos2d::Menu* m_menu;
};

#endif // !__BACK_PACK_LAYER

