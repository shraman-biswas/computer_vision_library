#include "disjointset.h"

/* TODO: implement disjoint-set with a forest */

/* create new disjoint-set */
int *dscreate(void)
{
	int *ds = (int *)calloc(DSMAX, sizeof(int));
	if (!ds)
		cv_error("dscreate: disjoint-set could not be created!\n");
	return ds;
}

/* destroy disjoint-set */
void dsfree(int *ds)
{
	free(ds);
}

/* add new set to disjoint-set */
void dsadd(int *ds, int s)
{
	ds[s] = -1;
}

/* create disjoint-set union between sets s1 and s2 */
void dsunion(int *ds, int s1, int s2)
{
	int p1, p2;
	p1 = dsfind(ds, s1);
	p2 = dsfind(ds, s2);
	if (p1 == p2)
		return;
	/* union by rank optimization */
	/* uses negative ranking */
	if (ds[p1] < ds[p2]) {
		ds[p2] = p1;
	} else if (ds[p1] > ds[p2]) {
		ds[p1] = p2;
	} else {
		ds[p2] = p1;
		ds[p1]--;
	}
}

/* disjoint-set find parent of set */
int dsfind(int *ds, int s)
{
	int tmp, i = s;
	while (ds[s] >= 0)
		s = ds[s];
	/* path compression optimization */
	while (ds[i] >= 0) {
		tmp = i;
		i = ds[i];
		ds[tmp] = s;
	}
	return s;
}
