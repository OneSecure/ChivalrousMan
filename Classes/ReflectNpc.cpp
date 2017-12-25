#include"ReflectNpc.h"
#include"Commen.h"

DEFINE_SINGLE_ATTRIBUTES(ReflectNpc);

void ReflectNpc::registerReflectClass(const std::string& classname, Sel_NpcCallFunc callfunc)
{
	m_reflectMap[classname] = callfunc;
}

Npc* ReflectNpc::getReflectObject(const std::string& classname)
{
	auto it = m_reflectMap.find(classname);
	if (it != m_reflectMap.end())
	{
		return it->second();
	}
	return nullptr;
}

