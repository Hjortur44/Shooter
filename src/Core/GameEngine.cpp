#include "GameEngine.h"

GameEngine::GameEngine()
{
  init();
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
	EntityManager::Instance().update(); // this must be on top

	sUserInput();
	m_movement.update();
	m_physics.update();

  sRender();
}


// private
void GameEngine::init()
{
  m_window.create(sf::VideoMode(640, 480), "Game");
  m_window.setFramerateLimit(60);
}


void GameEngine::sUserInput()
{
  sf::Event event;

  while(m_window.pollEvent(event))
  {
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m_spawner.spawnEntity("Bullet");
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				m_spawner.spawnEntity("Player");
			}
		}

    if(event.type == sf::Event::KeyPressed)
      Input::Instance().keyPressed(event.key.code);

    if(event.type == sf::Event::KeyReleased)
      Input::Instance().keyReleased(event.key.code);

    if(event.type == sf::Event::Closed)
      quit();
  }
}


void GameEngine::sRender()
{
  m_window.clear();

	for(const std::string& type : EntityManager::Instance().types())
	{
		for(Entity e : EntityManager::Instance().entitiesByType(type))
		{
			CShape&     shape = e.getComponent<CShape>();
			CTransform& trans = e.getComponent<CTransform>();

			shape.circle.setPosition(trans.position.x, trans.position.y);
			m_window.draw(shape.circle);
		}
	}

	m_window.display();
}
