#define M 257

int hash(int v){
	return (v % M);
}

/*
int hash(char *v){
	int x;
	x = 0;
	while(*v)
		x = 256 * x + (*v++);
	if(x < 0)
		x = (-x);
	return (x % M);
}
*/
