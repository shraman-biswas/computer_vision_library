#ifndef BLOB_H
#define BLOB_H

#include <stdio.h>
#include <stdlib.h>

#include <gsl/gsl_matrix.h>

#include "../core/core.h"

/* function prototypes */
MAT *cv_conncomp(const MAT *const m, int bg);

#endif
