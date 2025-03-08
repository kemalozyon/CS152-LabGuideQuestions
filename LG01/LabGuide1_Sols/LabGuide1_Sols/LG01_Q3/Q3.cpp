#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define SIZE 50

int fillArray(int nums[]);
int isPrime(int num);
int isPerfect(int num);
//returns the count of Prime and the count of Perfect numbers in the array
void findPrimePerfect(int ar[], int size, int* noOfPrimes, int* noOfPerfects);

int main(void)
{
	int n;
	int nums[SIZE];
	int cntOfPrimes = 0,
		cntOfPerfects = 0;

	n = fillArray(nums);

	// find the count Of Prime and Perfect numbers 
	findPrimePerfect(nums, n, &cntOfPrimes, &cntOfPerfects);

	// Display the count Of Prime and Perfect numbers 
	printf("\nThere are %d prime numbers\n", cntOfPrimes);
	printf("There are %d perfect numbers\n", cntOfPerfects);

	return(0);
}

int fillArray(int nums[])
{
	int value, i = 0;

	printf("\nEnter a positive number:  ");
	scanf("%d", &value);

	// Input positive integers
	while (i < SIZE && value > 0)
	{
		nums[i] = value;
		i++;

		printf("Enter a positive number:  ");
		scanf("%d", &value);
	}

	return i;
}

// Function to check if a number is prime
int isPrime(int num)
{
	if (num <= 1) return 0; // Not prime
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return 0; // Not prime
	}
	return 1; // Prime
}

// Function to check if a number is perfect
int isPerfect(int num)
{
	int sum = 0;
	for (int i = 1; i <= num / 2; i++)
	{
		if (num % i == 0)
			sum += i;
	}
	return sum == num; // Perfect number if the sum of divisors equals the number
}

// Function to find the count of Prime and Perfect numbers
void findPrimePerfect(int ar[], int size, int* noOfPrimes, int* noOfPerfects)
{
	for (int i = 0; i < size; i++)
	{
		if (isPrime(ar[i]))
			(*noOfPrimes)++;
		if (isPerfect(ar[i]))
			(*noOfPerfects)++;
	}
}
