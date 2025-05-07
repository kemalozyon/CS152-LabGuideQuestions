#include <stdio.h>
#include <string.h>

int findFirstOcc(char *sent, char *sub);

int main(void){
    char string[300], subString[50];
    printf("Enter a sentence: ");
    scanf(" %[^\n]", string);
    printf("Enter a string to be found: ");
    scanf(" %[^\n]", subString);
    int index = findFirstOcc(string, subString);
    if(index == -1){
        printf("It is not found\n");
    }
    else{
        printf("The occurence of the string is %d\n", index);
    }
}

int findFirstOcc(char *sent, char *sub){
    int sentLen = strlen(sent);
    int subLen = strlen(sub);
    for(int i = 0; i <= sentLen - subLen; i++){
        if(strncmp(sent + i, sub, subLen) == 0){
            return i;
        }
    }
    return -1;
}