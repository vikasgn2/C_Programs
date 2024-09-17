#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	char *a = "1234567890\n";
	char b[] = "1234567890\n";
	char c[40] = "1234567890\n";
	printf("%s%s%sa - %ld, b - %ld, c - %ld\n", a, b, c, sizeof(a), sizeof(b), sizeof(c));
	return 0;
}
