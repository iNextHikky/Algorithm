struct node{
	char key;
	int info;
	struct node *left, *right;
};

struct node *head, *nn;

int search(char c){
	struct node *t;
	t = head -> right;
	nn -> key = c;
	while(c != t -> key)
		t = (c < t -> key) ? t -> left : t -> right;
	return t -> info;
}
