#include <stdio.h>

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("arguments error.\n");
		exit(1);
	}
	if((f1 = fopen(argv[1], "r")) == NULL){
		printf("can't open %s.\n", argv[1]);
		exit(1);
	}
	if((f2 = fopen(argv[2], "r")) == NULL){
		printf("can't open %s.\n", argv[2]);
		exit(1);
	}
	readin();
	lcs();
	printresult();
}
