#pragma once

#include "Component.hpp"

class CLifespan : public Component
{
public:
  CLifespan();
	~CLifespan();

  int remaining = 0;
  int total     = 0;

 	const bool active() override;

	void activate(const bool activate) override;

private:
	bool m_alive = false;
};
