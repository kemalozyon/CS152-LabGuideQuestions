/* LG6_Q1 -> Reads customers' information from the text file and displays them on the screen */

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20
#define MIN 5
#define SIZE 20

#define SINGLE 1000
#define TWIN 2500
#define DOUBLE 3500

typedef struct {
	int roomNum;
	char roomType;
}room_t;

typedef struct {
	char name[SIZE];
	int	birthyear;
	int day;
	room_t roomInfo;
	double payment;
}customer_t;

//read customers information form the file
void readFromFile(FILE *inp, customer_t *customers, int noOfCust);

//display customers information on the screen
void displayAll(customer_t *customers, int noOfCust);

//calculate the total earnings of the hotel
double calculateTotalEarnings(customer_t *customers, int noOfCust);

//find customers having maximum payment
int findCustomerMaxPayment(customer_t *customers, int noOfCust);

int main(void)
{
	FILE *inp = fopen("customers.txt", "r");;

	if (inp == NULL)
		printf("The file can NOT be opened!\n");
	else
	{
		srand(time(NULL));

		int noOfCust = rand() % (MAX - MIN + 1) + MIN;
		printf("\n%d Customers' info will be read:\n ", noOfCust);

		customer_t *customers = (customer_t*)malloc(sizeof(customer_t)*noOfCust);

		if (customers == NULL) {
			printf("Memory allocation error.\n");
		}
		else
		{
			double	total;
			int	cnt, maxIndx;

			readFromFile(inp, customers, noOfCust);

			fclose(inp);

			displayAll(customers, noOfCust);

			total = calculateTotalEarnings(customers, noOfCust);

			printf("\nTotal Earnings of the hotel : %.2f\n", total);

			maxIndx = findCustomerMaxPayment(customers, noOfCust);
			printf("\nThe Customer having maximum payment for accommodation:\n%s with the price %.2f TL\n",
				(customers + maxIndx)->name, (customers + maxIndx)->payment);

			free(customers);
		}
	}
	return 0;
}

void readFromFile(FILE *inp, customer_t *customers, int noOfCust)
{

	double roomPrice;

	for (int i = 0; i < noOfCust; i++)
	{
		fscanf(inp, "%s %d %d %d %c", (customers + i)->name, &(customers + i)->birthyear, &(customers + i)->day, &(customers + i)->roomInfo.roomNum, &(customers + i)->roomInfo.roomType);

		switch ((customers + i)->roomInfo.roomType)
		{
		case 'S':
			roomPrice = SINGLE;
			break;

		case 'T':
			roomPrice = TWIN;
			break;
		case 'D':
			roomPrice = DOUBLE;
			break;
		}

		(customers + i)->payment = (customers + i)->day * roomPrice;

	}
}

//ALTERNATIVE SOLUTION
/*void readFromFile(FILE *inp, customer_t *customers, int noOfCust)
{
	customer_t tmp;

	double roomPrice;

	int i = 0;
	while(fscanf(inp, "%s %d %d %d %c", tmp.name, &tmp.birthyear, &tmp.day, &tmp.roomInfo.roomNum, &tmp.roomInfo.roomType) != EOF && i < noOfCust)
	{
		*(customers + i) = tmp;

		switch ((customers + i)->roomInfo.roomType)
		{
		case 'S':
			roomPrice = SINGLE;
			break;

		case 'T':
			roomPrice = TWIN;
			break;
		case 'D':
			roomPrice = DOUBLE;
			break;
		}

		(customers + i)->payment = (customers + i)->day * roomPrice;
		i++;
	}
}
*/

void displayAll(customer_t *customers, int noOfCust)
{
	printf("\nName           BYear   Day   Room Num   Type    Payment  \n");
	printf("-------------------------------------------------------\n");

	for (int i = 0; i < noOfCust; i++)
		printf("%-15s %4d %5d %7d %8c %11.2f\n", (customers + i)->name,
		(customers + i)->birthyear,
			(customers + i)->day,
			(customers + i)->roomInfo.roomNum,
			(customers + i)->roomInfo.roomType,
			(customers + i)->payment);
}

double calculateTotalEarnings(customer_t *customers, int noOfCust)
{
	double total = 0;

	for (int i = 0; i < noOfCust; i++)
		total += (customers + i)->payment;

	return total;
}

int findCustomerMaxPayment(customer_t *customers, int noOfCust)
{
	int maxIndx = 0;

	for (int i = 1; i < noOfCust; i++)
		if ((customers + i)->payment > (customers + maxIndx)->payment)
			maxIndx = i;

	return maxIndx;
}

