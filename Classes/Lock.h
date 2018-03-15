#pragma once
#ifndef __LOCK_H__
#define __LOCK_H__
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

#endif // !__LOCJ_H__