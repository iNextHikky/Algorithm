int match;
int result[MAXLINE];

void lcs(){
	struct list{
		int apos, bpos;
		struct list *next;
	};
	int i, l, r, k, p;
	struct list *q;
	int thresh[MAXLINE];
	struct list *link[MAXLINE];
	int bnext[MAXLINE];
	for(i = 1; i <= b -> nl; i++){
		bnext[i] = b -> body[i] -> btail;
		b -> body[i] -> btail = i;
	}
	link[0] = NULL;
	match = 0;
	for(i = 1; i <= a -> nl; i++){
		p = a -> body[i] -> btail;
		while(p != 0){
			l = 1;
			r = match;
			while(r >= 1){
				k = (1 + r) / 2;
				if(p > thresh[k])
					l = k + 1;
				else
					r = k - 1;
			}
			k = l;
			if((k > match) || (p < thresh[k])){
				thresh[k] = p;
				link[k] = (struct list *)malloc(sizeof(structlist));
				link[k] -> apos = i;
				link[k] -> bpos = p;
				link[k] -> next = link[k - 1];
				if(k > match)
					match = k;
			}
			p = bnext[p];
		}
	}
	for(i = 1; i <= a -> nl; i++)
		result[i] = 0;
	q = link[match];
	while(q != NULL){
		result[q -> apos] = q -> bpos;
		q = q -> next;
	}
}
