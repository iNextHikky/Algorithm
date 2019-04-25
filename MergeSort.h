#define nmax 100000

int b[nmax + 1];

mergesort(int a[], int p, int q){
	int i, j, k, m;
	if(p < q){
		m = (p + q) / 2;
		mergesort(a, p, m);
		mergesort(a, m + 1, q);
		for(i = m + 1; i > p; i--)
			b[i - 1] = a[i - 1];
		for(j = m; j < q; j++)
			b[q + m - j] = a[j + 1];
		for(k = p; k <= q; k++)
			a[k] = (b[i] < b[j]) ? b[i++] : b[j--];
	}
}
