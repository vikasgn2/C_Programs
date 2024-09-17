#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE 64

int my_strlen(const char *str);
int main(int argc, char **argv)
{
	char *str = NULL;
	str = malloc(SIZE * sizeof(char));
	if(str == NULL) {
		printf("String Malloc failed\n");
	}
	printf("Enter the string whose length is to be measured\n");
	fgets(str, SIZE, stdin);
	str[strlen(str) - 1] = '\0';
	printf("lib strlen = %ld\n", strlen(str));
	int length = 0;
	length = my_strlen(str);
	printf("my_strlen = %d\n", length);
	return 0;
}

int my_strlen(const char *str) {
	int count = 0;
	if(str == NULL ){
		printf("String is empty\n");
		return count;
	}
	while(*str != '\0') {
		count++;
		str++;
	}
	return count;
}
