#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void swp(int *a, int *b) {
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int *arr, int size) {
	int flag;
	for (int i = 0; i < size - 1; i++) {
		flag = 0;
		for(int j = 0; j < size - i - 1; j++) {
			if(arr[j] > arr[j+1]) {
				swp(&arr[j], &arr[j+1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

void printarray(int *arr, int size) {
	for(int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	int a1[] = {5,4,3,2,1};
	int s = sizeof(a1)/sizeof(int);
	printarray(a1, s);
	bubble_sort(a1, s);
	printarray(a1, s);
	return 0;
}
