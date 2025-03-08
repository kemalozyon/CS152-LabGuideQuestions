/* LG7_Q1 -> Reads and displays a sentence using different placeholders */

#define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
# define SIZE 80

int main(void)
{
	char sent[SIZE];

	printf("Enter a sentence : ");
	//scanf("%s", sent);
	//scanf("%[^\n]", sent);
	scanf("%[^0-9]", sent);

	printf("The sentence is  : %s\n", sent);

	return(0);
}
