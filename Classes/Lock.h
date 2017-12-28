#pragma once
#include<WinSock2.h>

namespace Net
{
	/*
	*class CLock
	*������
	*/
	class CLock
	{
	public:
		CLock();
		~CLock();
		/*
		*Lock();
		*����
		*/
		void Lock();

		/*
		*UnLock();
		*����
		*/
		void UnLock();
	private:
		CRITICAL_SECTION m_criticalSection;
	};
}