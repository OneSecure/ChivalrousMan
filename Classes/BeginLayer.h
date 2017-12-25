#pragma once
#ifndef __BEGIN_LAYER_H__
#define __BEGIN_LAYER_H__
#include"PreProcess.h"

class BeginLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(BeginLayer);
	CREATE_FUNC(BeginLayer);
public:
	bool init() override;

	void onLoginCallBack(cocos2d::CCObject* sender);
	void onSigonCallBack(cocos2d::CCObject* sender);
	void onMusicOnOrOffCallBack(cocos2d::CCObject* sender);
};

#endif // !__BEGIN_LAYER_H__

