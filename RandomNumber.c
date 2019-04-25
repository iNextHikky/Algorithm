#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i, x;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		x = rand();
		printf("%12d\n",x);
	}
}
