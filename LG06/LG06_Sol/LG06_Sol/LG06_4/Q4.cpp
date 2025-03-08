/*LG6_Q4 -> Calls a fnc menu and calling fncs for selected menu item     */
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MIN 20
#define MAX 199

//Menu fnc
int menu();

//fill array
void fillArray(int **arr, int m);

//display array elements
void displayArray(int **arr, int m);

//search for a value
int searchAValue(int **arr, int m, int value);

//MAIN
int main(void)
{
	int m, i;
	printf("Please Enter the dimension: ");
	scanf("%d", &m);

	int **arr = (int **)malloc(m * sizeof(int *));

	for (i = 0; i < m; i++)
		*(arr + i) = (int *)malloc(m * sizeof(int));

	int value, cnt;
	int choice = menu();

	while (choice != 4)
	{
		//check the choice and call the suitable functions for each choice
		switch (choice)
		{
		case 1:
			fillArray(arr, m);
			printf("Array filled with random numbers (%d-%d)\n", MIN, MAX);
			break;
		case 2:
			displayArray(arr, m);
			break;
		case 3:
			printf("Enter the value to search: ");
			scanf("%d", &value);

			cnt = searchAValue(arr, m, value);

			if (cnt == 0)
				printf("The array does NOT contain the value %d\n", value);
			else
				printf("The number of occurences: %d\n", cnt);
		}
		//call the menu function to ask a user choice again
		choice = menu();
	}

	for (i = 0; i < m; i++)
		free(*(arr + i));
	free(arr);


	return 0;
}
//Menu fnc
int menu()
{
	int choice;

	printf("\n\tMENU");
	printf("\n1.Fill array with Random numbers");
	printf("\n2.Display Array Elements");
	printf("\n3.Display #of Occurrences of a value");
	printf("\n4.Exit");

	do {
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
	} while (choice < 1 || choice>4);

	return (choice);
}

//fill array
void fillArray(int **arr, int m)
{
	srand(time(NULL));

	int i, j;

	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++)
		{
			*(*(arr + i) + j) = rand() % ((MAX + 1) - MIN) + MIN; //20-199
		}
}

//display array elements
void displayArray(int **arr, int m)
{
	printf("Content of the array\n");
	printf("********************\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%4d", *(*(arr + i) + j));
		printf("\n");
	}
}

//search for a value
int searchAValue(int **arr, int m, int value)
{
	int cnt = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			if (*(*(arr + i) + j) == value)
				cnt++;

	return (cnt);
}
