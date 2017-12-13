#pragma once
#ifndef __AUDIO_SYSYTEM_H__
#define __AUDIO_SYSYTEM_H__
#include"PreProcess.h"
#include<thread>
#include<atomic>
#include<mutex>

class AudioSystem
{
	GET_SINGLE_OBJECT(AudioSystem);
public:
	static void releaseAudioSystem();
private:
	AudioSystem();
	~AudioSystem();

	void CheckBgMusic();
	
	void WorkThread();

	std::thread* m_threadHandle = nullptr;
	bool m_exitThread;

	SINGLE_ATTRIBUTES(AudioSystem);
};

#endif // !__AUDIO_SYSYTEM_H__

