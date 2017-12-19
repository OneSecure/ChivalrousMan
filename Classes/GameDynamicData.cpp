#include"GameDynamicData.h"
#include"Commen.h"
#include<regex>
#include<fstream>

using namespace std;
#define FileName "GameDynamicData.data"

#define SetValue(SAVE) stringstream ss ;\
                 ss << value; \
                 setValue(key, ss,SAVE)

#define GetValue(SUFFIX)	 \
auto it=m_data.find(key); \
if (it != m_data.end()) \
{ \
	return sto##SUFFIX(it->second); \
} \
it = m_saveData.find(key); \
if (it != m_saveData.end()) \
{\
	return sto##SUFFIX(it->second);  \
} \
return -1

DEFINE_SINGLE_ATTRIBUTES(GameDynamicData);

GameDynamicData::GameDynamicData()
{
	init();
}

GameDynamicData::~GameDynamicData()
{
	writeDateToFile();
}

void  GameDynamicData::setFloatByKey(const std::string& key, const float& value,bool save)
{
	SetValue(save);
}

void  GameDynamicData::setIntByKey(const std::string& key, const int& value,bool save)
{
	SetValue(save);
}

void GameDynamicData::setStringByKey(const std::string& key, const std::string& value,bool save)
{
	if (save)
	{
		m_saveData[key] = value;
	}
	else
	{
		m_data[key] = value;
	}
}

void  GameDynamicData::setValue(const std::string& key, stringstream& ss,bool save)
{
	string value;
	ss >> value;
	if (save)
	{
		m_saveData[key] = value;
	}
	else
	{
		m_data[key] = value;
	}
}

int GameDynamicData::getIntByKey(const std::string& key)
{
	GetValue(i);
}

float GameDynamicData::getFloatByKey(const std::string& key)
{
	GetValue(f);
}

std::string  GameDynamicData::getStringByKey(const std::string& key)
{
	auto it = m_data.find(key);
	if (it != m_data.end())
	{
		return it->second;
	}
	it = m_saveData.find(key);
	if (it != m_saveData.end())
	{
		return it->second;
	}
	return "";
}

bool  GameDynamicData::init()
{
	readDataFromFile();
	return true;
}

void GameDynamicData::release()
{
	RELEASE_NULL(m_instance);
}

void GameDynamicData::readDataFromFile()
{
	ifstream fin;
	fin.open(FileName, ios::in);
	if (fin.fail())
	{
		return;
	}

	string key;
	string value;
	while (!fin.eof())
	{
		fin >> key;
		fin >> value;
		m_saveData[key] = value;
	}
	fin.close();
}

void GameDynamicData::writeDateToFile()
{
	ofstream fout;
	fout.open(FileName, ios::out);
	if (fout.fail())
	{
		return;
	}
	
	for (auto it = m_saveData.begin(); it != m_saveData.end(); ++it)
	{
		fout << it->first<<" ";
		fout << it->second << endl;
	}
	fout.close();
}