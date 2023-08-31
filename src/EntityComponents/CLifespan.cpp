#include "CLifespan.h"

CLifespan::CLifespan() {}

CLifespan::CLifespan(int total, bool activate) : isActive(activate), remaining(total), total(total) {}
