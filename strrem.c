#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 128

char *strrem (char *str1, const char *str2);

int main (int argc, char **argv)
{
  char *str1;
  char *str2;
  char *ptr;

  str1 = malloc (SIZE);
  str2 = malloc (SIZE);

  if (str1 == NULL) {
      printf ("Str 1 Malloc Failed\n");
      return 0;
  }

  if (str2 == NULL) {
      printf ("Str 2 Malloc Failed\n");
      return 0;
  }

  printf ("Enter Original String\n");
  fgets (str1, SIZE, stdin);
  printf ("Enter String to be removed\n");
  fgets (str2, SIZE, stdin);

  str1[strlen (str1) - 1] = '\0';
  str2[strlen (str2) - 1] = '\0';
  printf ("Original String - %s\nString to be removed - %s\n", str1, str2);

  ptr = strrem (str1, str2);
  printf ("Original String after modification = %s\n", ptr);
  return 0;
}

char *strrem (char *str1, const char *str2)
{
  char *temp, *temp1 = str1;
  while (*str1 != '\0') {
    temp = str1;
    if (*str1 == *str2) {
      while (*str2 != '\0') {
        printf ("%c", *str1);
        if (*str1 != *str2) {
          break;
        }
        str2++;
        str1++;
     }
     while (*str1 != '\0') {
       *temp = *str1;
       temp++;
       str1++;
     }
     *temp = '\0';
    }
    str1++;
  }
  printf("\n");
  return temp1;
}
