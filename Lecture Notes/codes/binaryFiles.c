#include <stdio.h>


int main(void){
    //Creating a binary file:
    FILE *filew = fopen("data.bin", "wb");
    int number = 123;
    fwrite(&number, sizeof(int), 1, filew);
    fclose(filew);
    FILE *fileR = fopen("data.bin", "rb");
    int num;
    fread(&num, sizeof(int), 1, fileR); 
    printf("%d\n", num);
    fclose(fileR);

    //Putting entire array to a binary file:
    FILE *file = fopen("numbers.bin", "wb");
    int arr[20];
    for(int i = 0; i < 20; i++){
        *(arr + i) = i + 1;
    }
    fwrite(arr, sizeof(int), 20, file);
    fclose(file);
    FILE *file2 = fopen("numbers.bin", "rb");
    int num2;
    while (!feof(file2))
    {
        fread(&num2, sizeof(int), 1, file2);
        printf("%d\n",num2);
    }
    rewind(file2);
    fread(&num2, sizeof(int), 1, file2);
    printf("%d\n", num2);
    fclose(file2);
     

}