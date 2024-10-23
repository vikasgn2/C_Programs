#include <stdio.h>

unsigned int reverseBits(unsigned int num) {
  unsigned int bits = 32; // Since the input will be a 32 bit number
  unsigned int reverse = num;
  
  while (num) {
    reverse <<= 1; // Left shifting of original num
    reverse = reverse | (num & 1); // Extracting rightmost bit in original num
    num >>= 1; //Reducing number bit by bit till it reaches 
    bits--; // Keeping remaining unset bits count in case the number is very small for ex : 3 
  }

  reverse <<= bits; // Shift the extracted bits those many times
  return reverse;
}

// Driver code
int main(int argc, char **argv)
{
    unsigned int number = 1;// Binary Equivalent is 31zeroes.....1
			    // Reverse must be 1..........31zeroes
    printf("%u\n", reverseBits(number));
}
