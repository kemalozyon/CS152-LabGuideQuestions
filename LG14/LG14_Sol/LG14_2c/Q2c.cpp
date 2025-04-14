/* LG14_Q2c -> Request a user input for which number out of the 500 in the file should be read from the beginning */

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main(void)
{
	FILE* fp = fopen("numbers.bin", "rb");

	if (fp == NULL)
		printf("Error reading the file!!");
	else
	{
		int num, readNum;

		do {
			printf("Please enter the order of the item to be read: ");
			scanf("%d", &num);
		} while (num < 1 || num > 250);

		fseek(fp, sizeof(int) * (num - 1), SEEK_SET);

		fread(&readNum, sizeof(int), 1, fp);

		fclose(fp);

		printf("\n%3d. %d\n", num, readNum);
	}

	return 0;
}