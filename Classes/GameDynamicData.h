#pragma once
#ifndef __GAME_DYNAMIC_DATA_H__
#define __GAME_DYNAMIC_DATA_H__
#include"PreProcess.h"
#include<sstream>
#include<string>
#include<map>
#include<mutex>
#include<atomic>

class GameScene;

#define SetFloatData GameDynamicData::getInstance()->setFloatByKey
#define SetIntData GameDynamicData::getInstance()->setIntByKey
#define SetBoolData GameDynamicData::getInstance()->setBoolByKey
#define SetStringData GameDynamicData::getInstance()->setStringByKey
#define GetFloatData GameDynamicData::getInstance()->getFloatByKey
#define GetIntData GameDynamicData::getInstance()->getIntByKey
#define GetStringData GameDynamicData::getInstance()->getStringByKey
#define CurGameScene GameDynamicData::getInstance()->getCurGameScene 
#define SetCurGameScene GameDynamicData::getInstance()->setCurGameScene

class GameDynamicData :public cocos2d::CCObject
{
	GET_SINGLE_OBJECT(GameDynamicData);
public:
	void setFloatByKey(const std::string& key, const float& value, bool save = false);

	void setIntByKey(const std::string& key, const int& value, bool save = false);

	void setStringByKey(const std::string& key, const std::string& value, bool save = false);

	int getIntByKey(const std::string& key);

	float getFloatByKey(const std::string& key);

	std::string getStringByKey(const std::string& key);

	static void release();

	inline GameScene* getCurGameScene() { return m_curgs; }
	
	inline void setCurGameScene(GameScene* gs) { m_curgs = gs; }
private:
	GameDynamicData();
	~GameDynamicData();

	void readDataFromFile();

	void writeDateToFile();
	
	void setValue(const std::string& key, std::stringstream& ss, bool save);

	bool init();

	std::map<std::string, std::string> m_data;
	std::map<std::string, std::string> m_saveData;
	//保存当前游戏场景
	GameScene* m_curgs;
	
	SINGLE_ATTRIBUTES(GameDynamicData);
};

#endif // !__GAME_DYNAMIC_DATA_H__

