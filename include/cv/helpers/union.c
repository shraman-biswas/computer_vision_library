#include "union.h"

/* TODO: implement dynamic union structure */
/* create new union structure */
int *unew(void)
{
	int *un = (int *)malloc(100 * sizeof(int));
	if (!un)
		cv_error("unew: union structure could not be created!");
	uadd(un, 0);
	return un;
}

/* destroy union structure */
void ufree(int *un)
{
	free(un);
}

/* add new union structure element */
void uadd(int *un, int n)
{
	un[n] = -1;
}

/* set new union structure link between elements n1 and n2 */
void uset(int *un, int n1, int n2)
{
	int tmp;
	if (n1 == n2)
		return;
	if (n1 < n2) {
		tmp = n1;
		n1 = n2;
		n2 = tmp;
	}
	while (un[n1] > n2)
		n1 = un[n1];
	un[n1] = n2;
}

/* get union structure parent element */
int uget(int *un, int n)
{
	while (un[n] >= 0)
		n = un[n];
	return n;
}
