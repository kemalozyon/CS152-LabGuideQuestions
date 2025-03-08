/*LG01_Q2 -> generating n random numbers between 100-999,
the program writes each generated number and its digits of that number in reverse order into the file reverse.txt*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 2500
#define MAX 7500

int main(void)
{
	FILE *outp = fopen("reverse.txt", "w");

	srand(time(0));

	int	n, number, digit, i; //variables 

	//validate the positive number using while loop
	printf("How many numbers will you generate: ");
	scanf("%d", &n);

	fprintf(outp, "Generated number   Digits in reverse order\n");
	fprintf(outp, "****************   ***********************\n");

	i = 1;
	while (i <= n)
	{
		number = (rand() % (MAX - MIN + 1)) + MIN;
		fprintf(outp, "%16d", number);


		//seperate the digit and display in reverse order
		while (number > 0)
		{
			digit = number % 10;
			fprintf(outp, "%5d", digit);
			number = number / 10;
		}
		fprintf(outp, "\n");

		i++;
	}

	printf("%d numbers and their digits in reverse order were written to reverse.txt file\n\n", n);
	return (0);
}
