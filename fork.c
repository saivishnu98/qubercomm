#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main() {
	fork();
	fork();
	fork();
	printf("welcome fork\n");
	return 0;
}
