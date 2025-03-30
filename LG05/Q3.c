#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    int bMonth;
    int bYear;
    int eMonth;
    int eYear;
}date_t;
typedef struct 
{
    int id;
    int status;
    date_t date;
    int condition;
}warranty_t;

void readInfo(FILE *file, warranty_t *warranty);
void display(warranty_t *warranty, int numOfProducts);
void findLongestWarranty(warranty_t *warranty, int numOfProducts);
int main(void)
{
    FILE *file = fopen("LG05_files/warranty.txt","r");
    if(file == NULL){
        printf("File cannot be opened!\n");
        return 1;
    }
    int numOfProducts;
    fscanf(file, "%d", &numOfProducts);
    warranty_t *warranty = (warranty_t *)malloc(numOfProducts * sizeof(numOfProducts));
    readInfo(file, warranty);
    findLongestWarranty(warranty, numOfProducts);
}

void readInfo(FILE *file, warranty_t *warranty){
    int i = 0, endMonth;
    while(fscanf(file, "%d %d %d %d", &(warranty + i)->id, &(warranty + i)->status,&(warranty + i)->date.bMonth,&(warranty + i)->date.bYear) != EOF){
        endMonth = (warranty + i)->status + (warranty + i)->date.bMonth;
        (warranty + i)->date.eMonth = endMonth % 12;
        if((warranty + i)->date.eMonth == 0){
            (warranty + i)->date.eMonth = 12;
        }
        (warranty + i)->date.eYear = (warranty + i)->date.bYear + endMonth / 12;
        i++;
    }
}

void display(warranty_t *warranty, int numOfProducts){
    for(int i = 0; i < numOfProducts; i++){
        printf("ID: %d\t", (warranty + i)->id);
        printf("Warranty Period: %d months\t", (warranty + i)->status);
        // This line prints the start date in MM/YYYY format
        // If the month is single digit (1-9), adds leading 0 using ternary operator
        // (warranty + i)->date.bMonth < 10 checks if month needs leading 0
        // The ternary returns "0" if true, "" if false
        // Then prints the actual month and year values
        printf("Start Date: %s%d/%d\t", ((warranty + i)->date.bMonth < 10 ? "0" : ""), (warranty + i)->date.bMonth, (warranty + i)->date.bYear);
        printf("End Date: %s%d/%d\t", ((warranty + i)->date.eMonth < 10 ? "0" : ""), (warranty + i)->date.eMonth, (warranty + i)->date.eYear);
        printf("Status: %s\n", ((warranty + i)->condition == 0 ? "Deactive" : "Active"));
    }
}

void findLongestWarranty(warranty_t *warranty, int numOfProducts){
    int currentMonth, currentYear;
    int remainingMonth, maxMonth = 0, id;
    printf("Enter current month and year (MM YYYY): ");
    scanf("%d %d", &currentMonth, &currentYear);
    for(int i = 0; i < numOfProducts; i++){
        (warranty + i)->condition = 1;
        if((warranty + i)->date.eYear < currentYear || ((warranty + i)->date.eYear == currentYear && (warranty + i)->date.eMonth < currentMonth)){
            (warranty + i)->condition = 0;
        }

        remainingMonth = ((warranty + i)->date.eYear - currentYear) * 12 + ((warranty + i)->date.eMonth - currentMonth);
        if (remainingMonth > maxMonth){
            maxMonth = remainingMonth;
            id = (warranty + i)->id;
        }
    }
    display(warranty, numOfProducts);
    printf("Product with Longest Warranty Remaining: ID %d with %d months left.\n",id, maxMonth);
}