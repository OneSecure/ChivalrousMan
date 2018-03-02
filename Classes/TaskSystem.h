#pragma once
#ifndef __TASK_SYSTEM_H__
#define __TASK_SYSTEM_H__
#include"PreProcess.h"
#include<atomic>
#include<mutex>
#include<string>
#include<list>
#include<thread>
#include<set>
#include<map>
#include<vector>

struct TaskInfo
{
	std::string name;               //��������
	std::string fromwho;         //��˭����ӵ�����
	std::string destwho;          //�ύ�������
	std::string schedulewho;   //�ύ��
	float glodreward;              //��ҽ���
	float expreward;              //���齱��
	int index;                           //��������
	int curschedule;                //��ǰ��ɽ���
	int allschedule;                 //��ɸ�������Ҫ���ܽ���
	int type;                             //��������
};

/*
*TaskSystem
*����ϵͳ
*/
class TaskSystem
{
	GET_SINGLE_OBJECT(TaskSystem);

	static void release();

	std::map<std::string, std::string> m_entocn;         //Ӣ����ӳ�䵽������

	const std::list<TaskInfo>& getmissedTask() { return m_missedTask; }
	const std::list<TaskInfo>& getpickedupTask() { return m_pickedupTask; }

	/*
	*pickupTask(int index);
	*��ȡ����
	*@param index����������
	*/
	int pickupTask(int index);

	/*
	*submitTask(int index);
	*�ύ����
	*@param node����ʾ��ʾ��
	*@param index���ύ����������
	*/
	void submitTask(cocos2d::Node* node, int index);

	/*
	*haveMissedTask(const std::string& name);
	*ָ�����Ƶ�Npc��û��δ������
	*@param name��npc����
	*@return int���з�������������û�з���0
	*/
	int haveMissedTask(const std::string& name);

	/*
	*havePickedupTask(const std::string& name);
	*ָ�����Ƶ�Npc�Ƿ���ύ����
	*@param name��npc����
	*@return int��û�з���0���е�δ����򷵻������ĸ�������������ɷ�������
	*/
	int havePickedupTask(const std::string& name);

	/*
	*checkKillMonster(const std::string& name);
	*����ɱ�Ĺ����Ƿ�Ϊ��������
	*/
	void checkKillMonster(const std::string& name);

	/*
	*checkTask(int index);
	*�����������ͬʱ����Ŀ����
	*
	*/
	int checkTask(int index,std::string& name);
private:
	TaskSystem();
	~TaskSystem();

	/*
	*createTask()
	*��������
	*@return int������0��ʾ����һ�����񣬷���-1��ʾû������
	*/
	int createTask();

	/*
	*����ϵͳ�����߳�
	*/
	void workThread();

	SINGLE_ATTRIBUTES(TaskSystem);

	std::list<TaskInfo> m_missedTask;         //δ�������б�
	std::list<TaskInfo> m_pickedupTask;     //�ѽ��������б�
	std::set<int> m_taskindexs;                    //������������
	std::thread* m_thread = nullptr;                            //
	std::vector<std::string> m_npcvec;        
	bool m_exitThread = false;
};

#endif // !__TASK_SYSTEM_H__