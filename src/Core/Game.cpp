#include "Game.h"

Game::Game() {}

void Game::readEntityConfigs(const std::string& configIndex)
{
  std::map<std::string, std::vector<size_t>> configMap;
  std::string entityName = "";
  std::string filename = "";

  std::ifstream fin(configIndex);

  while(fin.good())
  {
    fin >> entityName;
    fin >> filename;

    configMap[entityName] = configs(filename);
  }

  fin.close();

  ConfigurationManager::Instance().setConfigs(configMap);
}


void Game::readAssetTextures(const std::string& textureIndex)
{
  std::map<std::string, std::string> map;
  std::string name  = "wood";
  std::string value = "";

  std::ifstream fin(textureIndex);

  while(fin.good())
  {
    fin >> value;
    map[name] = value;
  }

  fin.close();

  AssetManager::Instance().setAssets(map);
}


void Game::start()
{
  GameEngine engine;
  engine.run();
}


// private
std::vector<size_t> Game::configs(const std::string& index)
{
  std::vector<std::size_t> cs;
  std::ifstream fin(index);
  size_t value = 0;

  while(fin.good())
  {
    fin >> value;
    cs.push_back(value);
  }

  fin.close();

  return cs;
}
