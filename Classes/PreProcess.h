#pragma once
#ifndef __PRE_PROCESS_H__
#define __PRE_PROCESS_H__
#include"cocos2d.h"

#define CLASS_ESSENTAIL(__TYPE__)  \
    private:  \
           __TYPE__(){} \
    public:          \
           virtual ~__TYPE__(){}

#define Inherit(__TYPE__) :public __TYPE__

//单实例设计模式基本参数
#define SINGLE_ATTRIBUTES(__TYPE__) \
private: \
	static __TYPE__* m_instance; \
	static std::atomic<__TYPE__*> m_load; \
	static std::mutex m_mutex

//定义单实例设计模式的基本参数
#define DEFINE_SINGLE_ATTRIBUTES(__TYPE__) \
std::atomic<__TYPE__*> __TYPE__::m_load; \
std::mutex __TYPE__::m_mutex; \
__TYPE__* __TYPE__::m_instance = nullptr

//获取单实例设计模式的实例对象
#define GET_SINGLE_OBJECT(__TYPE__)  \
public: \
	static __TYPE__*  __TYPE__::getInstance() \
	{ \
	m_instance = m_load.load(std::memory_order_relaxed); \
	std::atomic_thread_fence(std::memory_order_acquire); \
	if (m_instance == nullptr) \
	{ \
		std::lock_guard<std::mutex> lock(m_mutex); \
		m_instance = m_load.load(std::memory_order_relaxed); \
		if (m_instance == nullptr) \
		{ \
			m_instance = new  __TYPE__; \
			std::atomic_thread_fence(std::memory_order_release); \
			m_load.store(m_instance, std::memory_order_release); \
		} \
	} \
	return m_instance; \
	}

#define GettingAndSetting(varType,varName,funName) \
protected: varType varName; \
public: virtual varType get##funName(void){return varName;} \
public: virtual void set##funName(varType var) {varName=var;}

#define PROPERTY__REF(varType, varName, funName)     \
protected: varType varName;     \
public: virtual const varType& get##funName(void){return varName;}    \
public: virtual void set##funName(const varType& var){varName=var;} 


#define CreateWithParam(__OBJTYPE__,__TYPE__,PARAM) \
static __OBJTYPE__* create##__OBJTYPE__(__TYPE__ PARAM)  \
{    \
__OBJTYPE__*  pRet = new __OBJTYPE__;     \
if (pRet&&pRet->init(PARAM))      \
{      \
	pRet->autorelease();    \
	return pRet;     \
}     \
else    \
{       \
	delete pRet;     \
	pRet = nullptr;      \
	return nullptr;      \
}      \
}  

#define ADD_PROPERTY(NAME)  \
fin >> tmp; \
fin >> tmp; \
m_##NAME = std::stof(tmp)

enum class Dir
{
	Dir_Left,
	Dir_Down,
	Dir_Right,
	Dir_Up,
};

enum class Player_Type
{
	Player1_Type,
	Player2_Type,
	Player3_Type,
};

#define LEVEL_ONE 1
#define LEVEL_TWO 2
#define LEVEL_THREE 3

#define MEDICATION 1001
#define EQUIPMENT 1002

#endif // !__PRE_PRECESS_H__

