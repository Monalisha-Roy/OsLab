#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main() {
	int pid = fork();

	if(pid == 0) {
		printf("Child Process\n");
		printf("Child Process id is %d\n", getpid());
		printf("Parent Process id is %d\n", getpid());
		sleep(5);
		printf("Child Process after sleep=5\n");
		printf("Child Process id: %d\n", getpid());
		printf("Parent Process id: %d\n", getpid());
	}
	else if(pid > 0) {
		printf("Parent Process\n");
		sleep(10);
		printf("Child Process after sleep=10\n");
		printf("Child Process id is %d\n", getpid());
		printf("Parent Process id is %d\n", getpid());
		printf("Parent  terminated\n");
	}
}
