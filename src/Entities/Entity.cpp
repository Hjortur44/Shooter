#include "Entity.h"

Entity::Entity() {}

Entity::Entity(int id) : m_id(id) {}


const int Entity::getId() const
{
  return m_id;
}
