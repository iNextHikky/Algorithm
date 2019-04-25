#include <stdio.h>
#define nmax 100000

unsigned bits(unsigned x, int k, int j){
	return (x >> k) & ~(~0 << j);
}

void radix_exchange(int a[], int pass, int p, int q){
	int i, j, t;
	if(p < q && pass >= 0){
		i = p;
		j = q;
		while(i != j){
			while(bits(a[i], pass, 1) == 0 && i < j)
				i++;
			while(bits(a[j], pass, 1) != 0 && i < j)
				j--;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		if(bits(a[q], pass, 1) == 0)
			j++;
		radix_exchange(a, pass - 1, p, j - 1);
		radix_exchange(a, pass - 1, j, q);
	}
}

int main(){
	int a[nmax + 1], n, i;
	n = 0;
	while(scanf("%d", &a[n + 1]) != EOF)
		n++;
	radix_exchange(a, 30, 1, n);
	printf(" %d\n\n", n);
	for(i = 0; i < n; i++)
		printf("%12d\n", a[i]);
}
