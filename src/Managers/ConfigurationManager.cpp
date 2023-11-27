#include "ConfigurationManager.hpp"

ConfigurationManager& ConfigurationManager::Instance()
{
  static ConfigurationManager INSTANCE;
  return INSTANCE;
}


const std::vector<int>& ConfigurationManager::getEntityConfigs(const std::string& type) const
{
  return m_entityConfigMap.at(type);
}


void ConfigurationManager::setEntityConfigs(std::map<std::string, std::vector<int>>& entityConfigMap)
{
  m_entityConfigMap = entityConfigMap;
}


//private
ConfigurationManager::ConfigurationManager() {}
