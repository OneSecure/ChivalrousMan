#include"CMClient.h"
#include"GameData.h"
#include"Commen.h"
#include<fstream>
#include<string>

using namespace Net;

DEFINE_SINGLE_ATTRIBUTES(CMClient);

CMClient::CMClient()
{
	readConfConnectServer();
}

CMClient::~CMClient()
{

}

void CMClient::release()
{
	RELEASE_NULL(m_instance);
}


void  CMClient::OnRecv(char* buff)
{

}

void CMClient::readConfConnectServer()
{
	std::ifstream fin;
	fin.open(StringValue("ServerConf"), std::ios::in);
	if (fin.fail())
	{
		return;
	}
	std::string serverip;
	std::string tmp;
	unsigned long port;
	
	fin >> serverip;

	fin >> serverip;
	fin >> serverip;
	fin >> tmp;
	fin >> port;

	fin.close();
}
