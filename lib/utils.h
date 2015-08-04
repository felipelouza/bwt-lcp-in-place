#ifndef UTILS_H
#define UTILS_H

#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef UCHAR_SIZE
#define UCHAR_SIZE 256
#endif

#define END_MARKER '$'

/**********************************************************************/

#define swap(a,b) do { typeof(a) aux_a_b = (a); (a) = (b); (b) = aux_a_b; } while (0)

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

void die(const char* where);
void dies(const char* where, char* format, ...);

int print_int(int* A, int n);
int min_range(int* A, int l, int r);

/**********************************************************************/

#endif
