#include "GameEngine.h"

GameEngine::GameEngine()
{
  init();
}


void GameEngine::run()
{
	m_spawner.spawnOuterWall();

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
	Vec2 window(640, 480);
  m_window.create(sf::VideoMode(window.x, window.y), "Game");
  m_window.setFramerateLimit(60);

	m_font.loadFromFile("/home/hjortur/Documents/Gits/Shooter/font/arcade_i.TTF");
	m_text.setFont(m_font);
	m_text.setCharacterSize(8);
	m_text.setFillColor(sf::Color::Red);
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
				//float x = sf::Mouse::getPosition(m_window).x;
				//float y = sf::Mouse::getPosition(m_window).y;

				//m_spawner.spawnBullet(x, y);
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
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

			shape.rectangle.setPosition(trans.position.x, trans.position.y);
			m_window.draw(shape.rectangle);
		}
	}

	const std::vector<Vec2> grid = m_grid.grid();
	for(int i = 0; i < grid.size(); i += 2)
	{
		Vec2 p0 = grid[i];
		Vec2 p1 = grid[i + 1];
		sf::Vertex line[] = {sf::Vector2f(p0.x,p0.y), sf::Vector2f (p1.x,p1.y)};
    m_window.draw(line, 2, sf::Lines);
	}

	for(const auto& [key, value] : m_grid.numbers())
	{
		m_text.setString(key);
		m_text.setPosition(value.x, value.y);
	  m_window.draw(m_text);
	}

	m_window.display();
}
