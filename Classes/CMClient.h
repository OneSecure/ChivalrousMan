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
	*接收服务器发来的消息
	*/
	virtual void  OnRecv(char* buff) override;
	
	static void release();
private:
	CMClient();
	~CMClient();

	/*
	* readConfConnectServer();
	*读取服务器配置并连接
	*/
	void readConfConnectServer();

	SINGLE_ATTRIBUTES(CMClient);
};

#endif // !__CM_CLIENT_H__

