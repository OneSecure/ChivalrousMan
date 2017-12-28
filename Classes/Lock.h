#pragma once
#include<WinSock2.h>

namespace Net
{
	/*
	*class CLock
	*»¥³âËø
	*/
	class CLock
	{
	public:
		CLock();
		~CLock();
		/*
		*Lock();
		*¼ÓËø
		*/
		void Lock();

		/*
		*UnLock();
		*½âËø
		*/
		void UnLock();
	private:
		CRITICAL_SECTION m_criticalSection;
	};
}