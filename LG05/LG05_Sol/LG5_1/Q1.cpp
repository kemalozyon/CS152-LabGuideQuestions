/* LG5_Q1 -> Real Estate Agency*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int pId;
	char pType; //R-Rented or S-Sale
	double price;
	int bedroomCnt;
	int bathroomCnt;
}property_t;


void readFromFile(FILE *inp, property_t *properties, int noOfProp)
{
	int i = 0;
	while (fscanf(inp, "%d %c %lf %d %d", &(properties+i)->pId, 
									&(properties + i)->pType, 
									&(properties + i)->price,
									& (properties + i) ->bedroomCnt,
									& (properties + i) ->bathroomCnt) != EOF && i < noOfProp)
		i++;

}

void displayAndCalculate(property_t *properties, int noOfProp, double *sumSold, double *sumRented)
{
	*sumSold = 0;
	*sumRented = 0;
	
	printf("Real Estate Agency\n");
	printf("ID      Type      Price (TL)       Bedroom#  Bathroom#\n");
	printf("******************************************************\n");

	for (int i = 0; i < noOfProp; i++)
	{
		printf("%5d  ", (properties+i)->pId);

		if ((properties+i)->pType == 'R')
		{
			*sumRented += (properties+i)->price;
			printf("\tRented  ");
		}
		else
		{
			*sumSold += (properties+i)->price;
			printf("\tSold    ");
		}

		printf("%12.2f %10d %10d\n", (properties+i)->price, (properties+i)->bedroomCnt, (properties + i) ->bathroomCnt);
	}

}

int main(void)
{
	FILE *inp = fopen("properties.txt", "r");

	if (inp == NULL)
		printf("Error!!\n");
	else
	{
		double sumRented = 0, sumSold = 0;
		int noOfProp;

		//first line of the file contains the number of properties
		fscanf(inp, "%d", &noOfProp);
		property_t *properties = (property_t*)malloc(sizeof(property_t)*noOfProp);
	
		readFromFile(inp, properties, noOfProp);
		displayAndCalculate(properties, noOfProp, &sumSold, &sumRented);

		printf("\nTotal price of the Sold Properties   -> %.2f TL\n", sumSold);
		printf("Total price of the Rented Properties -> %.2f TL\n", sumRented);
	}

	return 0;
}