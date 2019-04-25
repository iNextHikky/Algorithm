void printline(struct filetype *x, int ln){
	int k;
	for(k = 1; k <= x -> body[ln] -> length; k++)
		putchar(pool[x -> body[ln] -> head + k]);
	printf("\n");
}

void printresult(){
	int i, j, iinit, jinit;
	result[a -> nl + 1] = b -> nl + 1;
	i = 1;
	j = 1;
	while(i <= a -> nl + 1){
		iinit = i;
		jinit = j;
		while(result[i] == 0){
			printf(" %D    ", i);
			printline(a, i);
			i++;
		}
		while(j < result[i]){
			printf("    %D ", j);
			printline(b, j);
			j++;
		}
		if((iinit < i) || (jinit < j))
			printf("-----------\n");
		i++;
		j++;
	}
	printf("\n");
	if((match == a -> nl) && (match == b -> nl))
		printf("identical files (%d lines). \n", match);
	else
		printf("among (%d / %d) lines, %d lines matched.\n", a -> nl, b -> nl, match);
}
