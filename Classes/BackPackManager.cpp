#include"BackPackManager.h"
#include"Commen.h"
#include<utility>

DEFINE_SINGLE_ATTRIBUTES(BackPackManager);

BackPackManager::BackPackManager()
{
}

BackPackManager::~BackPackManager()
{
}

void BackPackManager::release()
{
	RELEASE_NULL(m_instance);
}

void BackPackManager::addBackPackThing(const std::string& name,const int& type)
{
	m_backpackMap[name] = type;
}

void BackPackManager::removeBackPackThing(const std::string& name)
{
	m_backpackMap.erase(name);
}

const std::map<std::string, int>& BackPackManager::getBackPackMap()
{
	return m_backpackMap;
}
