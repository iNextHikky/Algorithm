#include <stdio.h>
#include <stdlib.h>
#include "StackStruct.h"
#define NUMBER	1
#define PLUS	2
#define MINUS	3
#define MULT	4
#define DIV	5
#define OTHER	6

int c, token, num;

int gettoken(){
	while(c == ' ' || c == '\n' || c == '\t')
		c = getchar();
	switch(c){
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		num = c - '0';
		for(;;){
		c = getchar();
		if('0' <= c && c <= '9')
			num = 10 * num + c - '0';
		else
			break;
		}
		return NUMBER;
		case '+': c = getchar(); return PLUS;
		case '-': c = getchar(); return MINUS;
		case '*': c = getchar(); return MULT;
		case '/': c = getchar(); return DIV;
		case EOF: return EOF;
		default: c = getchar(); return OTHER;
	}
}

int main(){
	int x;
	c = getchar();
	token = gettoken();
	init_stack;
	while(token != EOF){
		switch(token){
			case NUMBER: push(num); break;
			case PLUS: push(pop() + pop()); break;
			case MINUS: x = pop(); push(pop() - x); break;
			case MULT: push(pop() * pop()); break;
			case DIV: x = pop();
				if(x != 0){
					push(pop() / x);
					break;
				}else{
					printf("zero divide error. \n");
					exit(1);
				}
			case OTHER: printf("illegal charactor. \n"); exit(1);
		}
		token = gettoken();
	}
	if(sp == 0)
		printf("% 10d\n", pop());
	else{
		printf("expression syntax error. \n");
		exit(1);
	}
}
