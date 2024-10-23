#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Prints from MSB to LSB
#define PRINT_BINARY(num,pos) ((num >> pos) & 1)
void print_binary(int num) {
    int bit = 0;
    int pos =31; // Change this variable based on size or number of bits needed
    while(pos > -1) {
	bit = PRINT_BINARY(num,pos);
    	printf("%d", bit);
    	pos--;
    }
    printf("\n");
}

int swap_even_odd_bits(int num) {
	int result = 0;

	//0x5 in hexadecimal is equivalent to 0101
	int even_mask = 0x55555555;
	//0xA in hexadecimal is equivalent to 1010
	int odd_mask = 0xAAAAAAAA;

	// Extract all bits present from 0...32
	int even_part = num & even_mask;
	// Extract all bits present from 1...31
	int odd_part = num & odd_mask;

	// Shifting them by 1 to reverse them	
	even_part = even_part << 1;
	odd_part = odd_part >> 1;
	
	// Storing it in result
	result = even_part|odd_part;

	return result;

}

int main(int argc, char **argv)
{
	int a = 153;
	print_binary(a);
	int b = 0;
	b = swap_even_odd_bits(a);
	print_binary(b);
	return 0;
}
