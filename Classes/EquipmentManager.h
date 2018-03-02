#pragma once
#ifndef __EQUIPMETNMANAGER_H__
#define __EQUIPMETNMANAGER_H__
#include"PreProcess.h"
#include<list>
#include<string>

//װ����Ϣ
struct EMInfo  
{
	std::string name;
	int type;
	int grade;
};

/*
*class EquipmentManager
*װ������
*/
class EquipmentManager
{
	GET_SINGLE_OBJECT(EquipmentManager)
public:
	static void realse();

	/*
	*addEquipment(std::string name);
	*����װ���������ͬ���;��滻
	*@param info��װ����Ϣ
	*@return 
	*/
	int wearEquipment(const EMInfo& info);

	/*
	*upEquipment(std::string name);
	*����װ��������װ��
	*@param name��װ����
	*@return int�������ɹ�����0�����ڷ���-1
	*/
	int upEquipment(const std::string& name);

	/*
	*removeEquipment(const std::string& name);
	*���������Ƴ�װ��
	*@param name:װ����
	*@return int���Ƴ��ɹ�����0�������ڷ���-1
	*/
	int removeEquipment(const std::string& name);

	/*
	*getEmList();
	*��ȡװ������
	*/
	std::list<EMInfo>& getEmList();

	/*
	*readEquipmentInfo();
	*��ȡ��ɫװ����Ϣ
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

