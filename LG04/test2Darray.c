#include <stdio.h>
#include <stdlib.h>


int main(void){
    int row = 5; 
    int col = 4;

    int **array = (int **)malloc(row * sizeof(int *));
    if(array == NULL){
        printf("Memory allocation failed!");
        return 1;
    }

    for(int i = 0; i < row; i++){
        //Memory allocation for each row
        *(array + i) = (int *)malloc(col * sizeof(int));
        // Free if previously allocated memory if allocation fails
        if(*(array + i) == NULL){
            for(int j = 0; j < i; j++){
                free(*(array + i));
            }
            free(array);
            printf("Memory allocation failed\n");
            return 1;
        }
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            *(*(array + i) + j) = i * col + j;
        }
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%-5d ", *(*(array + i) + j));
        }
        printf("\n");
    }
}

