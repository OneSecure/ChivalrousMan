#include"EquipmentManager.h"
#include"Commen.h"
#include"EquipMent.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"Model.h"
#include"DBDao.h"
#include<map>

DEFINE_SINGLE_ATTRIBUTES(EquipmentManager);

void EquipmentManager::realse()
{
	RELEASE_NULL(m_instance);
}

int EquipmentManager::wearEquipment(const EMInfo& info)
{
	for (auto it =m_emlist.begin(); it != m_emlist.end(); ++it)
	{
		if (it->type == info.type)
		{
			auto eq=EquipMent::createWithImage(it->name + ".png");
			eq->setgrade(it->grade);
			eq->Disassemble(nullptr);
			it->name = info.name;
			it->grade = 1;
			return -1;
		}
	}
	m_emlist.push_back(info);
	return 0;
}

int EquipmentManager::upEquipment(const std::string& name)
{
	for (auto& var:m_emlist)
	{
		if (var.name == name)
		{
			var.grade += 1;
			updateEm(var);
			return 0;
		}
	}
	return 1;
}

int EquipmentManager::removeEquipment(const std::string& name)
{
	for (auto it = m_emlist.begin(); it != m_emlist.end(); ++it)
	{
		if (it->name == name)
		{
			m_emlist.erase(it);
			deleteEm(*it);
			return 0;
		}
	}
	return -1;
}

std::list<EMInfo>&  EquipmentManager::getEmList()
{
	return m_emlist;
}

void EquipmentManager::readEquipmentInfo()
{
	m_emlist.clear();
	EquipmentInfo info;
	DBDao<EquipmentInfo> dao;
	info.setplayername(GetStringData("playername"));
	info.setrolename(GetStringData("rolename"));
	dao.setModel(info);
	auto list = dao.queryModel();
	for (auto var : list)
	{
		EMInfo eminfo;
		eminfo.name = var.getequipmentname();
		eminfo.grade = std::stoi(var.getgrade());
		eminfo.type = std::stoi(var.gettype());
		m_emlist.push_back(eminfo);
	}
}

void EquipmentManager::saveEquipmentInfo()
{
	for (auto var : m_emlist)
	{
		EquipmentInfo info;
		DBDao<EquipmentInfo> dao;
		info.setplayername(GetStringData("playername"));
		info.setrolename(GetStringData("rolename"));
		info.setequipmentname(var.name);
		info.setgrade(NTS(var.grade));
		info.settype(NTS(var.type));
		dao.setModel(info);
		dao.insertModel();
	}
}

void EquipmentManager::updateEm(EMInfo info)
{
	EquipmentInfo em;
	DBDao<EquipmentInfo> dao;
	em.setgrade(NTS(info.grade));
	std::map<std::string, std::string> keyvls;
	keyvls["playername"] = GetStringData("playername");
	keyvls["rolename"] = GetStringData("rolename");
	keyvls["equipmentname"] = info.name;
	dao.setModel(em);
	dao.updateModel(keyvls);
}

void EquipmentManager::deleteEm(EMInfo info)
{
	EquipmentInfo em;
	DBDao<EquipmentInfo> dao;
	em.setgrade(NTS(info.grade));
	em.setequipmentname(info.name);
	em.setplayername(GetStringData("playername"));
	em.setrolename(GetStringData("rolename"));
	em.settype(NTS(info.type));
	dao.setModel(em);
	dao.deleteModel();
}