#include "Components.h"

CTransform::CTransform() {}

CTransform::CTransform(Vec2 position, Vec2 velocityRandom)
 : currentPosition(position), previousPosition(position), velocityRandom(velocityRandom) {}