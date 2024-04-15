#pragma once

#include "../../Entities/Entity.hpp"
#include "../../Managers/AssetManager.hpp"
#include "../../Managers/EntityManager.hpp"
#include "../../Managers/MapManager.hpp"
#include "../../Math/Vec2.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <vector>

class Spawner
{
public:
  ~Spawner();

	virtual void update(const int number) = 0;
};