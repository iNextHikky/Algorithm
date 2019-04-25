#include <stdio.h>

int main(){
	int t;
	extern void initialize;
	extern void enter(char *, int);
	extern int search(char *);
	initialize();
	enter("Copernicus", 1473);
	enter("Galilei", 1564);
	enter("Newton", 1643);
	enter("Maxwell", 1831);
	enter("Einstein", 1879);
	enter("Heisenberg", 1901);
	t = search("Newton");
	printf("%d\n", t);
}
