#include"Player.h"
#include"Commen.h"
#include"GameData.h"
#include"PlayerState.h"
#include"PlayerWait.h"
#include"PlayerRun.h"
#include"MapInfo.h"
#include"CameraPlayer.h"
#include"FindRoad.h"

XGamePlayer* XGamePlayer::create(const Player_Info& pinfo)
{
	XGamePlayer* pRet = new XGamePlayer;
	if (pRet&&pRet->init(pinfo))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

bool XGamePlayer::init(const Player_Info& pinfo)
{
	if (Node::init())
	{
		InitData(pinfo);
		char name[40] = { 0 };
		sprintf_s(name, "%sWaitDown", m_playerType.c_str());
		m_face = Sprite::create(StringValue(name));
		m_face->setPosition(0, 0);
		m_face->setAnchorPoint(ccp(0.5, 0.1));
		this->addChild(m_face);
		m_state = new PlayerWait(m_face, m_playerType);

		m_namelabel = LabelTTF::create(m_roleName, "¿¬Ìå", 20);
		m_namelabel->setPosition(0, 120);
		this->addChild(m_namelabel);
		
		scheduleUpdate();
		return true;
	}
	return false;
}

void XGamePlayer::InitData(const Player_Info& pinfo)
{
	m_vx = 0;
	m_vy = 0;
	m_v = FloatValue("PlayerSpeed");
	m_dir = Dir::Dir_Down;
	m_attack = pinfo.attack;
	m_blood = pinfo.blood;
	m_defense = pinfo.defense;
	m_mana = pinfo.mana;
	m_playerName = pinfo.playername;
	m_roleName = pinfo.rolename;
	m_playerType = pinfo.playertype;
	m_worldPos.x = pinfo.x;
	m_worldPos.y = pinfo.y;
	m_flag = 0;
}

bool XGamePlayer::move()
{
	if (m_vx == 0 && m_vy == 0)
	{
		return false;
	}
	m_worldPos.x += m_vx;
	m_worldPos.y += m_vy;
	return true;
}

void XGamePlayer::setVelocity(const float& v)
{
	m_v = v;
}

bool XGamePlayer::trunDir(const float& angle)
{
	bool bRet = false;
	if (m_vx == 0 && m_vy == 0)
	{
		bRet = true;
	}
	m_vx = m_v*sinf(angle);
	m_vy = m_v*cosf(angle);
	Dir newDir = abs(m_vx) > abs(m_vy) ? (m_vx > 0 ?
		Dir::Dir_Right : Dir::Dir_Left) :
		(m_vy > 0 ? Dir::Dir_Up : Dir::Dir_Down);
	if (!bRet)
		bRet = (m_dir != newDir);
	if (bRet)
		m_state->changeAnimation(newDir);
	m_dir = newDir;
	return bRet; 
}

const Dir& XGamePlayer::getDir()
{
	return m_dir;
}

bool XGamePlayer::canMove()
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

void XGamePlayer::clearRoadList()
{
	while (!m_roadList.empty())
	{
		m_roadList.pop();
	}
}

void XGamePlayer::goNext()
{
	Vec2 pos = m_roadList.top();
	int w = MapGridW;
	int h = MapGridH;
	pos.x *= w;
	pos.y *= h;
	pos.x += w*0.5;
	pos.y += h*0.5;
	if (abs(pos.x - m_worldPos.x) < w*0.5&&abs(pos.y - m_worldPos.y) < h*0.5)
	{
		m_roadList.pop();
	}
	float angle = CameraPlayer::getPlayerInstance()->CalcAngle(m_worldPos, pos);
	trunDir(angle);
}

void XGamePlayer::setMoveRoad(std::stack<cocos2d::Vec2>& road)
{
	m_roadList = road;
}

void XGamePlayer::update(float dt)
{
	if (canMove())
	{
		move();
	}
}

bool XGamePlayer::moveTo(cocos2d::Vec2 targetPos,int less)
{
	m_vx = 0;
	m_vy = 0;
	int h = MapGridH;
	int w = MapGridW;
	targetPos.x /= w;
	targetPos.y /= h;
	FOUR_LOSE_FIVE_ADD(targetPos.x);
	FOUR_LOSE_FIVE_ADD(targetPos.y);
	Vec2 start{ m_worldPos.x / w,m_worldPos.y / h };
	FindRoad froad{ start, targetPos, GetMapInfo(), MapCountX, MapCountY };
	froad.lessOne(less);
	froad.ExecuteAStar();
	if (froad.isHasRoad())
	{
		this->setMoveRoad(froad.GetRoadList());
		return true;
	}
	return false;
}