// Second largest element without sorting

#include <stdio.h>

int main()
{
    int a[8] = {10, 2, 5, 6, 92, 122, 36, 96};
    int first = a[0], second = a[0];
    for(int i = 0;i < 8; i++) {
	if (a[i] > first){
	    second = first;
	    first = a[i];
	}
	else if (a[i] > second && a[i] != first)
	    second = a[i];
    }
    printf("%d, %d\n", first, second);
    return 0;
}
