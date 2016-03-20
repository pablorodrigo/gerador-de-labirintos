#ifndef GENERATOR_H
#define GENERATOR_H

#include "labirinto.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DEAD_END 0
#define NORTE 1
#define SUL 2
#define OESTE 4
#define LESTE 8


void dfsGenerate(Labirinto l);
void btreeGenerate(Labirinto l);

#endif
