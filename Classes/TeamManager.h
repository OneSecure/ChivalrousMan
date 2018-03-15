#pragma once
#ifndef __TEAM_MANAGER_H__
#define __TEAM_MANAGER_H__
#include"PreProcess.h"
#include<map>

/*
*class TeamManager
*队伍管理器,暂时队伍人数上限为2个
*/
class TeamManager
{
	CLASS_ESSENTAIL(TeamManager)
public:
	GET_SINGLE_OBJECT(TeamManager);

	static void release();

	/*
	*创建一个队伍
	*@param fd：玩家唯一标识
	*@param status：成员状态
	*/
	void createTeam(const int& fd, int status);

	/*
	*删除队伍成员
	*@param fd：玩家唯一标识
	*/
	void removeTeamMembers(int fd);

	/*
	*解散队伍
	*/
	void dissolveTeam();

	std::map<int, int>& getTeamMembers() { return m_teamMembers; }
private:
	std::map<int, int> m_teamMembers;   //保存队员

	SINGLE_ATTRIBUTES(TeamManager);
};

#endif // !__TEAM_MANAGER_H__

