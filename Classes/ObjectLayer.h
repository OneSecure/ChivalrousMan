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
*��Ϸ�����,���ڻ��Ƴ���������������Ϸ����
*/
class ObjectLayer Inherit(cocos2d::Layer)
{
public:
	ObjectLayer();
	~ObjectLayer();

	/*
	*createWithLevel(const int& level);
	*���ݵ�ͼ���������
	*@param level:��ͼ����
	*/
	static ObjectLayer* createWithLevel(const int& level);

	bool init(const int& level);

	void update(float dt);

	inline std::vector<Npc*>& getNpcList() { return m_npcList; }

	/*
	*addPlayer(const Player_Info& pinfo);
	*�ڶ��������Ҫ��ʾ�����
	*@param pinfo:�����Ϣ
	*/
	void addPlayer(Player_Info pinfo);

	/*
	*removePlayer(const std::string& playername, const std::string& rolename);
	*������Ƴ���ҽ�ɫ
	*@param playername:�������
	*@param rolename:��ɫ����
	*/
	void removePlayer(const std::string& playername, const std::string& rolename);

	/*
	*moveOtherPlayer(const std::string& playername, const std::string& rolename, const cocos2d::Vec2& pos)
	*�ƶ��������������
	*@param playername:�������
	*@param rolenmae:��ɫ����
	*@param target��Ŀ��λ��
	*/
	void moveOtherPlayer(const std::string& playername, const std::string& rolename, const cocos2d::Vec2& target, int less = 0);
	
	/*
	*verifyPlayerPos(const std::string& playername, const std::string& rolename, const cocos2d::Vec2& pos);
	*У�����λ��
	*@param playername:�������
	*@param rolename:��ɫ����
	*@param pos:У׼��λ��
	*/
	void verifyPlayerPos(const std::string& playername, const std::string& rolename, const cocos2d::Vec2& pos);

	/*
	* updatePlayerData(const std::string& playername, const std::string& rolename, UpdateData_Msg msg);
	*�����������
	*@param playername:�������
	*@param rolename:��ɫ����
	*@param msg:������������ݵ���Ϣ
	*/
	void updatePlayerData(const std::string& playername, const std::string& rolename, UpdateData_Msg msg);

	/*
	*�ж϶�Ӧ��ҽ�ɫ�Ƿ��Ѿ����ڶ������
	*@param playername���������
	*@param rolename����ɫ����
	*@return std::list<Player*>::iterator�����ڷ��ض�Ӧ����ĵ������������ڷ���ĩβ������
	*/
	std::list<XGamePlayer*>::iterator existPlayer(const std::string& playername,const std::string& rolename);
private:
	/*
	*checkmissedTask();
	*���Npc�Ƿ���δ������
	*/
	void checkmissedTask();

	/*
	*checkpickedupTask();
	*���Npc�Ƿ����ѽ�����
	*/
	void checkpickedupTask();

	/*
	*updateNpcPos();
	*�����Ϊ��׼�������������λ����Ϣ
	*/
	void updateObjectScreenPos();

	/*
	*updateNpcScreenPos();
	*����Npc����Ļ�ϵ�λ��
	*/
	void updateNpcScreenPos();

	/*
    *updateOtherPlayerScreenPos();
	*���������������Ļ�ϵ�����
    */
	void updateOtherPlayerScreenPos();

	/*
	*initNpcObject(const int& level)
	*��ʼ�������Npc����
	*@param level����Ӧ�ؿ�
	*/
	void initNpcObject(const int& level);

	/*
	*InitOtherPlayer();
	*��ʼ���������
	*/
	void initOtherPlayer();

	/*
	*clearNpcObjectLayer();
	*����Npc����
	*/
	void clearNpcObjectLayer();

	std::vector<Npc*> m_npcList;
	std::list<XGamePlayer*> m_playerlist;
};

#endif // !__OBJECT_LAYER_H__

