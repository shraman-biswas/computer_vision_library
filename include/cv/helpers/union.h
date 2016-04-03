#ifndef UNION_H
#define UNION_H

#include <stdlib.h>

#include "../core/core.h"

/* function prototypes */
int *unew(void);
void ufree(int *un);
void uadd(int *un, int val);
void uset(int *un, int n1, int n2);
int uget(int *un, int n);

#endif
