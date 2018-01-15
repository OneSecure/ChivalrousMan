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

void BackPackManager::addBackPackThing(ThingInfo thinginfo)
{
	int flag = 0;
	for (auto it = m_backpackList.begin(); it != m_backpackList.end(); ++it)
	{
		if (it->name == thinginfo.name)
		{
			flag = 1;
			++it->nums;
		}
	}
	if (!flag)
	{
		thinginfo.nums = 1;
		m_backpackList.push_back(thinginfo);
	}
}

int BackPackManager::removeBackPackThing(const std::string& name)
{
	for (auto it = m_backpackList.begin(); it != m_backpackList.end(); ++it)
	{
		if (it->name == name)
		{
			--(it->nums);
			if (it->nums == 0)
			{
				m_backpackList.erase(it);
				return -2;
			}
			return -1;
		}
	}
	return 0;
}

const std::list<ThingInfo>& BackPackManager::getBackPackMap()
{
	return m_backpackList;
}
