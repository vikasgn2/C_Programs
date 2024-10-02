#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *arr, int size) {
    int flag;
    for(int i = 0; i < size -1; i++) {
	flag = 0;
	for(int j = 0; j < size - i - 1; j++) {
	    if(arr[j] > arr[j + 1]) {
		swap( &arr[j], &arr[j+1] );
		flag = 1;
    	    }
	}
	if ( flag == 0)
	    break;
    }
}

void ins_sort(int *arr, int size) {
    for(int  i = 0; i < size ; i ++){
	int j = i;
	while( (j > 0) && (arr[j - 1] > arr[j])){
	    swap(&arr[j -1],&arr[j]);
	    j--;
	}
    }
}

void sel_sort(int *arr, int size) {
    int min;
    for(int i = 0; i < size - 1; i++) {
	for(int j = i+1; j < size; j++) {
	    if( arr[j] < arr[min])
		min = j;
	}
	swap( &arr[i], &arr[min]);
    }
}

void printarray(int *arr, int size) {
    for(int i = 0; i <size; i++)
	printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char **argv)
{
    int a[] = {5,1,3,2,1,4,2,3,4,5};
    int b[] = {10,9,7,8,6};
    int c[] = {11,13,15,14,16,1,2,1,3,10,9,7,8,6};

    int size1 = sizeof(a)/sizeof(int);
    int size2 = sizeof(b)/sizeof(int);
    int size3 = sizeof(c)/sizeof(int);

    printf("Printing bubble sort output of array : ");
    printarray(a, size1);
    bubble_sort(a, size1);
    printarray(a, size1);
    
    printf("Printing insertion sort output of array : ");
    printarray(b, size2);
    ins_sort(b, size2);
    printarray(b, size2);
    
    printf("Printing selection sort output of array : ");
    printarray(c, size3);
    sel_sort(c, size3);
    printarray(c, size3);
    return 0;
}
