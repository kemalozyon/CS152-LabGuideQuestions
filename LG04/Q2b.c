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
    printf("Name: ");
    scanf("%s", racer->racerName);
    printf("Profession: ");
    scanf("%s", racer->profession); 
    printf("Championship Year: ");
    scanf("%d", &racer->champYear);
    printf("Best Duration: ");
    scanf("%lf", &racer->bestDuration);

    printf("\nRacer Information:\n");
    printf("Name: %s\n", racer->racerName);
    printf("Profession: %s\n", racer->profession);
    printf("Championship Year: %d\n", racer->champYear);
    printf("Best Duration: %.2f\n", racer->bestDuration);
    
    free(racer);
    
}