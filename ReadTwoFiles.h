#include <stdlib.h>
#include <stdio.h>
#define MAXLINE 402
#define MAXCHAR 10000
#define HASHSIZE 197

struct linerep{
	int length;
	int head;
	int btail;
	struct linerep *chain;
};

FILE *f1, *f2;

struct filetype{
	int nl;
	struct linerep *body[MAXLINE];
};

struct filetype *a, *b;
char pool[MAXCHAR];
int cp;
struct linerep *hashtable[HASHSIZE];
int leng;

struct linerep *search(){
	struct linerep *p;
	int h, i;
	h = 0;
	for(i = 1; i <= leng; i++)
		h = (2 * h + (int)pool[cp + i]) % HASHSIZE;
	p = hashtable[h];
	while(p != NULL){
		if(leng == p -> length){
		for(i = 1; i <= leng; i++)
			if(pool[cp + i] != pool[p -> head + i])
				break;
		return p;
		}
		p = p -> chain;
	}
	p = (struct linerep *)malloc(sizeof(struct linerep));
	p -> length = leng;
	p -> head = cp;
	p -> btail = 0;
	p -> chain = hashtable[h];
	hashtable[h] = p;
	cp += leng;
	return p;
}

void readfile(FILE *f, struct filetype *x){
	int lines = 0, c;
	while((c = getc(f)) != EOF){
		leng = 0;
		while(c != '\n'){
			if(cp + leng >= MAXCHAR - 1){
				printf("too many characters.\n");
				exit(1);
			}
			leng++;
			pool[cp + leng] = c;
			c = getc(f);
		}
		if(lines >= MAXLINE - 2){
			printf("too many lines.\n");
			exit(1);
		}
		lines++;
		x -> body[lines] = search();
	}
	x -> nl = lines;
	fclose(f);
}

void readin(){
	int k;
	cp = 0;
	for(k = 0; k < HASHSIZE; k++)
		hashtable[k] = NULL;
	a = (struct filetype *)malloc(sizeof(struct filetype));
	b = (struct filetype *)malloc(sizeof(struct filetype));
	readfile(f1, a);
	readfile(f2, b);
}
