#pragma once

#include "../Math/Vec2.h"

#include <SFML/Graphics.hpp>

class CBoundingBox
{
  public:
    CBoundingBox();
		CBoundingBox(Vec2 size);

		Vec2 size   = {0, 0};
    bool active = false;
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
    CShape(size_t radius, size_t points, Vec2 position, const sf::Color& fill, const sf::Color& outline, size_t thickness, const sf::Texture& texture);

		void update();

    sf::CircleShape circle;
		sf::Texture 		texture;
		sf::Color       fill      = {0, 0, 0};
		sf::Color       outline   = {0, 0, 0};
		Vec2            position  = {0, 0};


		size_t          m_radius    = 0;

		size_t          radius    = 0;
		size_t          points    = 0;
		size_t          thickness = 0;
		size_t 					angle 		= 0.0f;
    bool 						active 	  = false;
};


class CTransform
{
  public:
    CTransform();
    CTransform(Vec2 position, Vec2 velocityRandom);

    Vec2 currentPosition   = {0, 0};
    Vec2 previousPosition  = {0, 0};
    Vec2 scale             = {1, 1};
		Vec2 velocityRandom    = {0, 0};
    Vec2 velocityUp        = {0, -1};
    Vec2 velocityLeft      = {-1, 0};
    Vec2 velocityDown      = {0, 1};
    Vec2 velocityRight     = {1, 0};

    bool  active = false;
    size_t angle  = 0;
};