#include <stdio.h>
//#include <limits.h>
#define nmax 10000

void insert_sort(int a[], int n){
	int i, j, q;
	for(i = 2; i <= n; i++){
		q = a[i];
		j = i;
		while(a[j - 1] > q){
			a[j] = a[j - 1];
			j--;
		}
		a[j] = q;
	}
}

/*
void insert_sort(int a[], int *p[], int n){
	int i, j, *q;
	for(i = 0; i <= n; i++)
		p[i] = &a[i];
	for(i = 2; i <= n; i++){
		q = p[i];
		j = i;
		while(*p[j - 1] > *q){
			p[j] = p[j - 1];
			j--;
		}
		p[j] = q;
	}
}   

int main(){
	int a[nmax + 1], *p[nmax + 1], n, i;
	n = 0;
	while(scanf("%d", &a[n + 1]) != EOF)
		n++;
	a[0] = - INT_MAX;
	insert_sort(a, p, n);
	printf(" %d\n\n", n);
	for(i = 0; i < n; i++)
		printf("%12d\n", *p[i]);
}

*/

int main(){
	int a[nmax + 1], n, i;
	n = 0;
	while(scanf("%d", a[n + 1]) != EOF)
		n++;
	a[0] = -2147483647;
	insert_sort(a, n);
	printf(" %d\n", n);
	for(i = 0; i < n; i++)
		printf("%12d\n", a[i]);
}
