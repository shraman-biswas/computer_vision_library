#include "disjointset.h"

/* TODO: implement disjoint-set with pointers */

/* create new disjoint-set */
int *dscreate(void)
{
	int *ds = (int *)calloc(100, sizeof(int));
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
	int tmp;
	if (s1 == s2)
		return;
	if (s1 < s2) {
		tmp = s1;
		s1 = s2;
		s2 = tmp;
	}
	while (ds[s1] > s2)
		s1 = ds[s1];
	ds[s1] = s2;
}

/* disjoint-set find parent of set */
int dsfind(int *ds, int s)
{
	while (ds[s] >= 0)
		s = ds[s];
	return s;
}
