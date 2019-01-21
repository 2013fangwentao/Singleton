/*
** testSingle.cpp for Test Singleton in /home/fwt/program/Singleton/test
**
** Made by little fang
** Login   <wtfang@whu.edu.cn>
**
** Started on  undefined Jan 13 下午8:22:51 2019 little fang
** Last update Mon Jan 13 下午11:29:42 2019 little fang
*/

#include "Single.h"

int main(int argc, char *argv[])
{
    ConfigInfo::Ptr getconfig = ConfigInfo::GetInstance();
    getconfig->open("../config.txt");

	std::cout << getconfig->get<int>("num") << std::endl;
	std::cout << getconfig->get<double>("start") << std::endl;
	std::cout << getconfig->get<std::string>("path") << std::endl;
	std::cout << getconfig->get<double>("Angle") << std::endl;
	std::cout << getconfig->get<double>("haha") << std::endl;
    return 0;
}