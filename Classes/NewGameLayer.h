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
	*纪录玩家类型
	*/
	void recordPlayerType();

    void onTouchEnded(cocos2d::Touch *touch,cocos2d::Event *unused_event);

	/*
	*onConfirmCallBack(cocos2d::CCObject* sender);
	*确认按钮的回调函数
	*/
	void onConfirmCallBack(cocos2d::CCObject* sender);
	
	/*
	*onCancelCallBack(cocos2d::CCObject* sender);
	*取消按钮的回调函数
	*/
	void onCancelCallBack(cocos2d::CCObject* sender);
	
	bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF * sender);
	bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF * sender);
	
	/*
	*onStoneCallBack(cocos2d::CCObject* sender);
	*点击石台的回调函数
	*/
	void onStoneCallBack(cocos2d::CCObject* sender);
	
	/*
	*moveBracket(cocos2d::Vec2 dest, float delay);
	*移动浮标到目的地
	*@param dest：光标移动的目的地
	*@param delay：移动延迟
	*/
	void moveBracket(cocos2d::Vec2 dest, float delay);

	cocos2d::TextFieldTTF* m_username;
	cocos2d::Sprite* m_bracket[2];
	
	//标记选择的人物类型
	Player_Type m_playerType;
};

#endif // !__NEW_GAME_LAYER_H__

