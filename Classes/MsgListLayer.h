#pragma once
#ifndef __MSG_LIST_LAYER_H__
#define __MSG_LIST_LAYER_H__
#include"PreProcess.h"
#include<list>

class MsgItem;

class MsgListLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(MsgListLayer)
	CREATE_FUNC(MsgListLayer)
public:
	bool init() override;

	/*
	*removeMsgItem(cocos2d::MenuItemImage* item);
	*删除消息item
	*/
	void removeMsgItem(MsgItem* item);
private:
	/*
	*初始化所要显示的消息列表
	*@param basePos:基准位置
	*/
	void initMsgItem(cocos2d::Vec2 basePos);

	/*
	*item点击事件
	*/
	void onItemClickCallback(cocos2d::CCObject* sender);

	std::list<MsgItem*> m_itemlist;
};

#endif
