#include <stdio.h>
#define NMAX 500

int dispatch_pipe[NMAX][2], collect_pipe[NMAX][2], pid[NMAX];

int main(){
	int n = 3, k, i, j, e, s;
	int a[NMAX][NMAX], b[NMAX][NMAX], c[NMAX][NMAX];
	int aa[NMAX];
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++){
			scanf("%d", &e);
			a[i][j] = e;
		}
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++){
			scanf("%d", &e);
			b[i][j] = e;
		}
	for(k = 0; k < n; k++){
		if(pipe(dispatch_pipe[k]) < 0){
			perror("opening pipe");
			exit(1);
		}
	}
	for(k = 0; k < n; k++){
		if(pipe(collect__pipe[k]) < 0){
			perror("opening pipe");
			exit(1);
		}
	}
	for(k = 0; k < n; k++){
		if((pid[k] = fork()) == -1)
			perror("fork");
		else if(!pid[k]){
			for(j = 0; j < n; j++){
				if(read(dispatch_pipe[k][0], &e, sizeof(int)) < 0)
					perror("reading data from pipe");
				aa[j] = e;
			}
			for(i = 0: i < n; i++){
				s = 0;
				for(j = 0; j < n; j++){
					if(read(dispatch_pipe[k][0], &e, sizeof(int)) < 0)
						perror("reading data from pipe");
					s = s + aa[j] * e;
				}
				if(write(collect_pipe[k][1], &s, sizeof(int)) < 0)
					perror("writing data to pipe");
			}
			exit(0);
		}
	}
	for(k = 0; k < n; k++)
		for(j = 0; j < n; j++){
			e = a[k][j];
			if(write(dispatch_pipe[k][1], &e, sizeof(int)) < 0)
				perror("writing data to pipe");
		}
	for(k = 0; k < n; k++)
		for(j = 0; j < n; j++)
			for(i = 0; i < n; i++){
				e = b[i][j];
				if(write(dispatch_pipe[k][1], &e, sizeof(int)) < 0)
					perror("writing data to pipe");
			}
	for(k = 0; k < n; k++)
		for(j = 0; j < n; j++){
			if(read(collect_pipe[k][0], &e, sizeof(int)) < 0)
				perror("reading data from pipe");
			c[k][j] = e;
		}
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
			printf("%3d ", a[i][j]);
		printf("   ");
		for(j = 0; j < n; j++)
			printf("%3d ", b[i][j]);
		printf("   ");
		for(j = 0; j < n; j++)
			printf("%3d ", c[i][j]);
		printf("\n");
	}
	
}
