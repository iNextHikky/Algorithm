#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "BoyerMooreMethod.h"
#define NMAX 15000
#define MMAX 100

int main(int argc, char *argv[]){
	FILE *fp;
	char a[NMAX], p[MMAX];
	int i, j, c, position;
	if(argc != 3){
		printf("arguments error. \n");
		exit(1);
	}
	j = 0;
	while((p[j] = argv[1][j]) != '\0')
		j++;
	if((fp = fopen(argv[2], "r")) == NULL){
		printf("can't open %s. \n", argv[2]);
		exit(1);
	}else{
		i = 0;
		while((c = getc(fp)) != EOF)
			a[i++] = c;
		a[i] = '\0';
		fclose(fp);
	}
	position = naivesearch(a, p);
	printf("%d\n", position);
	position = bmsearch(a, p);
	printf("%d\n", position);
}
