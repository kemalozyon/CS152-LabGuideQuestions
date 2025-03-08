#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define SIZEWORD 20
#define SIZESENT 200
void convertToUpper(char word[]);
int main(void)
{
	char sent[SIZESENT] = "", word[SIZEWORD];
	int	cnt = 0;
	printf("Enter a word (or END to stop): ");
	scanf("%s", word);
	while (strcmp(word, "END") != 0)
	{
		cnt++;
		convertToUpper(word);
		strcat(sent, word);
		strcat(sent, " ");

		printf("Enter a word (or END to stop): ");
		scanf("%s", word);
	}

	printf("You have entered %d words\n\n", cnt);
	printf("The sentence form in uppercase of the given words:\n%s\n", sent);

	return(0);
}
void convertToUpper(char word[])
{
	int i, len;

	len = strlen(word);

	for (i = 0; i < len; i++)
		if (word[i] >= 'a' && word[i] <= 'z')
			word[i] = word[i] - ('a' - 'A');
}