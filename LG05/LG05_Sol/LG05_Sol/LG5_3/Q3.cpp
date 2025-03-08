#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int wStMonth;  // 1-12
	int wStYear;   // e.g., 2022
	int wEndMonth; // 1-12 (calculated)
	int wEndYear;  // e.g., 2025 (calculated)
} warranty_t;

typedef struct {
	int productID;
	int wPeriod;  // in months
	warranty_t warranty;
} product_t;

void readInfo(FILE *inp, product_t *products, int noOfProd);
void display(product_t *products, int noOfProd, int curMonth, int curYear);
void findLongestWarranty(product_t *products, int noOfProd, int curMonth, int curYear);

int main()
{
	FILE *inp = fopen("warranty.txt", "r");

	if (inp == NULL) {
		printf("Error opening inp.\n");
	}
	else
	{
		int noOfProd;
		fscanf(inp, "%d", &noOfProd);

		// Dynamic memory allocation
		product_t *products = (product_t *)malloc(noOfProd * sizeof(product_t));

		if (products == NULL) {
			printf("Memory allocation failed.\n");
		}
		else
		{
			readInfo(inp, products, noOfProd);

			// Get current date
			int curMonth, curYear;
			printf("Enter current month (1-12): ");
			scanf("%d", &curMonth);

			printf("Enter current year: ");
			scanf("%d", &curYear);

			// Display product warranty status
			display(products, noOfProd, curMonth, curYear);
			findLongestWarranty(products, noOfProd, curMonth, curYear);

		}
		free(products);
		fclose(inp);
	}

	return 0;
}

void readInfo(FILE *inp, product_t *products, int noOfProd)
{
	// Read product info from the inp
	for (int i = 0; i < noOfProd; i++)
	{
		fscanf(inp, "%d %d %d %d",
			&(products + i)->productID,
			&(products + i)->wPeriod,
			&(products + i)->warranty.wStMonth,
			&(products + i)->warranty.wStYear);

		// Calculate warranty end month and year
		int totalMonths = products[i].warranty.wStMonth + products[i].wPeriod;

		(products + i)->warranty.wEndYear = (products + i)->warranty.wStYear + (totalMonths / 12);
		(products + i)->warranty.wEndMonth = totalMonths % 12;

		if ((products + i)->warranty.wEndMonth == 0) {
			(products + i)->warranty.wEndMonth = 12;
			(products + i)->warranty.wEndYear--;
		}
	}
}
// Display product warranty information
void display(product_t *products, int noOfProd, int curMonth, int curYear)
{
	printf("\nWarranty Status:\n");
	printf("ID      Period   Start    End      Status\n");
	printf("---------------------------------------\n");

	for (int i = 0; i < noOfProd; i++) {
		printf("%5d   %5d    %02d/%d  %02d/%d ",
			products[i].productID,
			products[i].wPeriod,
			products[i].warranty.wStMonth, products[i].warranty.wStYear,
			products[i].warranty.wEndMonth, products[i].warranty.wEndYear);

		if (products[i].warranty.wEndYear > curYear ||
			(products[i].warranty.wEndYear == curYear && products[i].warranty.wEndMonth >= curMonth))
			printf(" Active\n");
		else
			printf(" Expired\n");
	}
}


// Find the longest remaining warranty
void findLongestWarranty(product_t *products, int noOfProd, int curMonth, int curYear)
{
	int maxMonths = 0, maxIndex = 0;
	int remMonths; //remaining months

	for (int i = 0; i < noOfProd; i++)
	{
		int remMonths = ((products + i)->warranty.wEndYear - curYear) * 12 + ((products + i)->warranty.wEndMonth - curMonth);

		if (remMonths > maxMonths)
		{
			maxMonths = remMonths;
			maxIndex = i;
		}
	}
	
	printf("\nProduct with Longest Warranty Remaining: ID %d with %d months left.\n",
		products[maxIndex].productID, maxMonths);
}


