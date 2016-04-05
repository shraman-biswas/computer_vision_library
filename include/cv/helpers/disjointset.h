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
void ds_create(ds_t **ds);
void ds_free(ds_t **ds);
void ds_add(ds_t *ds, int set);
void ds_union(ds_t *ds, int set1, int set2);
int ds_find(ds_t *ds, int set);

#endif
