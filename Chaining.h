#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NIL 0
#define M 257
#define ITEMMAX 200

typedef struct CHAIN_x{
	char *id;
	int info;
	struct CHAIN_x *next;
} CHAIN;
static CHAIN *hashtable[M];
static int itemtop = 0;
static CHAIN table[ITEMMAX];
void initialize(){
	int i;
	for(i = 0; i < M; i++)
		hashtable[i] = NIL;
}

void enter(char *id1, int info1){
	int x;
	CHAIN *p;
	extern int hash(char *);
	extern char *enterstring(char *);
	x = hash(id1);
	p = hashtable[x];
	while(p != NIL){
		if(strcmp(id1, p -> id) == 0){
			printf("already entered.");
			return;
		}
		p = p -> next;
	}
	if(itemtop >= ITEMMAX){
		printf("item table overflow.");
		exit(1);
	}
	table[itemtop].id = enterstring(id1);
	table[itemtop].info = info1;
	table[itemtop].next = hashtable[x];
	hashtable[x] = (&table[itemtop++]);
}

int search(char *id1){
	int x;
	CHAIN *p;
	extern hash(char *);
	x = hash(id1);
	p = hashtable[x];
	while(p != 0){
		if(strcmp(id1, p -> id) == 0)
			return p -> info;
		p = p -> next;
	}
	return -1;
}
