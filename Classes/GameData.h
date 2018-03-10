#pragma once
#ifndef __GAMEDATA_H__
#define __GAMEDATA_H__
#include"PreProcess.h"
#include<string>
#include<atomic>
#include<mutex>

#define StringValue GameData::getInstance()->getStringByKey
#define IntValue GameData::getInstance()->getIntByKey
#define BoolValue GameData::getInstance()->getBoolByKey
#define FloatValue GameData::getInstance()->getFloatByKey
#define NumberToString GameData::getInstance()->numberToString
#define NTS NumberToString

class GameData:public cocos2d::CCObject
{
	GET_SINGLE_OBJECT(GameData);
public:
	std::string getStringByKey(const std::string& key);

	int getIntByKey(const std::string& key);

	bool getBoolByKey(const std::string& key);

	float getFloatByKey(const std::string& key);

	std::string numberToString(float number);

	static void release();
private:
	GameData();
	~GameData();
	bool init();

	cocos2d::Dictionary* m_dictionary;
	cocos2d::Dictionary* m_dictionary1;

	SINGLE_ATTRIBUTES(GameData);
};

#endif // !__GAMEDATA_H__

