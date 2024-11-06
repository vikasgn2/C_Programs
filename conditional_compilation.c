#include <stdio.h>

int main(int argc, char **argv)
{
#ifdef CONDITIONAL_COMPILATION	
  printf("Printing One\n"); // Pass -D CONDITIONAL_COMPILATION 
			    //to GCC in order to get this print
#else
  printf("Printing Two\n");
#endif
	return 0;
}
