#include "Components.h"

CBoundingBox::CBoundingBox() {}

CBoundingBox::CBoundingBox(const Vec2& dimension, bool active)
	: dimension(dimension), halfDimension(dimension.x / 2, dimension.y / 2), active(active) {}
