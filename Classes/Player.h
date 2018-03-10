#pragma once
#ifndef __PLAYER_HXX__
#define __PLAYER_HXX__
#include"PreProcess.h"
#include"ShareData.h"

class PlayerState;

class XGamePlayer Inherit(cocos2d::Node)
{
	CLASS_ESSENTAIL(XGamePlayer)
public:
	static XGamePlayer* create(const Player_Info& pinfo);

	bool init(const Player_Info& pinfo);
	
	/*
	*move()
	*�ƶ�
	*@return bool���Ƿ�����ƶ���
	*/
	virtual bool move();

	/*
	*setVelocity(float& v)
	*���ú��ٶ�
	*@param v�����ٶȴ�С
	*/
	virtual void setVelocity(const float& v);
	
	/*
	*trunDir(float& angle)
	*�ı��ƶ�����
	*�µ�ת���
	*@param angle:ת��Ƕ�
	*@return bool����������һ������Ƿ�ı䷽��
	*/
	virtual bool trunDir(const float& angle);

	/*
	*getDir();
	*��ȡ����
	*/
	virtual const Dir& getDir();
	
	/*
	*canMove()
	*�ж��Ƿ�����ƶ�
	*/
	bool canMove();

	/*
	*clearRoadList();
	*���·������
	*/
	void clearRoadList();

	/*
	*goNext();
	*ǰ����һ���ڵ�
	*/
	void goNext();

	/*
	*setMoveRoad(stack<Vec2> road
	*���õ�ǰ���ƶ�·��
	*@param road���ƶ�·��
	*/
	void setMoveRoad(std::stack<cocos2d::Vec2>& road);

	/*
	*moveTo(cocos2d::Vec2 targetPos);
	*�ƶ���Ŀ��ص�
	*@param targetPos:Ŀ��ص�
	*/
	bool moveTo(cocos2d::Vec2 targetPos);
private:
	/*
	*��ʼ����Ϸ�������
	*@param pinfo���������
	*/
	void InitData(const Player_Info& pinfo);

	void update(float dt);

	cocos2d::Sprite* m_face;
	cocos2d::LabelTTF* m_namelabel;
	//�ƶ�·���б�
	std::stack<cocos2d::Vec2> m_roadList;
	//���״̬
	PlayerState* m_state = nullptr;
	//���״̬�ı�
	int m_flag;

	Dir m_dir;
	
	PROPERTY__REF(std::string,m_playerName,PlayerName)
	PROPERTY__REF(std::string,m_roleName,RoleName)
	PROPERTY__REF(float,m_blood,Blood)
	PROPERTY__REF(float,m_mana,Mana)
	PROPERTY__REF(float, m_attack, Attack)
	PROPERTY__REF(float,m_defense,Defense)
	PROPERTY__REF(std::string,m_playerType,PlayerType)
	PROPERTY__REF(cocos2d::Vec2,m_worldPos,WorldPos)
	PROPERTY__REF(float,m_vx,Vx)
	PROPERTY__REF(float,m_vy,Vy)
	PROPERTY__REF(float,m_v,V)
	PROPERTY__REF(float,m_teamStatus,TeamStatus)
};

#endif // !__PLAYER_H__

