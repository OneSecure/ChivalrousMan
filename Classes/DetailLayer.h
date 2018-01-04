#pragma once
#ifndef  __DETAIL_LAYER_H__
#define __DETAIL_LAYER_H__
#include"PreProcess.h"
#include"Thing.h"

class DetailLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(DetailLayer)
public:
	static DetailLayer* createWithThing(Thing* th);

	bool init(Thing* th);
private:
	/*
	*�رհ�ť����¼�
	*/
	void onCloseClickCallBack(cocos2d::CCObject* sender);
};

#endif
