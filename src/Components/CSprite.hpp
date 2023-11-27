#pragma once

#include <SFML/Graphics.hpp>

class CSprite
{
public:
  CSprite();
  CSprite(bool activate);

	sf::Sprite sprite;

	bool isActive = false;
};