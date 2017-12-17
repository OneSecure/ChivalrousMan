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
	GettingAndSetting(std::string, nums, nums);
public:
	std::string& operator[](const int& index)
	{
		switch (index)
		{
		case 1:
			return playerName;
		case 2:
			return playerPsw;
		case 3:
			return nums;
		default:
			break;
		}
	}

	std::string getAttributeName(const int& index)
	{
		switch (index)
		{
		case 1:
			return "playername";
		case 2:
			return "playerpsw";
		case 3:
			return "nums";
		default:
			break;
		}
		return "";
	}
	
	std::string getName()
	{
		return "player";
	}

	int getAttributeNums()
	{
		return 3;
	}
};

class PlayerInfo
{
public:
	PlayerInfo() {}
	~PlayerInfo() {}

	GettingAndSetting(std::string, playerName, playerName);
	GettingAndSetting(std::string, roleName, roleName);
	GettingAndSetting(std::string, roleType, roleType);
public:
	std::string& operator[](const int& index)
	{
		switch (index)
		{
		case 1:
			return playerName;
		case 2:
			return roleName;
		case 3:
			return roleType;
		default:
			break;
		}
	}
	
	std::string getAttributeName(const int& index)
	{
		switch (index)
		{
		case 1:
			return "playername";
		case 2:
			return "rolename";
		case 3:
			return "roletype";
		default:
			break;
		}
		return "";
	}

	std::string getName()
	{
		return "playerinfo";
	}
	
	int getAttributeNums()
	{
		return 3;
	}
};


#endif // !__MODEL_H__

