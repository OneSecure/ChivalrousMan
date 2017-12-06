#pragma once
#ifndef __SIGON_LAYER_H__
#define __SIGON_LAYER_H__
#include"PreProcess.h"

class SigOnLayer :public cocos2d::Layer,
	public cocos2d::CCTextFieldDelegate
{
public:
	CLASS_ESSENTAIL(SigOnLayer)
	CREATE_FUNC(SigOnLayer)

	virtual bool init();

	void AffirmBtnCallBack(cocos2d::CCObject* obj);

	void GoBackBtnCallBack(cocos2d::CCObject* obj);

	virtual bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF * sender) override;

	virtual bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF * sender) override;

	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
private:
	cocos2d::TextFieldTTF* m_tfUserName;
	cocos2d::TextFieldTTF* m_tfPasswd;
	cocos2d::TextFieldTTF* m_tfSurePasswd;
};

#endif // !__SIGON_LAYER_H__

