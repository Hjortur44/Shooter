#pragma once

class CLifespan
{
public:
  CLifespan();
  CLifespan(int total, bool activate);

	bool isActive = false;

  int remaining = 0;
  int total     = 0;
};
