#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <stdlib.h>

#include "../core/core.h"

/* function prototypes */
int *dscreate(void);
void dsfree(int *un);
void dsadd(int *un, int n);
void dsunion(int *un, int n1, int n2);
int dsfind(int *un, int n);

#endif
