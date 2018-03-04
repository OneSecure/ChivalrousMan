#pragma once
#ifndef __CM_CLIENT_H__
#define __CM_CLIENT_H__
#include"PreProcess.h"
#include"TCPClient.h"
#include"ShareData.h"

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
	*SendEntryMsg();
	*����������ͽ�����Ϸ��Ϣ
	*/
	void SendEntryMsg();

	/*
	*SendInitData();
	*���������ҽ�ɫ������Ϣ��
	*/
	void SendPlayerData();
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
};

#endif // !__CM_CLIENT_H__