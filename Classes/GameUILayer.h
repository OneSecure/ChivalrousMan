#pragma once
#ifndef __GAME_UI_LAYER_H__
#define __GAME_UI_LAYER_H__
#include"PreProcess.h"

/*
*class GameUILayer
*��Ϸ�����UI�㣬�������û����н���
*/
class GameUILayer:public cocos2d::Layer,
	public  cocos2d::TextFieldDelegate
{
	CLASS_ESSENTAIL(GameUILayer)
	CREATE_FUNC(GameUILayer)
public:
	bool init() override;

	/*
	*resetMenulayer();
	*����˵���Ϊfalse
	*/
	void resetMenulayer();
private:
	/*
	*generateUserInterface();
	*�����û�����
	*/
	void generateUserInterface();

	/*
	*�����ͼͼ�����ص�����
	*/
	void onMapIconClickCallBack(cocos2d::CCObject* sender);

	/*
	*����ͼ�����ص�����
	*/
	void onBackPackClickCallBack(cocos2d::CCObject* sender);

	/*
	*����ͼ�����ص�����
	*/
	void onSkillClickCallBack(cocos2d::CCObject* sender);

	/*
	*ͷ�����ص�����
	*/
	void onHeadClickCallBack(cocos2d::CCObject* sender);

	/*
	*�˵���ť����ص�����
	*/
	void onMenuClickCallBack(cocos2d::CCObject* sender);

	/*
	*������Ͱ�ť�ص�����
	*/
	void onSendClickCallBack(cocos2d::CCObject* sender);
	
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	virtual bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF * sender);

	virtual bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF * sender);

	cocos2d::LabelTTF* m_roleName;                   //��ɫ��
	cocos2d::ProgressTimer* m_bloodBar;           //Ѫ��
	cocos2d::ProgressTimer* m_manaBar;           //ħ��
	cocos2d::MenuItemImage* m_head;              //ͷ��
	cocos2d::LabelTTF* m_name;                         //��ɫ��
	cocos2d::LabelTTF* m_grade;                         //�ȼ�
	cocos2d::MenuItemImage* m_task;               //����
	cocos2d::MenuItemImage* m_worldMap;     //�����ͼ
	cocos2d::MenuItemImage* m_backpack;       //����
	cocos2d::MenuItemImage* m_skill;                //����
	cocos2d::Sprite* m_talkFrame;   //���������
	cocos2d::MenuItemImage* m_sendBtn;  //���Ͱ�ť
	cocos2d::TextFieldTTF* m_editFrame;       //�༭��Ϣ��
	cocos2d::MenuItemImage* m_menuBtn;
	
	bool m_isclickGameMenuLayer = false;
	bool m_isclickSkillLayer = false;
	bool m_isclickBackPackLayer = false;
	bool m_isclickWorldMapLayer = false;
};

#endif // !__GAME_UI_LAYER_H__

