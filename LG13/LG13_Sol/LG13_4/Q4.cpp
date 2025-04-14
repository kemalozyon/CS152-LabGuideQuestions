/*LG13_Q4 -> Reads an number as a string from the user and its base then calls the recursive function with the given string
to return its convertDecimal  equivalent*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

//The Recursive Function that gets the  string number and its base and finds the convertDecimal  of that number
int convertDecimal(char *strnumber, int base);
int validateBase(char* str, int base);
int main(void)
{
	char strnumber[MAX];  //the variable that will hold the string number that the user will enter
	int	len,   //the variable that holds the length of the number
		deci,  //the variable that holds the convertDecimal  result of the binary number
		base, check;

	printf("Enter a number: ");
	scanf("%s", strnumber);  //read the string number into strnumber variable

	do {
		printf("Enter the base of the number: ");
		scanf("%d", &base);
		check = validateBase(strnumber, base);
	} while (check != 1);

	deci = convertDecimal(strnumber, base); //call the recursive function the binary string number and its length

	printf("The convertDecimal  is: %d\n", deci); //print the convertDecimal  result on the screen

	return(0);
}

int validateBase(char *str, int base) {
	int digit = str[0] - '0';

	if (str[0] == '\0')
		return 1;
	else if (digit < base)
		return validateBase(str + 1, base);
	else
		return -1;
}

int convertDecimal(char *strnumber, int base)
{
	if (*strnumber == '\0')
		return 0;
	else
	{
		int num = *strnumber - '0';  //convert the char to an integer
		int pow = num * powf(base, strlen(strnumber) - 1);

		return(pow + convertDecimal(strnumber + 1, base));
	}

}