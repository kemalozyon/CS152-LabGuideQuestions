// LG13_Q1 -> Recursively check if an array is sorted in ascending order

#define _CRT_SECURE_NO_WARNINGS 
#define SIZE 30

#include <stdio.h>

// Recursive function to check if an array is sorted in ascending order
int isSorted(int *arr, int n) 
{
	// If the array has one or no element, it is sorted
	if (n == 1 || n == 0) 
		return 1;  // True (sorted)

	// If the current element is greater than the next element, return false
	if (arr[n - 1] < arr[n - 2]) 
		return 0;  // False (not sorted)

	// Recall the function for the remaining part of the array
	return isSorted(arr, n - 1);
}

int main(void) 
{
	int arr[SIZE], num, i;

	printf("Enter a positive number: ");
	scanf("%d", &num);
	
	i = 0;
	while(num > 0 && i < SIZE)
	{
		arr[i] = num;
		i++;

		printf("Enter a positive number: ");
		scanf("%d", &num);
	}

	// Check if the array is sorted
	if (isSorted(arr, i)) 
		printf("The array is sorted in ascending order.\n");
	else 
		printf("The array is NOT sorted in ascending order.\n");

	return 0;
}