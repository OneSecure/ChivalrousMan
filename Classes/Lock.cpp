#include "Lock.h"
#pragma comment(lib,"ws2_32.lib")
using namespace Net;

CLock::CLock()
{
	InitializeCriticalSection(&m_criticalSection);
}

CLock::~CLock()
{
}

void CLock::Lock()
{
	EnterCriticalSection(&m_criticalSection);
}

void CLock::UnLock()
{
	LeaveCriticalSection(&m_criticalSection);
}