#pragma once
#ifndef __MSG_LIST_LAYER_H__
#define __MSG_LIST_LAYER_H__
#include"PreProcess.h"

class MsgListLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(MsgListLayer)
	CREATE_FUNC(MsgListLayer)
public:
	bool init() override;
private:
	/*
	*��ʼ����Ҫ��ʾ����Ϣ�б�
	*@param basePos:��׼λ��
	*/
	void initMsgItem(cocos2d::Vec2 basePos);
};

#endif
