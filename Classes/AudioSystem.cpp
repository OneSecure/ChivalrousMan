#include"AudioSystem.h"
#include"Commen.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"SimpleAudioEngine.h"
#include"TeamManager.h"
#include"CameraPlayer.h"
#include"CMClient.h"
#include"MapInfo.h"

using namespace CocosDenshion;
using namespace std;

DEFINE_SINGLE_ATTRIBUTES(HelpToolSystem);

HelpToolSystem::HelpToolSystem():
	m_exitThread(false)
{
	m_threadHandle = new std::thread{ &HelpToolSystem::WorkThread,this };
}

HelpToolSystem::~HelpToolSystem()
{
	m_exitThread = true;
	if (m_threadHandle != nullptr)
		m_threadHandle->join();
	RELEASE_NULL(m_threadHandle);
}

void HelpToolSystem::WorkThread()
{
	long count = 0;
	long count2 = 0;
	while (true)
	{
		if (m_exitThread)
		{
			break;
		}
		
		CheckBgMusic();
		Sleep(50);
		count++;
		count2++;
		if (count >= 180&&GetIntData("IsHaveGameScene")==1)
		{
			CMClient::getInstance()->VerifyPlayerPos();
			count = 0;
		}
		if (count2 >= 4 && PlayerTeamStatus() == P_STATUS_HEADER)
		{
			for (auto var : TeamManager::getInstance()->getTeamMembers())
			{
				auto info = CMClient::getInstance()->findPlayerInfoByFd(var.first);
				int  mapindex=GetIntData("CurMap");
				if (info.curmap != mapindex)
				{
					Vec2 target{ GetFloatData("DestX"),GetFloatData("DestY") };
					CMClient::getInstance()->sendTeamGotoMapMsg("map" + NTS(mapindex), target, var.first);
				}
			}
			count2 = 0;
		}
	}
}

void HelpToolSystem::CheckBgMusic()
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

void HelpToolSystem::releaseAudioSystem()
{
	RELEASE_NULL(m_instance);
}