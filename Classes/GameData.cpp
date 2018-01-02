#include"GameData.h"
#include"Commen.h"
using namespace std;

#define DataFileName "GameData.xml"

DEFINE_SINGLE_ATTRIBUTES(GameData);

GameData::GameData()
{
	init();
}

 GameData::~GameData()
{
	 RELEASE_NULL(m_dictionary);
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

std::string GameData::numberToString(float number)
{
	std::string res;
	std::stringstream ss;
	ss << number;
	ss >> res;
	return res;
}