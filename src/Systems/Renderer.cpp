#include "Renderer.hpp"

Renderer::Renderer()
{
	init();
}

Renderer::~Renderer() {}

bool Renderer::isOpen()
{
	return m_window.isOpen();
}


sf::RenderWindow& Renderer::window()
{
	return m_window;
}


void Renderer::setWindowDimension(const Vec2 dimension)
{
	m_winDim = dimension;
}


void Renderer::update()
{
	m_window.clear();

	eventHandler();

	m_scenePlay.update();
	mapRendering();
	entityRendering();

	m_window.display();
}


// private
void Renderer::entityRendering()
{
	EntityManager& manager = EntityManager::Instance();
	std::vector<CSprite>& sprites = manager.getComponentType<CSprite>();
	std::vector<CTransform>& trans = manager.getComponentType<CTransform>();

	for(size_t i = 0; i < sprites.size(); i++)
	{
		CTransform& tr = trans.at(i);
		Vec2 p = tr.currentPosition;

		CSprite& sp = sprites.at(i);
		sp.sprite.setPosition(p.x, p.y);

		m_window.draw(sp.sprite);
	}
}


void Renderer::eventHandler()
{
	sf::Event event;

	while(m_window.pollEvent(event))
	{
	  if(event.type == sf::Event::Closed)
	      m_window.close();

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//sf::Vector2i m = sf::Mouse::getPosition(m_window);
			}

			if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {}
		}

	  if(event.type == sf::Event::KeyPressed)
			Input::Instance().keyPressed(event.key.code);

	  else if(event.type == sf::Event::KeyReleased)
			Input::Instance().keyReleased(event.key.code);
	}
}


void Renderer::init()
{
  m_window.create(sf::VideoMode(m_winDim.x, m_winDim.y), "Game");
  m_window.setFramerateLimit(60);

	//m_font.loadFromFile("../font/arcade_i.TTF");

	m_scenePlay.mapNumber(0);
}

void Renderer::mapRendering()
{
	MapTileManager& man = MapTileManager::Instance();

	for(CSprite& sp : man.getComponentType<CSprite>())
	{
		m_window.draw(sp.sprite);
	}
}