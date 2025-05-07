#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_str.h"

int main(void){
    FILE *file = fopen("LG15_files/players.txt", "r");

    if(file == NULL){
        printf("File cannot be opened");
        return 1;
    }

    my_stack_t stack;

    initializeS(&stack);
    char *name;
    name = (char *)malloc(50 * sizeof(char));
    while(fscanf(file, " %[^\n]", name) != EOF){
        push(&stack, name);
        //fgetc(file);
    }
    while (!isEmptyS(&stack))
    {
        strcpy(name, pop(&stack));
        printf("%s\n",name);
    }
    
}