#pragma once

#include "../Math/Vec2.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>

class Grid
{
public:
	Grid(const Vec2& window, const int boxSize);
	~Grid();

	const std::vector<Vec2> grid();

	const std::map<std::string, Vec2> coordNumbers();

private:
	Vec2 m_size   = {0.0f, 0.0f};
	Vec2 m_window = {0.0f, 0.0f};

	int m_boxSize = 0;
};
