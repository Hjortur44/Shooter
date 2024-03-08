#pragma once

#include <iostream>

class Entity
{
public:
  Entity(const size_t id);

	const size_t id() const;

private:
  size_t m_id = 0;
};
