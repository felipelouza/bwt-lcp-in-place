#include "utils.h"

/**********************************************************************/
void die(const char* where) {

	printf("Error at %s: %s.\n",where,errno ? strerror(errno) : "errno not set");
	exit(errno?errno:1);
}
 
void dies(const char* where, char* format, ...) {

	int err = errno;
	va_list val;

	printf("Error at %s: %s.\n",where,errno ? strerror(errno) : "errno not set");
	va_start(val,format);
	vprintf(format,val);
	va_end(val);
	printf("\n");

	exit(err ? err : 1);
}
/**********************************************************************/
int print_int(int* A, int n){

	int i;
	for(i=0; i<n; i++)	
		printf("%d) %d\n", i, A[i]);

	printf("\n");

return 0;
}
/**********************************************************************/
int min_range(int* A, int l, int r){


	if(r>l)return 0;

	printf("[l, r] = [%d, %d]\n", l, r);

	int min = INT_MAX;
	int i;
	for(i=l; i<=l; i++)
		min = (A[i]<min?A[i]:min);

	printf("min = %d\n", min);

return min;
}
/**********************************************************************/
