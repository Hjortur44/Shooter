#pragma once

#include <string>
#include <map>
#include <iostream>

class ConfigurationManager
{
		std::map<std::string, int> m_configMap;

		ConfigurationManager();

	public:
    ConfigurationManager(ConfigurationManager&) = delete;

    static ConfigurationManager& Instance();

		const std::map<std::string, int>& getConfigs() const;

		void setConfigs(std::map<std::string, int>& entityConfigMap);
};