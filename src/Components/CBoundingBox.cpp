#include "Components.h"

CBoundingBox::CBoundingBox() {}

CBoundingBox::CBoundingBox(const Vec2& dimension, bool activate, bool isCollidable)
	: dimension(dimension), halfDimension(dimension.x / 2, dimension.y / 2), isActive(activate), isCollidable(isCollidable) {}
