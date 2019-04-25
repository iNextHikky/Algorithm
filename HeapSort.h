void downheap(int a[], int j, int k){
	int i, v;
	v = a[j];
	while(j <= k / 2){
		i = 2 * j;
		if(i < k && a[i] < a[i + 1])
			i++;
		if(v >= a[i])
			break;
		a[j] = a[i];
		j = i;
	}
	a[j] = v;
}

void heapsort(int a[], int n){
	int j, k, t;
	for(j = n / 2; j >= 1; j--)
		downheap(a, j, n);
	k = n;
	while(k > 1){
		t = a[1];
		a[1] = a[k];
		a[k] = t;
		downheap(a, 1, --k);
	}
}
