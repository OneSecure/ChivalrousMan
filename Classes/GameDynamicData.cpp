#include"GameDynamicData.h"
#include"Commen.h"
#include<mutex>
#include<atomic>
#include<regex>

using namespace std;

#define SetValue() stringstream ss ;\
                 ss << value; \
                 setValue(key, ss)

#define GetValue() auto it = m_data.find(key); \
        return it != m_data.end() ? stoi(it->second) :-1;

atomic<GameDynamicData*> g_dynaload;
mutex g_dynamutex;
GameDynamicData* GameDynamicData::m_instance = nullptr;

GameDynamicData::GameDynamicData()
{
	init();
}

GameDynamicData::~GameDynamicData()
{

}

GameDynamicData* GameDynamicData::getInstance()
{
	m_instance = g_dynaload.load(memory_order_relaxed);
	atomic_thread_fence(memory_order_acquire);
	if (m_instance == nullptr)
	{
		lock_guard<mutex> lock(g_dynamutex);
		m_instance = g_dynaload.load(memory_order_relaxed);
		if (m_instance == nullptr)
		{
			m_instance = new GameDynamicData;
			atomic_thread_fence(memory_order_release);
			g_dynaload.store(m_instance, memory_order_release);
		}
	}
	return m_instance;
}

void  GameDynamicData::setFloatByKey(const std::string& key, const float& value)
{
	SetValue();
}

void  GameDynamicData::setIntByKey(const std::string& key, const int& value)
{
	SetValue();
}

void GameDynamicData::setBoolByKey(const std::string& key, bool value)
{
	SetValue();
}

void GameDynamicData::setStringByKey(const std::string& key, const std::string& value)
{
	m_data[key] = value;
}

void  GameDynamicData::setValue(const std::string& key, stringstream& ss)
{
	string value;
	ss >> value;
	m_data[key] = value;
}

int GameDynamicData::getIntByKey(const std::string& key)
{
	GetValue();
}

float GameDynamicData::getFloatByKey(const std::string& key)
{
	GetValue();
}

bool GameDynamicData::getBoolByKey(const std::string& key)
{
	GetValue();
}

std::string  GameDynamicData::getStringByKey(const std::string& key)
{
	auto it = m_data.find(key);
	return it != m_data.end() ? it->second : "";
}

bool  GameDynamicData::init()
{
	return true;
}

void GameDynamicData::release()
{
	RELEASE_NULL(m_instance);
}