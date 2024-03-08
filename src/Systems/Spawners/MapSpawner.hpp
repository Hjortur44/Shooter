#pragma once

#include "Spawner.hpp"

class MapSpawner : public Spawner
{
public:
	MapSpawner();
	~MapSpawner();

 	void update(const int number) override;
};