#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void main() {
	int pid = fork();

	if(pid == 0) {
		printf("Child Process is running with pid: %d\n", getpid());
		exit(0);
	}
	if(pid > 0) {
		printf("Parent process is running with pid: %d\n", getpid());
	}
	else {
		printf("Process creation failed\n");
		exit(-1);
	}
}
