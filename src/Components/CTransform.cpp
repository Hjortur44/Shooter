#include "Components.h"

CTransform::CTransform() {}

CTransform::CTransform(Vec2 position, Vec2 velocityRandom, bool active)
 : currentPosition(position), previousPosition(position), velocityRandom(velocityRandom), active(active) {}