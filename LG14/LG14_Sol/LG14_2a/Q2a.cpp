
/* LG14_Q2a -> Reads and displays n numbers one by one from the binary file created by the user */

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createBinaryFile(void);

int main(void)
{
	int num, * arr;

	createBinaryFile();

	printf("Please enter the number of items to be read: ");
	scanf("%d", &num);

	arr = (int*)malloc(sizeof(int) * num);

	FILE* fp = fopen("numbers.bin", "rb");

	if (fp == NULL)
		printf("Error reading the file!!");
	else
	{
		for (int i = 0; i < num; i++)
			fread(arr + i, sizeof(int), 1, fp);

		fclose(fp);

		for (int i = 0; i < num; i++)
			printf("%3d. %d\n", i + 1, arr[i]);
	}
	free(arr);
	return 0;
}

void createBinaryFile(void)
{
	int n;

	srand(time(NULL));


	FILE* fp = fopen("numbers.bin", "wb");

	for (int i = 0; i < 250; i++) {
		n = rand() % 5000 + 1;

		fwrite(&n, sizeof(int), 1, fp);
	}


	fclose(fp);
}