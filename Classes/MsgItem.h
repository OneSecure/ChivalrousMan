#pragma once
#ifndef __MSG_ITEM_H__
#define __MSG_ITEM_H__
#include"PreProcess.h"

/*
*class MsgItem
*�����Ϣitem
*/
class MsgItem Inherit(cocos2d::MenuItemImage)
{
	CLASS_ESSENTAIL(MsgItem)
public:
	/*
	*ͨ�����Ψһ��ʶ����һ��MsgItem
	*/
	static MsgItem* create(const int& fd);
	
	bool init(const int& fd);

	const int& getFd() { return m_fd; }

	/*
	*������Ϣ���
	*/
	void setRedSpot(bool b);
private:
	void onDeleteBtnClick(cocos2d::CCObject* sender);

	cocos2d::Sprite* m_redspot;

	int m_fd;
};

#endif // !_MSG_ITEM_H__

