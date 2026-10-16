/* This program contains intentional memory access violation and memory leaks
   This is to learn regarding how ASAN and LSAN works in Linux/GCC

   ASAN - Address Sanitizer that checks for access violations 
          (Out of Bounds, Use After Free etc)
   LSAN - Leak Sanitizer that checks for memory leaks (unfreed mem)

   GCC args used
   1. "-g"                      : Enables debug symbols
   2. "-fno-omit-frame-pointer" : Enables frame ptr preservation for stack trace
   3. "-fsanitize=address"      : Enables both ASAN and LSAN by default
   4. "-fsanitize=leak"         : Enables LSAN only

   Steps to reproduce

   1. Run "gcc -g -fsanitize=address -fno-omit-frame-pointer
           asan_lsan_test.c -o asan_report"
      - ASAN reports the out of bounds violation and exits immediately.
      - This can be viewed by running asan_report
      - LSAN output isn't captured since program never exits.

   2. Run "gcc -g -fsanitize=address -fno-omit-frame-pointer
        asan_lsan_test.c -o lsan_report"
      - Comment out the Mem Access violation section of the code and recompile
      - This can be viewed by running lsan_report
      - LSAN executes at the program exit and reports memory leak(s) as output

   Note: To test LSAN independently, compile with:
   gcc -g -fsanitize=leak asan_lsan_test.c -o lsan_report
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(int argc, char **argv)
{
    char *ptr1 = malloc(SIZE * sizeof(char));
    ptr1 = NULL;      // Mem leak to be caught by LSAN

    int *ptr2 = malloc(SIZE * sizeof(int));
    *(ptr2+20) = 10; // Mem access violation to be caught by ASAN
    free(ptr2);      // Can't be reached due to ASAN exit above

    return 0;
}
