#include"DBDao.h"

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"libmysql.lib")
  
DBDao::DBDao()
{
	m_sqlCon = mysql_init(0);
}

DBDao::~DBDao()
{
	mysql_close(m_sqlCon);
}

void DBDao::registerModel()
{

}

