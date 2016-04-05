#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <stdlib.h>

#include <gsl/gsl_matrix.h>

/* macros */
#define MAT			gsl_matrix
#define MGET(m, i, j)		gsl_matrix_get((m), (i), (j))
#define MSET(m, i, j, x)	gsl_matrix_set((m), (i), (j), (x))

/* function prototypes */
void cv_imcreate(MAT **m, const double *data, int rows, int cols);
void cv_imprint(const MAT *m);
void cv_to2d(const MAT *m, double **data);
inline void cv_error(const char *msg);

#endif
