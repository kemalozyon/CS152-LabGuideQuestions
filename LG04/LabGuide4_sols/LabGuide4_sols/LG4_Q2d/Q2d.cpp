/* LG4_Q2d -> Structure Array */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char racerName[20];
	char profession[50];
	int championshipYear;
	double bestDuration;
} racer_t;

int main(void)
{
	FILE *fp = fopen("drivers.txt", "r");
	racer_t *driver;
	int count;

	if (fp == NULL)
		printf("The file drivers.txt couldn't be opened.\n");
	else
	{
		fscanf(fp, "%d", &count);

		driver = (racer_t *)malloc(count * sizeof(racer_t));

		printf("There are %d drivers.\n", count);

		for (int i = 0; i < count; i++)
			fscanf(fp, "%s %s %d %lf", (driver + i)->racerName, (driver + i)->profession, &(driver + i)->championshipYear, &(driver + i)->bestDuration);

		printf("\nThe Car Racer information is:\n");
		printf("**************************************\n");

		for (int i = 0; i < count; i++)
		{
			printf("Racer Name       : %s\n", (driver + i)->racerName);
			printf("Profession       : %s\n", (driver + i)->profession);
			printf("Appearance Year  : %d\n", (driver+ i)->championshipYear);
			printf("Broadcast Time   : %.2f\n", (driver + i)->bestDuration);
			printf("**************************************\n");
		}

		fclose(fp);
		free(driver);
	}

	return 0;
}
