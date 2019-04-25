#include <string.h>

int naivesearch(char *a, char *p){
	int N = strlen(a), M = strlen(p);
	int i, j;
	for(i = 0; i <= N - M; i++){
		for(j = 0; j < M; j++)
			if(a[i + j] != p[j])
				goto L1;
		return i;
		L1: ;
	}
	return -1;
}
