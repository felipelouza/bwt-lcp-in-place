#include "bwt.h"

#define DEBUG 0

/*******************************************************************/

int rank(char *T, char c, int i){

	int sum=0;
	int j;

	for(j=0; j<i; j++) if(T[j] <= c) sum++;
	for(; j<strlen(T); j++) if(T[j] < c) sum++;

return sum;
}

/*******************************************************************/

int bwt_lcp_inplace(char *T, int n, int *LCP){

	int i, p, r=1, s;
	int p_a1, p_b1, l_a, l_b;
	LCP[n-1] = LCP[n-2] = 0;//base case

	for(s=n-3; s>=0; s--){
	
		/*steps 1 and 2*/
		p=r+1;
		for(i=s+1, r=0; T[i]!=END_MARKER; i++)if(T[i]<=T[s])r++;
		for(; i<n; i++) if(T[i]<T[s])r++;
		
		/*steps 2'*/
		p_a1=p+s-1;
		l_a=LCP[p_a1+1];
		while(T[p_a1]!=T[s])//RMQ function
			if(LCP[p_a1--]<l_a) l_a=LCP[p_a1+1];
		if(p_a1==s) l_a=0;
		else l_a++;
		
		/*steps 2''*/
		p_b1=p+s+1;
		l_b=LCP[p_b1];
		while(T[p_b1]!=T[s] && p_b1<n) //RMQ function
			if(LCP[++p_b1]<l_b) l_b=LCP[p_b1];
		if(p_b1==n) l_b=0;
		else l_b++;
		
		/*steps 3 and 4*/
		T[p+s]=T[s];
		for(i=s; i<s+r; i++){
			T[i]=T[i+1];
			LCP[i]=LCP[i+1];
		}
		T[s+r]=END_MARKER;
		
		/*steps 4'*/
		LCP[s+r]=l_a;
		if(s+r+1<n)//If r+1 is not the last position
			LCP[s+r+1]=l_b;
		
		#if DEBUG
			printf("%c|%s\n", T[s], &T[s+1]);
			printf("lcp:\n");
			print_int(&LCP[s], n-s);
		#endif			
	}

return 0;
}

/*******************************************************************/

int bwt_inplace(char *T, int n){

	int p, r=1;
	int i, s;

	for(s=n-3; s>=0; s--){

		p = r+1;//	p = find_sentinel(&T[s]);
		r = rank(&T[s+1], T[s], p);
	
		T[p+s] = T[s]; //replace('$', T[s]);

		for(i=s; i<s+r; i++) 
			T[i] = T[i+1];

		T[s+r] = END_MARKER;
	}

return 0;
}

/*******************************************************************/

int bwt_lyndon_inplace(char *T, int n, int *LA){

	int p, r=1;
	int i, s;

	LA[n-1]=LA[n-2]=1;

	for(s=n-3; s>=0; s--){

		p = r+1;//	p = find_sentinel(&T[s]);
		r = rank(&T[s+1], T[s], p);
	
		T[p+s] = T[s]; //replace('$', T[s]);

		for(i=s; i<s+r; i++) 
			T[i] = T[i+1];

		T[s+r] = END_MARKER;
	}

return 0;
}
/*******************************************************************/

char* bwt_reverse(char *bwt, int n){

	char* rev = (char*) malloc((n+1)*sizeof(char));
	int p = 0;

	//backward reconstruction
	int s;
	for(s=n-2; s>=0; s--){

		rev[s] = bwt[p];
		p = rank(bwt, rev[s], p);
	}

	rev[n-1] = END_MARKER;
	rev[n] = '\0';

return rev;
}
/*******************************************************************/

void get_count(char* T, int *C){

	int i;
	for(i=0; i<UCHAR_SIZE; i++) C[i]=0;
	for(i=0; i<strlen(T); i++) C[T[i]]++;	
}

void get_bucket(int *C, int *B){

	int sum=0;
	int i;
	for(i=0; i<UCHAR_SIZE; i++){
			B[i] = sum;
			sum+=C[i];
	}
}

int find_sentinel(char *T){

	int i;
	for(i=0; i<strlen(T); i++)
		if(T[i] == END_MARKER) return i;

return -1;
}
/*******************************************************************/
