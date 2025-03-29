#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    char racerName[30];
    char profession[50];
    int champYear;
    double bestDuration;
} racer_t;

int main(void){
    racer_t *racer = (racer_t *)malloc(sizeof(racer_t));
    strcpy(racer->racerName,"Dale Earnhardt");
    strcpy(racer->profession, "Nascar");
    racer->champYear = 1998;
    racer->bestDuration = 23.14;

    printf("\nRacer Information:\n");
    printf("Name: %s\n", racer->racerName);
    printf("Profession: %s\n", racer->profession);
    printf("Championship Year: %d\n", racer->champYear);
    printf("Best Duration: %.2f\n", racer->bestDuration);
    
}