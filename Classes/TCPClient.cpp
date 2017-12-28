#include "TCPClient.h"

#pragma comment(lib,"ws2_32.lib")
using namespace Net;
using namespace std;

Net::CTCPClient::CTCPClient()
{
	m_clientProc.func = NULL;
	m_clientProc.Param = NULL;
	m_recvThread = nullptr;
}

CTCPClient::CTCPClient(ClientFunc clientProc, LPVOID Param)
{
	m_clientProc.func = clientProc;
	m_clientProc.Param = Param;
	m_recvThread = nullptr;
}

CTCPClient::~CTCPClient()
{
	CloseClient();
}

bool Net::CTCPClient::ConnectSever(std::string ServerIp, unsigned long port)
{
	m_isClose = false;
	WSAData wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		m_Error = "初始化网络环境失败!";
		return false;
	}
	m_sockServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_sockServer == INVALID_SOCKET)
	{
		m_Error = "创建套接字失败";
		return false;
	}
	SOCKADDR_IN sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_addr.S_un.S_addr = inet_addr(ServerIp.c_str());
	sockAddr.sin_port = htons(port);
	if (connect(m_sockServer, (SOCKADDR*)&sockAddr, sizeof(sockAddr)) == SOCKET_ERROR)
	{
		m_Error = "连接服务失败!";
		return false;
	}
	m_recvThread=new thread{ &CTCPClient::DoServerMsg,this };
	return true;
}

bool Net::CTCPClient::SendMsg(const char * buff,unsigned int len)
{
	if (send(m_sockServer, buff,len, 0) == SOCKET_ERROR)
	{
		m_Error = "向服务发送消息失败!";
		return false;
	}
	return true;
}

const std::string & Net::CTCPClient::GetLastError()
{
	return m_Error;
}

void Net::CTCPClient::CloseClient()
{
	WSACleanup();
	closesocket(m_sockServer);
	m_isClose = true;
	if (m_recvThread != nullptr)
	{
		m_recvThread->join();
		delete m_recvThread;
		m_recvThread = nullptr;
	}
}

void Net::CTCPClient::OnRecv(char * buff)
{
}

void Net::CTCPClient::DoServerMsg()
{
	while (true)
	{
		if (m_isClose == true)
		{
			break;
		}
		char buff[BUFF_SIZE] = { 0 };
		int iRet = recv(m_sockServer, buff, sizeof(buff), 0);
		if (iRet == 0 || iRet == SOCKET_ERROR)
		{
			printf("服务器断开连接!");
			if (m_clientProc.func != NULL)
			{
				m_clientProc.func(CLOSE_MESSAGE, this, m_clientProc.Param);
			}
			else
			{
				OnRecv(CLOSE_MESSAGE);
			}
			break;
		}
		else
		{
			if (m_clientProc.func != NULL)
			{
				m_clientProc.func(buff, this, m_clientProc.Param);
			}
			else
			{
				OnRecv(buff);
			}
		}
	}
}