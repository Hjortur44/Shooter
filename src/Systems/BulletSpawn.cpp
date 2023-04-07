#include "BulletSpawn.h"

BulletSpawn::BulletSpawn() {}
BulletSpawn::~BulletSpawn() {}

void BulletSpawn::shoot()
{
	if(m_cont.isRequestingShoot())
	{
		m_spawn.spawnEntity();
	}
}