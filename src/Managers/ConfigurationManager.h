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

  const std::vector<Vec2>& getAssetConfigs(const std::string& type) const;
  const std::vector<size_t>& getEntityConfigs(const std::string& type) const;

  void setAssetConfigs(std::map<std::string, std::vector<Vec2>>& assetConfigMap);
  void setEntityConfigs(std::map<std::string, std::vector<size_t>>& entityConfigMap);

private:
  ConfigurationManager();

  std::map<std::string, std::vector<Vec2>> m_assetConfigMap;
  std::map<std::string, std::vector<size_t>> m_entityConfigMap;
};
