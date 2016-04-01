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
MAT *cv_imcreate(const double *const data, int rows, int cols);
void cv_imprint(const MAT *const m);
inline void cv_error(const char *msg);

#endif
