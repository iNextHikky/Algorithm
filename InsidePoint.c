#include <stdio.h>

struct point{
	int x, y;
};

struct segment{
	struct point p1, p2;
};

int inside(struct point p[], int n, struct point v){
	int i, j = 0, count = 0;
	struct segment sw, sp;
	p[0] = p[n];
	p[n + 1] = p[1];
	sw.p1 = v;
	sw.p2.x = 200000000;
	sw.p2.y = v.y;
	for(i = 1; i <= n; i++){
		sp.p1 = p[i];
		sp.p2 = p[i];
		if(!intersect(sp, sw)){
			sp.p2 = p[j];
			j = i;
			if(intersect(sp, sw))
				count++;
		}
	}
	return count & 1;
}

int main(){
	struct point w;
	struct point q[10];
	int n = 5;
	q[1].x = 0;
	q[1].y = 0;
	q[2].x = 5;
	q[2].y = 1;
	q[3].x = 4;
	q[3].y = 5;
	q[4].x = 9;
	q[4].y = 2;
	q[5].x = 2;
	q[5].y = 8;
	w.x = 3;
	w.y = 3;
	printf("  %d\n", inside(q, n, w));
}
