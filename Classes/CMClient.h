#pragma once
#ifndef __CM_CLIENT_H__
#define __CM_CLIENT_H__
#include"PreProcess.h"
#include"TCPClient.h"
#include"ShareData.h"
#include<list>

class CMClient Inherit(Net::CTCPClient)
{
	GET_SINGLE_OBJECT(CMClient)
public:
	/*
	*���շ�������������Ϣ
	*/
	virtual void  OnRecv(char* buff) override;
	
	static void release();

	/*
	*���ӷ�������
	*/
	int Connect();

	/*
	*SendInitData();
	*���������ҽ�ɫ������Ϣ��
	*/
	void SendInitPlayerData();

	/*
	*SendInitPos();
	*����������ͳ�ʼ��λ����Ϣ
	*/
	void SendInitPos();
	
	/*
	*SendMoveToMsg(const cocos2d::Vec2& pos);
	*�����ƶ���Ŀ��λ����Ϣ
	*@param pos:Ŀ��λ��
	*/
	void SendMoveToMsg(const cocos2d::Vec2& pos);

	/*
	*������ҳ�ʼ��λ����Ϣ��Ϣ
	*/
	void doInitPlayerPosMsg(InitPos_Msg* msg);

	/*
	*�������������Ϣ
	*/
	void SendPlayerLeaveMsg();

	/*
	*ɾ�����
	*@param fd:���Ψһ��ʶ
	*/
	void removePlayer(int fd);

	/*
	*doPlayerMoveToMsg();
	*��������ƶ���Ϣ
	*/
	void doPlayerMoveToMsg(MoveTo_Msg* msg);

	/*
	*doPlayerPosVerifyMsg();
	*�������λ��У����Ϣ
	*@param msg��У����Ϣ
	*/
	void doPlayerPosVerifyMsg(VerifyPos_Msg* msg);

	/*
	*VerifyPlayerPos();
	*��������������λ��У����Ϣ
	*/
	void VerifyPlayerPos();

	const std::list<Player_Info>& getPlayerList() { return m_playerlist; }
private:
	CMClient();
	~CMClient();

	/*
	* readConfConnectServer();
	*��ȡ���������ò�����
	*/
	void readConfConnectServer();

	SINGLE_ATTRIBUTES(CMClient);

	std::string m_serverip;
	unsigned long m_port;

	std::list<Player_Info> m_playerlist;
	std::list<std::string> m_worldTalkMsgs;
	std::list<PrivateMsg> m_privateTalkMsgs;
};

#endif // !__CM_CLIENT_H__