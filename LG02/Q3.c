#include <stdio.h>
#include <stdlib.h>


int main(void){
    int *arr = (int *)malloc(10 * sizeof(int));
    int max, number, index = 0;
    FILE *file = fopen("./outputs/result2.txt","w");
    
    if(file == NULL){
        printf("File cannot be opened!");
        return 1;
    }
    double sum = 0;
    do{
        printf("Enter a number: ");
        scanf("%d", &number);
        if(number > 0){
            *(arr + index) = number;
            index++;
        }
        if(index == 10){
            printf("10 numbers is given");
        }
        if(index == 0){
            printf("Program terminated\n");
            return 0;
        }
        if(index != 0 && number <= 0){
            printf("Result is printed\n");
        }
    }while(number > 0 && index < 10);
    max = *(arr);
    sum = *(arr);
    for(int i = 1; i < index; i++) {
        sum += *(arr + i);
        if (max < *(arr + i)){
            max = *(arr + i);
        }
    }   
    double avg = sum / (index + 1);
    fprintf(file,"Maximum number is %d\nAvarage is %.2f\n",max,avg);
    
    
}