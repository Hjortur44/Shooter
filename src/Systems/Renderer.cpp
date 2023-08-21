#include "Renderer.h"

Renderer::Renderer(const Vec2 winDim) : m_winDim(winDim)
{
	init();
}

Renderer::~Renderer() {}

sf::RenderWindow& Renderer::renderWindow()
{
	return m_window;
}


void Renderer::update()
{
	m_window.clear();

	entityRendering();

	m_window.display();
}


void Renderer::windowDim(const Vec2& winDim)
{
	m_winDim = winDim;
}


// private
void Renderer::init()
{
  m_window.create(sf::VideoMode(m_winDim.x, m_winDim.y), "Game");
  m_window.setFramerateLimit(60);

	//m_font.loadFromFile("../font/arcade_i.TTF");

	m_ScenePlay.mapNumber(0);
}


void Renderer::entityRendering()
{
	EntityComponentsManager& ecManager = EntityComponentsManager::Instance();

	for(const std::string& type : ecManager.types())
	{
		for(Entity e : ecManager.entitiesByType(type))
		{
			CTexture& tex = e.getComponent<CTexture>();
			CTransform& trans = e.getComponent<CTransform>();

			sf::Sprite s(tex.texture);
			s.setPosition(trans.currentPosition.x, trans.currentPosition.y);

		  m_window.draw(s);
		}
	}
}