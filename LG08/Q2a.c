#include <stdio.h>
#include <string.h>


int findFirstOcc(char *sent, char *sub);
void deleteFirstOcc(char *sent, char *word);
void get_string(char *propmt, char arr[]);
int countBlanks(char *str);
int main(void){
    char word[300], delWord[50];
    printf("Enter a string: ");
    scanf(" %[^\n]", word);  // %*c consumes the newline
    printf("Enter a string: ");
    scanf(" %[^\n]", delWord);
    deleteFirstOcc(word, delWord);
    printf("%s\n", word);
    return 0;
}

int countBlanks(char *str){
    int strLen = strlen(str);
    int count = 0;
    while(str[strLen - 1] == ' '){
        count++;
        strLen--;
    }
    return count;
}

void get_string(char *propmt, char arr[]){
    printf("%s",propmt);
    scanf(" %[^\n]", arr);
}



int findFirstOcc(char *sent, char *sub){
    int sentlen = strlen(sent);
    int sublen = strlen(sub);

    if(sublen > sentlen){
        printf("The length of sub sentence cannot be bigger than sentence!\n");
        return -2;
    }
    else{
        for(int i = 0; i <= sentlen - sublen; i++){
            if(strncmp(sent + i, sub, sublen) == 0){
                return i;
            }
        }
    }
    return -1;
}

void deleteFirstOcc(char *sent, char *word){
    int index = findFirstOcc(sent, word);
    if(index == -1){
        printf("The subString cannot be found on the given string!\n");
    }
    else{
        char before[50], after[50];
        strncpy(before, sent, index);
        before[index] = '\0';
        strcpy(after, sent + index + strlen(before) + 1);
        strcpy(sent, before);
        strcat(sent, after);
    }
}