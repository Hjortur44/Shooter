#include "Components.h"

CLifespan::CLifespan() {}

CLifespan::CLifespan(size_t total, bool active) : total(total), remaining(total), active(active) {}