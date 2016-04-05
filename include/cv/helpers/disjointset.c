#include "disjointset.h"

/* create new disjoint-set */
void dscreate(ds_t **ds)
{
	ds_t *tmp = (ds_t *)malloc(sizeof(ds_t));
	if (!tmp)
		cv_error("dscreate: disjoint-set could not be created!\n");

	tmp->items = (int *)malloc(DS_SIZE * sizeof(int));
	if (!tmp->items)
		cv_error("dscreate: items list could not be created!\n");

	tmp->capacity = DS_SIZE;
	tmp->total = 0;
	*ds = tmp;
}

/* destroy disjoint-set */
void dsfree(ds_t **ds)
{
	free((*ds)->items);
	*ds = NULL;
}

/* add new set to disjoint-set */
void dsadd(ds_t *ds, int set)
{
	if (ds->total == ds->capacity)
		ds->items = (int *)realloc(ds->items, ds->capacity * 2);
	if (!ds->items)
		cv_error("dsadd: items list could not be extended!\n");

	ds->items[set] = -1;
	ds->capacity *= 2;
	ds->total++;
}

/* create disjoint-set union between sets s1 and s2 */
void dsunion(ds_t *ds, int set1, int set2)
{
	int p1, p2;
	p1 = dsfind(ds, set1);
	p2 = dsfind(ds, set2);
	if (p1 == p2)
		return;
	/* union by size optimization */
	/* uses negative ranking */
	if (ds->items[p1] <= ds->items[p2]) {
		ds->items[p1] += ds->items[p2];
		ds->items[p2] = p1;
	} else {
		ds->items[p2] += ds->items[p1];
		ds->items[p1] = p2;
	}
}

/* disjoint-set find parent of set */
int dsfind(ds_t *ds, int set)
{
	int tmp, i = set;
	while (ds->items[set] >= 0)
		set = ds->items[set];
	/* path compression optimization */
	while (ds->items[i] >= 0) {
		tmp = i;
		i = ds->items[i];
		ds->items[tmp] = set;
	}
	return set;
}
