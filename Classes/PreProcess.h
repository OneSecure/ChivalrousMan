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

#define SINGLE_ATTRIBUTES(__TYPE__) \
private: \
	static __TYPE__* m_instance; \
	static std::atomic<__TYPE__*> m_load; \
	static std::mutex m_mutex

#define DEFINE_SINGLE_ATTRIBUTES(__TYPE__) \
std::atomic<__TYPE__*> __TYPE__::m_load; \
std::mutex __TYPE__::m_mutex; \
__TYPE__* __TYPE__::m_instance = nullptr

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

#endif // !__PRE_PRECESS_H__

