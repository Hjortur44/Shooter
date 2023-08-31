#pragma once

#include "../Math/Vec2.h"

#include <SFML/Graphics.hpp>

class CTexture
{
public:
  CTexture();
  CTexture(const sf::Texture& texture, bool activate);

	sf::Texture texture;

	bool isActive = false;
};