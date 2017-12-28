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
		*���ӷ�����
		*@Param serverIp��������ip
		*@Param port���������˿�
		*@return bool��true���ӳɹ���false����ʧ��
		*/
		bool ConnectSever(std::string ServerIp, unsigned long port = PORT);

		/*
		*sendMsg(const char* buff);
		*�����������Ϣ
		*@Param buff�����͵���Ϣ����
		*@return bool��true����ʧ�ܣ�false���ͳɹ�
		*/
		bool SendMsg(const char* buff, unsigned int len);

		/*
		*GetLastError();
		*��ȡ��һ�δ�������
		*@return string����������
		*/
		const std::string& GetLastError();

		/*
		*CloseClient();
		*�رտͻ��˲�������Դ
		*/
		void CloseClient();

		/*
		*OnRecv(char* buff);
		*�յ���������Ϣ�Ļص�����
		*@Param buff:��Ϣ����
		*/
		virtual void OnRecv(char* buff);
	private:
		/*
		*DoServerMsg()
		*�����������������Ϣ
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