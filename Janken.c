#include <stdio.h>
#include "PseudoRandomNumber.h"
#include "RockPaperScissors.h"

int main(){
	int i, p, q, randf(), myrandf();
	int count0 = 0, count1 = 0, count2 = 0;
	for(i = 0; i < 1000000; i++){
		p = randf(3);
		q = myrandf(3);
		if(p == q)
			count0++;
		else if(p - q == 1 || p - q == -2)
			count1++;
		else
			count2++;
	}
	printf("%12d%12d%12d\n", count0, count1, count2);
}
