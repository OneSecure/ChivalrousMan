#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include"Animal.h"
#include"PlayerData.h"
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
#define InitPlayerState CameraPlayer::getPlayerInstance()->initStateInfo
#define GetPlayerData CameraPlayer::getPlayerInstance()->getPlayerData
#define AttackPlayer CameraPlayer::getPlayerInstance()->beAttack
#define PlayerTeamStatus CameraPlayer::getPlayerInstance()->getTeamStatus

class PlayerState;

/*
class CameraPlayer 
*�����࣬ͬʱ�䵱�����
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

	/*
	*initStateInfo();
	*��ʼ��״̬��Ϣ
	*@param level:��ͬ��ͼ��
	*/
	void initStateInfo(const int& level);

	/*
	*��ȡ�������
	*/
	PlayerData& getPlayerData() { return m_playerData; }
	
	/*
	*beAttack(float attack);
	*��ұ�����
	*@param attack�������˺�
	*/
	void beAttack(float attack);

	/*
	*SaveGameData();
	*�־û�������Ϸ��ɫ����
	*/
	void SaveGameData();

	/*
	*MoveTo(const cocos2d::Vec2& targetPos);
	*�Ƶ�ĳ��
	*@param targetPos:��Ҫ�ƶ�����Ŀ��ص������ͼ����
	*@return bool������true��ʾ�����ƶ���������false��ʾ����
	*/
	bool moveTo(cocos2d::Vec2 targetPos);
private:
	/*
	*AdjustPlayerAndMapPos()
	*������Һ͵�ͼ��λ��
	*/
	void AdjustPlayerAndMapPos();

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

	CameraPlayer();
	~CameraPlayer();

	//���UI
	cocos2d::Sprite* m_face = nullptr;

	//����ʵ��
	static CameraPlayer* m_instance;

	//�ƶ�·���б�
	std::stack<cocos2d::Vec2> m_roadList;

	//���״̬
	PlayerState* m_state = nullptr;

	//���״̬�ı�
	int m_flag;
	//�����������
	PlayerData m_playerData;
	//��Ҷ���״̬
	PROPERTY__REF(int, m_teamStatus, TeamStatus)
};

#endif // !__PLAYER_H__