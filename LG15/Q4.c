#include <stdio.h>
#include <math.h>
#include "stack_int.h"

int main(void){
    int num, decimal = 0;
    printf("Enter a number: ");
    scanf("%d",&num);
    my_stack_t stack;
    initializeS(&stack);
    while (num != 0)
    {
        push(&stack, num % 10);
        num /= 10;
    }

    while (!isEmptyS(&stack))
    {
        decimal += pow(8, stack.top) * pop(&stack);
    }
    printf("%d\n", decimal);
}