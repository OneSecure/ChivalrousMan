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
	std::string rolename;    //谁发送的
	std::string destname;   //发给谁
	std::string msg;             //消息内容
	bool change = false;
};

class CMClient Inherit(Net::CTCPClient)
{
	GET_SINGLE_OBJECT(CMClient)
public:
	/*
	*接收服务器发来的消息
	*/
	virtual void  OnRecv(char* buff) override;
	
	static void release();

	/*
	*连接服务器·
	*/
	int Connect();

	/*
	*SendInitData();
	*向服务器玩家角色数据消息·
	*/
	void SendInitPlayerData();

	/*
	*SendInitPos();
	*向服务器发送初始化位置信息
	*/
	void SendInitPos();

	/*
	*处理初始化消息
	*/
	void doInitMsg(InitData_Msg* msg);
	
	/*
	*SendMoveToMsg(const cocos2d::Vec2& pos);
	*发送移动至目标位置消息
	*@param pos:目标位置
	*/
	void SendMoveToMsg(const cocos2d::Vec2& pos, int less = 0);

	/*
	*处理玩家初始化位置信息消息
	*/
	void doInitPlayerPosMsg(InitPos_Msg* msg);

	/*
	*发送玩家离线消息
	*/
	void SendPlayerLeaveMsg();

	/*
	*处理玩家离线消息
	*/
	void doPlayerLeaveMsg(PlayerLeave_Msg* msg);

	/*
	*删除玩家
	*@param fd:玩家唯一标识
	*/
	void removePlayer(int fd);

	/*
	*doPlayerMoveToMsg();
	*处理玩家移动消息
	*/
	void doPlayerMoveToMsg(MoveTo_Msg* msg);

	/*
	*doPlayerPosVerifyMsg();
	*处理玩家位置校验消息
	*@param msg：校验消息
	*/
	void doPlayerPosVerifyMsg(VerifyPos_Msg* msg);

	/*
	*VerifyPlayerPos();
	*向服务器发送玩家位置校验消息
	*/
	void VerifyPlayerPos();

	/*
	*updatePlayerData();
	*向服务器更新玩家数据
	*/
	void updatePlayerData();

	/*
	*处理玩家数据更新消息
	*doPlayerDataUpdaeMsg();
	*/
	void doPlayerDataUpdaeMsg(UpdateData_Msg* msg);

	std::list<Player_Info>& getPlayerList() { return m_playerlist; }

	/*
	*findRoleNameByFd(const int& fd);
	*通过玩家的唯一标识查找其名称
	*@param fd:玩家的唯一标识
	*@return string:玩家的名称·
	*/
	std::string findRoleNameByFd(const int& fd);

	/*
	*findPlayerInfoByFd(const int& fd);
	*通过玩家唯一标识查找玩家信息
	*@param fd:玩家唯一标识
	*@return Player_Info：玩家信息
	*/
	Player_Info findPlayerInfoByFd(const int& fd);

	/*
	*添加世界聊天消息
	*/
	void addWorldTalkMsg(WorldTalk_Msg* msg);

	/*
	*添加私聊消息
	*/
	void addPrivateTalkMsg(PrivateTalk_Msg* msg);

	/*
	*处理队伍申请消息
	*/
	void doTeamApplyMsg(TeamApply_Msg* msg);

	std::map<int, std::deque<TalkMsg>>& getPrivateMsgs() { return m_privateTalkMsgs; }

	std::list<int>& getApplyTeamList() { return m_applyTeamList; }

	/*
	*doRefuseTeamMsg(RefuseTeam_Msg* msg);
	*处理拒绝组队消息
	*@param msg：拒绝消息内容
	*/
	void doRefuseTeamMsg(RefuseTeam_Msg* msg);

	/*
	*处理同意组队消息
	*@param msg：同意消息内容
	*/
	void doAgreeTeamMsg(AgreeTeam_Msg* msg);

	/*
	*发送队伍移动消息
	*@param target：移动到的目的地
	*@param dest：发送给的目标
	*/
	void sendTeamMoveMsg(cocos2d::Vec2 target, int dest);

	/*
	*处理队伍移动消息
	*/
	void doTeamMoveMsg(TeamMove_Msg* msg);

	/*
	*发送队伍进入地图消息
	*@param map：进入的地图名
	*@param target ：目的坐标
	*@param dest：发送给谁
	*/
	void sendTeamGotoMapMsg(std::string map, cocos2d::Vec2 target, int dest);

	/*
	*处理队伍进入某地图消息
	*/
	void doTeamGotoMapMsg(TeamGotoMap_Msg* msg);

	/*
	*SendTeamDissolveMsg(int dest)
	*@param dest：发送给谁
	*/
	void SendTeamDissolveMsg(int dest);

	/*
	*处理队伍解散消息
	*/
	void doTeamDissolveMsg();

	/*
	*sendTeamFightMsg(int dest, std::string name, int nums);
	*发送队伍进入战斗消息
	*@param dest:发送消息给谁
	*@param name:进入战斗的怪物名字
	*@param nums:怪物数量
	*/
	void sendTeamFightMsg(int dest, std::string name, int nums);

	/*
	*处理队伍进入战斗消息
	*/
	void doTeamFightMsg(TeamFight_Msg* msg);

	/*
	*发送玩家进攻消息
	*@param skill:是否使用技能
	*@param dest:发送给谁
	*@param towho：进攻谁
	*/
	void sendPlayerAtkMsg(std::string skill,int grade, int dest, int towho);

	/*
	*发送怪物进攻消息
	*@param dest：发送给谁
	*@param who:谁进攻
	*@param towho:进攻谁
	*/
	void sendMonsterAtkMsg(int dest, int who, int towho);

	/*
	*处理玩家进攻消息
	*/
	void doPlayerAtkMsg(PlayerAtk_Msg* msg);

	/*
	*处理怪物进攻消息
	*/
	void doMonsterAtkMsg(MonsterAtk_Msg* msg);

	std::list<TeamGotoMap_Msg>& getGotoMapMsgs() { return m_gotoMapMsgs; }
private:
	CMClient();
	~CMClient();

	/*
	* readConfConnectServer();
	*读取服务器配置并连接
	*/
	void readConfConnectServer();

	SINGLE_ATTRIBUTES(CMClient);

	std::string m_serverip;
	unsigned long m_port;

	std::list<Player_Info> m_playerlist;            //其他玩家列表
	std::list<int> m_applyTeamList;          //队伍申请列表
	std::deque<TalkMsg> m_worldTalkMsgs;    //世界聊天消息
	std::map<int, std::deque<TalkMsg>> m_privateTalkMsgs;    //私聊消息
	std::list<TeamGotoMap_Msg> m_gotoMapMsgs;            //保存前往某地图消息
};

#endif // !__CM_CLIENT_H__