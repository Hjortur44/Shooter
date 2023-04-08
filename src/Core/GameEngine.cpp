#include "GameEngine.h"

GameEngine::GameEngine()
{
  init();
}


sf::RenderWindow& GameEngine::window()
{
  return m_window;
}


void GameEngine::run()
{
  while(m_window.isOpen())
  {
    update();
  }
}


void GameEngine::quit()
{
  m_window.close();
}


void GameEngine::update()
{
	sUserInput();
  //sEnemySpawner();
	sBulletSpawner();
	sMovement();
	sRender();
}


// private
void GameEngine::init()
{
  m_window.create(sf::VideoMode(640, 480), "Game");
  m_window.setFramerateLimit(60);
}


void GameEngine::sMovement()
{
	m_movement.moving();
}


void GameEngine::sEnemySpawner()
{
}


void GameEngine::sBulletSpawner()
{
	m_bulletSpawn.shoot();
}


void GameEngine::sUserInput()
{
	sf::Event event;

	while(m_window.pollEvent(event))
	{
		if(event.type == sf::Event::KeyPressed)
			m_input.keyPressed(event.key.code);

		if(event.type == sf::Event::KeyReleased)
			m_input.keyReleased(event.key.code);

		if(event.type == sf::Event::Closed)
			quit();
	}


/*
	if(currentScene()->getActionMap().find(event.key.code) != currentScene()->getActionMap().end())
	{
		const std::string actionType = (event.type == sf::Event::KeyPressed) ? "START" : "END";
		currentScene()->doAction(Action(currentScene()->getActionMap().at(event.key.code), actionType));
	}
*/
}


void GameEngine::sRender()
{
	m_window.clear();

	for(CShape& s : m_pool.getComponentVector<CShape>())
	{
		if(s.active)
			m_window.draw(s.circle);
	}

  m_window.display();
}