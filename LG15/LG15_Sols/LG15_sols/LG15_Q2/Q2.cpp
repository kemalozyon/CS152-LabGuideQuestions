/* LG15_Q2 -> Displays the given words in reverse order by using a stack */

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack_str.h"

int main(void)
{
	FILE* fbp = fopen("players.txt", "r");

	if (fbp == NULL)
		printf("Error!! Please check the binary file...\n");
	else
	{
		stack_t stack;
		initializeS(&stack);
		int status;

		char word[SIZE];

		status = fscanf(fbp, " %[^\n]", word);

		while (status != EOF)
		{
			push(&stack, word);
			status = fscanf(fbp, " %[^\n]", word);
		}

		printf("PLAYERS IN REVERSE ORDER\n");
		printf("***********************\n");

		while (!isEmptyS(&stack))
		{
			strcpy(word, pop(&stack));
			printf("%s\n", word);
		}
	}

	return 0;
}
