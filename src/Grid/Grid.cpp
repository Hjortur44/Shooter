#include "Grid.hpp"

Grid::Grid(const Vec2& window, const int boxSize) : m_size(window / boxSize), m_window(window), m_boxSize(boxSize) {}

Grid::~Grid() {}

const std::vector<Vec2> Grid::grid()
{
	std::vector<Vec2> grid;

	for(int i = 0; i < m_size.y; i++)
	{
		grid.push_back(Vec2(0, m_boxSize * i));
		grid.push_back(Vec2(m_window.x, m_boxSize * i));
	}

	for(int i = 0; i < m_size.x; i++)
	{
		grid.push_back(Vec2(m_boxSize * i, 0));
		grid.push_back(Vec2(m_boxSize * i, m_window.y));
	}

	return grid;
}


const std::map<std::string, Vec2> Grid::coordNumbers()
{
	std::map<std::string, Vec2> nums;

	for(int i = 0; i < m_size.y; i++)
	{
		for(int j = 0; j < m_size.x; j++)
		{
			std::string str = std::to_string(i) + ",\n" + std::to_string(j);
			nums[str] = Vec2(j * m_boxSize, i * m_boxSize);
		}
	}

	return nums;
}