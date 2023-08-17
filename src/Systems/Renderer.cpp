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

	//coordinateRendering();
	entityRendering();
	//gridRendering();

	m_window.display();
}


void Renderer::windowDim(const Vec2& winDim)
{
	m_winDim = winDim;
}


void Renderer::coordinates(const std::map<std::string, Vec2>& coords)
{
	m_coords = coords;
}


void Renderer::grid(const std::vector<Vec2>& lines)
{
	m_lines = lines;
}


// private
void Renderer::init()
{
  m_window.create(sf::VideoMode(m_winDim.x, m_winDim.y), "Game");
  m_window.setFramerateLimit(60);

	m_font.loadFromFile("../font/arcade_i.TTF");

	m_text.setFont(m_font);
	m_text.setCharacterSize(8);
	m_text.setFillColor(sf::Color::Red);

	m_scene_play.mapNumber(0);
}


void Renderer::coordinateRendering()
{
	for(const auto& [key, value] : m_coords)
	{
		m_text.setString(key);
		m_text.setPosition(value.x, value.y);
	  m_window.draw(m_text);
	}
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


void Renderer::gridRendering()
{
	for(int i = 0; i < m_lines.size(); i += 2)
	{
		Vec2 p0 = m_lines[i];
		Vec2 p1 = m_lines[i + 1];
		sf::Vertex line[] = {sf::Vector2f(p0.x,p0.y), sf::Vector2f (p1.x,p1.y)};
    m_window.draw(line, 2, sf::Lines);
	}
}