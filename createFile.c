#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

void main() {
	int id;
	if(id=creat("z.txt",0)==-1) {
		printf("Cannot create the file\n");
		exit(1);
	}
	else {
		printf("file is created\n");
		exit(1);
	}
}
