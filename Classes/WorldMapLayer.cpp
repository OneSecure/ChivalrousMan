#include"WorldMapLayer.h"
#include"GameData.h"
#include"Commen.h"
#include"GameDynamicData.h"
#include<fstream>

bool WorldMapLayer::init()
{
	if (Layer::init())
	{
		auto size = SCREEN;
		auto bg = Sprite::create(StringValue("WorldMap"), Rect{ 40,20,800,600});
		bg->setPosition(size.width*0.5, size.height*0.5);
		this->addChild(bg);
		Vec2 basePos = bg->getPosition();
		basePos.x -= bg->getContentSize().width*0.5;
		basePos.y -= bg->getContentSize().height*0.5;
		
		initMapInfo();
		for (auto var : m_maps)
		{
			LabelTTF* namelabel = LabelTTF::create(var.second.name, "¿¬Ìå", 30);
			namelabel->setColor(Color3B::RED);
			namelabel->setPosition(basePos.x + var.second.pos.x, basePos.y + var.second.pos.y);
			this->addChild(namelabel);
		}
		Sprite* spot = Sprite::create(StringValue("RedSpot"));
		std::string key = "map" + NumberToString(GetIntData("CurMap"));
		spot->setPosition(basePos.x + m_maps[key].pos.x, basePos.y + m_maps[key].pos.y-30);
		this->addChild(spot);
		return true;
	}
	return false;
}

void  WorldMapLayer::initMapInfo()
{
	std::ifstream fin;
	fin.open("mapinfo.xxp", std::ios::in);
	if (fin.fail())
	{
		return;
	}
	std::string key;
	stMap stmap;
	while (!fin.eof())
	{
		fin >> key;
		fin >> stmap.pos.x;
		fin >> stmap.pos.y;
		fin >> stmap.name;
		m_maps[key] = stmap;
	}
	fin.close();
}