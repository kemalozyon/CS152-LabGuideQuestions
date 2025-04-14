/* LG14_Q1b -> Finds the number of records in the files, creates a dynamic array, Reads the numbers into the array, and displays them on teh screen */

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
		fseek(fp, 0, SEEK_END);

		int cnt = ftell(fp)/sizeof(int);

		rewind(fp);

		printf("There are %d numbers in the files\n", cnt);

		int *arr = (int *)malloc(sizeof(int)*cnt);

		fread(arr, sizeof(int), cnt, fp);
		
		for(int i=0; i<cnt; i++)
			printf("%d ", *(arr+i));
		
		fclose(fp);

		free(arr);
	}
	return 0;
}
