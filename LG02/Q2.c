#include <stdio.h>
#include <stdlib.h>


int main(void){
    int *arr = (int *)malloc(5 * sizeof(int));
    FILE *file = fopen("./outputs/result.txt", "w");
    if (arr == NULL){
        printf("Memory cannot be allocated!");
        return 1;
    }
    if(file == NULL){
        printf("File cannot be opened!");
        return 1;
    }
    *arr = 2;
    *(arr + 1) = 4;
    *(arr + 2) = 8;
    *(arr + 3) = 16;
    *(arr + 4) = 32;;
    fprintf(file,"Element Name     Value   Address\n");
    for(int i = 0; i < 5; i++){
        fprintf(file,"*(arr + %d) \t\t %d \t\t%p\n", i, *(arr + i), arr + i);
    }
}