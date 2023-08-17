#pragma once

#include "../Managers/AssetManager.h"
#include "../Managers/EntityComponentsManager.h"
#include "../Math/Vec2.h"
#include "../Scenes/Scene_Play.h"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <map>
#include <vector>

class Renderer
{
public:
	Renderer(const Vec2 winDim);
	~Renderer();

	sf::RenderWindow& renderWindow();

	void windowDim(const Vec2& winDim);

	void coordinates(const std::map<std::string, Vec2>& coords);

	void grid(const std::vector<Vec2>& lines);

	void update();

private:
	void init();

	void coordinateRendering();
	void entityRendering();
	void gridRendering();

	sf::Font m_font;
  sf::RenderWindow m_window;
	sf::Sprite m_sprite;
	sf::Text m_text;

	Scene_Play m_scene_play;

	Vec2 m_winDim;

	std::map<std::string, Vec2> m_coords;

	std::vector<sf::Texture> m_textures;
	std::vector<Vec2> m_lines;
};