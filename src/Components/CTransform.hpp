#pragma once

#include "Component.hpp"

class CTransform : public Component
{
public:
  CTransform();
  CTransform(const Vec2& position, const Vec2& velocity, bool activate);

  const bool alive() override;

	void active(const bool activate) override;

  Vec2 currentPosition  = {0.0f, 0.0f};
  Vec2 previousPosition = {0.0f, 0.0f};
  Vec2 velocity         = {0.0f, 0.0f};

	bool isActive = false;

  int angle = 0;
};