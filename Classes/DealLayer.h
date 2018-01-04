#pragma once
#ifndef __DEAL_LAYER_H__
#define __DEAL_LAYER_H__
#include"PreProcess.h"
#include"Thing.h"
#include<vector>
#include<string>

/*
*class DealLayer
*���ײ�
*/
class DealLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(DealLayer)
public:
	/*
	*���ݴ������ʹ���һ����Ʒ���ײ�
	*@param type��ָ����������
	*/
	static DealLayer* createWithType(const int& type,const std::string& name);

	bool init(const int& type, const std::string& name);
private:
	void checkBuy(Thing* thing);

	/*
	*����ť�ص�����
	*/
	void onBuyBtnCallBack(cocos2d::CCObject* sender);
	
	/*
	*onCloseBtnCallBack(cocos2d::CCObject* sender);
	*�رհ�ť�ص�����
	*/
	void onCloseBtnCallBack(cocos2d::CCObject* sender);

	/*
	*��ʼ�����ײ����Ʒ
	*/
	void initThingByName(const int& type,const std::string& name);

	/*
	*�����Ʒ�Ļص�����
	*/
	void onClickThingCallBack(cocos2d::CCObject* sender);

	cocos2d::Vec2 m_basePoint;
	cocos2d::Sprite* m_selector;
	cocos2d::Menu* menu;
};

#endif // !__DEAL_LAYER_H__
