#include "Components.h"

CCollision::CCollision() {}

CCollision::CCollision(bool flag, bool collision, bool activate)
 : flag(flag), collision(collision), isActive(activate) {}