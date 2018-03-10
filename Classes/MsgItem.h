#pragma once
#ifndef __MSG_ITEM_H__
#define __MSG_ITEM_H__
#include"PreProcess.h"

/*
*class MsgItem
*玩家消息item
*/
class MsgItem Inherit(cocos2d::MenuItemImage)
{
	CLASS_ESSENTAIL(MsgItem)
public:
	/*
	*通过玩家唯一标识创建一个MsgItem
	*/
	static MsgItem* create(const int& fd);
	
	bool init(const int& fd);

	const int& getFd() { return m_fd; }

	/*
	*调整消息红点
	*/
	void setRedSpot(bool b);
private:
	void onDeleteBtnClick(cocos2d::CCObject* sender);

	cocos2d::Sprite* m_redspot;

	int m_fd;
};

#endif // !_MSG_ITEM_H__

