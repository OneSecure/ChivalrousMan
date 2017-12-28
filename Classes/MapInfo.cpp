#include"MapInfo.h"
#include"Commen.h"
#include"Door.h"
#include"GameMapLayer.h"
#include"GameData.h"
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
	reset();
	string row;
	fin >> row;
	fin >> m_countx;
	fin >> m_county;
	fin >> m_mapSize.width;
	fin >> m_mapSize.height;
	fin >> m_maptextures;
	m_mapinfo = new int*[m_county];
	for (int i = 0; i < m_county; ++i)
	{
		m_mapinfo[i] = new int[m_countx];
	}
	regex r4(("\\s*[,]\\s*"));
	for (int i = m_county-1; i>=0; --i)
	{
		fin >> row;
		const sregex_token_iterator send;
		int j = 0;
		for (sregex_token_iterator iter(row.cbegin(), row.cend(), r4, -1); iter != send; ++iter)
		{
			m_mapinfo[i][j] = stoi(*iter);
			if (m_mapinfo[i][j] == -100)
			{
				Door pos;
				pos.x = j*getMapGridW() + getMapGridW()*0.5;
				pos.y = i*getMapGridH() + getMapGridH()*0.5;
				m_doorPos.push_back(pos);
			}
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

void MapInfo::updateDoorsScreenPos()
{
	if (m_mapLayer != nullptr)
	{
		m_mapLayer->updateDoorScreenPos();
	}
}

void MapInfo::loadDoorInfo(const std::string& name)
{
	ifstream fin;
	fin.open(StringValue("DoorInfo"), ios::in);
	if (fin.fail())
	{
		return;
	}
	string cur, map;
	int n;
	float x, y;
	fin >> cur;
	do
	{
		fin >> cur;
		fin >> n;
		for (int i = 0; i < n; ++i)
		{
			fin >> map;
			fin >> x;
			fin >> y;
			if (cur == name) 
			{
				m_doorPos[i].dest = map;
				m_doorPos[i].destPos.x = x*getMapGridW() + getMapGridW()*0.5;
				m_doorPos[i].destPos.y = y*getMapGridH() + getMapGridH()*0.5;
			}
		}
	} while (!fin.eof());
	fin.close();
}

void MapInfo::reset()
{
	m_doorPos.clear();
	releaseMapInfo();
}