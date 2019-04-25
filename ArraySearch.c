#include <stdio.h>
#define N 7

int linsearch(int x, int v[], int n){
	int p = 0;
	while(p < n){
		if(v[p] == x)
			break;
		p++;
	}
	if(p < n)
	       	return p;
	else
		return -1;
}

/*
int binsearch(int x, int v[], int n){
	int p, q, m;
	p = 0;
	q = n - 1;
	while(p <= q){
		m = (p + q) / 2;
		if(x < v[m])
			q = m - 1;
		else if(x > v[m])
			p = m + 1;
		else
			return m;
	}
	return -1;
}
*/

int main(){
	int a[N], i ,t;
	for(i = 0; i < N; i++)
		scanf("%d", a + i);
	scanf("%d", &t);
	printf("%d \n", linsearch(t, a, N));
}
