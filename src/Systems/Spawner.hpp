#pragma once

#include "../Entities/Entity.hpp"
#include "../Managers/AssetManager.hpp"
#include "../Managers/ConfigurationManager.hpp"
#include "../Managers/EntityManager.hpp"
#include "../Math/Vec2.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <vector>

class Spawner
{
public:
  Spawner();
  ~Spawner();

	void spawnBullet(const int x, const int y);
	void spawnEnemy();
	void spawnPlayer();
	void update(const int number);

private:
	std::vector<sf::Texture> m_currentTextures;

	int m_currentNumber = -1;
	int m_enemyCount = 0;
};