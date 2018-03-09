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
	*SendMoveToMsg(const cocos2d::Vec2& pos);
	*发送移动至目标位置消息
	*@param pos:目标位置
	*/
	void SendMoveToMsg(const cocos2d::Vec2& pos);

	/*
	*处理玩家初始化位置信息消息
	*/
	void doInitPlayerPosMsg(InitPos_Msg* msg);

	/*
	*发送玩家离线消息
	*/
	void SendPlayerLeaveMsg();

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

	/*
	*updatePlayerMap();
	*更新玩家当前所在地图
	*/
	void updatePlayerMap();

	/*
	* doUpdatePlayerMapMsg();
	*处理更新玩家地图消息
	*/
	void doUpdatePlayerMapMsg(UpdateMap_Msg* msg);

	const std::list<Player_Info>& getPlayerList() { return m_playerlist; }

	/*
	*findRoleNameByFd(const int& fd);
	*通过玩家的唯一标识查找其名称
	*@param fd:玩家的唯一标识
	*@return string:玩家的名称·
	*/
	std::string findRoleNameByFd(const int& fd);

	/*
	*添加世界聊天消息
	*/
	void addWorldTalkMsg(WorldTalk_Msg* msg);

	/*
	*添加私聊消息
	*/
	void addPrivateTalkMsg(PrivateTalk_Msg* msg);
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

	std::list<Player_Info> m_playerlist;
	std::deque<TalkMsg> m_worldTalkMsgs;
	std::map<int, std::deque<TalkMsg>> m_privateTalkMsgs;
};

#endif // !__CM_CLIENT_H__