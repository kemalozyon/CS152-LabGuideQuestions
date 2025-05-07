#include <stdio.h>
#include "stack_struct.h"

int main(void){
    FILE *file = fopen("LG15_files/competitions.bin", "rb");
    if(file == NULL){
        printf("File cannot be opened!\n");
        return 1;
    }
    my_stack_t stack;
    initializeS(&stack);
    info_t info;
    while (fread(&info, sizeof(info_t), 1, file) == 1)
    {
        push(&stack, info);
    }
    
    while (!isEmptyS(&stack))
    {
        info = pop(&stack);
        printf("%-50s %-24s %-24s\n\n", info.name, info.startTime, info.endTime);
    }
    
    
}