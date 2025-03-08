/* LG4_Q2c -> Structure as a pointer */

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
	racer_t racer = { "DaleEarnhardt", "Nascar", 1998, 23.14 };
	racer_t	*ptr;

	ptr = &racer;

	printf("\nThe Nascar Racer information is:\n");
	printf("Character Name   : %s\n", ptr->racerName);
	printf("Profession       : %s\n", ptr->profession);
	printf("Appearance Year  : %d\n", ptr->championshipYear);
	printf("Broadcast Time   : %.2f\n", ptr->bestDuration);

	return 0;
}