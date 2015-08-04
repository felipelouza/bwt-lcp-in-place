#ifndef LCPH
#define LCPH

#include <string.h>
#include <stdio.h>
#include <limits.h>

#include "utils.h"


int lcp_kasai(char* T, int* SA, size_t n, int* LCP);
int lcp_check(char *T, int *SA, size_t n, int *LCP);


#endif
