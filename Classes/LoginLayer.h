#pragma once
#ifndef __LOGIN_LAYER_H__
#define __LOGIN_LAYER_H__
#include"PreProcess.h"

class LoginLayer:public cocos2d::Layer,
	public cocos2d::CCTextFieldDelegate
{
public:
	~LoginLayer();
	//CLASS_ESSENTAIL(LoginLayer)
	CREATE_FUNC(LoginLayer)

	virtual bool init() override;

	virtual bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF * sender) override;
	virtual bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF * sender) override;

	void LoginCallback(cocos2d::CCObject* obj);
	void CancelCallBack(cocos2d::CCObject* obj);

	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
private:
	bool isEntryUserName(cocos2d::Vec2 pos);

	bool isEntryPasswd(cocos2d::Vec2 pos);

	cocos2d::TextFieldTTF* tfUserName;
	cocos2d::TextFieldTTF* tfPasswd;
};

#endif // !__LOGIN_LAYER_H__

