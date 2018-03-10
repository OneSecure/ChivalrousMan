#pragma once
#ifndef __TEAM_MSG_ITEM_H__
#define __TEAM_MSG_ITEM_H__
#include"PreProcess.h"

/*
*class TeamMsgItem
*组队消息item
*/
class TeamMsgItem Inherit(cocos2d::Node)
{
	CLASS_ESSENTAIL(TeamMsgItem)
public:
	/*
	*通过玩家唯一标识创建
	*@param fd：玩家标识
	*/
	static TeamMsgItem* create(const int& fd);
	
	bool init(const int& fd);
	
	//点击头像
	void onHeadClick(cocos2d::CCObject* sender);

	/*
	*同意按钮点击回调函数
	*/
	void onOkBtnClick(cocos2d::CCObject* sender);

	/*
	*拒绝按钮点击回调函数
	*/
	void onRefuseBtnClick(cocos2d::CCObject* sender);
private:
	int m_fd;
};

#endif