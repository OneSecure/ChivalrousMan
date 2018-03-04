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
	*接收服务器发来的消息
	*/
	virtual void  OnRecv(char* buff) override;
	
	static void release();

	/*
	*连接服务器·
	*/
	int Connect();

	/*
	*SendEntryMsg();
	*向服务器发送进入游戏消息
	*/
	void SendEntryMsg();

	/*
	*SendInitData();
	*向服务器玩家角色数据消息·
	*/
	void SendPlayerData();
private:
	CMClient();
	~CMClient();

	/*
	* readConfConnectServer();
	*读取服务器配置并连接
	*/
	void readConfConnectServer();

	SINGLE_ATTRIBUTES(CMClient);

	std::string m_serverip;
	unsigned long m_port;
};

#endif // !__CM_CLIENT_H__