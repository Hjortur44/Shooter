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
public:
  CShape();
  CShape(Vec2 shape, Vec2 position, const sf::Texture& texture);

  sf::CircleShape circle;
  sf::Texture     texture;

  bool   active = false;
};


class CTransform
{
public:
  CTransform();
  CTransform(Vec2 velocity);

  Vec2 scale    = {1.0f, 1.0f};
  Vec2 velocity = {0.0f, 0.0f};

  size_t angle = 0;
};
