#pragma once
#ifndef __ROLEINFOLAYER_H__
#define __ROLEINFOLAYER_H__
#include"PreProcess.h"

class RoleInfoLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(RoleInfoLayer)
	CREATE_FUNC(RoleInfoLayer)
public:
	virtual bool init() override;

private:
	void update(float dt);

	//������ť����ص�����
	void onUpBtnClick(cocos2d::CCObject* sender);

	//��ж��ť����ص�����
	void onDisassembleBtnClick(cocos2d::CCObject* sender);

	//���װ���ص�����
	void onEquipmentClickCallback(cocos2d::CCObject* sender);

	//��ʾ��ɫװ��
	void initRoleEquipment();

	cocos2d::ProgressTimer* m_bloodBar;          //Ѫ��
	cocos2d::ProgressTimer* m_manaBar;           //ħ��
	cocos2d::ProgressTimer* m_expBar;               //����
	cocos2d::LabelTTF* bloodvalue;
	cocos2d::LabelTTF* manavalue;
	cocos2d::LabelTTF* attacklabel;
	cocos2d::LabelTTF* defenselabel;
	cocos2d::CCObject* m_curSel = nullptr;         
	cocos2d::Sprite* m_selector;
	cocos2d::Vec2 m_centerP; 
	cocos2d::Menu* m_menu;
};

#endif // !__ROLEINFOLAYER_H__

