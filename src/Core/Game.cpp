#include "Game.h"

Game::Game() {}

Game::~Game() {}

void Game::readAssetIndex(const std::string& assetIndex)
{
  std::map<std::string, std::string> map;
  std::string name  = "";
  std::string value = "";

  std::ifstream fin(assetIndex);

  while(fin.good())
  {
    fin >> name;
    fin >> value;

    map[name] = value;
  }

  fin.close();

  AssetManager::Instance().setAssets(map);
}


void Game::readEntityIndex(const std::string& entityIndex)
{
  std::map<std::string, std::vector<int>> configMap;
  std::string entityName = "";
  std::string filename = "";

  std::ifstream fin(entityIndex);

  while(fin.good())
  {
    fin >> entityName;
    fin >> filename;

    configMap[entityName] = entityConfigs(filename);
  }

  fin.close();

  ConfigurationManager::Instance().setEntityConfigs(configMap);
}


void Game::readMapIndex(const std::string& mapIndex)
{
  std::map<int, std::string> map;
	int number = 0;
  std::string value = "";

  std::ifstream fin(mapIndex);

  while(fin.good())
  {
    fin >> number;
    fin >> value;

    map[number] = value;
  }

  fin.close();

  MapManager::Instance().analizeMapConfigs(map);
}


void Game::start()
{
  GameEngine engine;
  engine.run();
}


// private
std::vector<int> Game::entityConfigs(const std::string& index)
{
  std::vector<int> cs;
  std::ifstream fin(index);
  int value = 0;

  while(fin.good())
  {
    fin >> value;
    cs.push_back(value);
  }

  fin.close();

  return cs;
}