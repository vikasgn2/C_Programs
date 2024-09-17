#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	fork();
	printf("1 Fork PID - %d, PPID - %d\n", getpid(), getppid());
	fork();
	printf("2 Fork PID - %d, PPID - %d\n", getpid(), getppid());
	fork();
	printf("3 Fork PID - %d, PPID - %d\n", getpid(), getppid());
	return 0;
}
