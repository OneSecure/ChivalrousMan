#pragma once
#ifndef __DB_INTERFACE_H__
#define __DB_INTERFACE_H__
#include<WinSock2.h>
#include<mysql.h>
#include<mysqld_error.h>
#include<string>

class DBDao
{
public:
	DBDao(const std::string& host, const std::string& username, const std::string& passwd, const std::string& dbname);
	~DBDao();

	void registerModel();
private:
	MYSQL* m_sqlCon;
	std::string m_host;
	std::string m_username;
	std::string m_passwd;
	std::string m_dbname;
	unsigned int m_port = 3306;
};

#endif // !__DB_INTERFACE_H__

