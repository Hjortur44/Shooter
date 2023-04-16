#pragma once

#include "../Math/Vec2.h"
#include "../Systems/Action.h"

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <memory>
#include <string>
#include <iostream>

typedef std::map<int, std::string> ActionMap;

class Scene
{
protected:
  ActionMap     m_actionMap;

  bool          m_isPaused = false;
  bool          m_hasEnded = false;
  size_t        m_currentFrame = 0;

  virtual void onEnd() = 0;
  void setPaused(bool paused);

public:
  Scene();
  ~Scene();

  virtual void update() = 0;
  virtual void sDoAction(const Action& action) = 0;
  virtual void sRender() = 0;

  size_t width() const;
  size_t height() const;
  size_t currentFrame() const;

  bool hasEnded() const;
  const ActionMap& getActionMap() const;

  void drawLine(const Vec2& p1, const Vec2 p2);
  void simulate(const size_t frames);

  void registerAction(int inputKey, const std::string& actionName);
};
