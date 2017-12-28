#pragma once
#ifndef __REFLECT_NPC_H__
#define __REFLECT_NPC_H__
#include"PreProcess.h"
#include<map>
#include<string>

class Npc;

typedef Npc* (*Sel_NpcCallFunc)();

#define DEC_REFLECT_FUNC(__TYPE__)    \
friend Npc* ReflectClass##__TYPE__();

#define DEF_REFLECT_FUNC(__TYPE__) \
Npc* ReflectClass##__TYPE__() \
{ \
	return (new __TYPE__); \
}

#define REG_REFLECT_CLASS(__TYPE__) \
ReflectNpc::getInstance()->registerReflectClass(#__TYPE__,&ReflectClass##__TYPE__)

#define GET_REFLECT_OBJECT ReflectNpc::getInstance()->getReflectObject

/*
*ReflectNpc
*������������Npc����
*/
class ReflectNpc
{
	GET_SINGLE_OBJECT(ReflectNpc)
	CLASS_ESSENTAIL(ReflectNpc)
public:
	/*
	* registerReflectClass(const std::string& classname, Sel_NpcCallFunc callfunc);
	*ע�ᷴ��ص�����
	*@param classname:��Ҫ���������
	*@param callfunc:����ص�����
	*/
	void registerReflectClass(const std::string& classname, Sel_NpcCallFunc callfunc);

	/*
	*getReflectObject(const std::string& classname);
	*��ȡ����Ķ���
	*@param classname:���������
	*/
	Npc* getReflectObject(const std::string& classname);

	static void release();
private:
	SINGLE_ATTRIBUTES(ReflectNpc);

	std::map<std::string, Sel_NpcCallFunc> m_reflectMap;
};

#endif // !__REFLECT_NPC_H__

