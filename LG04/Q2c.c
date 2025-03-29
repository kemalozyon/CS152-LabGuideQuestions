#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[30];
    char profession[40];
    int appearanceYear;
    double broadcastTime;
} racer_t;

int main(void)
{
    FILE *file = fopen("LG04_files/drivers.txt", "r");
    if (file == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }
    int numOfDrivers;
    fscanf(file, "%d", &numOfDrivers);
    printf("There are %d drivers.\n", numOfDrivers);
    racer_t *racers = (racer_t *)malloc(numOfDrivers * sizeof(racer_t));
    int i = 0;
    while (fscanf(file, "%s %s %d %lf", (racers + i)->name, (racers + i)->profession, &(racers + i)->appearanceYear, &(racers + i)->broadcastTime) != EOF)
    {
        i++;
    }
    fclose(file);
    
    for (int j = 0; j < i; j++)
    {
        printf("Name: %s\n", (racers + j)->name);
        printf("Profession: %s\n", (racers + j)->profession);
        printf("Championship Year: %d\n", (racers + j)->appearanceYear);
        printf("Best Duration: %.2f\n", (racers + j)->broadcastTime);
    }
    free(racers);
}