#include"AudioSystem.h"
#include"Commen.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"SimpleAudioEngine.h"
#include"CMClient.h"

using namespace CocosDenshion;
using namespace std;

DEFINE_SINGLE_ATTRIBUTES(AudioSystem);

AudioSystem::AudioSystem():
	m_exitThread(false)
{
	m_threadHandle = new std::thread{ &AudioSystem::WorkThread,this };
}

AudioSystem::~AudioSystem()
{
	m_exitThread = true;
	if (m_threadHandle != nullptr)
		m_threadHandle->join();
	RELEASE_NULL(m_threadHandle);
}

void AudioSystem::WorkThread()
{
	long count = 0;
	while (true)
	{
		if (m_exitThread)
		{
			break;
		}
		
		CheckBgMusic();
		Sleep(50);
		count++;
		if (count >= 160&&GetIntData("IsHaveGameScene")==1)
		{
			CMClient::getInstance()->VerifyPlayerPos();
			count = 0;
		}
	}
}

void AudioSystem::CheckBgMusic()
{
	if (GetIntData("BgMusic") == 1)
	{
		if (!SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
			SimpleAudioEngine::getInstance()->playBackgroundMusic(StringValue("BgMusic").c_str(), true);
	}
	else
	{
		if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
			SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	}
}

void AudioSystem::releaseAudioSystem()
{
	RELEASE_NULL(m_instance);
}