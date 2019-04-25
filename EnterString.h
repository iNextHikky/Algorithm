#include <stdlib.h>
#include <stdio.h>
#define CHARMAX 10000

static int chartop = 0;
static int charbtm = CHARMAX;
static char charheap[CHARMAX];

char *enterstring(char *s){
	char *cp;
	int i, j, len, result;
	cp = s;
	len = 0;
	while(*cp++)
		len++;
	len++;
	if(charbtm - chartop < len){
		printf("identifier string buffer overflow.");
		exit(1);
	}
	result = chartop;
	j = chartop;
	chartop += len;
	cp = s;
	for(i = 0; i < len; i++)
		charheap[j++] = (*cp++);
	return (&charheap[result]);
}
