#include "GameEngine.h"

GameEngine::GameEngine()
{
  init();
}


void GameEngine::run()
{
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
	EntityComponentsManager::Instance().update(); // this must be on top

	sUserInput();
	sPhysics();
	sRender();
}


// private
void GameEngine::init()
{
	m_allPlayers = EntityComponentsManager::Instance().entitiesByType("Player");
}

void GameEngine::sPhysics()
{
	m_physics.update();
}


void GameEngine::sRender()
{
	m_renderer.update();
}


void GameEngine::sUserInput()
{
  sf::Event event;

  while(m_renderer.renderWindow().pollEvent(event))
  {
    if(event.type == sf::Event::Closed)
        m_renderer.renderWindow().close();

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//sf::Vector2i m = sf::Mouse::getPosition(m_renderer.renderWindow());
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {}
		}

    if(event.type == sf::Event::KeyPressed)
			m_movement.keyPressed(event.key.code);

    if(event.type == sf::Event::KeyReleased)
			m_movement.keyReleased(event.key.code);
  }

	if(!m_allPlayers.empty())
		m_movement.update(m_allPlayers.at(0));
}