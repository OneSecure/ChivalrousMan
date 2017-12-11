#pragma once
#ifndef __NEW_GAME_LAYER_H__
#define __NEW_GAME_LAYER_H__
#include"PreProcess.h"

class NewGameLayer:public cocos2d::Layer,
	public cocos2d::TextFieldDelegate
{
	CLASS_ESSENTAIL(NewGameLayer)
	CREATE_FUNC(NewGameLayer)
public:
	virtual bool init();
private:
	/*
	*recordPlayerType();
	*��¼�������
	*/
	void recordPlayerType();

    void onTouchEnded(cocos2d::Touch *touch,cocos2d::Event *unused_event);

	/*
	*onConfirmCallBack(cocos2d::CCObject* sender);
	*ȷ�ϰ�ť�Ļص�����
	*/
	void onConfirmCallBack(cocos2d::CCObject* sender);
	
	/*
	*onCancelCallBack(cocos2d::CCObject* sender);
	*ȡ����ť�Ļص�����
	*/
	void onCancelCallBack(cocos2d::CCObject* sender);
	
	bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF * sender);
	bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF * sender);
	
	/*
	*onStoneCallBack(cocos2d::CCObject* sender);
	*���ʯ̨�Ļص�����
	*/
	void onStoneCallBack(cocos2d::CCObject* sender);
	
	/*
	*moveBracket(cocos2d::Vec2 dest, float delay);
	*�ƶ����굽Ŀ�ĵ�
	*@param dest������ƶ���Ŀ�ĵ�
	*@param delay���ƶ��ӳ�
	*/
	void moveBracket(cocos2d::Vec2 dest, float delay);

	cocos2d::TextFieldTTF* m_username;
	cocos2d::Sprite* m_bracket[2];
	
	//���ѡ�����������
	Player_Type m_playerType;
};

#endif // !__NEW_GAME_LAYER_H__

