#include <stdio.h>
#include <string.h>

int findFirstOcc(char *sent, char *sub);
void deleteFirstOcc(char *sent, char *word);

int main(void) {
    char word[300], delWord[50];
    
    printf("Enter a string: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = 0;  // Remove newline
    
    printf("Enter a string: ");
    fgets(delWord, sizeof(delWord), stdin);
    delWord[strcspn(delWord, "\n")] = 0;  // Remove newline
    
    deleteFirstOcc(word, delWord);
    printf("%s\n", word);
    return 0;
}

int findFirstOcc(char *sent, char *sub) {
    int sentlen = strlen(sent);
    int sublen = strlen(sub);

    if(sublen > sentlen) {
        printf("The length of sub sentence cannot be bigger than sentence!\n");
        return -2;
    }
    
    for(int i = 0; i <= sentlen - sublen; i++) {
        if(strncmp(sent + i, sub, sublen) == 0) {
            return i;
        }
    }
    return -1;
}

void deleteFirstOcc(char *sent, char *word) {
    int index = findFirstOcc(sent, word);
    if(index == -1) {
        printf("The subString cannot be found on the given string!\n");
        return;
    }
    
    int wordLen = strlen(word);
    int sentLen = strlen(sent);
    
    // Shift the remaining characters to the left
    for(int i = index; i <= sentLen - wordLen; i++) {
        sent[i] = sent[i + wordLen];
    }
} 