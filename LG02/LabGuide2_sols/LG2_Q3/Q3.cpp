/*LG2_Q3 -> Finding the max number in the given numbers. Calculate and write the average to the text file.*/
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define SENTINEL -1

int main(void)
{
	FILE *out1 = fopen("result.txt", "w");

	int arr[10];
	int i = 0, size;
	double avg, sum = 0;
	int max = -999999;

	printf("Enter a number: ");
	scanf("%d", arr + i);

	//fill the array until the size is reaced or sentinel value is entered
	if (*(arr + i) != -1) {

		while (*(arr + i) != SENTINEL && i != 10) {

			sum += *(arr + i);

			if (*(arr + i) > max)
				max = *(arr + i);

			i++;
			if (i != 10)
			{
				printf("Enter a number: ");
				scanf("%d", arr + i);
			}

		}

		if (i == 10)//check if the size is reached
			printf("10 number is entered. Array size will be exceeded!!");

		size = i;

		//calculae the avg
		avg = (sum - max) / (size - 1);
		fprintf(out1, "Maximum number is %d \nAverage is %.2f", max, avg);
		fclose(out1);

		printf("\n\nResult is printed!!");
	} // if
	
	else printf("\nProgram terminated!");
	return(0);
	
}