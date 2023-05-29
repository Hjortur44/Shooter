#include "Components.h"

CTransform::CTransform() {}

CTransform::CTransform(const Vec2& position, const Vec2& velocity, bool activate)
 : currentPosition(position), previousPosition(position), velocity(velocity), isActive(activate) {}