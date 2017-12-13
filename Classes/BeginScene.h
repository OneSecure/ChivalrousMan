#pragma once
#ifndef __BEGIN_SCENE_H__
#define __BEGIN_SCENE_H__
#include"PreProcess.h"

class BeginScene:public cocos2d::Scene
{
	CLASS_ESSENTAIL(BeginScene)
	CREATE_FUNC(BeginScene)
public:
	virtual bool init();
private:
	void onLoginCallBack(cocos2d::CCObject* sender);
	void onSigonCallBack(cocos2d::CCObject* sender);
	void onMusicOnOrOffCallBack(cocos2d::CCObject* sender);
};

#endif // !__BEGIN_SCENE_H__

