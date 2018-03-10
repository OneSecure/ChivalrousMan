#pragma once
#ifndef __TEAM_MSG_ITEM_H__
#define __TEAM_MSG_ITEM_H__
#include"PreProcess.h"

/*
*class TeamMsgItem
*�����Ϣitem
*/
class TeamMsgItem Inherit(cocos2d::Node)
{
	CLASS_ESSENTAIL(TeamMsgItem)
public:
	/*
	*ͨ�����Ψһ��ʶ����
	*@param fd����ұ�ʶ
	*/
	static TeamMsgItem* create(const int& fd);
	
	bool init(const int& fd);
	
	//���ͷ��
	void onHeadClick(cocos2d::CCObject* sender);

	/*
	*ͬ�ⰴť����ص�����
	*/
	void onOkBtnClick(cocos2d::CCObject* sender);

	/*
	*�ܾ���ť����ص�����
	*/
	void onRefuseBtnClick(cocos2d::CCObject* sender);
private:
	int m_fd;
};

#endif