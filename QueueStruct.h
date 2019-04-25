#include <stdio.h>
#include <stdlib.h>
#define queue_size 100
#define queue_el_type double

queue_el_type queue[queue_size];
int inx, outx, count;

void init_queue(){
	inx = 0;
	outx = 0;
	count = 0;
}

void enter(queue_el_type x){
	if(count < queue_size){
		inx++;
		if(inx == queue_size)
			inx = 0;
		count++;
		queue[inx] = x;	
	}else{
		printf("queue full error. \n");
		exit(1);
	}
}

queue_el_type qremove(){
	if(count > 0){
		outx++;
		if(outx == queue_size)
			outx = 0;
		count--;
		return queue[outx];
	}else{
		printf("queue empty error. \n");
		exit(1);
	}
}
