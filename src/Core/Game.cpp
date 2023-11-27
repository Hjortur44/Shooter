#include "Game.hpp"

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
  std::map<std::string, std::vector<int>> configs;
  std::string entityName = "";
  std::string filename = "";

  std::ifstream fin(entityIndex);

  while(fin.good())
  {
    fin >> entityName;
    fin >> filename;

    configs[entityName] = entityConfigs(filename);
  }

  fin.close();

  ConfigurationManager::Instance().setEntityConfigs(configs);
}


void Game::readMapIndex(const std::string& mapIndex)
{
	using Json = nlohmann::json;

	std::ifstream fin(mapIndex);
	Json data = Json::parse(fin);
  fin.close();

  std::string domainFolder = data["domainFolder"];

	ConfigMap configs;

  for(const Json& maps : data["maps"])
  {
  	std::string conf = maps["confPath"];
		int number = maps["number"];

 	 	std::ifstream fin2(domainFolder + conf);
		Json data2 = Json::parse(fin2);
 		fin2.close();

 		std::map<std::string, std::vector<int>> confs;

 		for(const Json& tex : data2["textures"])
  	{
  		std::string name = tex["name"];
			std::vector<int> pos = tex["positions"];

			confs[name] = pos;
	 	}

	 	configs[number] = confs;
  }

  MapTileManager::Instance().setMapTileConfigs(configs);
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


std::vector<int> Game::mapConfigs(const std::string& index)
{
  std::vector<int> cs;
  std::string filename = "";
  int value = 0;

  std::ifstream fin(index);

  while(fin.good())
  {
		fin >> filename;
   	std::ifstream fin2(filename);

		while(fin2.good())
		{
			fin2 >> value;
		  cs.push_back(value);
		}

  	fin2.close();
  }

  fin.close();

  return cs;
}