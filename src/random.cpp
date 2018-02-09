#include "random.h"

#include <ctime>
#include <cstdlib>

void rnd::Init() { srand(time(NULL)); }

int rnd::RandInt() { return rand(); }
int rnd::RandInt(int limit) { return rand() % (limit + 1); }                  // Inclusive
int rnd::RandInt(int start, int end) { return RandInt(end - start) + start; } // Inclusive