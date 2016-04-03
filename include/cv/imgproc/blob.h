#ifndef BLOB_H
#define BLOB_H

#include <stdio.h>
#include <stdlib.h>

#include <gsl/gsl_matrix.h>

#include "../core/core.h"
#include "../helpers/union.h"

/* macros */
#define NONE		0
#define TOP_ONLY	1
#define LEFT_ONLY	2
#define LEFT_AND_TOP	3

/* function prototypes */
MAT *cv_conncomp(const MAT *const m, int bg);

#endif
