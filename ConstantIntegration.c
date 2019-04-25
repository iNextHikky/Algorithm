#include <stdio.h>
#include <math.h>
#include "MonteCarloMethod.h"

double monte_carlo(double (*f)(double), double a, double b, double c, int n){
	double x, y;
	int count, i;
	count = 0;
	for(i = 0; i < n; i++){
		x = a + myrandd() * (b - a);
		y = myrandd() * c;
		if((*f)(x) > y)
			count++;
	}
	return (double) count / (double) n * (b - a) * c;
}

double h(double x){
	double y;
	y = sqrt(1.0 - x * x);
	return y;
}

int main(){
	double s;
	s = monte_carlo(&h, -1.0, 1.0, 1.0, 1000000);
	printf("%f\n", s);
}
