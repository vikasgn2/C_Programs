#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void naive_two_sum(int *arr, int size, int sum) {
    printf("===== Naive Approach =====\n");
    int flag = 0;
    for(int i = 0; i < size; i++) {
	for(int j = i+1; j < size; j++) {
	    if(arr[i] + arr[j] == sum) {
		printf("Adding numbers from index [%d] %d and [%d] %d will give %d\n", i, arr[i], j,arr[j], sum);
	    	flag = 1;
	    }
	}
    }
    if(flag == 0)
	printf("No such numbers found\n");
}

void optimized_two_sum (int *arr, int size, int sum) {
    printf("\n===== Optimal Approach =====\n");
    int *left = NULL, *right = NULL;
    int res = 0;
    left = &arr[0];
    right = &arr[size - 1];
    while( left < right ) {
	res = *left + *right;
	if(res == sum) {
		printf("Adding numbers from index [%p] %d and [%p] %d will give %d\n", left, *left, right, *right, sum);
		return;
	}
	else if( res > sum )
	    right--;
	else
	    left++;

    }
    printf("No such numbers found\n");
}

int main(int argc, char **argv)
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10}; // Input array needs to be sorted for optimal approach
    int sum = 14;
    int size = 0;
    size = sizeof(arr) / sizeof(int);
    naive_two_sum(arr, size, sum);
    optimized_two_sum(arr, size, sum);

    return 0;
}
