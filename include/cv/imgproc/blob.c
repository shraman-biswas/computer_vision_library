#include "blob.h"

/* flood fill a row of pixels */
static void floodrow(const MAT *m, MAT *res, int i, int j, double label)
{
	int k=j;
	/* fil starting pixel */
	MSET(res, i, j, label);
	/* fill left pixels */
	while ((--k > 0) && (MGET(m, i, k) == MGET(m, i, k+1)))
		MSET(res, i, k, label);
	/* fill right pixels */
	k = j;
	while ((++k < m->size2) && (MGET(m, i, k) == MGET(m, i, k-1)))
		MSET(res, i, k, label);
}

/* labelled connected components algorithm */
MAT *cv_conncomp(const MAT *m, int bg)
{
	if (!m)
		cv_error("cv_conncomp: source matrix not provided!\n");
	int i, j, cnt=1;
	double label, pixel=0;
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
	for (i=m->size1-2; i>0; --i) {
		for (j=m->size2-2; j>0; --j) {
			pixel = MGET(m, i, j);
			if (!bg && !pixel)
				continue;
			if ((MGET(res, i, j) !=
				(label = MGET(res, i+1, j))) &&
				(pixel == MGET(m, i+1, j))) {
				floodrow(m, res, i, j, label);
			}
		}
	}

	return res;
}
