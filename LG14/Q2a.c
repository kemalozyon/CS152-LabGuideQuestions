#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define STORENUM 250
int createRandomNum(int begin, int end);
void createBinFile();

int main(void){
    srand(time(NULL));
    createBinFile();
    FILE *file = fopen("number.bin", "rb");
    if(file == NULL){
        printf("File cannot be opened!\n");
        return 1;
    }
    int numbers, *arr;
    printf("Please enter the number of items to be read: ");
    scanf("%d",&numbers);
    arr = (int *)malloc(sizeof(int) * numbers);
    fread(arr, sizeof(int), numbers, file);
    for(int i = 0; i < numbers; i++){
        printf("%d. %d\n", i+1, *(arr + i));
    }
}

int createRandomNum(int begin, int end){
    return rand() % (end - begin + 1) + begin;
}

void createBinFile(){
    int random;
    FILE *file = fopen("number.bin","wb");
    if(file == NULL){
        printf("File cannot be created!\n");
    }
    for(int i = 0; i < STORENUM; i++){
        random = createRandomNum(1, 5000);
        fwrite(&random, sizeof(int), 1, file);
    }
    fclose(file);
}