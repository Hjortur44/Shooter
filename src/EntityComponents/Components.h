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


class CCollision
{
public:
  CCollision();
 	CCollision(bool flag, bool collision, bool activate);

	bool collisionL = false;
	bool collisionR = false;
	bool collisionU = false;
	bool collisionD = false;

	bool collision = false;
	bool flag      = false;
	bool isActive  = false;
};


class CController
{
public:
  CController();
  CController(int keyCount, bool activate);

	// If x and y == 0 => stop.
  // If x < 0 => up, else down.
	// If y < 0 => left, else right.
	// If x != 0 and y != 0 => diagonal.
	Vec2 directions = {0.0f, 0.0f};

  bool down  = false;
  bool left  = false;
  bool right = false;
  bool up    = false;

	bool isActive = false;

	int keyCount = 0;
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


class CMovement
{
public:
  CMovement();
  CMovement(bool activate);

	const Vec2& diagonal() const;
	const Vec2& down()     const;
	const Vec2& left()     const;
	const Vec2& right()    const;
	const Vec2& up()       const;

	bool isActive = false;

private:
  Vec2 m_diagonal = {0.707106781f, 0.707106781f};
  Vec2 m_down     = {0.0f, 1.0f};
  Vec2 m_left     = {-1.0f, 0.0f};
  Vec2 m_right    = {1.0f, 0.0f};
  Vec2 m_up       = {0.0f, -1.0f};
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