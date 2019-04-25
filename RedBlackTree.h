#include <stdlib.h>

/*
struct node{
	char key;
	int info;
	int red;
	struct node *left, *right;
};
*/

struct node *head, *nn, *t, *p, *pp, *ppp;

void initialize(){
	nn = (struct node *) malloc(sizeof *nn);
	nn -> info = 0;
	nn -> red = 0;
	nn -> left = nn;
	nn -> right = nn;
	head = (struct node *) malloc(sizeof *head);
	head -> key = 0;
	head -> red = 0;
	head -> right = nn;
}

void enter(char c, int info){
	extern void split(char);
	t = head;
	p = head;
	pp = head;
	while(t != nn){
		ppp = pp;
		pp = p;
		p = t;
		t = (c < t -> key) ? t -> left : t -> right;
		if(t -> left -> red && t -> right -> red)
			split(c);
	}
	t = (struct node *) malloc(sizeof *t);
	t -> key = c;
	t -> info = info;
	t -> left = nn;
	t -> right = nn;
	if(c < p -> key)
		p -> left = t;
	else
		p -> right = t;
	split(c);
}

void split(char c){
	extern struct node *rotate(char, struct node *);
	t -> red = 1;
	t -> left -> red = 0;
	t -> right -> red = 0;
	if(p -> red){
		pp -> red = 1;
		if((c < pp -> key) != (c < p -> key))
			p = rotate(c, pp);
		t = rotate(c, ppp);
		t -> red = 0;
	}
	head -> right -> red = 0;
}

struct node *rotate(char c, struct node *x){
	struct node *u, *v;
	u = (c < x -> key) ? x -> left : x -> right;
	if(c < u -> key){
		v = u -> left;
		u -> left = v -> right;
		v -> right = u;
	}else{
		v = u -> right;
		u -> right = v -> left;
		v -> left = u;
	}
	if(c < x -> key)
		x -> left = v;
	else
		x -> right = v;
	return v;
}
