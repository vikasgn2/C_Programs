#include <stdio.h>

int fib (int n) {
    if( n == 0 || n == 1)
	return n;
    return fib(n-1) + fib(n-2);
}

int fact(int n) {
    if(n == 0 || n == 1)
	return n;
    return n * fact(n-1);
}

int main(int argc, char **argv)
{

    int a = 10;
    int fib_num = 0;
    int factorial = 0;

    printf("Printing Fibonacci series : \n");
    for(int i = 0; i < a; i++)
	printf("%d ", fib(i));
    printf("\n");

    fib_num = fib(a);
    factorial = fact(a);

    printf("Fibonnaci number %d is %d\n%d Factorial is %d\n", a, fib_num, a, factorial);
    return 0;
}
