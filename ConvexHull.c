#include <stdio.h>
#include <math.h>

struct point{
	int x, y;
};

double angle(struct point q1, struct point q2){
	int dx, dy;
	double a = 0.0;
	dx = q2.x - q1.x;
	dy = q2.y - q1.y;
	if(dx != 0 || dy != 0)
		a = (double) dy / (double)(abs(dx) + abs(dy));
	if(dx < 0)
		a = 2.0 - a;
	else if(dy < 0)
		a += 4.0;
	return a * 90.0;
}

int convex_hull(struct point p[], int n){
	int i, m, min;
	double th, prev;
	struct point t;
	min = 1;
	for(i = 2; i <= n; i++)
		if(p[i].y < p[min].y)
			min = i;
	t = p[1];
	p[1] = p[min];
	p[min] = t;
	p[n + 1] = p[1];
	min = n;
	th = 360.0;
	for(i = 2; i <= n; i++)
		if(angle(p[1], p[i]) < th){
			min = i;
			th = angle(p[1], p[min]);
		}
	for(m = 2; m <= n; m++){
		t = p[m];
		p[m] = p[min];
		p[min] = t;
		prev = th;
		min = n + 1;
		th = 360.0;
		for(i = m + 1; i <= n + 1; i++)
			if(angle(p[m], p[i]) < th && angle(p[m], p[i]) >= prev){
				min = i;
				th = angle(p[m], p[min]);
			}
		if(min == n + 1)
			return m;
	}
}

int main(){
	int m, i;
	struct point q[11];
	q[1].x = 9;
	q[1].y = 3;
	q[2].x = 7;
	q[2].y = 7;
	q[3].x = 4;
	q[3].y = 3;
	q[4].x = 2;
	q[4].y = 8;
	q[5].x = 3;
	q[5].y = 4;
	q[6].x = 1;
	q[6].y = 1;
	q[7].x = 5;
	q[7].y = 4;
	q[8].x = 8;
	q[8].y = 2;
	q[9].x = 1;
	q[9].y = 5;
	m = convex_hull(q, 9);
	printf("  %d\n", m);
	for(i = 1; i <= m; i++)
		printf("  %d  %d\n", q[i].x, q[i].y);
}
