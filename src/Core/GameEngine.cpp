#include "GameEngine.hpp"

GameEngine::GameEngine() {}

GameEngine::~GameEngine() {}

void GameEngine::run()
{
  while(m_renderer.isOpen())
  {
		m_physics.update();
		m_renderer.update();
  }

	// System hierachy
	/*
		scene update
		spawner update
		input update
		movement updatge
		physic updatge
		render update
	*/
}