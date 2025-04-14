/* LG14_Q2b -> Read n numbers from the file without any usage of a loop */

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createBinaryFile(void);

int main(void)
{
	createBinaryFile();

	int num, * arr;

	printf("Please enter the number of items to be read: ");
	scanf("%d", &num);

	arr = (int*)malloc(sizeof(int) * num);

	FILE* fp = fopen("numbers.bin", "rb");

	if (fp == NULL)
		printf("Error reading the file!!");
	else
	{
		fread(arr, sizeof(int), num, fp);

		fclose(fp);

		for (int i = 0; i < num; i++)
			printf("%3d. %d\n", i + 1, arr[i]);
	}
	free(arr);

	return 0;
}

void createBinaryFile(void)
{
	int arr[250];

	srand(time(NULL));

	for (int i = 0; i < 250; i++)
	{
		arr[i] = rand() % 5000 + 1;
	}

	FILE* fp = fopen("numbers.bin", "wb");

	fwrite(arr, sizeof(int), 250, fp);

	fclose(fp);
}