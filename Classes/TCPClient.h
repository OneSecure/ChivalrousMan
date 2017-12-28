#pragma once
#ifndef __TCP_CLIENT_H__
#define __TCP_CLIENT_H__
#include<WinSock2.h>
#include<string>
#include<thread>
#include"public.h"

namespace Net
{
	class CTCPClient;
	typedef void(*ClientFunc)(const char* buff, CTCPClient* pClient, LPVOID Param);

	typedef struct ClientSt
	{
		ClientFunc func;
		LPVOID Param;
	};

	class CTCPClient
	{
	public:
		CTCPClient();
		explicit CTCPClient(ClientFunc clientProc, LPVOID Param = NULL);
		CTCPClient(const CTCPClient& src) = delete;
		CTCPClient& operator=(const CTCPClient& src) = delete;
		virtual ~CTCPClient();

		/*
		*ConnectSever(std::string ServerIp, unsigned long port = PORT);
		*连接服务器
		*@Param serverIp：服务器ip
		*@Param port：服务器端口
		*@return bool：true连接成功，false连接失败
		*/
		bool ConnectSever(std::string ServerIp, unsigned long port = PORT);

		/*
		*sendMsg(const char* buff);
		*向服务起发送消息
		*@Param buff：发送的消息内容
		*@return bool：true发送失败，false发送成功
		*/
		bool SendMsg(const char* buff, unsigned int len);

		/*
		*GetLastError();
		*获取上一次错误描述
		*@return string：错误描述
		*/
		const std::string& GetLastError();

		/*
		*CloseClient();
		*关闭客户端并销毁资源
		*/
		void CloseClient();

		/*
		*OnRecv(char* buff);
		*收到服务器消息的回调函数
		*@Param buff:消息内容
		*/
		virtual void OnRecv(char* buff);
	private:
		/*
		*DoServerMsg()
		*处理服务启发来的消息
		*/
		void DoServerMsg();

		SOCKET m_sockServer;
		std::string m_Error;
		ClientSt m_clientProc;
		std::thread* m_recvThread;
		bool m_isClose;
	};
}

#endif // !__TCP_CLIENT_H__