#include "blob.h"

/* union add */
static void uadd(int *ids, int l1, int l2)
{
	double tmp;
	if (l1 == l2)
		return;
	if (l1 < l2) {
		tmp = l1;
		l1 = l2;
		l2 = tmp;
	}
	while (ids[l1] > l2)
		l1 = ids[l1];
	ids[l1] = l2;
}

/* union find */
inline static int ufind(int *ids, int l)
{
	while (ids[l] >= 0)
		l = ids[l];
	return l;
}

/* labelled connected components algorithm */
MAT *cv_conncomp(const MAT *m, int bg)
{
	if (!m)
		cv_error("cv_conncomp: source matrix not provided!\n");

	int b1, b2, i, j, k=1;
	double px;
	MAT *res = gsl_matrix_calloc(m->size1, m->size2);

	/* union array of label ids */
	int ids[100] = {-1};

	/* pass 1 */
	for (i=1; i< m->size1-1; ++i) {
		for (j=1; j< m->size2-1; ++j) {
			px = MGET(m, i, j);		/* current pixel */
			if (!bg && !px)
				continue;
			b1 = (px == MGET(m, i, j-1));	/* check left pixel */
			b2 = (px == MGET(m, i-1, j));	/* check up pixel */
			switch ((b1 << 1) | b2) {
			case NONE:
				ids[k] = -1;
				MSET(res, i, j, k++);
				break;
			case TOP_ONLY:
				MSET(res, i, j, MGET(res, i-1, j));
				break;
			case LEFT_AND_TOP:
				uadd(ids, MGET(res, i, j-1), MGET(res, i-1, j));
			case LEFT_ONLY:
				MSET(res, i, j, MGET(res, i, j-1));
				break;
			}
		}
	}

	/* pass 2 */
	for (i=1; i< m->size1-1; ++i) {
		for (j=1; j< m->size2-1; ++j)
			MSET(res, i, j, ufind(ids, MGET(res, i, j)));
	}

	return res;
}
