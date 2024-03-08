#pragma once

#include "../../Managers/EntityManager.hpp"
#include "../../Math/Vec2.hpp"

#include <iostream>
#include <string>
#include <vector>

class Spawner
{
public:
  ~Spawner();

	virtual void update(const int number) = 0;
};