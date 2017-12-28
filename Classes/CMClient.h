#pragma once
#ifndef __CM_CLIENT_H__
#define __CM_CLIENT_H__
#include"PreProcess.h"
#include"TCPClient.h"

class CMClient Inherit(Net::CTCPClient)
{
	GET_SINGLE_OBJECT(CMClient)
public:
	/*
	*���շ�������������Ϣ
	*/
	virtual void  OnRecv(char* buff) override;
	
	static void release();
private:
	CMClient();
	~CMClient();

	/*
	* readConfConnectServer();
	*��ȡ���������ò�����
	*/
	void readConfConnectServer();

	SINGLE_ATTRIBUTES(CMClient);
};

#endif // !__CM_CLIENT_H__

