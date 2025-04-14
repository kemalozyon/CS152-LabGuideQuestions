/* LG14_Q3a -> Generates a number n, Reads n records from the binary file and Displays them */

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE1 15
#define SIZE2 20
#define SIZE3 25

typedef struct {
	char leadDoctor[SIZE2];
	char patient[SIZE2];
	char operation[SIZE3];
	int expectedOperationTime;
	char status[SIZE1];
}surgery_t;


int main(void)
{

	FILE *bfp = fopen("surgery.bin", "rb");

	if (bfp == NULL)
		printf("Binary file can not be opened");
	else
	{
		surgery_t * mLst;
		int size = 0, recordSize;

		//go to the end of the file
		fseek(bfp, 0, SEEK_END);

		//find the number of records in the file
		size = ftell(bfp) / sizeof(surgery_t);

		//dynamically create the array
		mLst = (surgery_t *)malloc(size * sizeof(surgery_t));

		printf("There are %d surgery in the file\n", size);

		srand(time(NULL));

		recordSize = 1 + rand() % size;;

		//rewind the file so that you can read it
		rewind(bfp);

		fread(mLst, sizeof(surgery_t), recordSize, bfp);

		fclose(bfp);

		printf("\n%d surgery will be displayed\n", recordSize);
		printf("\nDoctor		   Patient		 Operaiton	     Time           Status\n");
		printf("-------------------------------------------------------------------------------------------\n");

		for (int k = 0; k < recordSize; k++)
			printf("%-20s %-20s %-20s %-10d %-25s\n", mLst[k].leadDoctor, mLst[k].patient, mLst[k].operation, mLst[k].expectedOperationTime, mLst[k].status);
	}
	return 0;
}
