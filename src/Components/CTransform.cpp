#include "Components.h"

CTransform::CTransform() {}

CTransform::CTransform(const Vec2& position, const Vec2& velocity, bool active)
 : position(position), velocity(velocity), active(active) {}