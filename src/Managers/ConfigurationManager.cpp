#include "ConfigurationManager.h"

ConfigurationManager& ConfigurationManager::Instance()
{
  static ConfigurationManager INSTANCE;
  return INSTANCE;
}


const std::vector<size_t>& ConfigurationManager::getConfigs(const std::string& entity) const
{
  return m_configMap.at(entity);
}


void ConfigurationManager::setConfigs(std::map<std::string, std::vector<size_t>>& entityConfigMap)
{
  m_configMap = entityConfigMap;
}


//private
ConfigurationManager::ConfigurationManager() {}
