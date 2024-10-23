#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Leader elements are those elements which are the largest compared to
// all elements present to their right
// Note : Rightmost element is also a leader element

int* leader_in_array(int *arr, int size, int *res) {
  int *start;
  int *end;
  int max = 0;
  start= arr; // Storing beginning of the array
  end = arr+(size-1); // Storing end of the array
  max = *end; // Storing right most elt of array

  int *result;
  result = malloc(size * sizeof(int));
  
  // Rightmost element is always leader so store it in resultant array
  result[0] = max;
  end--; // Shift end pointer by one
  int i = 1; // Index to iterate through array
  
  while(1) {
//    printf("End - %d, Max - %d\n", *end,max);
    if(*end > max) {
      max = *end;
      result[i] = max;
      i++;
    }
    end--;
    if(end < start)
      break;
  }
  return result;
}

void printarray(int *arr, int size) {
  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char **argv)
{
  int a1[] = {10,6,7,1,5,4,3,2,1};
  int s = sizeof(a1)/sizeof(int);
  int *res;
  printarray(a1, s);
  res = leader_in_array(a1,s, res);
  printarray(res,s);
  return 0;
}
