#pragma once

#include <string>
#include <map>
#include <vector>
#include <iostream>

class ConfigurationManager
{
  std::map<std::string, std::vector<size_t>> m_configMap;

  ConfigurationManager();

public:
  ConfigurationManager(ConfigurationManager&) = delete;

  static ConfigurationManager& Instance();

  const std::vector<size_t>& getConfigs(const std::string& entity) const;

  void setConfigs(std::map<std::string, std::vector<size_t>>& entityConfigMap);
};
