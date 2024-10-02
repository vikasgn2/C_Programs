#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printarray(int *arr, int size) {
    for(int i = 0; i < size; i++)
	printf("%d ", arr[i]);
    printf("\n");
}

int remove_duplicates(int *arr, int size) {
    int i = 0;
    for(int j = 1; j < size; j++) {
	if(arr[i] != arr[j]) {
	    i++;
	    arr[i] = arr[j];
	}
    }
    return i + 1;
}
int main(int argc, char **argv)
{
    int arr[] = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5}; // Sort the array if it is unsorted
    int size = sizeof(arr)/sizeof(int);
    printf("Original array \n");
    printarray(arr, size);
    
    int new_size = remove_duplicates(arr,size);
    printf("Array after removing duplicates\n");
    printarray(arr, new_size);
    
    return 0;
}
