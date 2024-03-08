#include "Game.hpp"

Game::Game() {}

Game::~Game() {}

void Game::fileRead(const std::string& type, const std::string& file)
{
	std::ifstream fIn(file);
	Json data = Json::parse(fIn);
	fIn.close();

	Json textureFiles = data["texture_files"];

	for(const std::string& png : textureFiles)
	{
		m_list["textureFiles"].push_back(png);
	}

	for(const auto& [key, value] : m_list)
	{
		std::cout << key << ": ";

		for(const auto& v : value)
		{
			std::cout << v << " ";
		}

		std::cout << "" << std::endl;
	}

	EntityManager::Instance();
}

void Game::start()
{
	GameEngine gameEngine;
	gameEngine.run();
}