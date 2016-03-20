#!/bin/bash
gcc -o mazegenerator generatorplexer.c io/tui.c io/arquivador.c commons/error.c commons/labirinto.c generators/dfsgenerator.c generators/btreegenerator.c commons/bits.c
#-lncurses
