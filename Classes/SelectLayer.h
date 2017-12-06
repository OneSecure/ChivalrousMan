#pragma once
#ifndef __SELECT_LAYER_H__
#define __SELECT_LAYER_H__
#include"PreProcess.h"

class SelectLayer :public cocos2d::Layer
{
	CLASS_ESSENTAIL(SelectLayer)
	CREATE_FUNC(SelectLayer)

	virtual bool init();

private:
	void moveArrow(float delay,cocos2d::Vec2 dest);

	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;

	void onMenuCallBack(cocos2d::CCObject* sender);

	void onConfirmCallBack(cocos2d::CCObject* sender);

	void onCancelCallBack(cocos2d::CCObject* sender);

	cocos2d::Sprite* m_arrow;
};

#endif // !__SELECT_LAYER_H__

