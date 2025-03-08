/*LG4_Q3 -> Reads all products’s information from the file into a structure array and
displays them with the discounted price and the saved amount on the screen */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct {
	char pname[SIZE];
	double  price;
	int discRate;
}product_t;

int main(void)
{
	FILE* inp = fopen("amazon.txt", "r");

	if (inp == NULL)
		printf("Error! File counldn't be opened!\n");
	else
	{
		product_t* prod;
		int	noOfProd, status, i = 0;

		fscanf(inp, "%d", &noOfProd);
		prod = (product_t*)malloc(noOfProd * sizeof(product_t));

		status = fscanf(inp, "%s %lf %d", (prod + i)->pname, &(prod + i)->price, &(prod + i)->discRate);
		while (status != EOF && i < noOfProd)
		{
			i++;
			status = fscanf(inp, "%s %lf %d", (prod + i)->pname, &(prod + i)->price, &(prod + i)->discRate);
		}

		double discAmount, savedAmount;

		printf("\nThere are %d products in the market\n\n", noOfProd);
		printf("PRODUCT NAME      PRICE      DISCOUNT  DISC. PRICE   SAVED AMOUNT\n");
		printf("************      *********  ********  ***********   ************\n");
		for (i = 0; i < noOfProd; i++)
		{
			discAmount = (prod + i)->price * (prod + i)->discRate / 100.0;
			printf("%-17s %7.2f $       %%%-5d %7.2f $ %12.2f $\n", (prod + i)->pname, (prod + i)->price, (prod + i)->discRate, (prod + i)->price - discAmount, discAmount);
		}

		fclose(inp);
		free(prod);
	}
	return(0);
}