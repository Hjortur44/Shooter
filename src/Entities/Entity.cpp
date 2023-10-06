#include "Entity.h"

Entity::Entity() {}

Entity::Entity(const size_t id) : m_id(id) {}

const bool Entity::active() const
{
	return m_isActive;
}


const size_t Entity::id() const
{
  return m_id;
}


void Entity::active(bool active)
{
	m_isActive = active;
}


bool Entity::operator == (const Entity& e) const
{
  return m_id == e.id();
}


bool Entity::operator != (const Entity& e) const
{
  return m_id != e.id();
}