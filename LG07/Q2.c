#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myStrLen(char *sent);
int main(void){
    char word[50];
    int count;
    FILE *file = fopen("LG07_files/LG07_files/words.txt","r");
    FILE *fout = fopen("LG07_files/result.txt", "w");
    if(file == NULL){
        printf("File cannot be opened");
        return 1;
    }
    while (fscanf(file, "%s", word) != EOF)
    {
        count = myStrLen(word);
        fprintf(fout, "%s-%d\n", word, count);
    }
    fclose(file);
    fclose(fout);
    
}

int myStrLen(char *sent){
    int count = 0;
    while(*(sent + count) != '\0'){
        count++;
    }
    return count;
}