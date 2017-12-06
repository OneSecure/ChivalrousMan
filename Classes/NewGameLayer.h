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
    void onTouchEnded(cocos2d::Touch *touch,cocos2d::Event *unused_event);
	void onConfirmCallBack(cocos2d::CCObject* sender);
	void onCancelCallBack(cocos2d::CCObject* sender);
	bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF * sender);
	bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF * sender);
	void onStoneCallBack(cocos2d::CCObject* sender);
	void moveBracket(cocos2d::Vec2 dest, float delay);

	cocos2d::TextFieldTTF* m_username;
	cocos2d::Sprite* m_bracket[2];
};

#endif // !__NEW_GAME_LAYER_H__

