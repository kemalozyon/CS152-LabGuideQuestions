/* LG14_Q2d -> Read and display the mth from the last, and the nth from the last items in the file */

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define SIZE 250

int main(void)
{
	FILE* fp = fopen("numbers.bin", "rb");

	if (fp == NULL)
		printf("Error reading the file!!");
	else
	{
		int m, n, readNum;

		printf("Please enter the order of the item to be read from the end : ");
		scanf("%d", &m);

		fseek(fp, (-m) * sizeof(int), SEEK_END);
		fread(&readNum, sizeof(int), 1, fp);

		printf("%d. %d\n", SIZE - m + 1, readNum);


		printf("\nPlease enter the second order of the item to be read from its current position: ");
		scanf("%d", &n);

		fseek(fp, (-n) * sizeof(int), SEEK_CUR);
		fread(&readNum, sizeof(int), 1, fp);

		printf("%d. %d\n", SIZE - m - n + 2, readNum);
	}

	fclose(fp);

	return 0;
}