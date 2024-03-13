#pragma once

#include "Component.hpp"

class CBoundingBox : public Component
{
public:
  CBoundingBox();
  CBoundingBox(bool activate);

	const bool alive() override;

  void active(const bool activate) override;

  bool isActive = false;
};