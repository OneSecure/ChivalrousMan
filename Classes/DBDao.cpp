#include"DBDao.h"

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"libmysql.lib")
  
DBDao::DBDao(const std::string& host, const std::string& username, const std::string& passwd,const std::string& dbname):
	m_host(host),
	m_username(username),
	m_passwd(passwd),
	m_dbname(dbname)
{
	m_sqlCon = mysql_init(0);
	mysql_real_connect(m_sqlCon, m_host.c_str(), m_username.c_str(),
		m_passwd.c_str(), m_dbname.c_str(), m_port, NULL, 0);
}

DBDao::~DBDao()
{
	mysql_close(m_sqlCon);
}

void DBDao::registerModel()
{

}

