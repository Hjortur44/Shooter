#pragma once

#include "../Systems/Spawners/EntitySpawner.hpp"
#include "../Systems/Spawners/MapSpawner.hpp"

class Scene
{
public:
  virtual ~Scene();

	virtual void update() = 0;
};
