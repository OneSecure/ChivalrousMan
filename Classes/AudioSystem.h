#pragma once
#ifndef __AUDIO_SYSYTEM_H__
#define __AUDIO_SYSYTEM_H__
#include"PreProcess.h"
#include<thread>
#include<atomic>
#include<mutex>

class HelpToolSystem
{
	GET_SINGLE_OBJECT(HelpToolSystem);
public:
	static void releaseAudioSystem();
private:
	HelpToolSystem();
	~HelpToolSystem();

	void CheckBgMusic();
	
	void WorkThread();

	std::thread* m_threadHandle = nullptr;
	bool m_exitThread;

	SINGLE_ATTRIBUTES(HelpToolSystem);
};

#endif // !__AUDIO_SYSYTEM_H__

