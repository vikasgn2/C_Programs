#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SET_BIT(num, pos) ((num) | (1 << (pos)))
#define CLR_BIT(num, pos) ((num) & ~(1 << pos))
#define TGL_BIT(num, pos) ((num) ^ (1 << pos))
#define CHK_BIT(num, pos) ((num) & (1 << pos))
#define NIBBLE_SWP(num)   (((num << 4) & (0xF0)) | ((num >> 4) & 0x0F))
#define BIT_SWAP_16(num)  (((num << 8) & (0xFF00)) | ((num >> 8) & (0x00FF)))
#define BIT_SWAP_32(num)  (((num << 24) & (0xFF000000)) | ((num << 8) & (0x00FF0000)) | ((num >> 8) & (0x0000FF00)) | ((num >> 24) & (0x000000FF)))

void binary(int num) {
	while(num > 0) {
		printf("%d", (num%2));
		num /= 2;
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	int a = 134;
	binary(a);
	
	int b = CLR_BIT(15, 1);
	binary(b);
	
	int c =  SET_BIT(16, 0);
	printf("%d\n", c);

	int nibble = 0x84;
	printf("%x - ", nibble);
	nibble = NIBBLE_SWP(nibble);
	printf("%x\n", nibble);

	int bit_16 = 0x1234;
	printf("%x - ", bit_16);
	bit_16 = BIT_SWAP_16(bit_16);
	printf("%x\n", bit_16);

	int bit_32 = 0x12345678;
	printf("%x - ", bit_32);
	bit_32 = BIT_SWAP_32(bit_32);
	printf("%x\n", bit_32);

	int f = 16;
	for(int i = 1; i < 3; i++){
		 f = SET_BIT(f,i);
		binary(f);
	}
	return 0;
}
