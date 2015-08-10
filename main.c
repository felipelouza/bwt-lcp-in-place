#include <stdio.h>

#include "lib/file.h"
#include "lib/utils.h"
#include "lib/bwt.h"
#include "lib/lcp.h"
#include "external/divsufsort-lite/divsufsort.h"

#define DEBUG 0

/*******************************************************************/
int main(int argc, char** argv){

	int i;
	char *T = NULL;//input string

	//input string is read from a file in dir/file
	char* dir = argv[1];
	char* file = argv[2];

	if(argc!=3){
		dies(__func__,"argc!=3");
	}

	file_chdir(dir);

	FILE* f_in = file_open(file, "rb");

	//disk access
	T = file_load(f_in);
	printf("T:\n%s\n\n", T);

	size_t n = strlen(T);

	char* copy = (char*) malloc((n+1)*sizeof(char));
	strcpy(copy, T);	

	int *lcp = (int*) malloc((n+1)*sizeof(int));
	for(i=0; i<n+1;i++) lcp[i]=0;

	/**/
	bwt_lcp_inplace(T, n, lcp);
	printf("bwt(T):\n%s\n\n", T);
	/**/

	#if DEBUG		
		printf("lcp:\n");
		print_int(lcp, n);
	#endif

	//validate
	char* rev = bwt_reverse(T, n);
	if(strcmp(rev, copy)==0) printf("bwt: okay!\n");
	else printf("bwt: error!\n");

	int *sa = (int*) malloc(n*sizeof(int));
	divsufsort((const unsigned char*)copy, sa, n);//Yuta_Mori
	lcp_check(copy, sa, n, lcp);

	//free memory
	free(T);
	free(copy);
	free(rev);
	free(lcp);
	free(sa);

	file_close(f_in);

return 0;
}

