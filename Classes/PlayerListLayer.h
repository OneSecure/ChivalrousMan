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
	
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
private:
	void initPlayerItem();

	void onScrollBarClick(cocos2d::CCObject* sender);

	/*
	*moveItem(float dy);
	*�ƶ��б��е�item
	*@param dy���ƶ��ľ���
	*/
	void moveItem(float dy);

	/*
	*void recoverItem(float dy);
	*��ԭitem��λ��
	*��ԭʱ�����е�ƫ��
	*/
	void recoverItem(float dy);

	std::vector<PlayerItem*> m_itemlist;
	cocos2d::MenuItemImage* m_scrollBar; 
	cocos2d::Vec2 m_basePos;    //
	cocos2d::Vec2 m_topPos;            //��������λ������
	cocos2d::Vec2 m_bottomPos;      //��������λ������
	float m_pagenums = 6;                //һҳ���ܴ�ŵ����Item��
	bool m_click = false;
	bool m_scrollClick = false;
	cocos2d::Vec2 m_startPos;          //��ʼ�����λ��
	cocos2d::Vec2 m_startScrollPos; //�����ʼScrollBar��λ��
	float m_dy = 0;
};

#endif // !__PLAYER_LIST_H__

