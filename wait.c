#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int i = 10;

void main() {
	int pid = fork();

	if(pid == 0) {
		printf("Initial value of i = %d\n", i);
		i+=10;
		printf("Value of i = %d\n", i);
		printf("Child terminated\n");
	}
	else {
		wait(0);
		printf("value of i in parent process i = %d\n", i);
	}
}
