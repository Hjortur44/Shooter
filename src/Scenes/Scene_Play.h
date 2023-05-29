#pragma once

#include "Scene.h"

class Scene_Play : public Scene
{
public:
  Scene_Play(const std::string& levelPath);
  ~Scene_Play();

	void spawnEnviroment();

private:
};
