#include <stdio.h>
//#include <limits.h>
#define nmax 10000

void select_sort(int a[], int n){
	int i, j, min, t;
	for(i = 1; i < n; i++){
		min = i;
		for(j = i + 1; j <= n; j++)
			if(a[j] < a[min])
				min = j;
		t = a[min];
		a[min] = a[i];
		a[i] = t;
	}
}

/*
void select_sort{
	register int *i, *j, *min;
	int t;
	a[n + 1] = INT_MAX;
	for(i = &a[i]; *i != INT_MAX; i++){
		min = i;
		for(j = i + 1; j != INT_MAX; j++)
			if(*j < *min)
				min = j;
		t = *min;
		*min = *i;
		*i = t;
	}
}
*/

int main(){
	int a[nmax + 1], n, i;
	n = 0;
	while(scanf("%d", &a[n + 1]) != EOF)
		n++;
	select_sort(a, n);
	printf("%d\n", n);
	for(i = 1; i <= n; i++)
		printf("%12d\n", a[i]);
}
