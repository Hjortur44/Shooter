#pragma once

#include "../Math/Vec2.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Grid
{
public:
	Grid();
	Grid(const Vec2& window);
	~Grid();

	const std::vector<Vec2> grid();

	const std::map<std::string, Vec2> numbers();

private:
	Vec2 m_window = {640.0f, 480.0f};

	int m_rectSize = 64;
};
