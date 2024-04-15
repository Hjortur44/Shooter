#pragma once

#include "Component.hpp"

#include <SFML/Graphics.hpp>

class CSprite : public Component
{
public:
  CSprite();
  ~CSprite();

	sf::Sprite sprite;

 	const bool active() override;

	void activate(const bool activate) override;

private:
	bool m_alive = false;
};