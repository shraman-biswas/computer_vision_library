#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <stdlib.h>

#include "../core/core.h"

/* macros */
#define DS_SIZE	128

/* disjoint-set structure */
typedef struct __ds_t {
	int *items;
	int capacity;
	int total;
} ds_t;

/* function prototypes */
void dscreate(ds_t **ds);
void dsfree(ds_t **ds);
void dsadd(ds_t *ds, int set);
void dsunion(ds_t *ds, int set1, int set2);
int dsfind(ds_t *ds, int set);

#endif
