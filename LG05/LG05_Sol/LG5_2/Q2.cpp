/* LG5_Q2 -> Appliance */

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int id;
	int consump;
	double hours;
}appliance_t;

int readFromFile(FILE *inp, appliance_t *app, int noOfAppliance)
{
	int i=0;
	//after opening the file Appliance informations getting from the file into an array
	while (fscanf(inp, "%d %d %lf", &(app + i)->id, &(app + i)->consump, &(app + i)->hours) != EOF && i < noOfAppliance)
		i++;

	return i;
}

//display appliance records and calculate daily energy consumption
void display(appliance_t *app, int noOfAppliance)
{
	printf("\nID   Cons (W)    Hours    Daily Energy (kWh)\n");
	printf("--------------------------------------------\n");

	for (int i = 0; i < noOfAppliance; i++)
	{
		double energy = ((app + i)->consump * (app + i)->hours) / 1000.0;
		printf("%-5d %6d %8.2f %8.2f\n", (app + i)->id, (app + i)->consump, (app + i)->hours, energy);
	}
}

int searchItem(appliance_t *app, int noOfAppliance, int srchId)
{
	int i = 0;
	while (i < noOfAppliance)
	{
		if ((app + i)->id == srchId)
			return i;
		i++;
	}

	return -1;
}

int main(void)
{
	FILE *inp = fopen("appliances.txt", "r");

	if (inp == NULL)
		printf("File NOT found\n");
	else
	{
		int noOfAppliance;

		fscanf(inp, "%d", &noOfAppliance);
		appliance_t *app = (appliance_t*)malloc(noOfAppliance * sizeof(appliance_t));

		if (app == NULL) {
			printf("No more available memory!\n");
		}
		else
		{
			int status, id;
			double sum = 0;

			noOfAppliance = readFromFile(inp, app, noOfAppliance);
			display(app, noOfAppliance);

			do {
				//getting id of a Appliance from the user
				printf("\nEnter the id of an appliance : ");
				scanf("%d", &id);

				if (id > 0)
				{
					int indx = searchItem(app, noOfAppliance, id);

					if (indx == -1)
						printf("Appliance NOT found!!\n");
					else
					{
						//displaying info about given Appliance
						printf("\nId        : %6d\n", (app + indx)->id);
						printf("Power Cons: %6d\n", (app + indx)->consump);
						printf("Hours     : %6.2f\n", (app + indx)->hours);
					}
				}
			} while (id > 0);

			free(app);
		}
		fclose(inp);
	}

	return 0;
}
