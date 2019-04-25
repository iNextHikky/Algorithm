#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define NMAX 100

int max(int u, int v){
	if(u >= v)
		return u;
	else
		return v;
}

void simplelcs(char *a, char *b){
	int m, n, i, j;
	int p[NMAX][NMAX], rec[NMAX];
	m = strlen(a) - 1;
	n = strlen(b) - 1;
	for(i = 0; i <= m; i++)
		p[i][0] = 0;
	for(j = 0; j <= n; j++)
		p[0][j] = 0;
	for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++){
			if(a[i] == b[j])
				p[i][j] = p[i - 1][j - 1] + 1;
			else
				p[i][j] = max(p[i][j - 1], p[i - 1][j]);
		}
	for(i = 1; i <= m; i++)
		rec[i] = 0;
	i = m;
	j = n;
	while(i >= 1 && j >= 1){
		if(a[i] == b[j]){
			rec[i] = 1;
			i--;
			j--;
		}else{
			if(p[i][j] == p[i - 1][j])
				i--;
			else
				j--;
		}
	}
	printf("	%s\n	%s\n lcs   = ", a, b);
	for(i = 1; i < m; i++)
		if(rec[i] == 1)
			printf("%c", a[i]);
	printf("\n length = %d\n", p[m][n]);
}

main(int args, char *argv[]){
	char a[NMAX], b[NMAX];
	int i;
	if(argc != 3){
		printf("arguments error.\n");
		exit(1);
	}	
	a[0] = ' ';
	b[0] = ' ';
	i = 1;
	while((a[i] = argv[1][i - 1]) != '\0')
		i++;
	i = 1;
	while((b[i] = argv[2][i - 1]) != '\0')
		i++;
	simplelcs(a, b);
}
