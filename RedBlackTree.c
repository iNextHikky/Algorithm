#include <stdio.h>
#include "RedBlackTree.h"
#include "BinarySearch.h"

void print1(struct node *x);
void print();

int main(){
	initialize();
	enter('C', 67);
	enter('O', 79);
	enter('M', 77);
	enter('P', 80);
	enter('U', 85);
	enter('T', 84);
	enter('E', 69);
	enter('R', 82);
	printf(" code of P: %d\n", search('P'));
	print();
}

void print1(struct node *x){
	if(x != nn){
		print1(x -> left);
		printf(" %c  ", x -> key);
		print1(x -> right);
	}
}

void print(){
	print1(head -> right);
	printf("\n");
}
