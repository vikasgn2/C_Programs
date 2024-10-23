#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int count_set_bits(unsigned int n) {
	unsigned int count = 0;
	while(n) {
		count = count + (n & 1);
		n = n >> 1;
	}
	return count;
}

int main(int argc, char **argv)
{
	int a = 19764; //Binary representation is 100110100110100
	unsigned int b = (unsigned int)a;
	unsigned int count = count_set_bits(b);
	printf("Number of bits set in %d is %d\n", a, count);
	return 0;
}
