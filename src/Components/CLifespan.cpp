#include "CLifespan.hpp"

CLifespan::CLifespan() {}

CLifespan::CLifespan(int total, bool activate) : isActive(activate), remaining(total), total(total) {}
