#pragma once

#include "Component.hpp"

class CBoundingBox : public Component
{
public:
  CBoundingBox();
 	~CBoundingBox();

  const bool active() override;

	void activate(const bool activate) override;

private:
	bool m_alive = false;
};