#include <stdio.h>

double inprod(double x[], double y[], int n){
	double s;
	int i;
	s = 0.0;
	for(i = 0; i < n; i++)
		s += x[i] * y[i];
	return s;
}

int main(){
	double a[3], b[3], inprod(); //inprod()は型がdoubleという宣言であり,これを宣言しなければ暗黙的にintになる.
	int i;
	for(i = 0; i < 3; i++)
		scanf("%lf %lf", a+i, b+i);
	printf("%f \n", inprod(a, b, 3));
}
