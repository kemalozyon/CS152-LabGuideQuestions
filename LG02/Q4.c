#include <stdio.h>
#include <stdlib.h>

int readList(FILE *file, int *arr);
int findPro(int *arr, int size);
int main(void){
    FILE *file = fopen("./LG02_Files/numbers.txt","r");
    if(file == NULL){
        printf("File cannot be opened");
        return 1;
    }
    int *arr = (int *)malloc(15*sizeof(int));
    int size = readList(file, arr);
    int pro = findPro(arr, size);
    printf("Product excluding the numbers that are divisible by 5: %d\n",pro);
}

int readList(FILE *file, int *arr){
    int i = 0;
    while(fscanf(file, "%d", (arr + i)) != EOF){
        i++;
    }
    return i;
}
int findPro(int *arr, int size){
    int pro = 1;
    for(int i = 0; i < size; i++){
        if(*(arr + i) % 5 != 0){
            pro *= *(arr + i);
        }
    }
    return pro;
}