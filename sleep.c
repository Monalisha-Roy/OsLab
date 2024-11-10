// Process creation with sleep
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main() {
	int pid = fork();

	if(pid == 0) {
		sleep(2);
		printf("This is the child process with pid: %d\n", getpid());
		exit(0);
	}
	else if(pid > 0) {
		printf("Parent process running with pid: %d\n", getpid());
		exit(1);
	}
	else {
		printf("Cannot create process\n");
		exit(-1);
	}
}
