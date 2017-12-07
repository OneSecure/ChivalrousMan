#include"GameData.h"
#include"Commen.h"
#include<atomic>
#include<mutex>
using namespace std;

#define DataFileName "GameData.xml"
atomic<GameData*> g_load;
mutex g_mutex;
GameData * GameData::m_instance = nullptr;

GameData::GameData()
{
	init();
}

 GameData::~GameData()
{
	 RELEASE_NULL(m_dictionary);
}

GameData*  GameData::getInstance()
{
	m_instance = g_load.load(memory_order_relaxed);
	atomic_thread_fence(memory_order_acquire);
	if (m_instance == nullptr)
	{
		lock_guard<mutex> lock(g_mutex);
		m_instance = g_load.load(memory_order_relaxed);
		if (m_instance == nullptr)
		{
			m_instance = new GameData;
			atomic_thread_fence(memory_order_release);
			g_load.store(m_instance,memory_order_release);
		}
	}
	return m_instance;
}

string GameData::getStringByKey(const std::string & key)
{
	return m_dictionary->valueForKey(key)->getCString();
}

int GameData::getIntByKey(const std::string& key)
{
	return m_dictionary->valueForKey(key)->intValue();
}

bool GameData::getBoolByKey(const std::string& key)
{
	return m_dictionary->valueForKey(key)->boolValue();
}

float GameData::getFloatByKey(const std::string& key)
{
	return m_dictionary->valueForKey(key)->floatValue();
}

void  GameData::release()
{
	RELEASE_NULL(m_instance);
}

bool GameData::init()
{
	m_dictionary = Dictionary::createWithContentsOfFile(DataFileName);
	if (m_dictionary == nullptr)
	{
		return false;
	}
	CC_SAFE_RETAIN(m_dictionary);
	return true;
}