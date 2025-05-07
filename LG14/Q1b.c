#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *file = fopen("LG14_files/nums.bin", "rb");
    if(file == NULL){
        printf("File cannot be opened!\n");
        return 1;
    }

    int *nums, count = 0, size;
    fseek(file, 0, SEEK_END);
    size = ftell(file) / sizeof(int);
    rewind(file);
    nums = (int *)malloc(size * sizeof(int));

    fread(nums, sizeof(int), size, file);
    printf("There are %d numbers in the file!\n", size);

    for(int i = 0; i < size; i++){
        printf("%d ", *(nums + i));
    }
    printf("\n");
}