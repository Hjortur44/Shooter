#pragma once

#include <cstddef>

class Entity
{
  int m_id = 0;

public:
  Entity();
  Entity(int id);

  const int getId() const;
};
