#include"GameDynamicData.h"
#include"Commen.h"
#include<regex>
#include<fstream>

using namespace std;
#define FileName "GameDynamicData.data"

#define SetValue() stringstream ss ;\
                 ss << value; \
                 setValue(key, ss)

#define GetValue() auto it = m_data.find(key); \
        return it != m_data.end() ? stoi(it->second) :-1;

DEFINE_SINGLE_ATTRIBUTES(GameDynamicData);

GameDynamicData::GameDynamicData()
{
	init();
}

GameDynamicData::~GameDynamicData()
{
	writeDateToFile();
}

void  GameDynamicData::setFloatByKey(const std::string& key, const float& value)
{
	SetValue();
}

void  GameDynamicData::setIntByKey(const std::string& key, const int& value)
{
	SetValue();
}

void GameDynamicData::setStringByKey(const std::string& key, const std::string& value)
{
	m_data[key] = value;
}

void  GameDynamicData::setValue(const std::string& key, stringstream& ss)
{
	string value;
	ss >> value;
	m_data[key] = value;
}

int GameDynamicData::getIntByKey(const std::string& key)
{
	GetValue();
}

float GameDynamicData::getFloatByKey(const std::string& key)
{
	GetValue();
}

std::string  GameDynamicData::getStringByKey(const std::string& key)
{
	auto it = m_data.find(key);
	return it != m_data.end() ? it->second : "";
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
		m_data[key] = value;
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
	
	for (auto it = m_data.begin(); it != m_data.end(); ++it)
	{
		fout << it->first<<" ";
		fout << it->second << endl;
	}
	fout.close();
}