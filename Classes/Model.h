#pragma once
#ifndef __MODEL_H__
#define __MODEL_H__
#include<string>

#define GettingAndSetting(varType,varName,funName) \
private: varType varName; \
public: varType& get##funName(void){return varName;} \
public: void set##funName(const varType& var) {varName=var}

class Player
{
public:
	Player() {}
	~Player() {}

	GettingAndSetting(std::string, playerName, playerName);
	GettingAndSetting(std::string, playerPsw, playerPsw);
	GettingAndSetting(int, nums, nums);
};

class PlayerInfo
{
public:
	PlayerInfo() {}
	~PlayerInfo() {}

	GettingAndSetting(std::string, playerName, playerName);
	GettingAndSetting(std::string, roleName, roleName);
	GettingAndSetting(std::string, roleType, roleType);
};


#endif // !__MODEL_H__

