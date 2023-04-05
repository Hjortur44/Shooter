#pragma once

#include "Scene.h"

class Scene_Play : public Scene
{
  std::string   m_levelPath;
  size_t        m_playerId;

  void init(const std::string& levelPath);
  void loadLevel(const std::string& levelPath);

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
};