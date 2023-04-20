#include "Components.h"

CTransform::CTransform() {}

CTransform::CTransform(const Vec2& velocity, bool active) : velocity(velocity), active(active) {}