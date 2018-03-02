#pragma once
#ifndef __BACK_PACK_LAYER_H__
#define  __BACK_PACK_LAYER_H__
#include"PreProcess.h"
#include<vector>

/*
*class BackPackLayer
*��ʾ���Ǳ���
*/
class BackPackLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(BackPackLayer)
	CREATE_FUNC(BackPackLayer)
public:
	virtual bool init() override;

	/*
	*sellBtnCallback(cocos2d::CCObject* sender);
	*������۰�ť�ص�����
	*/
	void sellBtnCallback(cocos2d::CCObject* sender);
	
	/*
	*useBtnCallBack(cocos2d::CCObject* sender);
	*���ʹ�ð�ť�ص�����
	*/
	void useBtnCallBack(cocos2d::CCObject* sender);
	
	/*
	*bp1BtnCallBack(cocos2d::CCObject* sender);
	*1�ű�����ť���»ص�����
	*/
	void bp1BtnCallBack(cocos2d::CCObject* sender);
	
	/*
	*bp2BtnCallBack(cocos2d::CCObject* sender);
	*2�ű�����ť���»ص�����
	*/
	void bp2BtnCallBack(cocos2d::CCObject* sender);

	/*
	*onClickThingCallBack(cocos2d::CCObject* sender);
	*���������ť�ص�����
	*/
	void onClickThingCallBack(cocos2d::CCObject* sender);

	/*
	*clickThingCallBack();
	*�����Ʒ�ص�����
	*/
	void clickThingCallBack();
private:
	/*
	*initBackPackThing()
	*��ʼ��������Ʒ
	*/
	void initBackPackThing();

	cocos2d::Vec2 m_basePoint;
	cocos2d::Sprite* m_selector;
	cocos2d::CCObject* m_curSel;
	std::vector<cocos2d::LabelTTF*> m_numlabels;   
	cocos2d::Menu* m_menu;
};

#endif // !__BACK_PACK_LAYER

