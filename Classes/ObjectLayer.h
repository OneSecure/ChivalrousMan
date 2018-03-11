#pragma once
#ifndef __OBJECT_LAYER_H__
#define __OBJECT_LAYER_H__
#include"PreProcess.h"
#include"Npc.h"
#include"Monster.h"
#include<vector>
#include<string>

class XGamePlayer;
struct Player_Info;
struct UpdateData_Msg;

/*
*class ObjectLayer
*游戏对象层,用于绘制出玩家以外的其它游戏对象
*/
class ObjectLayer Inherit(cocos2d::Layer)
{
public:
	ObjectLayer();
	~ObjectLayer();

	/*
	*createWithLevel(const int& level);
	*根据地图创建对象层
	*@param level:地图类型
	*/
	static ObjectLayer* createWithLevel(const int& level);

	bool init(const int& level);

	void update(float dt);

	inline std::vector<Npc*>& getNpcList() { return m_npcList; }

	/*
	*addPlayer(const Player_Info& pinfo);
	*在对象层新添要显示的玩家
	*@param pinfo:玩家信息
	*/
	void addPlayer(Player_Info pinfo);

	/*
	*removePlayer(const std::string& playername, const std::string& rolename);
	*对象层移除玩家角色
	*@param playername:玩家名称
	*@param rolename:角色名称
	*/
	void removePlayer(const std::string& playername, const std::string& rolename);

	/*
	*moveOtherPlayer(const std::string& playername, const std::string& rolename, const cocos2d::Vec2& pos)
	*移动对象层的其它玩家
	*@param playername:玩家名称
	*@param rolenmae:角色名称
	*@param target：目标位置
	*/
	void moveOtherPlayer(const std::string& playername, const std::string& rolename, const cocos2d::Vec2& target, int less = 0);
	
	/*
	*verifyPlayerPos(const std::string& playername, const std::string& rolename, const cocos2d::Vec2& pos);
	*校验玩家位置
	*@param playername:玩家名称
	*@param rolename:角色名曾
	*@param pos:校准的位置
	*/
	void verifyPlayerPos(const std::string& playername, const std::string& rolename, const cocos2d::Vec2& pos);

	/*
	* updatePlayerData(const std::string& playername, const std::string& rolename, UpdateData_Msg msg);
	*更新玩家数据
	*@param playername:玩家名称
	*@param rolename:角色名称
	*@param msg:保存玩家新数据的消息
	*/
	void updatePlayerData(const std::string& playername, const std::string& rolename, UpdateData_Msg msg);

	/*
	*判断对应玩家角色是否已经存在对象层中
	*@param playername：玩家名称
	*@param rolename：角色名称
	*@return std::list<Player*>::iterator：存在返回对应链表的迭代器，不存在返回末尾迭代器
	*/
	std::list<XGamePlayer*>::iterator existPlayer(const std::string& playername,const std::string& rolename);
private:
	/*
	*checkmissedTask();
	*检查Npc是否有未接任务
	*/
	void checkmissedTask();

	/*
	*checkpickedupTask();
	*检查Npc是否有已接任务
	*/
	void checkpickedupTask();

	/*
	*updateNpcPos();
	*以玩家为基准更新其它对象的位置信息
	*/
	void updateObjectScreenPos();

	/*
	*updateNpcScreenPos();
	*更新Npc在屏幕上的位置
	*/
	void updateNpcScreenPos();

	/*
    *updateOtherPlayerScreenPos();
	*更新其它玩家在屏幕上的坐标
    */
	void updateOtherPlayerScreenPos();

	/*
	*initNpcObject(const int& level)
	*初始化对象层Npc对象
	*@param level：对应关卡
	*/
	void initNpcObject(const int& level);

	/*
	*InitOtherPlayer();
	*初始化其它玩家
	*/
	void initOtherPlayer();

	/*
	*clearNpcObjectLayer();
	*清理Npc对象
	*/
	void clearNpcObjectLayer();

	std::vector<Npc*> m_npcList;
	std::list<XGamePlayer*> m_playerlist;
};

#endif // !__OBJECT_LAYER_H__

