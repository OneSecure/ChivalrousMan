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
*根据类名反射Npc对象
*/
class ReflectNpc
{
	GET_SINGLE_OBJECT(ReflectNpc)
	CLASS_ESSENTAIL(ReflectNpc)
public:
	/*
	* registerReflectClass(const std::string& classname, Sel_NpcCallFunc callfunc);
	*注册反射回调函数
	*@param classname:需要反射的类名
	*@param callfunc:反射回调函数
	*/
	void registerReflectClass(const std::string& classname, Sel_NpcCallFunc callfunc);

	/*
	*getReflectObject(const std::string& classname);
	*获取反射的对象
	*@param classname:反射的类名
	*/
	Npc* getReflectObject(const std::string& classname);

	static void release();
private:
	SINGLE_ATTRIBUTES(ReflectNpc);

	std::map<std::string, Sel_NpcCallFunc> m_reflectMap;
};

#endif // !__REFLECT_NPC_H__

