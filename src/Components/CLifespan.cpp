#include "Components.h"

CLifespan::CLifespan() {}

CLifespan::CLifespan(size_t total) : total(total), remaining(total) {}
