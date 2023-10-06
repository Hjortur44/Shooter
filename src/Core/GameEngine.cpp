#include "GameEngine.h"

GameEngine::GameEngine()
{
  init();
}


GameEngine::~GameEngine() {}

void GameEngine::run()
{
  while(m_renderer.renderWindow().isOpen())
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
				Input::Instance().keyPressed(event.key.code);

		  if(event.type == sf::Event::KeyReleased)
				Input::Instance().keyReleased(event.key.code);
		}

		m_physics.update();
		m_renderer.update();
  }
}


// private
void GameEngine::init() {}