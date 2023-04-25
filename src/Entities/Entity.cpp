#include "Entity.h"

Entity::Entity() {}

Entity::Entity(const size_t id) : m_id(id) {}

const size_t Entity::id() const
{
  return m_id;
}