#pragma once

#include "../Math/Vec2.h"

#include <SFML/Graphics.hpp>

class CBoundingBox
{
public:
  CBoundingBox();
  CBoundingBox(const Vec2& dimension, bool active);

  Vec2 dimension     = {0.0f, 0.0f};
  Vec2 halfDimension = {0.0f, 0.0f};

  bool active = false;
};


class CCollision
{
public:
	CCollision();
  CCollision(bool active);

	bool active = false;
};


class CLifespan
{
public:
  CLifespan();
  CLifespan(int total, bool active);

  int remaining = 0;
  int total     = 0;

	bool active = false;
};


class CShape
{
public:
  CShape();
  CShape(const Vec2& shape,
				 const Vec2& position,
				 const sf::Texture& texture,
				 bool active);

  sf::RectangleShape rectangle;
  sf::Texture        texture;

	Vec2 position = {0.0f, 0.0f};

  bool active = false;
};


class CTransform
{
public:
  CTransform();
  CTransform(const Vec2& position, const Vec2& velocity, bool active);

  Vec2 position = {0.0f, 0.0f};
  Vec2 velocity = {0.0f, 0.0f};

  int angle = 0;

	bool active = false;
};
