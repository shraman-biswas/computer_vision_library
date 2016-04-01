#include "blob.h"

/* labelled connected components algorithm */
MAT *cv_conncomp(const MAT *const m, int bg)
{
	if (!m)
		cv_error("cv_conncomp: source matrix not provided!\n");
	int i, j, cnt=1;
	double label1, label2, pixel=0;
	MAT *res = gsl_matrix_calloc(m->size1, m->size2);

	/* pass 1 */
	for (i=1; i< m->size1-1; ++i) {
		for (j=1; j< m->size2-1; ++j) {
			pixel = MGET(m, i, j);
			if (!bg && !pixel)
				continue;
			if (pixel == MGET(m, i, j-1)) {
				MSET(res, i, j, MGET(res, i, j-1));
			} else if (pixel == MGET(m, i-1, j)) {
				MSET(res, i, j, MGET(res, i-1, j));
			} else {
				MSET(res, i, j, cnt++);
			}
		}
	}

	/* pass 2 */
	for (j= m->size2-2; j>0; --j) {
		for (i= m->size1-2; i>0; --i) {
			pixel = MGET(m, i, j);
			if (!bg && !pixel)
				continue;
			label1 = MGET(res, i, j);
			if ((label1 != (label2 = MGET(res, i+1, j))) &&
				(pixel == MGET(m, i+1, j))) {
				MSET(res, i, j, label2);
			} else if ((label1 != (label2 = MGET(res, i, j+1))) &&
				(pixel == MGET(m, i, j+1))) {
				MSET(res, i, j, label2);
			}
		}
	}

	return res;
}
