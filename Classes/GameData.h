#pragma once
#ifndef __GAMEDATA_H__
#define __GAMEDATA_H__
#include"cocos2d.h"
#include<string>

#define StringValue GameData::getInstance()->getStringByKey
#define IntValue GameData::getInstance()->getIntByKey
#define BoolValue GameData::getInstance()->getBoolByKey
#define FloatValue GameData::getInstance()->getFloatByKey

class GameData:public cocos2d::CCObject
{
public:
	static GameData* getInstance();

	std::string getStringByKey(const std::string& key);

	int getIntByKey(const std::string& key);

	bool getBoolByKey(const std::string& key);

	float getFloatByKey(const std::string& key);

	void release();
private:
	GameData();
	~GameData();
	bool init();

	cocos2d::Dictionary* m_dictionary;
	static GameData* m_instance;
};

#endif // !__GAMEDATA_H__

