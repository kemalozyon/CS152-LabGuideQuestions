/* LG12_Q2b -> Counts the number of occurrences of the string in a sentence recursively */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAXS 200
#define MAXW 25

int countSub(char str[], char search[]);

int main(void)
{
	char mainstr[MAXS];
	char search[MAXW];
	int len;
	int result;

	printf("\nEnter a sentence: ");
	scanf("%[^\n]", mainstr);

	printf("Enter a word to search in the sentence: ");
	scanf("%s", search);

	result = countSub(mainstr, search);

	printf("\nThe word -%s- occurred %d times in the sentence\n", search, result);

	return(0);
}

int countSub(char str[], char search[])
{
	
	if (*str == '\0')
		return 0;
	else
	{
		int lenSearch;

		lenSearch = strlen(search);
		if (strncmp(str, search, lenSearch) == 0)
			return (1 + countSub(str + lenSearch, search));
		else
			return (countSub(str + 1, search));
	}
}