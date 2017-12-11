#pragma once
#ifndef __DB_INTERFACE_H__
#define __DB_INTERFACE_H__
#include<WinSock2.h>
#include<mysql.h>
#include<mysqld_error.h>

class DBDao
{
public:
	DBDao();
	~DBDao();

	void registerModel();
private:
	MYSQL* m_sqlCon;
};

#endif // !__DB_INTERFACE_H__

