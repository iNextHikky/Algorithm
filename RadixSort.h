#define nmax 100000

int b[nmax + 1];

unsigned bits(unsigned x, int k, int j){
	return (x >> k) & ~(~0 << j);
}

radixsort(int a[], int n){
	int pass, order[2], i, j;
	for(pass = 0; pass < 31; pass++){
		for(j = 0; j < 2; j++)
			order[j] = 0;
		for(i = 1; i <= n; i++)
			order[bits(a[i], pass, 1)]++;
		order[1] = order[0] + order[1];
		for(i = n; i >= 1; i--)
			b[order[bits(a[i], pass, 1)]--] = a[i];
		for(i = 1; i <= n; i++)
			a[i] = b[i];
	}
}

/*
void radixsort(int a[], int n){
	int pass, order[256], i, j;
	for(pass = 0; pass < 4; pass++){
		for(j = 0; j < 256; j++)
			order[j] = 0;
		for(i = 1; i <= n; i++)
			order[bits(a[i], pass * 8, 8)]++;
		for(j = 1; j < 256; j++)
			order[j] = order[j - 1] + order[j];
		for(i = n; i >= 1; i--)
			b[order[bits(a[i], pass * 8, 8)]--] = a[i];
		for(i = 1; i <= n; i++)
			a[i] = b[i];
	}
}
*/
