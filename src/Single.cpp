/*
** Single.cpp for Singleton in /home/fwt/program/Singleton/src
**
** Made by little fang
** Login   <wtfang@whu.edu.cn>
**
** Started on  undefined Jan 13 下午7:52:33 2019 little fang
** Last update Tue Jan 21 10:36:58 PM 2019 little fang
*/

#include "Single.h"
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

ConfigInfo::Ptr ConfigInfo::config_info(new ConfigInfo());

/**
 * @brief  初始化函数
 * @note   
 * @param  *config_file_path: 配置文件路径
 * @retval None
 */
bool ConfigInfo::open(const char *config_file_path)
{
    ifstream ifs_in(config_file_path, ios::in);
    if (!ifs_in)
    {
        cout << "Config File Lost" << endl;
		return false;
    }
    while (!ifs_in.eof())
    {
        string line, key, value;
        getline(ifs_in, line);
        if (line.size() == 0)
        {
            continue;
        }
        else if (line.substr(0, 1) == "#" || line.substr(0, 1) == "*")
        {
            continue;
        }
        stringstream sstr_line(line);
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        sstr_line >> key;
        sstr_line >> value;
        storage[key] = value;
    }
	return true;
}

/**
 * @brief  获取单例模式下的唯一对象
 * @note   
 * @retval 
 */
ConfigInfo::Ptr ConfigInfo::GetInstance()
{
    return config_info;
}
