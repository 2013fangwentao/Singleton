/*
** Single.h for Test Singleton in /home/fwt/program/Singleton/include
**
** Made by little fang
** Login   <wtfang@whu.edu.cn>
**
** Started on  Sun Jan 13 下午7:40:39 2019 little fang
** Last update Mon Jan 13 下午11:30:55 2019 little fang
*/

#ifndef SINGLE_H_
#define SINGLE_H_
#include <memory>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <string>
#include <stdio.h>

class ConfigInfo
{
  public:
    using Ptr = std::shared_ptr<ConfigInfo>;

  private:
    ConfigInfo() {}
    ConfigInfo(ConfigInfo &&) = default;
    ConfigInfo(const ConfigInfo &) = default;
    ConfigInfo &operator=(ConfigInfo &&) = default;
    ConfigInfo &operator=(const ConfigInfo &) = default;

  public:
    ~ConfigInfo() {}
    static Ptr config_info;
    std::map<std::string, std::string> storage;

  public:
    static Ptr GetInstance();
    void Open(const char *config_file_path);
    template <typename T>
    T Get(std::string key)
    {
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        if (storage.count(key) > 0)
        {
            double value = stod(storage[key]);
            return T(value);
        }
        else
        {
            std::cout << "[-CONFIG-]--Warning! the key of \" " << key << "\" is not exit, return a default value" << std::endl;
            std::cout << "Press enter to continue" << std::endl;
            getchar();
            return T(0x0);
        }
    }
};

template <>
std::string ConfigInfo::Get<std::string>(std::string key)
{
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    if (storage.count(key) > 0)
    {
        return (storage[key]);
    }
    else
    {
        std::cout << "[-CONFIG-]--Warning! the key of \" " << key << "\" is not exit, return a default value" << std::endl;
        std::cout << "Press enter to continue" << std::endl;
        getchar();
        return "";
    }
}
#endif /* !SINGLE_H_ */
