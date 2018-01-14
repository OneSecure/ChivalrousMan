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