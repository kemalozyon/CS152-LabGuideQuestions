/* LG14_Q1a -> Reads and displays numbers one by one from the given binary file */

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
	FILE* fp = fopen("nums.bin", "rb");

	if (fp == NULL)
		printf("Error reading the file!!");
	else
	{
		int num, cnt = 0;

		fread(&num, sizeof(int), 1, fp);

		while (!feof(fp))
		{
			printf("%d ", num);
			cnt++;
			fread(&num, sizeof(int), 1, fp);
		}

		printf("\n\nThere are %d numbers in the files\n", cnt);

		fclose(fp);
	}
	return 0;
}
