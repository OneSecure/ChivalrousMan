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
	*初始化所要显示的消息列表
	*@param basePos:基准位置
	*/
	void initMsgItem(cocos2d::Vec2 basePos);
};

#endif
