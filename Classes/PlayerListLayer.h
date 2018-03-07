#pragma once
#ifndef __PLAYER_LIST_H__
#define  __PLAYER_LIST_H__
#include"PreProcess.h"
#include<vector>

class  PlayerItem;

/*
*class PlayerListLayer
*��ʾ��Χ����б�
*/
class PlayerListLayer Inherit(cocos2d::Layer)
{
	CLASS_ESSENTAIL(PlayerListLayer)
	CREATE_FUNC(PlayerListLayer)
public:
	bool init();
	
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
private:
	void initPlayerItem(cocos2d::Vec2 basePos);

	void onScrollBarClick(cocos2d::CCObject* sender);

	std::vector<PlayerItem*> m_itemlist;
	cocos2d::MenuItemImage* m_scrollBar; 
	cocos2d::Vec2 m_topPos;            //��������λ������
	cocos2d::Vec2 m_bottomPos;      //��������λ������
	float m_pagenums = 6;                //һҳ���ܴ�ŵ����Item��
};

#endif // !__PLAYER_LIST_H__

