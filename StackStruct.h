#include <stdio.h>
#define stack_size 100
#define stack_el_type int

stack_el_type stack[stack_size];
int sp;

void init_stack(){
	sp = -1;
}

void push(stack_el_type x){
	if(sp < stack_size - 1)
		stack[++sp] = x; //前置++でないと判定に問題あり
	else{
		printf("stack full error. \n");
		exit(1);
	}
}

stack_el_type pop(){
	if(sp >= 0)
		return stack[sp--];
	else{
		printf("stack empty error. \n");
		exit(1);
	}
}
