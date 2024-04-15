#include "Game.hpp"

Game::Game() {}

Game::~Game() {}

void Game::fileRead(const std::string& file)
{
	std::ifstream fIn(file);
	Json data = Json::parse(fIn);
	fIn.close();

	std::string domain = data["domain"];
	std::string folder = data["folder"];
	std::string path = domain + folder;

	if(folder == "/assets")
	{
		AssetManager::Instance().update(data["texture_names"], files(path, data["file_list"]));
	}
	else if(folder == "/configurations/maps")
	{
		int mapNumber = 0;

		for(const std::string& map : files(path, data["file_list"]))
		{
			std::ifstream fInner(map);
			Json dataInner = Json::parse(fInner);
			fInner.close();

			std::map<std::string, std::vector<int>> textures;

			for(const Json& config : dataInner["config_list"])
			{
				std::string name = config["texture_name"];
				std::vector<int> pos = config["positions"];
				textures[name] = pos;
			}

			MapManager::Instance().update(mapNumber, textures);
			mapNumber++;
		}
	}
}


void Game::start()
{
	GameEngine gameEngine;
	gameEngine.run();
}


// private
std::vector<std::string> Game::files(const std::string& path, const Json& data)
{
	std::vector<std::string> files;

	for(const std::string& file : data)
		files.push_back(path + file);

	return files;
}