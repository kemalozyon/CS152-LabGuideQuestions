/* LG12_Q2a -> Counts the number of occurrences of the character in a sentence recursively */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int countRec(char sent[], char ch);

int main(void)
{
	char str[100];
	char ch;
	int count;

	printf("Enter a string: ");
	scanf("%[^\n]", str);

	printf("Enter a character: ");
	scanf("\n%c", &ch);

	count = countRec(str, ch);

	printf("\n%s", str);
	printf("\nThe number of '%c' is %d\n\n", ch, count);

	return(0);
}

int countRec(char sent[], char ch)
{
	if (*sent == '\0')
		return 0;
	else
	{
		if (*sent == ch || *sent == (ch - ('a' - 'A')) || *sent == (ch + ('a' - 'A')))
			return(1 + countRec(sent + 1, ch));
		else
			return(countRec(sent + 1, ch));
	}
}
