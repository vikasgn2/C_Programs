// Usage of static variable within a function in C
#include <stdio.h>

void func() {
  static int a = 2; // Will be preserved in memory
  for(int i = 0; i < 2; i++) {
    a++;
  }
  printf("Func variable value = %d\n", a);
}


int main(int argc, char **argv)
{
  func();
  func();
  return 0;
}
