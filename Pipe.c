#include <stdio.h>

int pipe_sender_receiver[2], pid[2];

int main(){
	int i, e;
	if(pipe(pipe_sender_receiver) < 0){
		perror("opening pipe");
		exit(1);
	}
	if((pid[0] = fork()) == -1)
		perror("fork sender");
	else if(!pid[0]){
		close(pipe_sender_receiver[0]);
		for(i = 0; ; i++){
			e = 2 * i + 1;
			if(write(pipe_sender_receiver[1], &e, sizeof(int)) < 0)
				perror("writing data in sender");
			usleep(5000000);
		}
	}
	if((pid[1] = fork()) == -1) 
		perror("fork receiver");
	else if(!pid[1]){
		close(pipe_sender_receiver[1]);
		for(;;){
			read(pipe_sender_receiver[0], &e, sizeof(int)) < 0)
			perror("reading data in receiver");
		if(e % 3)
			printf("%d\n", e);
		}
	}
	printf("start\n");
	for(;;);
}

