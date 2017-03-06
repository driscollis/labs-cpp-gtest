#ifndef RAND_GENERATOR_HEADER
#define RAND_GENERATOR_HEADER

#include <cstdlib>

typedef int(*Random)(void);

extern Random generator;

int rnd(int maximum);

#endif // RAND_GENERATOR_HEADER
