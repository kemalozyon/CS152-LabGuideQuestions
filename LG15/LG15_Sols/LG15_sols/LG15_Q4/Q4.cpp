// LG15_Q4 -> Reads an octal number and converts it to decimal number using a stack

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include "stack_int.h"

int
convertToDecimal(int number);

int main(void)
{
	int num;

	printf("Enter an octal number: ");
	scanf("%d", &num);

	int decEq = convertToDecimal(num);

	printf("Decimal equivalent of the number is: %d\n", decEq);

	return(0);
}

int
convertToDecimal(int number)
{
	int decNum = 0;

	stack_t s;
	initializeS(&s);

	//put the digits of the given number into the stack
	while (number > 0)
	{
		push(&s, number % 10);
		number /= 10;
	}

	//convertion of the octal number to decimal number
	while (!isEmptyS(&s))
	{
		decNum += pow(8, s.top) * pop(&s);
	}
	return decNum;
}
