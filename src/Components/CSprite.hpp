#pragma once

#include "Component.hpp"

class CSprite : public Component
{
public:
  CSprite();
  CSprite(bool activate);

	sf::Sprite sprite;

  const bool alive() override;

	void active(const bool activate) override;

	bool isActive = false;
};