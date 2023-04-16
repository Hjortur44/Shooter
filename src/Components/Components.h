#pragma once

#include "../Math/Vec2.h"

#include <SFML/Graphics.hpp>

class CBoundingBox
{
public:
  CBoundingBox();
  CBoundingBox(size_t sizeX, size_t sizeY);

  size_t sizeX = 0;
  size_t sizeY = 0;
  bool   active = false;
};


class CCollision
{
public:
  CCollision();
  CCollision(size_t radius);

  size_t radius = 0;
  bool   active = false;
};


class CLifespan
{
public:
  CLifespan();
  CLifespan(size_t total);

  size_t total     = 0;
  size_t remaining = 0;
  bool   active    = false;
};


class CShape
{
  sf::CircleShape m_circle;

public:
  CShape();
  CShape(Vec2 shape, Vec2 position, const sf::Texture& texture);

  sf::CircleShape getCircle();

  sf::Texture texture;

  Vec2 position = {0, 0};
  Vec2 shape    = {0, 0};

  size_t angle  = 0;
  bool   active = false;
};


class CTransform
{
public:
  CTransform();
  CTransform(Vec2 velocity);

  Vec2 scale    = {1, 1};
  Vec2 velocity = {0, 0};

  size_t angle = 0;
};
