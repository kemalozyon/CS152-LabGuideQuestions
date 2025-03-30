#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int id;
    int cons;
    double hours;
    double dailyEnergy;
}power_t;

void readFromFile(FILE *file, power_t *power);
void display(power_t *power, int num);
int searchApp(power_t *power, int num, int search);
int main(void){
    int search, index; 
    FILE *file = fopen("LG05_files/appliances.txt","r");
    if(file == NULL){
        printf("File cannot be opened!\n");
        return 1;
    }
    int numOfApp;
    fscanf(file,"%d",&numOfApp);
    power_t *power = (power_t *)malloc(numOfApp * sizeof(power_t));
    if(power == NULL){
        printf("Memory cannot be allocated!\n");
        return 1;
    }
    readFromFile(file, power);
    display(power, numOfApp);
    printf("Enter the id of an appliance: ");
    scanf("%d", &search);
    while (search > 0){
        index = searchApp(power, numOfApp, search);
        if(index != -1){
            printf("\nFound Appliance:\n");
            printf("ID: %d\t", (power + index)->id);
            printf("Power Consumption: %d W\t", (power + index)->cons);
            printf("Hours Used: %.2f\t", (power + index)->hours);
            printf("Daily Energy: %.2f kWh\n", (power + index)->dailyEnergy);
        }
        else{
            printf("Item is not found!\n");
        }
        printf("\nEnter the id of an appliance: ");
        scanf("%d", &search);
    }
    
}

void readFromFile(FILE *file, power_t *power){
    int i = 0;
    while (fscanf(file,"%d %d %lf", &(power + i)->id, &(power + i)->cons, &(power + i)->hours) != EOF)
    {
        i++;
    }
    
}

void display(power_t *power, int num){
    printf("\nAppliance Details:\n");
    printf("-----------------\n");
    double totalEnergy = 0;
    for(int i = 0; i < num; i++) {
        (power + i)->dailyEnergy = ((power + i)->cons * (power + i)->hours) / 1000.0;
        totalEnergy += (power + i)->dailyEnergy;
        
        printf("ID: %d\t", (power + i)->id);
        printf("Power Consumption: %d W\t", (power + i)->cons); 
        printf("Hours Used: %.2f\t", (power + i)->hours);
        printf("Daily Energy: %.2f kWh\n", (power + i)->dailyEnergy);
    }
    printf("\nTotal Daily Energy Consumption: %.2f kWh\n", totalEnergy);
}

int searchApp(power_t *power, int num, int search){
    for(int i = 0; i < num; i++){
        if((power + i) -> id == search){
            return i;
        }
    }
    return -1;
}