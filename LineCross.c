#include <stdio.h>

struct point{
	int x, y;
};

struct segment{
	struct point p1, p2;
};

int turn(struct point q0, struct point q1, struct point q2){
	int dx1, dx2, dy1, dy2;
	dx1 = q1.x - q0.x;
	dx2 = q2.x - q0.x;
	dy1 = q1.y - q0.y;
	dy2 = q2.y - q0.y;
	if(dx1 * dy2 > dx2 * dy1)
		return 1;
	if(dx1 * dy2 < dx2 * dy1)
		return -1;
	if((dx1 * dx2 < 0) || (dy1 * dy2 < 0))
		return -1;
	if((dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2))
		return -1;
	return 0;
}

int intersect(struct segment s1, struct segment s2){
	return ((turn(s1.p1, s1.p2, s2.p1) * turn(s1.p1, s1.p2, s2.p2)) <= 0) && ((turn(s2.p1, s2.p2, s1.p1) * turn(s2.p1, s2.p2, s1.p2)) <= 0);
}

int main(){
	struct segment test1, test2;
	test1.p1.x = 0;
	test1.p1.y = 0;
	test1.p2.x = 10;
	test1.p2.y = 10;
	test2.p1.x = 8;
	test2.p1.y = 1;
	test2.p2.x = 3;
	test2.p2.y = 7;
	printf("   %d\n", intersect(test1, test2));

}
