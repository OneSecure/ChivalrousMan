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
*技能管理器
*/
class SkillManager
{
	GET_SINGLE_OBJECT(SkillManager)
public:
	static void release();

	/*
	*alterSkill(const std::string& name, const int& grade);
	*添加或修改技能
	*@param name：技能名称
	*@param grade：技能等级
	*/
	void alterSkill(const std::string& name, const int& grade);

	/*
	*removeSkill(const std::string& name);
	*移除技能
	*@param name：技能名称
	*/
	void removeSkill(const std::string& name);

	/*
	*getSkillMap();
	*获取技能映射列表
	*/
	const std::map<std::string, int>& getSkillMap();
private:
	SkillManager();
	~SkillManager();

	std::map<std::string, int> m_skillMap;
	SINGLE_ATTRIBUTES(SkillManager);
};

#endif // !__SKILL_MANAGER_H__
