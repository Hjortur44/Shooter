#include "Entity.h"

Entity::Entity() {}

Entity::Entity(size_t id) : m_id(id) {}


const size_t Entity::getId() const
{
	return m_id;
}