int strcompare(char *a, char *b){
	while(*a == *b){
		if(*a == 0)
			return 0;
		a++;
		b++;
	}
	if(*a < *b)
		return -1;
	else
		return 1;
}
