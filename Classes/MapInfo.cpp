#include"MapInfo.h"
#include"Commen.h"

MapInfo* MapInfo::m_instance = nullptr;

MapInfo::MapInfo()
{

}

MapInfo::~MapInfo()
{

}

MapInfo* MapInfo::getMapInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new MapInfo;
	}
	return m_instance;
}

void MapInfo::setFace(cocos2d::Sprite* face)
{
	m_face = face;
	m_mapSize = m_face->getContentSize();
}

cocos2d::Sprite* MapInfo::getFace()
{
	return m_face;
}

const cocos2d::Size& MapInfo::getMapSize()
{
	return m_mapSize;
}