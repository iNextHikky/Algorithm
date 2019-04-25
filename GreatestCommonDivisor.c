#include <stdio.h>

int gcd(int m, int n){
	int r, t;
	if(m < n)
	{t = m; m = n; n = t;}
	while(n != 0){
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}

/*
int gcd(int m, int n){
	if(n != 0)
		return gcd(n, m % n);
	else
		return m;
}
*/

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d \n", gcd(x, y));
}
