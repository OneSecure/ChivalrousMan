#pragma once
#ifndef __SKILL_MANAGER_H__
#define __SKILL_MANAGER_H__
#include"PreProcess.h"
#include<thread>
#include<atomic>
#include<mutex>
#include<map>

/*
*class SkillManager
*���ܹ�����
*/
class SkillManager
{
	GET_SINGLE_OBJECT(SkillManager)
public:
	static void release();

	/*
	*alterSkill(const std::string& name, const int& grade);
	*��ӻ��޸ļ���
	*@param name����������
	*@param grade�����ܵȼ�
	*/
	void alterSkill(const std::string& name, const int& grade);

	/*
	*removeSkill(const std::string& name);
	*�Ƴ�����
	*@param name����������
	*/
	void removeSkill(const std::string& name);

	/*
	*getSkillMap();
	*��ȡ����ӳ���б�
	*/
	const std::map<std::string, int>& getSkillMap();
private:
	SkillManager();
	~SkillManager();

	std::map<std::string, int> m_skillMap;
	SINGLE_ATTRIBUTES(SkillManager);
};

#endif // !__SKILL_MANAGER_H__
