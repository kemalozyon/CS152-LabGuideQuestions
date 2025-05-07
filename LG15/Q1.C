#include <stdio.h>
#include <stdlib.h>
#include "stack_int.h"

int main(){
    int number;
    my_stack_t stack;
    initializeS(&stack);
    do{
        printf("Enter a number: ");
        scanf("%d", &number);
    }while (number < 30);
    
    while (number != 0)
    {
        push(&stack, number % 10);
        number /= 10;
    }
    while (!isEmptyS(&stack))
    {
        number = pop(&stack);
        printf("%d \n", number);
    }
    
    
}
