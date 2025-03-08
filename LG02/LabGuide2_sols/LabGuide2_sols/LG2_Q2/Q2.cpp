/* LG2_Q2 -> Filling an one dimensional integer array with the numbers like 4, 16, 64 ...*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define SIZE 5

int main(void)
{
	int	nums[SIZE], n = 1;
	FILE *fp = fopen("result.txt", "w"); //open the file to read

	if (fp == NULL)//check if the file is missing or not
		printf("The file couldn't be created.\n"); 
	else
	{

		fprintf(fp, "Element Name %3c Value   Address\n", ' ');
		fprintf(fp, "------------- %3c-----   --------\n", ' ');//print the headers on the txt file

		for (int i = 0; i < SIZE; i++)
		{
			n *= 2;
			*(nums + i) = n;
			fprintf(fp, "*(nums + %3d) %8d   %p\n", i, *(nums + i), nums + i);
		}//fill the array with the numbers one by one


		fclose(fp);//close the file

		printf("Successful! Please see the result.txt file for the output.\n\n");

		return 0;
	}
}
