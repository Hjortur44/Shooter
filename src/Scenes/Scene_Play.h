#pragma once

#include "Scene.h"

class Scene_Play : public Scene
{
public:
  Scene_Play(const std::string& levelPath);
  ~Scene_Play();

  void update();
  void onEnd();

  // Systems
  void sMovement();
  void sEnemySpawner();
  void sPlayerSpawner();
  void sCollision();
  void sRender();
  void sDoAction(const Action& action);
  void sDebug();

private:
  void init(const std::string& levelPath);
  void loadLevel(const std::string& levelPath);

  std::string m_levelPath;

  int m_playerId;
};
