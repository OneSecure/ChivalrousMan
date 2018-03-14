#pragma once
#ifndef __CM_CLIENT_H__
#define __CM_CLIENT_H__
#include"PreProcess.h"
#include"TCPClient.h"
#include"ShareData.h"
#include<deque>
#include<list>
#include<map>

struct TalkMsg
{
	std::string rolename;    //˭���͵�
	std::string destname;   //����˭
	std::string msg;             //��Ϣ����
	bool change = false;
};

class CMClient Inherit(Net::CTCPClient)
{
	GET_SINGLE_OBJECT(CMClient)
public:
	/*
	*���շ�������������Ϣ
	*/
	virtual void  OnRecv(char* buff) override;
	
	static void release();

	/*
	*���ӷ�������
	*/
	int Connect();

	/*
	*SendInitData();
	*���������ҽ�ɫ������Ϣ��
	*/
	void SendInitPlayerData();

	/*
	*SendInitPos();
	*����������ͳ�ʼ��λ����Ϣ
	*/
	void SendInitPos();

	/*
	*�����ʼ����Ϣ
	*/
	void doInitMsg(InitData_Msg* msg);
	
	/*
	*SendMoveToMsg(const cocos2d::Vec2& pos);
	*�����ƶ���Ŀ��λ����Ϣ
	*@param pos:Ŀ��λ��
	*/
	void SendMoveToMsg(const cocos2d::Vec2& pos, int less = 0);

	/*
	*������ҳ�ʼ��λ����Ϣ��Ϣ
	*/
	void doInitPlayerPosMsg(InitPos_Msg* msg);

	/*
	*�������������Ϣ
	*/
	void SendPlayerLeaveMsg();

	/*
	*�������������Ϣ
	*/
	void doPlayerLeaveMsg(PlayerLeave_Msg* msg);

	/*
	*ɾ�����
	*@param fd:���Ψһ��ʶ
	*/
	void removePlayer(int fd);

	/*
	*doPlayerMoveToMsg();
	*��������ƶ���Ϣ
	*/
	void doPlayerMoveToMsg(MoveTo_Msg* msg);

	/*
	*doPlayerPosVerifyMsg();
	*�������λ��У����Ϣ
	*@param msg��У����Ϣ
	*/
	void doPlayerPosVerifyMsg(VerifyPos_Msg* msg);

	/*
	*VerifyPlayerPos();
	*��������������λ��У����Ϣ
	*/
	void VerifyPlayerPos();

	/*
	*updatePlayerData();
	*������������������
	*/
	void updatePlayerData();

	/*
	*����������ݸ�����Ϣ
	*doPlayerDataUpdaeMsg();
	*/
	void doPlayerDataUpdaeMsg(UpdateData_Msg* msg);

	std::list<Player_Info>& getPlayerList() { return m_playerlist; }

	/*
	*findRoleNameByFd(const int& fd);
	*ͨ����ҵ�Ψһ��ʶ����������
	*@param fd:��ҵ�Ψһ��ʶ
	*@return string:��ҵ����ơ�
	*/
	std::string findRoleNameByFd(const int& fd);

	/*
	*findPlayerInfoByFd(const int& fd);
	*ͨ�����Ψһ��ʶ���������Ϣ
	*@param fd:���Ψһ��ʶ
	*@return Player_Info�������Ϣ
	*/
	Player_Info findPlayerInfoByFd(const int& fd);

	/*
	*�������������Ϣ
	*/
	void addWorldTalkMsg(WorldTalk_Msg* msg);

	/*
	*���˽����Ϣ
	*/
	void addPrivateTalkMsg(PrivateTalk_Msg* msg);

	/*
	*�������������Ϣ
	*/
	void doTeamApplyMsg(TeamApply_Msg* msg);

	std::map<int, std::deque<TalkMsg>>& getPrivateMsgs() { return m_privateTalkMsgs; }

	std::list<int>& getApplyTeamList() { return m_applyTeamList; }

	/*
	*doRefuseTeamMsg(RefuseTeam_Msg* msg);
	*����ܾ������Ϣ
	*@param msg���ܾ���Ϣ����
	*/
	void doRefuseTeamMsg(RefuseTeam_Msg* msg);

	/*
	*����ͬ�������Ϣ
	*@param msg��ͬ����Ϣ����
	*/
	void doAgreeTeamMsg(AgreeTeam_Msg* msg);

	/*
	*���Ͷ����ƶ���Ϣ
	*@param target���ƶ�����Ŀ�ĵ�
	*@param dest�����͸���Ŀ��
	*/
	void sendTeamMoveMsg(cocos2d::Vec2 target, int dest);

	/*
	*��������ƶ���Ϣ
	*/
	void doTeamMoveMsg(TeamMove_Msg* msg);

	/*
	*���Ͷ�������ͼ��Ϣ
	*@param map������ĵ�ͼ��
	*@param target ��Ŀ������
	*@param dest�����͸�˭
	*/
	void sendTeamGotoMapMsg(std::string map, cocos2d::Vec2 target, int dest);

	/*
	*����������ĳ��ͼ��Ϣ
	*/
	void doTeamGotoMapMsg(TeamGotoMap_Msg* msg);

	/*
	*SendTeamDissolveMsg(int dest)
	*@param dest�����͸�˭
	*/
	void SendTeamDissolveMsg(int dest);

	/*
	*��������ɢ��Ϣ
	*/
	void doTeamDissolveMsg();

	/*
	*sendTeamFightMsg(int dest, std::string name, int nums);
	*���Ͷ������ս����Ϣ
	*@param dest:������Ϣ��˭
	*@param name:����ս���Ĺ�������
	*@param nums:��������
	*/
	void sendTeamFightMsg(int dest, std::string name, int nums);

	/*
	*����������ս����Ϣ
	*/
	void doTeamFightMsg(TeamFight_Msg* msg);

	/*
	*������ҽ�����Ϣ
	*@param skill:�Ƿ�ʹ�ü���
	*@param dest:���͸�˭
	*@param towho������˭
	*/
	void sendPlayerAtkMsg(std::string skill,int grade, int dest, int towho);

	/*
	*���͹��������Ϣ
	*@param dest�����͸�˭
	*@param who:˭����
	*@param towho:����˭
	*/
	void sendMonsterAtkMsg(int dest, int who, int towho);

	/*
	*������ҽ�����Ϣ
	*/
	void doPlayerAtkMsg(PlayerAtk_Msg* msg);

	/*
	*������������Ϣ
	*/
	void doMonsterAtkMsg(MonsterAtk_Msg* msg);

	std::list<TeamGotoMap_Msg>& getGotoMapMsgs() { return m_gotoMapMsgs; }
private:
	CMClient();
	~CMClient();

	/*
	* readConfConnectServer();
	*��ȡ���������ò�����
	*/
	void readConfConnectServer();

	SINGLE_ATTRIBUTES(CMClient);

	std::string m_serverip;
	unsigned long m_port;

	std::list<Player_Info> m_playerlist;            //��������б�
	std::list<int> m_applyTeamList;          //���������б�
	std::deque<TalkMsg> m_worldTalkMsgs;    //����������Ϣ
	std::map<int, std::deque<TalkMsg>> m_privateTalkMsgs;    //˽����Ϣ
	std::list<TeamGotoMap_Msg> m_gotoMapMsgs;            //����ǰ��ĳ��ͼ��Ϣ
};

#endif // !__CM_CLIENT_H__