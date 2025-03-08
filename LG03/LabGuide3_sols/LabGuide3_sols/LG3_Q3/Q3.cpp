#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void inputDistances(int *pDist, int count);
double calculateConsumption(int *pDist, int count);
int main(void)
{
	int fuelStops;
	int *pDistances;
	double consumption;
	printf("How many times did you refuel? ");
	scanf("%d", &fuelStops);
	while (fuelStops > 0)
	{
		pDistances = (int *)malloc(sizeof(int) * fuelStops);
		if (pDistances != NULL)
		{
			inputDistances(pDistances, fuelStops);
			consumption = calculateConsumption(pDistances, fuelStops);
			printf("The average fuel consumption per 100 km: %.2f liters\n", consumption);
			free(pDistances);
			printf("\nHow many times did you refuel? ");
			scanf("%d", &fuelStops);
		}
		else
		{
			printf("No more available memory!\n");
			fuelStops = -1;
		}
	}
	return 0;
}
void inputDistances(int *pDist, int count)
{
	int i;
	printf("Enter distances traveled after each refuel (km): ");
	for (i = 0; i < count; i++)
		scanf("%d", pDist + i);
}
double calculateConsumption(int *pDist, int count)
{
	int i;
	double totalDistance = 0;
	double fuelUsed = count * 50.0; // Assuming 50 liters per refuel
	for (i = 0; i < count; i++)
		totalDistance += *(pDist + i);

	return (fuelUsed / totalDistance) * 100;
}
