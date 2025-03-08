//LG7_Q3 -> Reads the file named “morning.txt” and finds how many words there are in each line of the paragraph. 
//Display the line numbers and the number of words of each line.

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *inp = fopen("morning.txt", "r");
	if (inp == NULL)
		printf("The file does not exists!!");
	else
	{
		char word[100];
		int wordcount = 0,	//word number
			status,
			i = 1;			//line number

		status = fscanf(inp, "%s", word);
		while (status != EOF)
		{
			while (strcmp(word, "EOL") != 0)
			{
				wordcount++;
				status = fscanf(inp, "%s", word);
			}
			printf("\n%2d. line contains %d words", i, wordcount);
			i++;			//line number
			wordcount = 0;	//wordcount gets 0 for the new line
			status = fscanf(inp, "%s", word);
		}
	}
	fclose(inp);

	return 0;
}
