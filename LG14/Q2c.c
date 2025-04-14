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
    int numbers, arr;
    printf("Please enter the number of items to be read: ");
    scanf("%d",&numbers);
    fseek(file, (numbers - 1) * sizeof(int), SEEK_SET);
    fread(&arr, sizeof(int), 1, file);
    printf("%d. %d\n",numbers, arr);
}

int createRandomNum(int begin, int end){
    return rand() % (end - begin + 1) + begin;
}

void createBinFile(){
    int *randomArr;
    randomArr = (int *)malloc(250 * sizeof(int));
    FILE *file = fopen("number.bin","wb");
    if(file == NULL){
        printf("File cannot be created!\n");
    }
    for(int i = 0; i < STORENUM; i++){
        *(randomArr + i) = createRandomNum(0, 5000);
    }
    fwrite(randomArr, sizeof(int), 250, file);
    fclose(file);
}