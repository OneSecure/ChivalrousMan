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
	static XGamePlayer* create(const Player_Info& pinfo,int flag=0);

	bool init(const Player_Info& pinfo, int flag);
	
	/*
	*move()
	*移动
	*@return bool：是否真的移动了
	*/
	virtual bool move();

	/*
	*setVelocity(float& v)
	*设置合速度
	*@param v：合速度大小
	*/
	virtual void setVelocity(const float& v);
	
	/*
	*trunDir(float& angle)
	*改变移动方向
	*新的转向角
	*@param angle:转向角度
	*@return bool：返回与上一次相比是否改变方向
	*/
	virtual bool trunDir(const float& angle);

	/*
	*getDir();
	*获取方向
	*/
	virtual const Dir& getDir();
	
	/*
	*canMove()
	*判断是否可以移动
	*/
	bool canMove();

	/*
	*clearRoadList();
	*清空路径队列
	*/
	void clearRoadList();

	/*
	*goNext();
	*前往下一个节点
	*/
	void goNext();

	/*
	*setMoveRoad(stack<Vec2> road
	*设置当前的移动路径
	*@param road：移动路径
	*/
	void setMoveRoad(std::stack<cocos2d::Vec2>& road);

	/*
	*moveTo(cocos2d::Vec2 targetPos);
	*移动到目标地点
	*@param targetPos:目标地点
	*/
	bool moveTo(cocos2d::Vec2 targetPos, int less = 0);

	/*
	*玩家被攻击
	*@param attack：攻击力
	*/
	void beAttack(int attack);

	/*
	*进攻
	*@param 进攻谁
	*/
	float normalAttack(cocos2d::CCObject* who);

	/*
	*技能进攻
	*@param skill：使用的技能
	*@param garde：技能的等级
	*@param who:进攻谁
	*/
	float skillAttack(std::string skill, int grade,cocos2d::CCObject* who);
private:
	/*
	*初始化游戏玩家数据
	*@param pinfo：玩家数据
	*/
	void InitData(const Player_Info& pinfo);

	void update(float dt);

	cocos2d::Sprite* m_face;
	cocos2d::LabelTTF* m_namelabel;
	//移动路径列表
	std::stack<cocos2d::Vec2> m_roadList;
	//玩家状态
	PlayerState* m_state = nullptr;
	//标记状态改变
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
	PROPERTY__REF(int,m_fd,Fd)
};

#endif // !__PLAYER_H__

