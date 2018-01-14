#include"SkillManager.h"
#include"Commen.h"

DEFINE_SINGLE_ATTRIBUTES(SkillManager);

SkillManager::SkillManager()
{

}

 SkillManager::~SkillManager()
{

}

 void SkillManager::release()
 {
	 RELEASE_NULL(m_instance);
 }

 void SkillManager::alterSkill(const std::string& name, const int& grade)
 {
	 m_skillMap[name] = grade;
 }

 void SkillManager::removeSkill(const std::string& name)
 {
	 m_skillMap.erase(name);
 }

 const std::map<std::string, int>& SkillManager::getSkillMap()
 {
	 return m_skillMap;
 }