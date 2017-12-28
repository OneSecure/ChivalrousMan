#pragma once
#ifndef __TALK_LAYER_H__
#define __TALK_LAYER_H__
#include"PreProcess.h"

class Npc;

/**
*class TalkLayer
*����Npc��ʾ��Ӧ�ĶԻ�
*/
class TalkLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(TalkLayer)
public:
	/*
	*����Npc�����Ի���
	*/
	static TalkLayer* createWithNpc(Npc* npc);

	bool init(Npc* npc);
private:
	void onNextCallBack(cocos2d::CCObject* sender);

	Npc* m_npc = nullptr;

	cocos2d::Vec2 m_talkPos;
};

#endif // !__TALK_LAYER_H__

