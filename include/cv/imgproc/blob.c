#include "blob.h"

/* labelled connected components algorithm */
void cv_conncomp(const MAT *m, MAT **res, int bg)
{
	if (!m)
		cv_error("cv_conncomp: source matrix not provided!\n");

	/* create result matrix */
	*res = gsl_matrix_calloc(m->size1, m->size2);
	if (!(*res))
		cv_error("cv_conncomp: result matrix could not be created!\n");

	int i, j, b1, b2, l1, l2, cnt=1;
	double px;
	ds_t *labels=NULL;

	/* setup disjoint-set of labels */
	ds_create(&labels);
	ds_add(labels, 0);

	/* pass 1 */
	for (i=1; i< m->size1-1; ++i) {
		for (j=1; j< m->size2-1; ++j) {
			px = MGET(m, i, j);		/* current pixel */
			if (!bg && !px)
				continue;
			b1 = (px == MGET(m, i, j-1));	/* check left pixel */
			b2 = (px == MGET(m, i-1, j));	/* check top pixel */
			switch ((b1 << 1) | b2) {
			case NONE:
				ds_add(labels, cnt);
				MSET(*res, i, j, cnt++);
				break;
			case TOP_ONLY:
				MSET(*res, i, j, MGET(*res, i-1, j));
				break;
			case LEFT_AND_TOP:
				l1 = MGET(*res, i, j-1); /* left pixel label */
				l2 = MGET(*res, i-1, j); /* top pixel label */
				if (l1 != l2)
					ds_union(labels, l1, l2);
			case LEFT_ONLY:
				MSET(*res, i, j, MGET(*res, i, j-1));
				break;
			}
		}
	}

	/* pass 2 */
	for (i=1; i< m->size1-1; ++i) {
		for (j=1; j< m->size2-1; ++j)
			MSET(*res, i, j, ds_find(labels, MGET(*res, i, j)));
	}

	ds_free(&labels);
}
