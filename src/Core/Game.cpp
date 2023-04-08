#include "Game.h"

Game::Game() {}

void Game::readEntityConfigs(const std::string& configIndex)
{
	std::map<std::string, size_t> entityConfigMap;
	std::string name = "";
	size_t value = 0;

	std::ifstream fin(configIndex);

	while(fin.good())
	{
		fin >> name;
		fin >> value;
		entityConfigMap[name] = value;
	}

	fin.close();

	ConfigurationManager::Instance().setConfigs(entityConfigMap);
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