#include"TaskSystem.h"
#include"Commen.h"
#include"CameraPlayer.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"CameraPlayer.h"
#include"TipLayer.h"
#include<random>
#include<fstream>
#include<string>

using namespace std;

DEFINE_SINGLE_ATTRIBUTES(TaskSystem);

TaskSystem::TaskSystem()
{
	m_entocn["NpcBlue"] = StringValue("NpcBlueCN");
	m_entocn["NpcEquip"] = StringValue("NpcEquipCN");
	m_entocn["NpcMamom"] = StringValue("NpcMamomCN");
	m_entocn["NpcMonk"] = StringValue("NpcMonkCN");
	m_entocn["NpcPink"] = StringValue("NpcPinkCN");
	m_entocn["NpcSkill"] = StringValue("NpcSkillCN");
	m_entocn["NpcVallige"] = StringValue("NpcValligeCN");
	m_entocn["BlackDragon"] = StringValue("BlackDragonCN");
	m_entocn["Dragon"] = StringValue("DragonCN");
	m_entocn["Ghost"] = StringValue("GhostCN");
	m_entocn["Kougamon"] = StringValue("KougamonCN");
	m_entocn["Lion"] = StringValue("LionCN");
	m_entocn["Minotaur"] = StringValue("MinotaurCN");
	m_entocn["Octopus"] = StringValue("OctopusCN");
	m_entocn["Pterosaur"] = StringValue("PterosaurCN");
	m_entocn["SkeletonMaster"] = StringValue("SkeletonMasterCN");
	m_entocn["TarrasqueMessenger"] = StringValue("TarrasqueMessengerCN");
	m_thread = new std::thread{ &TaskSystem::workThread,this };
	m_npcvec = { "NpcVallige","NpcBlue","NpcMamom","NpcMonk" };
}

TaskSystem::~TaskSystem()
{
	m_exitThread = true;
	if (m_thread != nullptr)
		m_thread->join();
	RELEASE_NULL(m_thread);
}

void TaskSystem::release()
{
	RELEASE_NULL(m_instance);
}

void TaskSystem::workThread()
{
	while (true)
	{
		if (m_exitThread)
		{
			return;
		}
		createTask();
		Sleep(15000);
	}
}

int TaskSystem::createTask()
{
	if (m_missedTask.size() < 3)
	{
		std::random_device rand;
		int index = rand() % 11 + 1;
		auto it=m_taskindexs.find(index);
		if (it != m_taskindexs.end())
		{
			return -1;
		}
		std::ifstream fin;
		std::string filename = "Task/Task" + NTS(index) + ".tsk";
		fin.open(filename, std::ios::in);
		if (fin.fail())
		{
			return -1;
		}
		TaskInfo info;
		std::string tmp;
		fin >> tmp;
		fin >> info.name;
		fin >> tmp;
		fin >> info.schedulewho;
		fin >> tmp;
		fin >> info.glodreward;
		fin >> tmp;
		fin >> info.expreward;
		fin >> tmp;
		fin >> info.index;
		fin >> tmp;
		fin >> info.curschedule;
		fin >> tmp;
		fin >> info.allschedule;
		fin >> tmp;
		fin >> info.type;
		info.fromwho = m_npcvec[rand() % 4];
		info.destwho = m_npcvec[rand() % 4];
		m_missedTask.push_back(info);
		m_taskindexs.insert(info.index);
		return 0;
	}
	return -1;
}

int TaskSystem::pickupTask(int index)
{
	for (auto it = m_missedTask.begin(); it != m_missedTask.end(); ++it)
	{
		if (it->index == index)
		{
			m_pickedupTask.push_back(*it);
			m_missedTask.erase(it);
			return 0;
		}
	}
	return 1;
}

void TaskSystem::submitTask(cocos2d::Node* node,int index)
{
	for (auto it = m_pickedupTask.begin(); it != m_pickedupTask.end(); ++it)
	{
		if (it->index == index)
		{
			GetPlayerData().addGlod(it->glodreward);
			GetPlayerData().addExp(it->expreward);
			std::string tiptext = StringValue("Glod") + "+" + NTS(it->glodreward) + "," + StringValue("Exp") + "+" + NTS(it->expreward);
			auto tiplayer = TipLayer::createTipLayer(tiptext);
			node->addChild(tiplayer);
			m_pickedupTask.erase(it);
			m_taskindexs.erase(it->index);
			return;
		}
	}
}

int TaskSystem::haveMissedTask(const std::string& name)
{
	for (auto var : m_missedTask)
	{
		if (var.fromwho == name)
		{
			return var.index;
		}
	}
	return 0;
}

int TaskSystem::havePickedupTask(const std::string& name)
{
	int index = 0;
	for (auto var : m_pickedupTask)
	{
		if (var.destwho == name)
		{
			if (var.curschedule >= var.allschedule)
			{
				return var.index;
			}
			else
			{
				index = -var.index;
			}
		}
	}
	return index;
}

void TaskSystem::checkKillMonster(const std::string& name)
{
	for (auto it = m_pickedupTask.begin(); it != m_pickedupTask.end(); ++it)
	{
		if (it->schedulewho == name)
		{
			it->curschedule++;
			return;
		}
	}
}

int TaskSystem::checkTask(int index,std::string& name)
{
	for (auto var : m_missedTask)
	{
		if (var.index == index)
		{
			name = m_entocn[var.destwho];
			return var.type;
		}
	}
}