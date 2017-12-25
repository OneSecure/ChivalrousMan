#pragma once
#ifndef __SIGON_LAYER_H__
#define __SIGON_LAYER_H__
#include"PreProcess.h"
#include<thread>

class SigOnLayer :public cocos2d::Layer,
	public cocos2d::CCTextFieldDelegate
{
public:
	SigOnLayer();
	~SigOnLayer();
	CREATE_FUNC(SigOnLayer)

	virtual bool init();

	void AffirmBtnCallBack(cocos2d::CCObject* obj);

	void GoBackBtnCallBack(cocos2d::CCObject* obj);

	virtual bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF * sender) override;

	virtual bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF * sender) override;

	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
private:
	void update(float dt) override;

	/*
	*SigonEvent();
	*在单独的线程内处理注册事件
	*/
	void SigonEvent();

	cocos2d::TextFieldTTF* m_tfUserName;
	cocos2d::TextFieldTTF* m_tfPasswd;
	cocos2d::TextFieldTTF* m_tfSurePasswd;
	
	std::thread* m_sigonThread = nullptr;

	int m_goto = 0;
};

#endif // !__SIGON_LAYER_H__

