/*LG01_Q1 -> Swap operation using the call by reference*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//swap operation
void swap(int* x, int* y);

int main(void)
{
	int a, b; //variables 

	//check numbers positive or not
	do {
		printf("Enter first number: ");
		scanf("%d", &a);
		if (a <= 0)
			printf("First number must be positive.\n");
	} while (a <= 0);

	printf("\n");
	do {
		printf("Enter second number: ");
		scanf("%d", &b);
		if (b <= 0)
			printf("Second number must be positive.\n");
	} while (b <= 0);

	//display results
	printf("\nBefore swap: a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("After swap: a = %d, b = %d\n", a, b);

	return (0);
}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
