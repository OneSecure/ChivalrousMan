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
	*添加技能
	*@param name：技能名称
	*@param grade：技能等级
	*@return int：返回-1表示该技能已经习得，返回0表示添加成功
	*/
	int addSkill(const std::string& name, const int& grade = 1);

	/*
	*upSkill(const std::string& name)
	*升级技能等级
	*@param name：技能名称
	*@return int：返回0表示升级成功，返回-1表示该技能不存在
	*/
	int upSkill(const std::string& name);

	/*
	*removeSkill(const std::string& name);
	*移除技能
	*@param name：技能名称
	*/
	void removeSkill(const std::string& name);

	/*
	*haveSkill(const std::string& name)
	*判断是否已经学习了该技能
	*@param name：技能名称
	*@return bool：已经学习返回true，否则返回false
	*/
	bool haveSkill(const std::string& name);

	/*
	*getSkillMap();
	*获取技能映射列表
	*/
	const std::map<std::string, int>& getSkillMap();

	/*
	*skillNumbers();
	*获取技能数量
	*@return  int:技能数量
	*/
	int skillNumbers();

	/*
	*readSkillInfo();
	*读取角色技能信息
	*/
	void readSkillInfo();

	/*
	*saveSkillInfo();
	*保存角色技能信息
	*/
	void  saveSkillInfo();
private:
	SkillManager();
	~SkillManager();

	std::map<std::string, int> m_skillMap;
	SINGLE_ATTRIBUTES(SkillManager);
};

#endif // !__SKILL_MANAGER_H__
