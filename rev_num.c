#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int rev_num(int num){
	int temp = 0,rem = 0;
	while(num > 0) {
		rem = num % 10;
		temp = temp * 10 + rem;
		num /= 10;
	}
	return temp;
}

int main(int argc, char ** argv)
{
	int input, output;
	
	printf("Provide the number to be reversed\n");
	scanf("%d", &input);

	output = rev_num(input);
	printf("The output is ");
	if(input % 10 == 0) {
		while(input % 10 == 0) {
			printf("0");
			input /= 10;
		}
	}
       	printf("%d\n", output);
	return 0;
}
