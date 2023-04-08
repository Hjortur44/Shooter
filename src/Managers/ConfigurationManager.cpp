#include "ConfigurationManager.h"

ConfigurationManager& ConfigurationManager::Instance()
{
  static ConfigurationManager INSTANCE;
  return INSTANCE;
}


const std::map<std::string, size_t>& ConfigurationManager::getConfigs() const
{
	return m_configMap;
}


void ConfigurationManager::setConfigs(std::map<std::string, size_t>& configMap)
{
	m_configMap = configMap;
}


//private
ConfigurationManager::ConfigurationManager() {}