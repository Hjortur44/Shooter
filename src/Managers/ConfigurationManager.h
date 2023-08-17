#pragma once

#include "../Math/Vec2.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

class ConfigurationManager
{
public:
  ConfigurationManager(ConfigurationManager&) = delete;

  static ConfigurationManager& Instance();

  const std::vector<int>& getEntityConfigs(const std::string& type) const;

  void setEntityConfigs(std::map<std::string, std::vector<int>>& entityConfigMap);

private:
  ConfigurationManager();

  std::map<std::string, std::vector<int>> m_entityConfigMap;
};
