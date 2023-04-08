#include "BulletSpawn.h"

BulletSpawn::BulletSpawn() {}
BulletSpawn::~BulletSpawn() {}

void BulletSpawn::shoot()
{
	if(m_cont.isRequestingShoot())
	{
		m_componentPool.activateNext();
	}

	if(m_cont.isRequestingDestroy())
	{
		m_componentPool.freeUpId();
	}
}