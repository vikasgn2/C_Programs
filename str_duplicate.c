#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void str_dup(char *str, int size) {
    char buff[256] = {0};
    int index = 0;
    char c;

    for(int i = 0; i < size; i++) {
	c = str[i];
	if(buff[(unsigned char)c] == 0) {
	    str[index] = c;
	    index++;
	    buff[(unsigned char)c]++;
	}
    }
    str[index] = '\0';
}

int main(int argc, char **argv)
{
    char str[] = "heellooooo woorrrrllldddd";
    int size = sizeof(str)/sizeof(char);
    printf("Original String\n%s\n", str);
    str_dup(str,size);
    printf("String after removing duplicates\n%s\n", str);
    return 0;
}
