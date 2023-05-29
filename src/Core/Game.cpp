#include "Game.h"

Game::Game() {}

void Game::readAssetConfigs(const std::string& configIndex)
{
  std::map<std::string, std::vector<Vec2>> configMap;
  std::string entityName = "";
  std::string filename = "";

  std::ifstream fin(configIndex);

  while(fin.good())
  {
    fin >> entityName;
    fin >> filename;

    configMap[entityName] = assetConfigs(filename);
  }

  fin.close();

 ConfigurationManager::Instance().setAssetConfigs(configMap);
}


void Game::readEntityConfigs(const std::string& configIndex)
{
  std::map<std::string, std::vector<int>> configMap;
  std::string entityName = "";
  std::string filename = "";

  std::ifstream fin(configIndex);

  while(fin.good())
  {
    fin >> entityName;
    fin >> filename;

    configMap[entityName] = entityConfigs(filename);
  }

  fin.close();

  ConfigurationManager::Instance().setEntityConfigs(configMap);
}


void Game::readAssetTextures(const std::string& textureIndex)
{
  std::map<std::string, std::string> map;
  std::string name  = "";
  std::string value = "";

  std::ifstream fin(textureIndex);

  while(fin.good())
  {
    fin >> name;
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
std::vector<Vec2> Game::assetConfigs(const std::string& index)
{
  std::vector<Vec2> cs;
  std::ifstream fin(index);
  int x = 0;
	int y = 0;

  while(fin.good())
  {
    fin >> x;
		fin >> y;
    cs.push_back(Vec2(x, y));
  }

  fin.close();

  return cs;
}


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