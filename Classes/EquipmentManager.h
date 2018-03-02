#pragma once
#ifndef __EQUIPMETNMANAGER_H__
#define __EQUIPMETNMANAGER_H__
#include"PreProcess.h"
#include<list>
#include<string>

//装备信息
struct EMInfo  
{
	std::string name;
	int type;
	int grade;
};

/*
*class EquipmentManager
*装备管理
*/
class EquipmentManager
{
	GET_SINGLE_OBJECT(EquipmentManager)
public:
	static void realse();

	/*
	*addEquipment(std::string name);
	*穿戴装备如果存在同类型就替换
	*@param info：装备信息
	*@return 
	*/
	int wearEquipment(const EMInfo& info);

	/*
	*upEquipment(std::string name);
	*根据装备名升级装备
	*@param name：装备名
	*@return int：升级成功返回0，存在返回-1
	*/
	int upEquipment(const std::string& name);

	/*
	*removeEquipment(const std::string& name);
	*根据名字移除装备
	*@param name:装备名
	*@return int：移除成功返回0，不存在返回-1
	*/
	int removeEquipment(const std::string& name);

	/*
	*getEmList();
	*获取装备链表
	*/
	std::list<EMInfo>& getEmList();

	/*
	*readEquipmentInfo();
	*读取角色装备信息
	*/
	void readEquipmentInfo();

	void saveEquipmentInfo();
private:
	void updateEm(EMInfo);

	void  deleteEm(EMInfo);

	std::list<EMInfo> m_emlist;

	SINGLE_ATTRIBUTES(EquipmentManager);
};

#endif // !__EQUIPMETNMANAGER_H__

