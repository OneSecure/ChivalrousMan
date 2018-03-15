#include"PlayerData.h"
#include"Commen.h"
#include"CMClient.h"
#include"GameDynamicData.h"
#include"GameData.h"

PlayerData::PlayerData()
{

}

PlayerData::~PlayerData()
{

}

void PlayerData::addGlod(const float& vl)
{
	m_glod += vl;
}

void PlayerData::addExp(const float& vl)
{
	m_exp += vl;
	float overexp = m_exp > m_maxExp ? m_exp - m_maxExp : 0;
	if (overexp > 0)
	{
		upGrade();
		addExp(overexp);
	}
}

float PlayerData::subGlod(const float& vl)
{
	return m_glod > vl ? m_glod -= vl : -1;
}

void PlayerData::addcurBlood(const float& vl)
{
	m_curblood = m_curblood + vl > m_blood ? m_blood : m_curblood + vl;
}

void PlayerData::subcurBlood(const float& vl)
{
	m_curblood -= vl;
}

void PlayerData::addcurMana(const float& vl)
{
	m_curmana = m_curmana + vl > m_mana ? m_mana : m_curmana + vl;
}

void PlayerData::subcurMana(const float& vl)
{
	m_curmana -= vl;
}

void PlayerData::upGrade()
{
	m_exp = 0;
	++m_grade;
	m_maxExp += m_grade * 100;
	SetIntData("IsHaveTip", 1);
	SetStringData("TipText", StringValue("UpgradeText") + NTS(m_grade));
	addProperty(30, 30, 5, 5);
}

void PlayerData::addProperty(float blood, float mana, float attack, float defense)
{
	m_blood += blood;
	m_mana += mana;
	m_attack += attack;
	m_defense += defense;
	CMClient::getInstance()->updatePlayerData();
}