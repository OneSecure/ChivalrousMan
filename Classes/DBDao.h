#pragma once
#ifndef __DB_INTERFACE_H__
#define __DB_INTERFACE_H__
#include<WinSock2.h>
#include<mysql.h>
#include<mysqld_error.h>
#include<string>
#include<initializer_list>
#include<vector>

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"libmysql.lib")
#define QUERY 1
#define INSERT 2
#define DELETE 3
#define UPDATE 4

template<typename Model>
class DBDao
{
public:
	DBDao(const std::string& host, const std::string& username, const std::string& passwd, const std::string& dbname);
	~DBDao();

	void setModel(Model md);

	std::vector<Model> queryModel();

	bool insertModel();

	bool deleteModel();

	bool updateModel(const std::string& fieldName, const std::string& value);
private:
	void generateSql(int flag);

	std::string generateWhere();

	MYSQL* m_sqlCon;
	std::string m_host;
	std::string m_username;
	std::string m_passwd;
	std::string m_dbname;
	unsigned int m_port = 3306;
	std::string m_sql;
	Model m_md;
};

template<typename Model>
DBDao<Model>::DBDao(const std::string& host, const std::string& username, const std::string& passwd, const std::string& dbname) :
	m_host(host),
	m_username(username),
	m_passwd(passwd),
	m_dbname(dbname)
{
	m_sqlCon = mysql_init(0);
	mysql_real_connect(m_sqlCon, m_host.c_str(), m_username.c_str(),
		m_passwd.c_str(), m_dbname.c_str(), m_port, NULL, 0);
}

template<typename Model>
DBDao<Model>::~DBDao()
{
	mysql_close(m_sqlCon);
}

template<typename Model>
void DBDao<Model>::setModel(Model md)
{
	m_md = md;
}

template<typename Model>
std::vector<Model> DBDao<Model>::queryModel()
{
	std::vector<Model> resSet;
	generateSql(QUERY);
	int res=mysql_real_query(m_sqlCon, m_sql.c_str(), m_sql.length());
	if (res)
	{
		return resSet;
	}
	MYSQL_RES* result = mysql_store_result(m_sqlCon);
	if (!result)
	{
		return resSet;
	}
	MYSQL_ROW row;
	while ((row=mysql_fetch_row(result)))
	{
		Model md;
		for (int i = 0; i < mysql_num_fields(result); ++i)
		{
			md[i] = row[i];
		}
	}
}

template<typename Model>
bool DBDao<Model>::insertModel()
{
	generateSql(INSERT);
	mysql_real_query(m_sqlCon, m_sql.c_str(), m_sql.length());
}

template<typename Model>
bool DBDao<Model>::deleteModel()
{
	generateSql(DELETE);
	mysql_real_query(m_sqlCon, m_sql.c_str(), m_sql.length());
}

template<typename Model>
bool DBDao<Model>::updateModel(const std::string& fieldName,const std::string& value)
{
	generateSql(UPDATE);
	mysql_real_query(m_sqlCon, m_sql.c_str(), m_sql.length());
}
template<typename Model>
void  DBDao<Model>::generateSql(int flag)
{
	switch (flag)
	{
	case QUERY:
	{
		m_sql.append("select * from ");
		m_sql.append(m_md->getName());
		m_sql.append(generateWhere());
	}
		break;
	case INSERT:
		break;
	case DELETE:
		break;
	case UPDATE:
		break;
	default:
		break;
	}
}

template<typename Model>
std::string   DBDao<Model>::generateWhere()
{
	std::string wheres = "";
	int flag = 0;
	for (int i = 0; i < m_md.getAttributeNums; ++i)
	{
		if (flag == 0)
		{
			if (m_md[i] != "")
			{
				wheres += " where ";
				wheres += m_md.getAttributeName(i);
				wheres += "='";
				wheres += m_md[i];
				wheres += "'";
				flag = 1;
			}
		}
		else
		{
			if (m_md[i] != "")
			{
				wheres += " and ";
				wheres+= m_md.getAttributeName(i);
				wheres += "='";
				wheres += m_md[i];
				wheres += "'";
			}
		}
	}
	return wheres;
}

#endif // !__DB_INTERFACE_H__

