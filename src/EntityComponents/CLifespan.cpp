#include "Components.h"

CLifespan::CLifespan() {}

CLifespan::CLifespan(int total, bool activate) : total(total), remaining(total), isActive(activate) {}
