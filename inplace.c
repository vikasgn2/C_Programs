#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void swap( char *a, char *b) {
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void reverse( char *start, char *end) {
	while (start < end) {
		swap(start, end);
		start++;
		end--;
	}
}

void word_rev(char *str, int size) {
	char *start, *end;
	start = end = str;
	while(*end != '\0') {
		end++;
		if(*end == ' ') {
			reverse(start, end-1);
			start = end+1;
		}
	}
	if( *end == '\0') {
		reverse(start,end-1);
	}
}

void str_rev(char *str, int size) {
	char *ptr1, *ptr2;
	ptr1 = str;
	ptr2 = &str[strlen(str)-1];
	printf("%s\nSize = %d\n",str, size);
	reverse(ptr1, ptr2);
	word_rev(str, size);
	printf("%s\nSize = %d\n",str, size);
}

int main(int argc, char **argv)
{
	char str[40] = "out?\n dogs the let Who\0";
	int size = strlen(str);
	str_rev(str, size);
	return 0;
}
