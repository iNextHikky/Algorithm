struct point{
	int x, y;
	double angle;
};

struct segment{
	struct point p1, p2;
};

void quick(struct point a[], int le, int ri){
	int i, j, s;
	double v;
	struct point t;
	s = (le + ri) / 2;
	v = a[s].angle;
	i = le;
	j = ri;
	while(i <= j){
		while(a[i].angle < v)
			i++;
		while(a[i].angle > v)
			j--;
		if(i <= j){
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
	}
	if(le < j)
		quick(a, le, j);
	if(i < ri)
		quick(a, i, ri);
}

int graham(struct point p[], int n){
	int i, m, min;
	struct point t;
	min = 1;
	for(i = 2; i <= n; i++)
		if(p[i].y < p[min].y)
			min = i;
	for(i = 1; i <= n; i++)
		if(p[i].y == p[min].y)
			if(p[i].x > p[min].x)
				min = i;
	t = p[1];
	p[1] = p[min];
	p[min] = t;
	for(i = 1; i <= n; i++)
		p[i].angle = angle(p[1], p[i]);
	quick(p, 1, n);
	p[0] = p[n];
	m = 3;
	for(i = 4; i <= n; i++){
		while(turn(p[m], p[m - 1], p[i]) >= 0)
			m--;
		m++;
		t = p[m];
		p[m] = p[i];
		p[i] = t;
	}
	return m;
}
