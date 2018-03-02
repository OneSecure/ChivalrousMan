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
	std::string name;               //任务名称
	std::string fromwho;         //在谁那里接的任务
	std::string destwho;          //提交任务的人
	std::string schedulewho;   //提交物
	float glodreward;              //金币奖励
	float expreward;              //经验奖励
	int index;                           //任务索引
	int curschedule;                //当前完成进度
	int allschedule;                 //完成该任务需要的总进度
	int type;                             //任务类型
};

/*
*TaskSystem
*任务系统
*/
class TaskSystem
{
	GET_SINGLE_OBJECT(TaskSystem);

	static void release();

	std::map<std::string, std::string> m_entocn;         //英文名映射到中文名

	const std::list<TaskInfo>& getmissedTask() { return m_missedTask; }
	const std::list<TaskInfo>& getpickedupTask() { return m_pickedupTask; }

	/*
	*pickupTask(int index);
	*接取任务
	*@param index：任务索引
	*/
	int pickupTask(int index);

	/*
	*submitTask(int index);
	*提交任务
	*@param node：提示显示层
	*@param index：提交的任务索引
	*/
	void submitTask(cocos2d::Node* node, int index);

	/*
	*haveMissedTask(const std::string& name);
	*指定名称的Npc有没有未接任务
	*@param name：npc名称
	*@return int：有返回任务索引，没有返回0
	*/
	int haveMissedTask(const std::string& name);

	/*
	*havePickedupTask(const std::string& name);
	*指定名称的Npc是否可提交任务
	*@param name：npc名称
	*@return int：没有返回0，有但未完成则返回索引的负数，有且已完成返回索引
	*/
	int havePickedupTask(const std::string& name);

	/*
	*checkKillMonster(const std::string& name);
	*检查击杀的怪物是否为任务所需
	*/
	void checkKillMonster(const std::string& name);

	/*
	*checkTask(int index);
	*检测任务类型同时返回目标名
	*
	*/
	int checkTask(int index,std::string& name);
private:
	TaskSystem();
	~TaskSystem();

	/*
	*createTask()
	*产生任务
	*@return int：返回0表示新增一个任务，返回-1表示没有新增
	*/
	int createTask();

	/*
	*任务系统工作线程
	*/
	void workThread();

	SINGLE_ATTRIBUTES(TaskSystem);

	std::list<TaskInfo> m_missedTask;         //未接任务列表
	std::list<TaskInfo> m_pickedupTask;     //已接受任务列表
	std::set<int> m_taskindexs;                    //已有任务索引
	std::thread* m_thread = nullptr;                            //
	std::vector<std::string> m_npcvec;        
	bool m_exitThread = false;
};

#endif // !__TASK_SYSTEM_H__