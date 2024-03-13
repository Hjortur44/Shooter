#pragma once

#include "Component.hpp"

class CLifespan : public Component
{
public:
  CLifespan();
  CLifespan(int total, bool activate);

	const bool alive() override;

  void active(const bool activate) override;

	bool isActive = false;

  int remaining = 0;
  int total     = 0;
};
