#pragma once
#ifndef __TEAM_MANAGER_H__
#define __TEAM_MANAGER_H__
#include"PreProcess.h"
#include<map>

/*
*class TeamManager
*���������,��ʱ������������Ϊ2��
*/
class TeamManager
{
	CLASS_ESSENTAIL(TeamManager)
public:
	GET_SINGLE_OBJECT(TeamManager);

	static void release();

	/*
	*����һ������
	*@param fd�����Ψһ��ʶ
	*@param status����Ա״̬
	*/
	void createTeam(const int& fd, int status);

	/*
	*ɾ�������Ա
	*@param fd�����Ψһ��ʶ
	*/
	void removeTeamMembers(int fd);

	/*
	*��ɢ����
	*/
	void dissolveTeam();

	std::map<int, int>& getTeamMembers() { return m_teamMembers; }
private:
	std::map<int, int> m_teamMembers;   //�����Ա

	SINGLE_ATTRIBUTES(TeamManager);
};

#endif // !__TEAM_MANAGER_H__

