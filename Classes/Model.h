#pragma once
#ifndef __MODEL_H__
#define __MODEL_H__
#include<string>

#define GettingAndSetting(varType,varName,funName) \
private: varType varName=""; \
public: varType& get##funName(void){return varName;} \
public: void set##funName(const varType& var) {varName=var;}

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
			return playerName;
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
	GettingAndSetting(std::string, glod, glod);
	GettingAndSetting(std::string, grade, grade);
	GettingAndSetting(std::string, blood, blood);
	GettingAndSetting(std::string, mana, mana);
	GettingAndSetting(std::string, attack, attack);
	GettingAndSetting(std::string, defense, defense);
	GettingAndSetting(std::string, speed, speed);
	GettingAndSetting(std::string, exp, exp);
	GettingAndSetting(std::string, maxExp, maxExp);
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
		case 4:
			return glod;
		case 5:
			return grade;
		case 6:
			return blood;
		case 7:
			return mana;
		case 8:
			return attack;
		case 9:
			return defense;
		case 10:
			return speed;
		case 11:
			return exp;
		case 12:
			return maxExp;
		default:
			return playerName;
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
		case 4:
			return "glod";
		case 5:
			return "grade";
		case 6:
			return "blood";
		case 7:
			return "mana";
		case 8:
			return "attack";
		case 9:
			return "defense";
		case 10:
			return "speed";
		case 11:
			return "exp";
		case 12:
			return "maxexp";
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
		return 12;
	}
};

#endif // !__MODEL_H__

