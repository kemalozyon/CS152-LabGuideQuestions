#include <stdio.h>

void swap(int *x, int *y); //Swap function taking address of variables as parameter.

int main(void)
{
    int num1, num2;
    do{
        printf("Enter the first number: ");
        scanf("%d",&num1);
        if(num1 <= 0)
        {
            printf("The number must be positive\n");
        }
    }while(num1 <= 0);

    do{
        printf("Enter the second number: ");
        scanf("%d",&num2);
        if(num2 <= 0)
        {
            printf("The number must be positive\n");
        }
    }while(num2 <= 0);
    printf("The numbers are: %d %d\n",num1,num2);
    swap(&num1,&num2);
    printf("The swapped numbers are: %d %d",num1, num2);
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}