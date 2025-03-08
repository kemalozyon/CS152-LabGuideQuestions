/* LG2_Q1a -> Checks the results */
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	int x = 34, y; //Decleare and initialize x and y variables 
	int *ptrA = &x; //initialize pointer for variable x
	int *ptrB; //Decleare a pointer

	*ptrA = x + 2;
	y = *ptrA + 5;
	ptrB = ptrA;
	*ptrA = x + y;


	//display the variables of x, y and the pointers
	printf("\nValue represented by &x is %p", &x);
	printf("\nValue represented by &y is %p", &y);
	printf("\nValue represented by ptrA is %p", ptrA);
	printf("\nValue represented by *ptrA %d", *ptrA);
	printf("\nValue represented by x is %d", x);
	printf("\nValue represented by ptrB is %p", ptrB);
	printf("\nValue represented by *ptrB is %d", *ptrB);
	printf("\nValue represented by (ptrA + 3) is %p", ptrA + 3);
	printf("\nValue represented by (*ptrA + 3) is %d\n", (*ptrA + 3));

	return 0;
}

/*
Value represented by &x is 010FFA60
Value represented by &y is 010FFA54
Value represented by ptrA is 010FFA60
Value represented by *ptrA 77
Value represented by x is 77
Value represented by ptrB is 010FFA60
Value represented by *ptrB is 77
Value represented by (ptrA + 3) is 010FFA6C
Value represented by (*ptrA + 3) is 80
*/