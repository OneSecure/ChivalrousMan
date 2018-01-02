#include"Thing.h"
#include"Commen.h"
#include<fstream>

Thing::Thing(const std::string& name)
{
	initDetails(name);
}

Thing::~Thing()
{

}

void  Thing::showDetail()
{
	/*MessageBox("ฯ๊ว้", "");*/
}

std::string Thing::getName(const std::string& name)
{
	std::string targetname;
	std::string tmp = "";
	for (size_t i = 0; i < name.length(); i++)
	{
		tmp = name[i];
		if (tmp == ".")
		{
			break;
		}
		else
		{
			targetname += name[i];
		}
	}
	return targetname;
}

void  Thing::initDetails(const std::string& name)
{
	std::string realname = name;
	realname += ".dec";
	std::ifstream fin;
	fin.open(name, std::ios::in);
	if (fin.fail())
	{
		return;
	}
	std::string tmp;
	do
	{
		fin >> tmp;
		m_details.push_back(tmp);
	} while (!fin.eof());
	fin.close();
}
