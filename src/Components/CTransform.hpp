#pragma once

#include "Component.hpp"

class CTransform : public Component
{
public:
  CTransform();
  ~CTransform();

 	const bool active() override;

	void activate(const bool activate) override;

  Vec2 currentPosition  = {0.0f, 0.0f};
  Vec2 previousPosition = {0.0f, 0.0f};
  Vec2 velocity         = {0.0f, 0.0f};

  int angle = 0;

private:
	bool m_alive = false;
};