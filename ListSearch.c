#include <stdlib.h>
#include <stdio.h>
#define eltype int

typedef struct node{
	eltype data;
	struct node *next;
} LISTEL;

struct node *root;

void construct_list(){
	struct node *p;
	int i, y;
	for(i = 0; i < 6; i++){
		scanf("%d", &y);
		p = (struct node *)malloc(sizeof(LISTEL));
		p -> data = y;
		p -> next = root;
		root = p;
	}
}

void write_list(){
	struct node *p;
	p = root;
	while(p != NULL){
		printf(" %5d", p -> data);
		p = p -> next;
	}
	puts("");
}

struct node *search(int x){
	struct node *p;
	p = root;
	while(p != NULL){
		if(p -> data == x){
			printf("\t%d found. \n", x);
			return p;
		}
		else
			p = p -> next;
	}
	printf("\t%d not found. \n", x);
	return NULL;
}

int main(){
	void construct_list();
	void write_list();
	struct node *search();
	int x;
	root = NULL;
	construct_list();
	write_list();
	scanf("%d", &x);
	printf("%5d\n", x);
	search(x);
}
