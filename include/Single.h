/*
** Single.h for Test Singleton in /home/fwt/program/Singleton/include
**
** Made by little fang
** Login   <wtfang@whu.edu.cn>
**
** Started on  Sun Jan 13 下午7:40:39 2019 little fang
** Last update Tue Jan 21 10:41:24 PM 2019 little fang
*/

#ifndef SINGLE_H_
#define SINGLE_H_

#ifndef WIN32
#define CONFIGINFO_DLLAPI
#else
#ifdef ConfigInfo_EXPORTS
#define CONFIGINFO_DLLAPI __declspec(dllexport)
#else
#define CONFIGINFO_DLLAPI __declspec(dllimport)
#endif
#endif

#include <stdio.h>
#include <string>
#include <memory>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>

class CONFIGINFO_DLLAPI ConfigInfo
{
  public:
    using Ptr = std::shared_ptr<ConfigInfo>;

  private:
    ConfigInfo() {}
    ConfigInfo(ConfigInfo &&) = delete;
    ConfigInfo(const ConfigInfo &) = delete;
    ConfigInfo &operator=(ConfigInfo &&) = delete;
    ConfigInfo &operator=(const ConfigInfo &) = delete;
    static Ptr config_info;
    std::map<std::string, std::string> storage;

  public:
    ~ConfigInfo() {}

  public:
    static Ptr GetInstance();
    bool open(const char *config_file_path);
    template <typename T>
    T get(std::string key)
    {
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        if (storage.count(key) > 0)
        {
            double value = stod(storage[key]);
            return static_cast<T>(value);
        }
        else
        {
            std::cout << "[-CONFIG-] Warning! The key of \" " << key << "\" does not exist, return a default value" << std::endl;
            std::cout << "Press enter to continue" << std::endl;
            getchar();
            return T(0x0);
        }
    }
};

template <>
std::string ConfigInfo::get<std::string>(std::string key)
{
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    if (storage.count(key) > 0)
    {
        return (storage[key]);
    }
    else
    {
		std::cout << "[-CONFIG-] Warning! The key of \" " << key << "\" does not exist, return a default value" << std::endl;
		std::cout << "Press enter to continue" << std::endl;
        getchar();
        return "";
    }
}
#endif /* !SINGLE_H_ */
