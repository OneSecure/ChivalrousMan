#pragma once
#ifndef  __FIGHT_LAYER_H__
#define __FIGHT_LAYER_H__
#include"PreProcess.h"
#include<string>
#include<vector>

class Monster;
class Medication;
class Skill;
class XGamePlayer;

/*
*class FightLayer
*ս����
*/
class FightLayer Inherit(cocos2d::Layer)
{
public:
	friend class Skill;
	friend class CrackIt;
	friend class Dante;
	friend class DragonRoar;
	friend class LightStrike;
	friend class Long;
	friend class RecallCounterMand;
	friend class SealOfTheBlade;
	friend class XBArrow;
	FightLayer();
	~FightLayer();

	/*
	*���ݹ������ƴ���ս������
	*@param name������
	*@param nums:��������
	*/
	static cocos2d::Scene* createFightScene(const std::string& name, int nums = 1);

	bool init(const std::string& name, int nums);

	/*
	*�Ƴ�����
	*/
	void removeMonster(Monster* monster);

	/*
	*����Ƿ�ս���ɹ�
	*/
	bool checkSuccess();

	/*
	*������ҽ���
	*@param who��˭����
	*@param skill:�Ƿ�ʹ�ü��ܣ���Ϊ"null"��ʹ�ü��ܣ�����ʹ��
	*@param grade��ʹ�ü�����ô���ܵĵȼ�Ϊ����
	*@param towho������˭
	*/
	void otherPlayerAtk(int who, std::string skill, int grade, int towho);

	/*
	*֪ͨ������ҹ��﷢���˽������������ֻ�жӳ��Ż����
	*@param who��˭����
	*@param towho��������˭
	*/
	void notifyOtherPlayerMonsterAtk(int who, int towho);

	/*
	*monsterAttackPlayer();
	*���﹥�����
	*@param index��������ҵĹ���
	*@param dest����ǹ�����������
	*/
	void monsterAttackPlayer(int index, int who = -1);

	/*
	* findOtherPlayerIndexByFd(int fd);
	*ͨ�����Ψһ��ʶ�����������
	*/
	int findOtherPlayerIndexByFd(int fd);
private:
	/*
	*calcActionOrder();
	*�����ж�˳��
	*/
	void calcActionOrder();

	void update(float dt);

	/*
	*ѡ���Զ������ֶ�
	*/
	void onToggleAutoAndHand(cocos2d::CCObject* sender);

	/*
	*ҩƷ��ť����ص�����
	*/
	void onMedicationClickCallBack(cocos2d::CCObject* sender);

	/*
	*���ܰ�ť����ص�����
	*/
	void onSkillClickCallBack(cocos2d::CCObject* sender);

	/*
	*���ܰ�ť����ص�����
	*/
	void onRunClickCallBack(cocos2d::CCObject* sender);

	/*
	*��ͨ������ť����ص�����
	*/
	void onAttackClickCallBack(cocos2d::CCObject* sender);

	/*
	*ʹ��ҩƷ
	*/
	void onMedication(cocos2d::CCObject* sender);

	/*
	*ʹ�ü���
	*/
	void onSkill(cocos2d::CCObject* sender);
		
	/*
	*randomNumMonster();
	*������������Ĺ���
	*/
	void randomNumMonster(const std::string& name, int nums);

	/*
	*ѡ��������ص�����
	*/
	void onClickMonsterCallBack(cocos2d::CCObject* sender);
	
	/*
	*playerAttackMonster();
	*��ҶԹ��������ͨ����
	*/
	void playerAttackMonster();

	/*
	*��ʱ���ص�����
	*/
	void onTimer(float dt);

	/*
	* EndFight(std::string tip);
	*����ս��
	*@param tip������ս������ʾ��
	*/
	void EndFight(std::string tip);

	void endFunc(float dt);

	/*
	*checkMonsterBehavie()
	*��������Ϊ
	*/
	void checkMonsterBehavie();

	/*
	*checkFightEnd();
	*���ս���Ƿ����
	*/
	void checkFightEnd();
	
	/*
	*�������Ѫ����ħ��UI
	*/
	void updateBloodAndMana();

	/*
	*����ѡ����Ч�Ĺ���
	*/
	void reSelectMonster();

	/*
	*��ʼ������б�
	*/
	void initPlayer();
	
	std::string m_time = "10";   //�ж�ʱ��
	std::vector<Monster*> m_monsterList; 	//���������Ϣ����
	cocos2d::Sprite* m_player; 	//�����������
	cocos2d::Menu* m_menu;
	bool m_clickMedication = false;
	std::vector<Medication*> m_medications;    //����ҩƷ
	std::vector<cocos2d::LabelTTF*> m_medicationNums;    //��ʾ����
	bool m_clickskill = false;
	std::vector<Skill*> m_skills;
	bool m_clickAuto = false;
	cocos2d::Sprite* m_arrow;
	Monster* m_selectedMonster;   //��ǰѡ�еĹ���
	cocos2d::ProgressTimer* m_playerBlood;
	cocos2d::ProgressTimer* m_playerMana;
	cocos2d::LabelTTF* m_timeLabel;
	bool m_isPlayer = true;     //�Ƿ��ֵ���ҹ���
	bool m_isPlayerEnd = false;  //��ҽ����Ƿ����
	int m_curMonster = 0;     //��ǰ������ҵĹ�������
	bool m_lastMonsterEnd = true;   //��һ�������Ƿ񹥻�����
	float m_settlementGlod = 0;    //������
	float m_settlementExp = 0;      //���㾭��
	int m_mmor = 1;                      //��¼�غ���
	cocos2d::CCObject* m_selSkill = nullptr;     //ѡ�еļ���
	std::vector<XGamePlayer*> m_otherPlayers;    //�������
	bool m_otherplayerEnd = true;   //�����������Ƿ������Ϊ
};

#endif // ! __FIGHT_LAYER_HH_