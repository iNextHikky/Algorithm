#include <stdlib.h>

int randf(int m){
	double rand_max = 2147483647.0;
	double r1, r2;
	int r;
	r1 = (double) rand();
	r2 = (double) m;
	r = (int)(r1 / rand_max * r2);
	return r;
}
