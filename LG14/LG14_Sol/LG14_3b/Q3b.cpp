// LG14_Q3b -> will read the “surgery.bin” and write surgery information 
//if the status is “Finished” into a binary file named “output.bin”. Display the output file on the screen.

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int
main(void)
{

	FILE* bfp = fopen("surgery.bin", "rb");
	FILE* bout = fopen("output.bin", "wb");
	int i = 0;

	if (bfp == NULL)
		printf("Binary file can not be opened");
	else
	{
		surgery_t* mList, mArr[SIZE3];
		int size = 0, count = 0;

		//go to the end of the file
		fseek(bfp, 0, SEEK_END);

		//find the number of records in the file
		size = ftell(bfp) / sizeof(surgery_t);

		//dynamically create the array
		mList = (surgery_t*)malloc(size * sizeof(surgery_t));

		rewind(bfp);

		fread(mList, sizeof(surgery_t), size, bfp);

		while (i < size)
		{
			if (strcmp(mList[i].status, "Finished") == 0)
			{
				fwrite(mList + i, sizeof(surgery_t), 1, bout);
				count++;
			}
			i++;
		}

		fclose(bout);

		FILE* bout = fopen("output.bin", "rb");

		fread(mArr, sizeof(surgery_t), count, bout);

		printf("BINARY FILE CONTENT\n");
		printf("*******************\n");
		printf("\nDoctor		   Patient		 Operaiton	     Time           Status\n");
		printf("-------------------------------------------------------------------------------------------\n");

		for (int k = 0; k < count; k++)
			printf("%-20s %-20s %-20s %-10d %-25s\n", mArr[k].leadDoctor, mArr[k].patient, mArr[k].operation, mArr[k].expectedOperationTime, mArr[k].status);

		fclose(bfp);
		fclose(bout);
	}
	return 0;
}
