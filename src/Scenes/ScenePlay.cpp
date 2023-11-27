#include "ScenePlay.hpp"

ScenePlay::ScenePlay() {}

ScenePlay::~ScenePlay() {}

void ScenePlay::update()
{
 	EntityManager& ecManager = EntityManager::Instance();
	ecManager.update(); 	// this must be on top


	//m_enemyMovement.update();
	//m_playerMovement.update();
}


void ScenePlay::mapNumber(const int number)
{
	m_spawner.update(number);
	m_spawner.spawnPlayer();
}