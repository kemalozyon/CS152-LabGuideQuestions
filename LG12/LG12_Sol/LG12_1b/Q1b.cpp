/* LG12_Q1b -> Recursive Function that gets the number and prints its digits in the correct order */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void printDigits(int num);

int main(void)
{
	int num;					//the variable that hold the number that the user enters

	printf("Enter a number: ");
	scanf("%d", &num);			//read the number from user and put it in number variable

	printf("Digits of the number %d are:\n", num);
	printDigits(num);			//calling our recursive function with the number that the user enters

	printf("\n");

	return(0);
}

void printDigits(int num)
{
	if (num != 0)
	{
		printDigits(num / 10);
		printf("%5d", num % 10);
	}
}

/* Alternative solution
void printDigits(int num)
{
	if (num<10)                  //if number is lower than 10 this means it is the last digit
		printf("%5d", num);	 //so we can print it on the screen
	else
	{
		printDigits(num / 10);		//number divide 10 gives us the rest of the number
		printf("%5d",  num % 10);		//print the digit on the screen
		//we call our function again
	}
}
*/
