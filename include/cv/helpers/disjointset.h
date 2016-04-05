#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <stdlib.h>

#include "../core/core.h"

/* disjoint-set structure */
typedef struct __ds_t {
	int *ds;
	int capacity;
	int total;
} ds_t;

/* function prototypes */
int *dscreate(int size);
void dsfree(int *ds);
void dsadd(int *ds, int d);
void dsunion(int *ds, int s1, int s2);
int dsfind(int *ds, int s);

#endif
