#pragma once
#ifndef __MEMBER_ITEM_H__
#define  __MEMBER_ITEM_H__
#include"PreProcess.h"
#include"ShareData.h"

class MemberItem Inherit(cocos2d::Node)
{
	CLASS_ESSENTAIL(MemberItem)
public:
	static MemberItem* create(const Player_Info& info, const int& status, const int& btn_status);
	
	bool init(const Player_Info& info, const int& status, const int& btn_status);

	//点击头像
	void onHeadClick(cocos2d::CCObject* sender);

	/*
	*解散队伍按钮点击回调
	*/
	void onDissolveBtnClick(cocos2d::CCObject* sender);

	/*
	*提出队伍按钮点击回调
	*/
	void onKickOutBtnClick(cocos2d::CCObject* sender);

	/*
	*退出队伍按钮点击回调
	*/
	void onQuitTeamBtnClick(cocos2d::CCObject* sender);
private:
	Player_Info m_info;
};

#endif // !__MEMBER_ITEM_H__
