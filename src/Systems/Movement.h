#pragma once

#include "Controls.h"
#include "../Math/Vec2.h"
#include "../MemoryPools/ComponentMemoryPool.h"

#include <iostream>

class Movement
{
public:
  Movement();
  ~Movement();

  void moving();

private:
  CShape&     shape = ComponentMemoryPool::Instance().getComponent<CShape>(0);
  CTransform& trans = ComponentMemoryPool::Instance().getComponent<CTransform>(0);

  Controls m_cont;

  Vec2 momentum = {0, 0};
  Vec2 normal   = {0, 0};
  Vec2 d        = {0, 1};
  Vec2 l        = {-1, 0};
  Vec2 r        = {1, 0};
  Vec2 u        = {0, -1};
};
