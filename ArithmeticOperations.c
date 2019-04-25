#include <stdio.h>

int main(){
	int x, y, a, b, c, d, e;
	scanf("%d %d", &x, &y);
	a = x + y;
	b = x - y;
	c = x * y;
	d = x / y;
	e = x % y;
	printf("%d, %d, %d, %d, %d \n", a, b, c, d, e);
}
