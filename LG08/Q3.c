#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int findAllOccurences(char *sent, char *subsent, int arr[]);
int main(void){
    char sent[300], subsent[50];
    printf("Enter a sentence: ");
    scanf(" %[^\n]", sent);
    printf("Enter a sentence: ");
    scanf(" %[^\n]", subsent);
    int arr[40];
    int size = findAllOccurences(sent, subsent, arr);
    if(size == 0){
        printf("There is no matching indexes!\n");
    }
    else{
        printf("Matching indexes are: ");
        for(int i = 0; i < size; i++){
            printf("%d, ", arr[i]);
        }
        printf("\n");
    }
}

int findAllOccurences(char *sent, char *subsent, int arr[]){
    int sentlen = strlen(sent);
    int sublen = strlen(subsent);
    int count = 0;
    for(int i = 0; i <= sentlen - sublen; i++){
        if(strncmp(sent + i, subsent, sublen) == 0){
            arr[count] = i;
            count ++;
        }
    }
    return count;
}

