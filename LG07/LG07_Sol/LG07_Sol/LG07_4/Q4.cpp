/* LG7_Q4 -> Find the LAST longest word in an array */

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#define SIZE 20

int longest(char words[][SIZE], int n);

int main(void)
{
	char words[SIZE][SIZE];
	char temp[SIZE];
	int i, maxInd;

	i = 0;
	printf("Enter a word (or END): ");
	scanf("%s", temp);

	while (strcmp(temp, "END") != 0)
	{
		strcpy(words[i], temp);
		i++;

		printf("Enter a word (or END): ");
		scanf("%s", temp);
	}

	maxInd = longest(words, i);

	printf("\n\nLongest word: %s\nLength: %d\n\n", words[maxInd], strlen(words[maxInd]));

	return (0);
}

int longest(char words[][SIZE], int n)
{
	int i, maxInd = 0;

	for (i = 1; i < n; i++)
		if (strlen(words[i]) >= strlen(words[maxInd]))
			maxInd = i;

	return maxInd;
}

