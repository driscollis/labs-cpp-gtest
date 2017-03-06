#include "RandGenerator.h"

Random generator;

int rnd(int maximum) {
    return generator() % maximum;
}
