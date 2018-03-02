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
	*��Ӽ���
	*@param name����������
	*@param grade�����ܵȼ�
	*@return int������-1��ʾ�ü����Ѿ�ϰ�ã�����0��ʾ��ӳɹ�
	*/
	int addSkill(const std::string& name, const int& grade = 1);

	/*
	*upSkill(const std::string& name)
	*�������ܵȼ�
	*@param name����������
	*@return int������0��ʾ�����ɹ�������-1��ʾ�ü��ܲ�����
	*/
	int upSkill(const std::string& name);

	/*
	*removeSkill(const std::string& name);
	*�Ƴ�����
	*@param name����������
	*/
	void removeSkill(const std::string& name);

	/*
	*haveSkill(const std::string& name)
	*�ж��Ƿ��Ѿ�ѧϰ�˸ü���
	*@param name����������
	*@return bool���Ѿ�ѧϰ����true�����򷵻�false
	*/
	bool haveSkill(const std::string& name);

	/*
	*getSkillMap();
	*��ȡ����ӳ���б�
	*/
	const std::map<std::string, int>& getSkillMap();

	/*
	*skillNumbers();
	*��ȡ��������
	*@return  int:��������
	*/
	int skillNumbers();

	/*
	*readSkillInfo();
	*��ȡ��ɫ������Ϣ
	*/
	void readSkillInfo();

	/*
	*saveSkillInfo();
	*�����ɫ������Ϣ
	*/
	void  saveSkillInfo();
private:
	SkillManager();
	~SkillManager();

	std::map<std::string, int> m_skillMap;
	SINGLE_ATTRIBUTES(SkillManager);
};

#endif // !__SKILL_MANAGER_H__
