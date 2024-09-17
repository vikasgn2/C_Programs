#include <stdio.h>

void sum(int a, int b) {
	printf("Sum -> %d\n", a+b);
}


void dif(int a, int b) {
	printf("Difference -> %d\n", a-b);
}

void prod(int a, int b) {
	printf("Product -> %d\n", a*b);
}

void quot(int a, int b) {
	printf("Quotient -> %d\n", a/b);
}

void rem(int a, int b) {
	printf("Remainder -> %d\n", a%b);
}

int main(int argc, char **argv) 
{
	void (*func_ptr_array[4])(int, int) = {sum, dif, prod, quot};
	void (*func_ptr)(int, int) = rem;

	for(int i = 0; i < 4; i++) {
		func_ptr_array[i](10, 5);
	}
	func_ptr(10,2);
	return 0;
}
