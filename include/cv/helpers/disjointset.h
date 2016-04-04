#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <stdlib.h>

#include "../core/core.h"

/* macros */
#define DSMAX	100

/* function prototypes */
int *dscreate(void);
void dsfree(int *ds);
void dsadd(int *ds, int d);
void dsunion(int *ds, int s1, int s2);
int dsfind(int *ds, int s);

#endif
