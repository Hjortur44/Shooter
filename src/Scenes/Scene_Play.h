#pragma once

#include "Scene.h"

#include "../Managers/AssetManager.h"
#include "../Managers/EntityComponentsManager.h"
#include "../Managers/MapManager.h"
#include "../Math/Vec2.h"
#include "../Systems/Spawner.h"

#include <SFML/Graphics.hpp>

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

class Scene_Play : public Scene
{
public:
  Scene_Play();
  ~Scene_Play();

	void mapNumber(const int number);
  void update();

private:
	Spawner m_spawner;
};
