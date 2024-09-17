#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void func(char *array, int *even, int *odd, int size) {
	char temp1;
	int temp2;
	int j = 0, k =0;
	for(int i =0; i < size; i++) {
		temp1 = array[i];
		temp2 = atoi(&temp1);
//		printf("%c, %d\n", temp1, temp2);
		if(temp2 % 2 == 0) {
			even[j] = temp2;
			j++;
		}
		else {
			odd[k] = temp2;
			k++;
		}
	}
}

int main(int argc, char **argv)
{
	char array[10] = "0123456789"; 
	int size = sizeof(array)/sizeof(char);
	int *even = malloc((size*sizeof(int))/2);
	int *odd = malloc((size*sizeof(int))/2);
	func(array, even, odd, size);
	for(int i =0; i < 5; i++) {
		printf("%d ", even[i]);
	}
	printf("\n");
	for(int i =0; i < 5; i++) {
		printf("%d ", odd[i]);
	}
	printf("\n");
	free(even);
	free(odd);
	return 0;
}
