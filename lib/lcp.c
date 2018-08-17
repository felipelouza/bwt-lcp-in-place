#include "lcp.h"

/*******************************************************************/

int find_inverse(int* SA, int n, int* A){
	
	int i;
	for(i = 0; i < n; i++) A[SA[i]] = i;

return 0;
}

int lcp_kasai(char* T, int* SA, size_t n, int* LCP){
	
	int *I = (int* ) malloc(n * sizeof(int));
	find_inverse(SA, n, I);
	
	int l = 0;
	int j, k, i;
	
	for(i = 0; i < n; i++){

		k = I[i];
	
		if(!k) {
			LCP[k] = 0;
		}
		else{
			
			j = SA[k-1];
			while(T[i+l] == T[j+l] && !(T[i+l] == 0 && T[j+l]==0)){
				l++; 
			}
			
			LCP[k] = l;
			if(T[i+l] == 0 && T[j+l]==0) LCP[k]++;
			if(l>0) l--;
		}
	}	
	
	free(I);

return 0;
}
/*******************************************************************/
int lcp_check(char *T, int *SA, size_t n, int *LCP){
	
	size_t i,j,k;
	int h;

	for(i=1;i<n;i++) {
		
		j=SA[i-1]; k=SA[i];

		/* Compare two consecutive suffixes. */
		for(h=0;j+h<n && k+h<n;h++){
			if(T[j+h]== 0 && T[k+h]==0){++h; break;}
			if(T[j+h]!=T[k+h]) break;
		}
		
		/* LCP incorrect. */
		if(LCP[i]!=h) {
			fprintf(stdout,"isNotLCP! Incorrect LCP value: LCP[%zu]=%d!=%d\n",
			i,LCP[i],h);
			
			for(h=0;j+h<n && k+h<n;h++){
				printf("%d == %d\n", T[j+h], T[k+h]);
				if(T[j+h]!=T[k+h]) break;
			}
			
		return 1;
		}
	}
	
	fprintf(stdout,"lcp: okay!\n");
	
return 0;
}
/*******************************************************************/
