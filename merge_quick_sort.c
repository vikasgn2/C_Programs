#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void swap(int *a, int *b) {
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *arr, int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for(int j = low; j < high; j++) {
		if(arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return (i + 1);
}

void quicksort(int *arr, int low, int high) {
	if(low < high) {
		int pivot = partition(arr, low, high);
		quicksort(arr, low, pivot-1);
		quicksort(arr, pivot+1, high);
	}
}

void merge(int *arr, int low, int mid, int high) {
	int left_size = mid - low + 1;
	int right_size = high - mid;

	int left[left_size];
	int right[right_size];

	for(int i = 0; i < left_size;i++) {
		left[i] = arr[low + i];
	}
	for(int j = 0; j < right_size; j++) {
		right[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0, k = low;

	while((i < left_size) && (j < right_size)) {
		if(left[i] <= right[j]) {
			arr[k] = left[i];
			i++;
		} else {
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	while(i < left_size) {
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j < right_size) {
		arr[k] = right[j];
		j++;
		k++;
	}
}

void mergesort(int *arr, int left, int right) {
	if(left < right) {
		int mid = left + (right-left) / 2;
		
		mergesort(arr, left, mid);
		mergesort(arr, mid + 1, right);

		merge(arr, left, mid, right);
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
	int a1[] = {5,4,3,2,1,1,2,3,4,5};
	int a2[] = {9,8,7,6,10,6,7,8,9,10};
	int s1 = sizeof(a1)/sizeof(int);
	int s2 = sizeof(a2)/sizeof(int);
	printf("Sorted Using Quicksort\n");
	printarray(a1, s1);
	quicksort(a1,0, s1-1);
	printarray(a1, s1);
	printf("Sorted Using Mergesort\n");
	printarray(a2, s2);
	mergesort(a2,0, s2-1);
	printarray(a2, s2);
	return 0;
}
