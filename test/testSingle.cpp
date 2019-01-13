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
    getconfig->Open("./config.txt");

    std::cout<<getconfig->Get<int>("num")<<std::endl;
    std::cout<<getconfig->Get<double>("start")<<std::endl;
    std::cout<<getconfig->Get<std::string>("path")<<std::endl;
    std::cout<<getconfig->Get<double>("Angle")<<std::endl;
    std::cout<<getconfig->Get<double>("haha")<<std::endl;
    return 0;
}