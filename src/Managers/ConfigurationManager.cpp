#include "ConfigurationManager.h"

ConfigurationManager& ConfigurationManager::Instance()
{
  static ConfigurationManager INSTANCE;
  return INSTANCE;
}


const std::map<std::string, int>& ConfigurationManager::getConfigs() const
{
	return m_configMap;
}


void ConfigurationManager::setConfigs(std::map<std::string, int>& configMap)
{
	m_configMap = configMap;
}


//private
ConfigurationManager::ConfigurationManager() {}