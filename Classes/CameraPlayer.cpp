#include"CameraPlayer.h"
#include"MapInfo.h"
#include"GameMapLayer.h"
#include"Commen.h"
#include"PlayerState.h"
#include"PlayerWait.h"
#include"PlayerRun.h"
#include"GameDynamicData.h"
#include"HurtValueLayer.h"
#include"GameData.h"
#include"Model.h"
#include"DBDao.h"
#include"CameraPlayer.h"
#include"BackPackManager.h"
#include"SkillManager.h"
#include"EquipmentManager.h"
#include<map>

CameraPlayer* CameraPlayer::m_instance = nullptr;

CameraPlayer::CameraPlayer()
{
}

CameraPlayer::~CameraPlayer()
{
	SaveGameData();
}

CameraPlayer* CameraPlayer::getPlayerInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new CameraPlayer;
	}
	return m_instance;
}

void CameraPlayer::setFace(cocos2d::Sprite* face)
{
	m_face = face;
	m_face->setAnchorPoint(ccp(0.5, 0.1));
}

bool CameraPlayer::trunDir(const float& angle)
{
	if (Animal::trunDir(angle))
	{
		m_state->changeAnimation(m_dir);
		return true;
	}
	return false;
}

std::pair<Vec2,Vec2> CameraPlayer::changeMapPosToUI()
{
	Size sizeUI = SCREEN;
	Size sizeMap{ MapWidth,MapHeight };
	std::pair<Vec2, Vec2> pos;
	pos.first.x = sizeUI.width*0.5f;
	pos.first.y = sizeUI.height*0.5f;
	pos.second.x = m_pos.x - sizeUI.width*0.5f;
	pos.second.y = m_pos.y - sizeUI.height*0.5f;
	if (m_pos.x <= sizeUI.width*0.5)
	{
		pos.first.x = m_pos.x;
		pos.second.x = 0;
	}
	else if (m_pos.x >= sizeMap.width - sizeUI.width*0.5)
	{
		pos.first.x = sizeUI.width - sizeMap.width + m_pos.x;
		pos.second.x = sizeMap.width - sizeUI.width;
	}

	if (m_pos.y <= sizeUI.height*0.5)
	{
		pos.first.y = m_pos.y;
		pos.second.y = 0;
	}
	else if (m_pos.y >= sizeMap.height - sizeUI.height*0.5)
	{
		pos.first.y = sizeUI.height - sizeMap.height + m_pos.y;
		pos.second.y = sizeMap.height - sizeUI.height;
	}

	return pos;
}

bool CameraPlayer::move()
{
	if (Animal::move())
	{
		std::pair<Vec2, Vec2> pos = changeMapPosToUI();
		m_face->setPosition(pos.first);
		MapLayer->drawMap(pos.second.x, pos.second.y);
		return true;
	}
	return false;
}

void CameraPlayer::goNext()
{
	Vec2 pos = m_roadList.top();
	int w = MapGridW;
	int h = MapGridH;
	pos.x *= w;
	pos.y *= h;
	pos.x += w*0.5;
	pos.y += h*0.5;
	if (abs(pos.x - m_pos.x) < w*0.5&&abs(pos.y - m_pos.y) < h*0.5)
	{
		m_roadList.pop();
	}
	float angle = CalcAngle(m_pos, pos);
	trunDir(angle);
}

bool CameraPlayer::canMove()
{
	if (!m_roadList.empty())
	{
		goNext();
		if (!m_flag)
			m_state = m_state->goNextState();
		m_flag = 1;
		return true;
	}
	if (m_flag)
		m_state = m_state->goNextState();
	m_flag = 0;
	return false;
}

void CameraPlayer::release()
{
	RELEASE_NULL(m_instance);
}

void CameraPlayer::setMoveRoad(std::stack<cocos2d::Vec2>& road)
{
	m_roadList = road;
}

float  CameraPlayer::CalcAngle(cocos2d::Vec2 start, cocos2d::Vec2 target)
{
	if (start.x == target.x)
	{
		return start.y < target.y ? 0 : PI;
	}
	if (start.y == target.y)
	{
		return start.x < target.x ? PI : PI*1.5;
	}
	float dx = target.x - start.x;
	float dy = target.y - start.y;
	float angle = atanf(abs(dx / dy));
	if (start.x < target.x&&start.y < target.y)
	{
		return angle;
	}
	else if (start.x<target.x&&start.y>target.y)
	{
		return PI - angle;
	}
	else if (start.x > target.x&&start.y > target.y)
	{
		return PI + angle;
	}
	else
	{
		return 2 * PI - angle;
	}
}

void CameraPlayer::initStateInfo(const int& level)
{
	float x = GetFloatData("DestX");
	float y = GetFloatData("DestY");
	if (x == -1 || y == -1)
	{
		m_pos.x = 100;
		m_pos.y = 100;
	}
	else
	{
		if (GetIntData("IsDoor") == 1)
		{
			m_pos.x = x - 40;
			m_pos.y = y - 40;
			SetIntData("IsDoor", 0);
		}
		else
		{
			m_pos.x = x;
			m_pos.y = y;
		}
	}
	clearRoadList();
	m_flag = 0;
	RELEASE_NULL(m_state);
	m_state = new PlayerWait(m_face, GetStringData("PlayerType"));
	AdjustPlayerAndMapPos();
}

void CameraPlayer::clearRoadList()
{
	while (!m_roadList.empty())
	{
		m_roadList.pop();
	}
}

void CameraPlayer::AdjustPlayerAndMapPos()
{
	std::pair<Vec2, Vec2> pos = changeMapPosToUI();
	m_face->setPosition(pos.first);
	MapLayer->drawMap(pos.second.x, pos.second.y);
}

void CameraPlayer::beAttack(float attack)
{
	auto move1 = MoveBy::create(0.2, ccp(35, 0));
	auto move2 = MoveBy::create(0.2, ccp(-35, 0));
	m_face->runAction(Sequence::createWithTwoActions(move1, move2));
	float hurtvalue = attack <= m_playerData.getdefense() ? 1 : attack - m_playerData.getdefense();
	Vec2 pos = m_face->getPosition();
	pos.y += 90;
	auto hurtlayer = HurtsValueLayer::createWithInfo(pos, hurtvalue);
	m_face->getParent()->addChild(hurtlayer);
	m_playerData.setcurblood(m_playerData.getcurblood() - hurtvalue);
	if (m_playerData.getcurblood() <= 0)
	{
		m_face->getParent()->removeChild(m_face);
	}
}

void CameraPlayer::SaveGameData()
{
	PlayerInfo playerinfo;
	DBDao<PlayerInfo> dbdao;
	playerinfo.setattack(NumberToString(m_playerData.getattack()));
	playerinfo.setblood(NumberToString(m_playerData.getblood()));
	playerinfo.setdefense(NumberToString(m_playerData.getdefense()));
	playerinfo.setdestx(NumberToString(m_pos.x));
	playerinfo.setdesty(NumberToString(m_pos.y));
	playerinfo.setexp(NumberToString(m_playerData.getexp()));
	playerinfo.setglod(NumberToString(m_playerData.getglod()));
	playerinfo.setgrade(NumberToString(m_playerData.getgrade()));
	playerinfo.setmana(NumberToString(m_playerData.getmana()));
	playerinfo.setmaxExp(NumberToString(m_playerData.getmaxExp()));
	playerinfo.setlevel(NTS(GetIntData("CurMap")));
	dbdao.setModel(playerinfo);
	std::map<std::string, std::string> keyvls;
	keyvls["playername"] = GetStringData("playername");
	keyvls["rolename"] = GetStringData("rolename");
	dbdao.updateModel(keyvls);
	BackPackManager::getInstance()->saveBackpackInfo();
	EquipmentManager::getInstance()->saveEquipmentInfo();
	SkillManager::getInstance()->saveSkillInfo();
}