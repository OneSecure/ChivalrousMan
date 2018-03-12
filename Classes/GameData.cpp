#include"GameData.h"
#include"Commen.h"
using namespace std;

#define RETURN_VALUE(__TYPE__)     \
return m_dictionary->valueForKey(key)->__TYPE__();

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

 std::string GameData::getStringByKey(const std::string & key)
{
	RETURN_VALUE(getCString);
}

int GameData::getIntByKey(const std::string& key)
{
	RETURN_VALUE(intValue);
}

bool GameData::getBoolByKey(const std::string& key)
{
	RETURN_VALUE(boolValue);
}

float GameData::getFloatByKey(const std::string& key)
{
	RETURN_VALUE(floatValue);
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