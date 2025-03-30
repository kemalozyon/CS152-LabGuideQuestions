#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int id;
    char type;
    double price;
    int bedroom; 
    int bathroom;
}properties_t;

void readFromFile(FILE *file, properties_t *properties);
void displayAndCalculate(properties_t *properties, int numOfProperties);
int main(void){

    FILE *file = fopen("LG05_files/properties.txt","r");
    if(file == NULL)
    {
        printf("File cannot be opened!");
        return 1;
    }
    
    int numOfProperties;
    fscanf(file, "%d", &numOfProperties);
    properties_t *properties = (properties_t *)malloc(numOfProperties * sizeof(properties_t));
    if(properties == NULL){
        printf("Memory allocation failed!");
        return 1;
    }

    readFromFile(file, properties);
    displayAndCalculate(properties, numOfProperties);
    

}

void readFromFile(FILE *file, properties_t *properties){
    int i = 0;
    while(fscanf(file, "%d %c %lf %d %d", &(properties + i)->id,&(properties + i)->type,&(properties + i)->price,&(properties + i)->bedroom,&(properties + i)->bathroom) != EOF){
        i++;
    }
}

void displayAndCalculate(properties_t *properties, int numOfProperties){
    printf("\nProperty Details:\n");
    printf("----------------\n");
    double totalRent = 0, totalSold = 0;
    for(int i = 0; i < numOfProperties; i++) {
        printf("ID: %d\t", (properties + i)->id);
        switch ((properties + i)->type)
        {
        case 'R':
            totalRent += (properties + i)->price;
            printf("Rented\t");
            break;
        case 'S':
            totalSold += (properties + i)->price;
            printf("Sold\t");
            break;
        default:
            printf("Type: Unknown\n");
            break;
        }
        printf("Price: $%.2f\t", (properties + i)->price);
        printf("Bedrooms: %d\t", (properties + i)->bedroom);
        printf("Bathrooms: %d\t", (properties + i)->bathroom);
        printf("\n");
    }
    printf("Total price of the Sold Properties   -> %f\n",totalSold);
    printf("Total price of the Rented Properties -> %f\n", totalRent);
}