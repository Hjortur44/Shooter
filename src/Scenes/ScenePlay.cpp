#include "ScenePlay.hpp"

ScenePlay::ScenePlay() {}

ScenePlay::~ScenePlay() {}

void ScenePlay::update() {}

void ScenePlay::mapNumber(const int number)
{
	int num = 1;

	MapSpawner msp;
	msp.update(num);

	EntitySpawner esp;
	esp.update(num);
}