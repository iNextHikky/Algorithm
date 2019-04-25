#include <stdio.h>
//#include <stdlib.h>
#define nmax 100000

int a[nmax + 1];

void quick(int le, int ri){
	int i, j, s;
	int p, t;
	s = (le + ri) / 2;
	p = a[s];
	i = le;
	j = ri;
	while(i <= j){
		while(a[i] < p)
			i++;
		while(a[j] > p)
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
		quick(le, j);
	if(i < ri)
		quick(i, ri);
}

/*
#define stack_size 1000
#define stack_el_type int

stack_el_type stack[stack_size];
int sp;

void init_stack(){
	sp--;
}

void push(stack_el_type x){
	if(sp < stack_size - 1)
		stack[++sp] = x;
	else{
		printf("stack full error.\n");
		exit(1);
	}
}

stack_el_type pop(){
	if(sp >= 0)
		return stack[sp--];
	else{
		printf("stack empty error.\n");
		exit(1);
	}
}

int empty_stack(){
	return sp == -1;
}

void quicksort(int n){
	int le, ri, i, j, s;
	int p, t;
	init_stack();
	push(1);
	push(n);
	while(!empty_stack()){
		ri = pop();
		le = pop();
		s = (le + ri) / 2;
		p = a[s];
		i = le;
		j = ri;
		while(i <= j){
			while(a[i] < p)
				i++;
			while(a[j] > p)
				j--;
			if(i <= j){
				t = a[i];
				a[i] = a[j];
				a[j] = t;
				i++;
				j--;
			}
		}
		if(le < j){
			push(le);
			push(j);
		}
		if(i < ri){
			push(i);
			push(ri);
		}
	}
}
*/

int main(){
	int n, i;
	n = 0;
	while(scanf("%d", &a[n + 1]) != EOF)
		n++;
	quick(1, n);
	printf(" %d\n\n", n);
	for(i = 0; i < n; i++)
		printf("%12d\n", a[i]);
}
