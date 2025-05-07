#include <stdio.h>
#include <string.h>

int findFirstOcc(char *sent, char *subSent);
void replaceFirstOcc(char *sent, char *subSent, char *replace);
void get_string(char *prompt, char arr[]);

int main(void){
    char sent[300], subSent[50], replace[50];
    char *prompt = "Enter a string: ";
    get_string(prompt, sent);
    get_string(prompt, subSent);
    get_string(prompt, replace);
    replaceFirstOcc(sent, subSent, replace);
    printf("%s\n", sent);
}
void get_string(char *prompt, char arr[]){
    printf("%s", prompt);
    scanf(" %[^\n]", arr); 
}

int findFirstOcc(char *sent, char *subSent){
    int sentLen = strlen(sent);
    int subLen = strlen(subSent);

    for(int i = 0; i <= sentLen - subLen; i++){
        if(strncmp(sent + i, subSent, subLen) == 0){
            return i;
        }
    }
    return -1;
}

void replaceFirstOcc(char *sent, char *subSent, char *replace){
    int index = findFirstOcc(sent, subSent);
    if(index == -1){
        printf("The given string cannot be found!\n");
    }
    else{
        char before[50], after[50];
        strncpy(before, sent, index);
        before[index] = '\0';
        strcpy(after, sent + index + strlen(before) + 1);
        strcpy(sent, before);
        strcat(sent, replace);
        strcat(sent, after);
    }
}