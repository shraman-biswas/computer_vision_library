#include "blob.h"

static void update(int *ids, int l1, int l2)
{
	int p=-1, val=-1;
	if (l1 == l2) {
		return;
	} else if (l1 < l2) {
		p = l2;
		val = l1;
	} else if (l2 < l1) {
		p = l1;
		val = l2;
	}

	while ((ids[p] >= 0) && (ids[p] != val))
		p = ids[p];
	ids[p] = val;
}

/* TODO: optimize code */
/* labelled connected components algorithm */
MAT *cv_conncomp(const MAT *m, int bg)
{
	if (!m)
		cv_error("cv_conncomp: source matrix not provided!\n");
	int i, j, cnt=1;
	double pixel=0;
	MAT *res = gsl_matrix_calloc(m->size1, m->size2);

	/* new vars */
	int ids[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	double label1, label2;

	/* pass 1 */
	for (i=1; i< m->size1-1; ++i) {
		for (j=1; j< m->size2-1; ++j) {
			pixel = MGET(m, i, j);
			if (!bg && !pixel)
				continue;
			if (pixel == MGET(m, i, j-1)) {
				MSET(res, i, j, MGET(res, i, j-1));
				/* when set left, look up */
				if (pixel == MGET(m, i-1, j)) {
					label1 = MGET(res, i, j);
					label2 = MGET(res, i-1, j);
					update(ids, (int)label1, (int)label2);
				}
				/* */
			} else if (pixel == MGET(m, i-1, j)) {
				MSET(res, i, j, MGET(res, i-1, j));
			} else {
				MSET(res, i, j, cnt++);
			}
		}
	}

	/* debug ids */
	//for (i=0; i<10; ++i)
	//	printf("ids[%i] = %d\n", i, ids[i]);

	/* pass 2 */
	int p;
	for (i=1; i< m->size1-1; ++i) {
		for (j=1; j< m->size2-1; ++j) {
			p = MGET(res, i, j);
			while (ids[p] >= 0)
				p = ids[p];
			MSET(res, i, j, p);
		}
	}

	return res;
}
