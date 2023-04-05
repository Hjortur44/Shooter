#pragma once

#include "../Math/Vec2.h"

#include <SFML/Graphics.hpp>

class CBoundingBox
{
  public:
    CBoundingBox() {}

		Vec2 size   = {0, 0};
    bool active = false;
};


class CCollision
{
  public:
    CCollision() {}

		size_t radius = 0;
    bool   active = false;
};


class CLifespan
{

  public:
    CLifespan() {}

    size_t total  = 0;
    bool   active = false;
};


class CShape
{
  public:
    CShape() {}

    sf::CircleShape circle;
		sf::Texture 		texture;
		sf::Color       fill      = {0, 0, 0};
		sf::Color       outline   = {0, 0, 0};
		Vec2            position  = {0, 0};

		size_t          radius    = 0;
		size_t          points    = 0;
		size_t          thickness = 0;
		float 					angle 		= 0.0f;
    bool 						active 	  = false;

		inline void update()
		{
			circle.setRadius(radius);
			circle.setPointCount(points);
			circle.setOrigin(radius, radius);
			circle.setPosition(position.getX(), position.getY());
			circle.setFillColor(fill);
			circle.setOutlineColor(outline);
			circle.setOutlineThickness(thickness);
			circle.setRotation(angle);
			circle.setTexture(&texture);
		}
};


class CTransform
{
  public:
    CTransform() {}

    Vec2 currentPosition   = {0, 0};
    Vec2 previousPosition  = {0, 0};
    Vec2 scale             = {1, 1};
		Vec2 velocityRandom    = {0, 0};
    Vec2 velocityUp        = {0, -1};
    Vec2 velocityLeft      = {-1, 0};
    Vec2 velocityDown      = {0, 1};
    Vec2 velocityRight     = {1, 0};

    bool  active = false;
    float angle  = 0;
};