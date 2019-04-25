#include <stdio.h>
#include <stdlib.h>
#define eltype char

typedef struct node{
	eltype data;
	struct node *left;
	struct node *right;
} TREEEL;

struct node *root;

void preorder(struct node *p){
	printf(" %c", p -> data);
	if(p -> left != NULL)
		preorder(p -> left);
	if(p -> right != NULL)
		preorder(p -> right);
}

void inorder(struct node *p){
	if(p -> left != NULL)
		inorder(p -> left);
	printf(" %c", p -> data);
	if(p -> right != NULL)
		inorder(p -> right);
}

void postorder(struct node *p){
	if(p -> left != NULL)
		postorder(p -> left);
	if(p -> right != NULL)
		postorder(p -> right);
	printf(" %c", p -> data);
}

void construct_tree(){
	struct node *new_node(eltype);
	char c;
	struct node *p;
	root = new_node(getchar());
	c = getchar();
	while(c != EOF && c != '\n'){
		p = root;
		while(p != NULL){
			if(c < p -> data){
				if(p -> left != NULL)
					p = p -> left;
				else{
					p -> left = new_node(c);
					break;
				}
			}else if(c > p -> data){
				if(p -> right != NULL)
					p = p -> right;
				else{
					p -> right = new_node(c);
					break;
				}
			}
		}
		c = getchar();
	}
}

struct node *new_node(eltype c){
	struct node * q;
	q = (struct node *)malloc(sizeof(TREEEL));
	q -> data = c;
	q -> left = NULL;
	q -> right = NULL;
	return q;
}

int main(){
	root = NULL;
	construct_tree();
	preorder(root);
	puts("");
	inorder(root);
	puts("");
	postorder(root);
	puts("");
}
