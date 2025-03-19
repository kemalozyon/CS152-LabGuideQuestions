#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandom(int beginning, int end);
void generateNumber(int n, int arr[]);
int get_int(char* prompt);
void printFile(FILE *file, int* arr, int n);
#define BEGIN 2500
#define END 7500

int main(void){
    srand(time(NULL));
    FILE *file = fopen("./outputs/reverse.txt", "w");
    if(file == NULL){
        printf("File cannot be opened");
        return 1;
    }
    int n = get_int("Enter the number: ");
    int *arr = (int*)malloc(sizeof(int) * n); 
    generateNumber(n, arr);
    
    printFile(file, arr, n);
    fclose(file);
    free(arr);
}

int generateRandom(int beginning, int end){
    int value = rand() % (end - beginning + 1) + beginning;
    return value;
}

void generateNumber(int n, int arr[]){
    int number, digit;
    for(int i = 0; i < n; i++){
        arr[i] = generateRandom(BEGIN, END);
        printf("%2d.  %7d \t->\t", i+1, arr[i]);
        number = arr[i];
        while(number != 0){
            digit = number % 10;
            printf("%d  ", digit);
            number /= 10;
        }
        printf("\n");
    }
}

void printFile(FILE *file, int* arr, int n){
    int number, digit;
    for(int i = 0; i < n; i++){
        number = *(arr + i);
        fprintf(file,"%2d. %7d \t->\t",i+1, number);
        while(number != 0){
            digit = number % 10;
            fprintf(file,"%d  ",digit);
            number /= 10;
        }
        fprintf(file,"\n");
    }
}

int get_int(char* prompt){
    int value;
    printf("%s",prompt);
    scanf("%d",&value);
    return value;
}