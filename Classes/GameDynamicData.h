#pragma once
#ifndef __GAME_DYNAMIC_DATA_H__
#define __GAME_DYNAMIC_DATA_H__
#include"cocos2d.h"
#include<sstream>
#include<string>
#include<map>

#define SetFloatData GameDynamicData::getInstance()->setFloatByKey
#define SetIntData GameDynamicData::getInstance()->setIntByKey
#define SetBoolData GameDynamicData::getInstance()->setBoolByKey
#define SetStringData GameDynamicData::getInstance()->setStringByKey
#define GetFloatData GameDynamicData::getInstance()->getFloatByKey
#define GetIntData GameDynamicData::getInstance()->getIntByKey
#define GetBoolData GameDynamicData::getInstance()->getBoolByKey
#define GetStringData GameDynamicData::getInstance()->getStringByKey

class GameDynamicData :public cocos2d::CCObject
{
public:
	static GameDynamicData* getInstance();

	void setFloatByKey(const std::string& key, const float& value);

	void setIntByKey(const std::string& key, const int& value);

	void setBoolByKey(const std::string& key, bool value);

	void setStringByKey(const std::string& key, const std::string& value);

	int getIntByKey(const std::string& key);

	float getFloatByKey(const std::string& key);

	bool getBoolByKey(const std::string& key);

	std::string getStringByKey(const std::string& key);

	void release();
private:
	GameDynamicData();
	~GameDynamicData();
	
	void setValue(const std::string& key,std::stringstream& ss);

	bool init();

	std::map<std::string, std::string> m_data;
	
	static GameDynamicData* m_instance;
};

#endif // !__GAME_DYNAMIC_DATA_H__

