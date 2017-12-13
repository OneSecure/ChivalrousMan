#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include"Animal.h"
#include<iostream>
#include<utility>
#include<stack>

#define GetPlayerFace CameraPlayer::getPlayerInstance()->getFace
#define SetPlayerFace CameraPlayer::getPlayerInstance()->setFace
#define PlayerTrunDir CameraPlayer::getPlayerInstance()->trunDir
#define SetPlayerVelocity CameraPlayer::getPlayerInstance()->setVelocity
#define PlayerPos CameraPlayer::getPlayerInstance()->getPos()
#define PlayerMove CameraPlayer::getPlayerInstance()->move
#define PlayerCanMove CameraPlayer::getPlayerInstance()->canMove
#define SetPlayerMoveRoad CameraPlayer::getPlayerInstance()->setMoveRoad
#define PlayerDir CameraPlayer::getPlayerInstance()->getDir
#define PlayerFacePos CameraPlayer::getPlayerInstance()->getFacePos

class PlayerState;

/*
*��������
*/
class CameraPlayer :public Animal
{
public:
	/*
	*��ȡ�������ҵĶ���
	*/
	static CameraPlayer* getPlayerInstance();

	inline cocos2d::Vec2 getFacePos() { return  m_face->getPosition(); }

	/*
	*������ҵ�UI
	*/
	void setFace(cocos2d::Sprite* face);

	/*
	*getFace()
	*��ȡ��ҵ�UI
	*@return Sprite*���õ���UI
	*/
	inline cocos2d::Sprite* getFace() { return m_face; }

	/*
	*changeMapPosToUI();
	*����Һ͵�ͼ�����������ϵ�λ��ת����UI��Ļ��
	*@return std::pair<cocos2d::Vec2,cocos2d::Vec2>������
	*/
	std::pair<cocos2d::Vec2,cocos2d::Vec2>  changeMapPosToUI();

	/*
	*move
	*�ƶ�
	*@return bool���Ƿ�����ƶ���
	*/
	bool move() override;
	
	/*
	*�ͷŸ���
	*�ͷ����ʵ������
	*/
	static void release();

	/*
	*canMove()
	*�ж��Ƿ�����ƶ�
	*/
	bool canMove();

	/*
	*trunDir(const float& angle)
	*ת��
	*@param angle��ת��Ƕ�
	*/
	bool trunDir(const float& angle) override;
	
	/*
	*setMoveRoad(stack<Vec2> road
	*���õ�ǰ���ƶ�·��
	*@param road���ƶ�·��
	*/
	void setMoveRoad(std::stack<cocos2d::Vec2>& road);

	/*
	*CalcAngle(cocos2d::Vec2,cocos2d::Vec2);
	*��������֮��ļн�
	*@param start:��ʼ��
	*@param target:�յ�
	*@return float:���ؼнǵĻ���ֵ
	*/
	float CalcAngle(cocos2d::Vec2 start, cocos2d::Vec2 target);
private:
	//ǰ����һ���ڵ�
	void goNext();

	CameraPlayer();
	~CameraPlayer();

	//���UI
	cocos2d::Sprite* m_face;

	//���ʵ��
	static CameraPlayer* m_instance;

	//�ƶ�·���б�
	std::stack<cocos2d::Vec2> m_roadList;

	//���״̬
	PlayerState* m_state;

	int m_flag;
};

#endif // !__PLAYER_H__

