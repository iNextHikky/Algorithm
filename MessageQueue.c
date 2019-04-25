#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/ipc.h>
#define msgbuf _msgbuf
#include <sys/msg.h>
#undef msgbuf
#include <stdio.h>

struct msgbuf{
	long mtype;
	char mtext[10];
};

void process1();
void process2();
void process3();

int main(){
	key_t key = 1995;
	int msqid;
	msqid = msgget(key, IPC_CHEAT | 0600);
	if(fork() == 0)
		process1(key);
	if(fork() == 0)
		process2(key);
	if(fork() == 0)
		process3(key);
	printf("start\n");
	for(;;);
}

void process1(key_t key){
	int msqid, i;
	struct msgbuf buf;
	msqid = msgget(key, 0600);
	for(i = 0; i < 10000; i += 3){
		buf.mtype = 1;
		sprintf(buf.mtext, "%5d", i);
		msgsnd(msqid, &buf, strlen(buf.mtext) + 1, 0);
		usleep(1000000);
	}
}

void process2(key_t key){
	int msqid, j;
	struct msgbuf buf;
	msqid = msgget(key, 0600);
	for(j = 0; j < 10000; j += 5){
		buf.mtype = 2;
		sprintf(buf.mtext, "%5d", j);
		msgsnd(msqid, &buf, strlen(buf.mtext) + 1, 0);
		usleep(1200000);
	}
}

void process3(key_t key){
	int msqid, x;
	struct msgbuf buf;
	msqid = msgget(key, 0600);
	for(;;){
		msgrcv(msqid, &buf, 10, 0, 0);
		x = atoi(buf.mtext);
		printf("%d\n", x);
	}
}
