/* LG3_Q2 -> Filling a two dimensional integer array with the numbers like 2, 4, 8... */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define SIZE 3

int main(void)
{
	FILE *fp = fopen("result.txt", "w");

		int	arr[SIZE][SIZE], n = 1;

		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
			{
				n *= 2;
				*(*(arr + i) + j) = n;
			}

		fprintf(fp, "Element Name %12c Value   Address\n", ' ');
		fprintf(fp, "-------------------- %4c -----  --------\n", ' ');

		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				fprintf(fp, "*(*(arr + %3d) + %3d) %8d   %p\n", i, j, *(*(arr + i) + j), *(arr + i) + j);

		fclose(fp);

		printf("Successful! Please see the result.txt file for the output.\n\n");
}
