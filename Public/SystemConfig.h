#ifndef _SYSTEM_CONFIG_H_
#define _SYSTEM_CONFIG_H_

#include <string>
#include <map>
#include <fstream>

namespace PUBLIC
{

class SystemConfig
{
public:
    SystemConfig(const std::string& filepath);
	void Load();
	const std::string& GetProperty(const std::string& name);

private:
    std::map<std::string, std::string> properties_;
	std::string filepath_;
};

}

#endif // _SYSTEM_CONFIG_H_
