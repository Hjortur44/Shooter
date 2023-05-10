#include "Grid.h"

Grid::Grid() {}
Grid::Grid(const Vec2& window) : m_window(window) {}

Grid::~Grid() {}

const std::vector<Vec2> Grid::grid()
{
	std::vector<Vec2> grid;
	Vec2 size = m_window / m_rectSize;

	for(int i = 0; i < size.y; i++)
	{
		grid.push_back(Vec2(0, m_rectSize * i));
		grid.push_back(Vec2(m_window.x, m_rectSize * i));
	}

	for(int i = 0; i < size.x; i++)
	{
		grid.push_back(Vec2(m_rectSize * i, 0));
		grid.push_back(Vec2(m_rectSize * i, m_window.y));
	}

	return grid;
}


const std::map<std::string, Vec2> Grid::numbers()
{
	std::map<std::string, Vec2> nums;
	Vec2 size = m_window / m_rectSize;

	for(int i = 0; i < size.x; i++)
	{
		for(int j = 0; j < size.y; j++)
		{
			std::string str = "(" + std::to_string(i) + " , " + std::to_string(j) + ")";
			nums[str] = Vec2(i, j) * m_rectSize;
		}
	}

	return nums;
}