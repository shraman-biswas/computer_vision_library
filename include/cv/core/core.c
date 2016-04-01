#include "core.h"

/* create image matrix from image pixel data */
MAT *cv_imcreate(const double *const data, int rows, int cols)
{
	if (!data)
		cv_error("cv_imcreate: matrix data not provided!\n");
	int i, j;
	MAT *m = gsl_matrix_calloc(rows, cols);
	for (i=0; i<rows; ++i) {
		for (j=0; j<cols; ++j)
			MSET(m, i, j, data[i * cols + j]);
	}
	return m;
}

/* print image matrix pixels */
void cv_imprint(const MAT *const m)
{
	if (!m)
		cv_error("cv_imprint: matrix not provided!\n");
	int i, j;
	for (i=0; i< m->size1; ++i) {
		for (j=0; j< m->size2-1; ++j)
			printf("%.0f, ", MGET(m, i, j));
		printf("%.0f\n", MGET(m, i, j));
	}
}

/* error handler */
inline void cv_error(const char *msg)
{
	fputs(msg, stderr);
	exit(EXIT_FAILURE);
}
