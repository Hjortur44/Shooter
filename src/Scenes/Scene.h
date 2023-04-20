#pragma once

#include "../Math/Vec2.h"
#include "../Systems/Action.h"

#include <iostream>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

typedef std::map<int, std::string> ActionMap;

class Scene
{
public:
  Scene();
  ~Scene();

  const ActionMap& getActionMap() const;

  bool hasEnded() const;

  int currentFrame() const;
  int height() const;
  int width() const;

  void drawLine(const Vec2& p1, const Vec2 p2);
  void registerAction(int inputKey, const std::string& actionName);
  void simulate(const int frames);

  virtual void sDoAction(const Action& action) = 0;
  virtual void sRender()                       = 0;
  virtual void update()                        = 0;

protected:
  virtual void onEnd() = 0;

  void setPaused(bool paused);

  ActionMap m_actionMap;

  bool m_isPaused = false;
  bool m_hasEnded = false;

  int m_currentFrame = 0;
};
