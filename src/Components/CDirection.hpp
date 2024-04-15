#pragma once

#include "Component.hpp"

class CDirection : public Component
{
public:
  CDirection();
 	~CDirection();

  bool diagonal = false;
  bool down = false;
  bool left = false;
  bool right = false;
  bool up = false;

  const bool active() override;

	void activate(const bool activate) override;

private:
	bool m_alive = false;
};