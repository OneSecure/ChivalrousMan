#include"BackPackManager.h"
#include"Commen.h"

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
