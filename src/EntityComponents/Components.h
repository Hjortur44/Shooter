#pragma once

#include "../Math/Vec2.h"

#include <SFML/Graphics.hpp>

class CBoundingBox
{
public:
  CBoundingBox();
  CBoundingBox(bool activate);

  bool isActive = false;
};


class CLifespan
{
public:
  CLifespan();
  CLifespan(int total, bool activate);

	bool isActive = false;

  int remaining = 0;
  int total     = 0;
};


class CTexture
{
public:
  CTexture();
  CTexture(const sf::Texture& texture, bool activate);

	sf::Texture texture;

	bool isActive = false;
};

class CTransform
{
public:
  CTransform();
  CTransform(const Vec2& position, const Vec2& velocity, bool activate);

  Vec2 currentPosition  = {0.0f, 0.0f};
  Vec2 previousPosition = {0.0f, 0.0f};
  Vec2 velocity         = {0.0f, 0.0f};

	bool isActive = false;

  int angle = 0;
};