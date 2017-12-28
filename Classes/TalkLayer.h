#pragma once
#ifndef __TALK_LAYER_H__
#define __TALK_LAYER_H__
#include"PreProcess.h"

class Npc;

/**
*class TalkLayer
*根据Npc显示相应的对话
*/
class TalkLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(TalkLayer)
public:
	/*
	*根据Npc创建对话层
	*/
	static TalkLayer* createWithNpc(Npc* npc);

	bool init(Npc* npc);
private:
	void onNextCallBack(cocos2d::CCObject* sender);

	Npc* m_npc = nullptr;

	cocos2d::Vec2 m_talkPos;
};

#endif // !__TALK_LAYER_H__

