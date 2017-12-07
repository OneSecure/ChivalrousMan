#include"MapInfo.h"
#include"Commen.h"
#include"GameMapLayer.h"
#include<fstream>
#include<string>
#include<regex>
using namespace std;

MapInfo* MapInfo::m_instance = nullptr;

MapInfo::MapInfo()
{

}

MapInfo::~MapInfo()
{
	releaseMapInfo();
}

MapInfo* MapInfo::getMapInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new MapInfo;
	}
	return m_instance;
}

void MapInfo::release()
{
	RELEASE_NULL(m_instance);
}

bool MapInfo::readMapInfoFromFile(const std::string& filename)
{
	ifstream fin;
	fin.open(filename, ios::in);
	if (fin.fail())
	{
		return false;
	}
	releaseMapInfo();
	fin >> m_countx;
	fin >> m_county;
	fin >> m_mapSize.width;
	fin >> m_mapSize.height;
	fin >> m_maptextures;
	m_mapinfo = new int*[m_county];
	string row;
	for (int i = 0; i < m_county; ++i)
	{
		m_mapinfo[i] = new int[m_countx];
	}
	
	for (int i = 0; i < m_county; ++i)
	{
		fin >> row;
		regex r4(("\\s*[,]\\s*"));
		const sregex_token_iterator send;
		int j = 0;
		for (sregex_token_iterator iter(row.cbegin(), row.cend(), r4, -1); iter != send; ++iter)
		{
			m_mapinfo[i][j] = stoi(*iter);
			++j;
		}
	}
	fin.close();
	return true;
}

void MapInfo::releaseMapInfo()
{
	if (m_mapinfo != nullptr)
	{
		for (int i = 0; i < m_county; ++i)
		{
			delete[] m_mapinfo[i];
		}
		delete[] m_mapinfo;
		m_mapinfo = nullptr;
	}
}

void MapInfo::setMapLayer(GameMapLayer* maplayer)
{
	m_mapLayer = maplayer;
}