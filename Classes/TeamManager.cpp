#include"TeamManager.h"
#include"Commen.h"
#include"CameraPlayer.h"
#include"CMClient.h"

DEFINE_SINGLE_ATTRIBUTES(TeamManager);

void TeamManager::release()
{
	RELEASE_NULL(m_instance);
}

void TeamManager::createTeam(const int& fd, int status)
{
	m_teamMembers.clear();
	m_teamMembers[fd] = status;
}

void TeamManager::removeTeamMembers(int fd)
{
	int iRet = m_teamMembers.erase(fd);
	if (iRet)
	{
		if (m_teamMembers.size() == 0)
		{
			CameraPlayer::getPlayerInstance()->setTeamStatus(P_STATUS_NORMAL);
		}
	}
}

void TeamManager::dissolveTeam()
{
	m_teamMembers.clear();
	CameraPlayer::getPlayerInstance()->setTeamStatus(P_STATUS_NORMAL);
}