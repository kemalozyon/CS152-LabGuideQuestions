/* LG15_Q1 -> Display the digits of a given number using an int stack */

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "stack_int.h"

int main(void)
{
	int num;
	stack_t s;
	do
	{
		printf("Enter a number: ");
		scanf("%d", &num);
	} while (num <= 30);

	initializeS(&s);

	printf("Digits of %d are ", num);

	while (num != 0)
	{
		push(&s, num % 10);
		num /= 10;
	}

	while (!isEmptyS(&s))
		printf("%d ", pop(&s));

	printf("\n");

	return (0);
}