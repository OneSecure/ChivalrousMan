#pragma once
#ifndef __GAME_LOGIC_LAYER_H__
#define __GAME_LOGIC_LAYER_H__
#include"PreProcess.h"

class GameLogicLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(GameLogicLayer)
	CREATE_FUNC(GameLogicLayer)
public:
	virtual bool init();

	void onTouchEnded(cocos2d::Touch *touch,cocos2d::Event *unused_event);

	void update(float dt);

	/*
	*generateUserInterface(); 
	*�����û�����
	*/
	void generateUserInterface(); 
private:
	void onHeadClickCallBack(cocos2d::CCObject* sender);

	cocos2d::ProgressTimer* m_bloodBar;           //Ѫ��
	cocos2d::ProgressTimer* m_manaBar;           //ħ��
	cocos2d::MenuItemImage* m_head;              //ͷ��
 	cocos2d::LabelTTF* m_name;                         //��ɫ��
	cocos2d::LabelTTF* m_grade;                         //�ȼ�
	cocos2d::MenuItemImage* m_task;               //����
	cocos2d::MenuItemImage* m_worldMap;     //�����ͼ
	cocos2d::MenuItemImage* m_backpack;       //����
	cocos2d::MenuItemImage* m_skill;                //����
	cocos2d::Sprite* m_bloodbar;    //Ѫ��
	cocos2d::Sprite* m_manabar;    //����
};

#endif // !__GAME_LOGIC_LAYER_H__

