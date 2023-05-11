#include "ConfigurationManager.h"

ConfigurationManager& ConfigurationManager::Instance()
{
  static ConfigurationManager INSTANCE;
  return INSTANCE;
}


const std::vector<Vec2>& ConfigurationManager::getAssetConfigs(const std::string& type) const
{
  return m_assetConfigMap.at(type);
}


const std::vector<size_t>& ConfigurationManager::getEntityConfigs(const std::string& type) const
{
  return m_entityConfigMap.at(type);
}


void ConfigurationManager::setAssetConfigs(std::map<std::string, std::vector<Vec2>>& assetConfigMap)
{
  m_assetConfigMap = assetConfigMap;
}


void ConfigurationManager::setEntityConfigs(std::map<std::string, std::vector<size_t>>& entityConfigMap)
{
  m_entityConfigMap = entityConfigMap;
}


//private
ConfigurationManager::ConfigurationManager() {}
