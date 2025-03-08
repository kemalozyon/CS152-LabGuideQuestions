/* LG4_Q2b -> Get the structure information from the user */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	char racerName[20];
	char profession[50];
	int championshipYear;
	double bestDuration;
} racer_t;

int main(void)
{
	racer_t racer;

	printf("Enter the information of the racer:\n");
	printf("Racer Name: ");
	scanf("%s", racer.racerName);

	printf("Profession: ");
	scanf("%s", racer.profession);

	printf("Championship Year: ");
	scanf("%d", &racer.championshipYear);

	printf("Broadcast Time: ");
	scanf("%lf", &racer.bestDuration);

	printf("\nThe Racer information is:\n");
	printf("Racer Name         : %s\n", racer.racerName);
	printf("Profession         : %s\n", racer.profession);
	printf("Championship Year  : %d\n", racer.championshipYear);
	printf("Best Duration      : %.2f\n", racer.bestDuration);

	return 0;
}