#pragma once

#include <cstddef>

class Entity
{
	size_t m_id = 0;

	public:
		Entity();
		Entity(size_t id);

		const size_t getId() const;
};