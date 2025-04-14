// LG15_Q3 -> Display the structure information in a stack
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#include "stack_struct.h"

int main(void)
{
	FILE* binp = fopen("Competitions.bin", "rb");

	if (binp == NULL)
		printf("File can not open");
	else
	{
		SType c;
		stack_t st;
		int status;

		initializeS(&st);
		fread(&c, sizeof(comp_t), 1, binp);
		while (!feof(binp))
		{
			push(&st, c);
			fread(&c, sizeof(comp_t), 1, binp);
		}

		printf("Competition Name%35cStart Time %12c End Time\n", ' ', ' ');
		printf("************************************************************************************************\n");

		while (!isEmptyS(&st))
		{
			c = pop(&st);
			printf("%-50s %-23s %-23s\n", c.cName, c.startTime, c.endTime);
		}
	}

	return(0);
}

