#pragma once

#include "../Managers/EntityManager.hpp"
#include "../Math/Vec2.hpp"
#include "../Scenes/ScenePlay.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <map>
#include <vector>

class Renderer
{
public:
	Renderer();
	~Renderer();

	bool isOpen();

	sf::RenderWindow& window();

	void setWindowDimension(const Vec2 dimension);
	void update();

private:
	void eventHandler();
	void entityRendering();
	void init();
	void mapRendering();

  sf::RenderWindow m_window;

	ScenePlay m_scenePlay;

	Vec2 m_winDim = {640.0f, 480.0f};
};