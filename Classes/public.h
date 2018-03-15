#pragma once
#ifndef __PUBLIC_H__
#define __PUBLIC_H__

#define PORT 6036
#define BUFF_SIZE 1024

typedef struct OVP_IO_DATA {
	OVERLAPPED overlapped;
	WSABUF wsaBuf;
	char Message[BUFF_SIZE];
	DWORD RecvNums;
	DWORD flags;
}MY_IO_DATA;

typedef struct OVP_IO_UDATA
{
	OVERLAPPED  overlap;
	WSABUF wsaBuf;
	CHAR   Message[BUFF_SIZE];
	DWORD recvNums;      //存储接收到的字节数
	DWORD flags;
	SOCKADDR_IN sourceAddr; //存储数据来源IP地址
	int sourceAddrLen;              //存储数据来源IP地址长度
};

#define CLOSE_MESSAGE "~#@**close**@#~"
#define CONNECT_MESSAGE "~#@**connect**@#~"

#endif // !__PUBLIC_H__