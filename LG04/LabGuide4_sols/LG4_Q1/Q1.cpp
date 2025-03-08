/* LG4_Q1 -> Two dimensional character pointer array */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define WORDSIZE 10

void readFile(FILE *p, char **ar);
void displayWord(char *ar);
void displayWordSpecCol(char **ar, int noOfwords);

int main(void)
{
	FILE *file = fopen("words.txt", "r");

	if (file == NULL)
		printf("Error!! Can NOT read the file!");
	else
	{
		int i, noOfwords;
		char **words;

		fscanf(file, "%d", &noOfwords);
		printf("The number of words in the text file : %d\n", noOfwords);

		words = (char **)malloc(noOfwords * sizeof(char *));
		for (i = 0; i < noOfwords; i++)
			*(words + i) = (char *)malloc(WORDSIZE * sizeof(char));

		readFile(file, words);

		fclose(file);

		printf("\n WORDS\n");
		printf("*******\n");

		for (i = 0; i < noOfwords; i++)
			displayWord(*(words + i));

		displayWordSpecCol(words, noOfwords);

		for (i = 0; i < noOfwords; i++)
			free(*(words + i));  //free all columns of each row
		free(words);   //free all rows
	}
	return 0;
}


void readFile(FILE *p, char **ar)
{
	int r = 0;
	while (fscanf(p, "%s", *(ar + r)) != EOF)
		r++;
}

void displayWord(char *ar)
{
	printf("%s\n", ar);
}

void displayWordSpecCol(char **ar, int noOfwords)
{
	int col, r;

	printf("\nEnter the column number: ");
	scanf("%d", &col);

	for (r = 0; r < noOfwords; r++)
		printf("%c", *(*(ar + r) + (col - 1)));
}
