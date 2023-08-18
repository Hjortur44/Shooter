#pragma once

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

	void update();

private:
	void init();

	void entityRendering();

  sf::RenderWindow m_window;
	sf::Sprite m_sprite;

	Scene_Play m_scene_play;

	Vec2 m_winDim;

	std::vector<sf::Texture> m_textures;
};