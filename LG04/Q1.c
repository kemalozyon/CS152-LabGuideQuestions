#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD 10

void readFile(FILE *file, char **array);
void displayWords(char **arr, int numOfWords);
void displaySpecCol(char **arr, int colNumber, int numOfWords);
int main(void){
    FILE *file = fopen("LG04_files/words.txt", "r");
    if(file == NULL){
        printf("File cannot be opened!");
        return 1;
    }
    int numOfWords;
    fscanf(file, "%d", &numOfWords);
    char **words = (char **)malloc(numOfWords * sizeof(char *));
    if(words == NULL){
        printf("Memory allocation failed");
        return 1;
    }
    //Memory allocation for each row.
    for(int r = 0; r < numOfWords; r++){
        words[r] = (char *)malloc(MAX_WORD * sizeof(char));
        //If any mistake occur durin allocation process free previous allocations.
        if(words[r] == NULL){
            for(int j = 0; j < r; j++){
                free(words[j]);
            }
            free(words);
        }
    }
    readFile(file, words);
    displayWords(words, numOfWords);
    int colNumber;
    do{
        printf("Enter col number: ");
        scanf("%d",&colNumber);
        colNumber--;
        displaySpecCol(words, colNumber, numOfWords);
    }while(colNumber > -1 && colNumber < 7);
}

void readFile(FILE *file, char **array){
    int r = 0;
    while (fscanf(file, "%s", *(array + r)) != EOF)
        r++;
}

void displayWords(char **arr, int numOfWords){
    printf("***WORDS***\n");
    for (int i = 0; i < numOfWords; i++){
        printf("%s\n", *(arr + i));
    }
}

void displaySpecCol(char **arr, int colNumber, int numOfWords){
    for (int i = 0; i < numOfWords; i++){
        printf("%c", *(*(arr + i) + colNumber));
    }
    printf("\n");
}