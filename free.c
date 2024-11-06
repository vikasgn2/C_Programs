#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// Will this free work ?
// Why is the assert statement failing
void my_free(void *c);

int main(int argc, char **argv) {
  char *c = malloc(10) ;
  strcpy(c,"hello");
  printf("%p, %s, %d, %s\n", c, c,__LINE__, __FUNCTION__);
  my_free(c);
  printf("%p, %s, %d, %s\n", c, c,__LINE__, __FUNCTION__);
  assert (c == NULL) ;
  return 0;
}

void my_free (void *c) {
  printf("%p, %s, %d, %s\n", c, (char *)c,__LINE__, __FUNCTION__);
  if(c) {
    free(c);// Free works on the pointer
  }
  printf("%p, %s, %d, %s\n", c, (char *)c,__LINE__, __FUNCTION__);
  c = NULL; // (c = NULL) doesn't work because we are passing single pointer 
	    // hence it is assigned to NULL only within the function and 
	    // not in main
  return;
}
