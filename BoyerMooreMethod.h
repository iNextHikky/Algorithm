#include <string.h>
#define NMAX 100

int table1[256];
int table2[NMAX];

int bmsearch(char *a, char *p){
	int N = strlen(a), M = strlen(p);
	int i, j;
	extern void inittable1(char *);
	extern void inittable2(char *);
	inittable1(p);
	inittable2(p);
/*
	for(j = 0; j < M; j++)
		printf(" %d", table2[j]);
	printf("\n");
*/
	i = M - 1;
	do{
		j = M - 1;
		while(j >= 0){
			if(a[i] != p[j])
				break;
			i--;
			j--;
		}
		if(j >= 0)
			if(table1[a[i]] > table2[j]])
				i = i + table[a[i]];
			else
				i = i + table2[j];
	}
	while(i < N && j >= 0);
	if(j < 0)
		return i + 1;
	else
		return -1;
}

void inittable1(char *p){
	int M = strlen(p), j, c;
	for(c = 0; c < 256; c++)
		table1[c] = M;
	for(j = 0; j < M; j++)
		table1[p[j]] = M - j - 1;
}

void inittable2(char *p){
	int g[NMAX];
	int M = strlen(p);
	int j, k, s;
	for(j = 0; j < M; j++)
		table2[j] = 2 * M - j - 1;
	j = M;
	for(k = M - 1; k >= 0; k--){
		g[k] = j;
		while(j < M){
			if(p[k] == p[j])
				break;
			if(table2[j] > M - k - 1)
				table2[j] = M - k - 2;
			j = g[j];
		}
		j--;
	}
	s = j;
	for(j = 0; j < M; j++){
		if(table2[j] > s + M + j)
			table2[j] = s + M - j;
		if(j >= s)
			s = g[s];
	}
}
