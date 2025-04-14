/* LG13_Q2 -> Recursively find the sum of divisors of  a given number, and check whether the number is perfect or not */

#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>

int sumDivisors(int num, int divisor)
{
	if (divisor == 1)		//all numbers are divisible by 1
		return (1);
	else
		if (num % divisor == 0)
			return (divisor + sumDivisors(num, divisor - 1));
		else
			return(sumDivisors(num, divisor - 1));
}

int main(void)
{
	int number;

	do {
		printf("Enter a non-negative number: ");
		scanf("%d", &number);
	} while (number <= 0);

	if (number == sumDivisors(number, number / 2))
		printf("\n%d is a perfect number!\n", number);
	else
		printf("\n%d is NOT a perfect number!\n", number);

	return 0;
}