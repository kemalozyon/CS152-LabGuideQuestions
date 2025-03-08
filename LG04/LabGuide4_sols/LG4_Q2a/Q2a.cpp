/*LG4_Q2a -> Initializing the structure */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//structure definition
typedef struct {
	char racerName[20];
	char profession[50];
	int championshipYear;
	double bestDuration;
} racer_t;


int main(void)
{
	racer_t racer = { "DaleEarnhardt", "Nascar", 1998, 23.14 };

	printf("The Nascar Racer information is:\n");
	printf("Racer Name       : %s\n", racer.racerName);
	printf("Profession       : %s\n", racer.profession);
	printf("Cahmpionship Year: %d\n", racer.championshipYear);
	printf("Best Duration    : %.2f\n", racer.bestDuration);

	return 0;
}