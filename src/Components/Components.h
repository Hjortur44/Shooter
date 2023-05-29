#pragma once

#include "../Math/Vec2.h"

class CBoundingBox
{
public:
  CBoundingBox();
  CBoundingBox(const Vec2& dimension, bool activate, bool isCollidable);

  Vec2 dimension     = {0.0f, 0.0f};
  Vec2 halfDimension = {0.0f, 0.0f};

  bool isActive     = false;
  bool isCollidable = false;
};


class CController
{
public:
  CController();
  CController(int keyCount, bool activate);

	Vec2 direction = {0.0f, 0.0f};

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


class CTexture
{
public:
  CTexture();
  CTexture(const std::string& name, bool activate);

	bool isActive = false;

	std::string name = "";
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