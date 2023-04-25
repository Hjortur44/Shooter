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

  const std::vector<size_t>& getConfigs(const std::string& type) const;

  void setConfigs(std::map<std::string, std::vector<size_t>>& entityConfigMap);

private:
  ConfigurationManager();

  std::map<std::string, std::vector<size_t>> m_configMap;
};
