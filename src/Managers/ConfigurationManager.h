#pragma once

#include <string>
#include <map>
#include <iostream>

class ConfigurationManager
{
		std::map<std::string, size_t> m_configMap;

		ConfigurationManager();

	public:
    ConfigurationManager(ConfigurationManager&) = delete;

    static ConfigurationManager& Instance();

		const std::map<std::string, size_t>& getConfigs() const;

		void setConfigs(std::map<std::string, size_t>& entityConfigMap);
};