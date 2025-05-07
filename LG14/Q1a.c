#include <stdio.h>

int main(void){
    FILE *file = fopen("LG14_files/nums.bin", "rb");
    if(file == NULL){
        printf("File cannot be opened!\n");
        return 1;
    }
    int nums, count = 0;
    while(fread(&nums, sizeof(int), 1, file) == 1){
        printf("%d\n", nums);
        count++;
    }
    printf("There are %d numbers in the file!\n", count);
    fclose(file);
    return 0;
}