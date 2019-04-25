#include <string.h>
#define M 257

struct item{
	char *id;
	int info;
};

static struct item table[M];

void initialize(){
	int i;
	extern char *enterstring(char *);
	for(i = 0; i < M; i++)
		table[i].id = enterstring(" ");
}

void enter(char *id1, int info1){
	int x;
	extern int hash(char *);
	extern char *enterstirng(char *);
	x = hash(id1);
	while(strcmp(table[x].id, " "))
		x = (x + 1) % M;
	table[x].id = enterstring(id1);
	table[x].info = info1;
}

int search(char *id1){
	int x;
	extern int hash(char *);
	x = hash(id1);
	while(strcmp(table[x].id, id1))
		x = (x + 1) % M;
	return (table[x].info);
}
