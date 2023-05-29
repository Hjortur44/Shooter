#include "GameEngine.h"

GameEngine::GameEngine()
{
  init();
}


void GameEngine::run()
{
	Scene s;
  while(m_renderer.renderWindow().isOpen())
  {
    update();
  }
}


void GameEngine::quit()
{
  m_renderer.renderWindow().close();
}


void GameEngine::update()
{
	ComponentManager::Instance().update(); // this must be on top

	sUserInput();
	sPhysics();
	sRender();
}


// private
void GameEngine::init()
{
	m_spawner.spawnPlayer();
}


void GameEngine::sPhysics()
{
	m_movement.update();
	m_physics.update();
}


void GameEngine::sRender()
{
	m_renderer.grid(m_grid.grid());
	m_renderer.coordinates(m_grid.coordNumbers());
	m_renderer.update();
}


void GameEngine::sUserInput()
{
  sf::Event event;

  while(m_renderer.renderWindow().pollEvent(event))
  {
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//float x = sf::Mouse::getPosition(m_renderer).x;
				//float y = sf::Mouse::getPosition(m_renderer).y;

				//m_spawner.spawnBullet(x, y);
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
			}
		}

    if(event.type == sf::Event::KeyPressed)
      m_controller.keyPressed(event.key.code);

    if(event.type == sf::Event::KeyReleased)
      m_controller.keyReleased(event.key.code);

    if(event.type == sf::Event::Closed)
      quit();

		m_controller.update();
  }
}