#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char productName[30];
    double price;
    double discount;
    double discountPrice;
    double savedAmount;
}amazon_t;


int main(void){
    FILE *file = fopen("LG04_files/amazon.txt", "r");
    if(file == NULL){
        printf("File cannot be opened\n");
        return 1; 
    }
    int numOfProducts;
    fscanf(file, "%d", &numOfProducts);
    printf("There are %d products in the market!\n", numOfProducts);
    amazon_t *products = (amazon_t *)malloc(numOfProducts * sizeof(amazon_t));
    int i = 0;
    while(fscanf(file, "%s %lf %lf", (products + i)->productName, &((products + i)->price), &((products + i)->discount)) != EOF){
        i++;
    }
    fclose(file);
    for(int j = 0; j < i; j++){
        (products + j)->discountPrice = ((products + j) ->price) * (100 - (products + j) ->discount) / 100;
        (products + j)->savedAmount = ((products + j)->price) - ((products + j)->discountPrice);
    }
    for(int k = 0; k < i; k++){
        printf("Product Name: %s\n", (products + k)->productName);
        printf("Original Price: %.2f\n", (products + k)->price);
        printf("Discount: %.2f%%\n", (products + k)->discount);
        printf("Price after discount: %.2f\n", (products + k)->discountPrice);
        printf("You saved: %.2f\n\n", (products + k)->savedAmount);
    }
    free(products);
}