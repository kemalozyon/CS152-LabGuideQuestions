#include <stdio.h>
#include <stdlib.h>
void inputDistance(int *arr, int size);
double calculateConsumption(int *arr, int size);
int main(void)
{
    int size;
    printf("How many times did you refuel: ");
    scanf("%d", &size);
    while (size > 0)
    {

        int *arr = (int *)malloc(size * sizeof(int));
        inputDistance(arr, size);
        double avg = calculateConsumption(arr, size);
        printf("The average fuel consumption per 100 km: %.2f\n", avg);
        printf("How many times did you refuel: ");
        scanf("%d", &size);
    }
}

void inputDistance(int *arr, int size)
{
    int distance;
    printf("Enter distances traveled after each refuel (km): ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", (arr + i));
    }
}
double calculateConsumption(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(arr + i);
    }
    return (double)((size * 50) * 100) / sum;
}