#pragma once
#ifndef __LOGIN_LAYER_H__
#define __LOGIN_LAYER_H__
#include"PreProcess.h"
#include<thread>
#include<string>
#include<vector>

class LoginLayer:public cocos2d::Layer,
	public cocos2d::CCTextFieldDelegate
{
public:
	LoginLayer();
	~LoginLayer();
	CREATE_FUNC(LoginLayer)

	virtual bool init() override;

	virtual bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF * sender) override;
	virtual bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF * sender) override;

	/*
	*登录按钮回调
	*/
	void LoginCallback(cocos2d::CCObject* obj);

	/*
	*取消按钮回调
	*/
	void CancelCallBack(cocos2d::CCObject* obj);

	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
private:
	void LoginEvent();

	void update(float dt) override;

	/*
	*是否进入用户名区域
	*/
	bool isEntryUserName(cocos2d::Vec2 pos);

	/*
	*是否进入密码区域
	*/
	bool isEntryPasswd(cocos2d::Vec2 pos);

	cocos2d::TextFieldTTF* tfUserName;
	cocos2d::TextFieldTTF* tfPasswd;

	std::thread* m_loginThread = nullptr;

	int m_goto = -1;
};

#endif // !__LOGIN_LAYER_H__

