#pragma once

#include "../Entities/Entity.h"
#include "../Managers/AssetManager.h"
#include "../Managers/ConfigurationManager.h"
#include "../Managers/EntityManager.h"
#include "../Math/Vec2.h"

#include <iostream>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

class Spawner
{
public:
  Spawner();
  ~Spawner();

  void spawnEntity(const std::string& type);
};
