#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

class ConfigurationManager
{
public:
  ConfigurationManager(ConfigurationManager&) = delete;

  static ConfigurationManager& Instance();

  const std::vector<int>& getConfigs(const std::string& entity) const;

  void setConfigs(std::map<std::string, std::vector<int>>& entityConfigMap);

private:
  ConfigurationManager();

  std::map<std::string, std::vector<int>> m_configMap;
};
