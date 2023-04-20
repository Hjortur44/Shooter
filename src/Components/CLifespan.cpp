#include "Components.h"

CLifespan::CLifespan() {}

CLifespan::CLifespan(int total, bool active) : total(total), remaining(total), active(active) {}
