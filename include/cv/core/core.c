#include "core.h"

/* create image matrix from image pixel data */
MAT *cv_imcreate(const double *data, int rows, int cols)
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
void cv_imprint(const MAT *m)
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

/* convert 1d array to 2d array */
void cv_to2d(const MAT *m, double **data)
{
	if (!m)
		cv_error("cv_to2d: input matrix not provided!\n");
	if (!data)
		cv_error("cv_to2d: output data not provided!\n");
	int i, j;
	for (i=0; i< m->size1; ++i) {
		for (j=0; j< m->size2; ++j)
			data[i][j] = MGET(m, i, j);
	}
}

/* error handler */
inline void cv_error(const char *msg)
{
	fputs(msg, stderr);
	exit(EXIT_FAILURE);
}
