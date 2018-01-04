#pragma once
#ifndef __DEAL_LAYER_H__
#define __DEAL_LAYER_H__
#include"PreProcess.h"
#include"Thing.h"
#include<vector>
#include<string>

/*
*class DealLayer
*交易层
*/
class DealLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(DealLayer)
public:
	/*
	*根据触发类型创建一个物品交易层
	*@param type：指定触发类型
	*/
	static DealLayer* createWithType(const int& type,const std::string& name);

	bool init(const int& type, const std::string& name);
private:
	void checkBuy(Thing* thing);

	/*
	*购买按钮回调函数
	*/
	void onBuyBtnCallBack(cocos2d::CCObject* sender);
	
	/*
	*onCloseBtnCallBack(cocos2d::CCObject* sender);
	*关闭按钮回调函数
	*/
	void onCloseBtnCallBack(cocos2d::CCObject* sender);

	/*
	*初始化交易层的物品
	*/
	void initThingByName(const int& type,const std::string& name);

	/*
	*点击物品的回调函数
	*/
	void onClickThingCallBack(cocos2d::CCObject* sender);

	cocos2d::Vec2 m_basePoint;
	cocos2d::Sprite* m_selector;
	cocos2d::Menu* menu;
};

#endif // !__DEAL_LAYER_H__
