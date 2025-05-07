#include <stdio.h>
#include <string.h>

int main(void){
    FILE *file = fopen("LG07_files/LG07_files/morning.txt", "r");
    if(file == NULL){
        printf("File cannot be opened!\n");
        return 1;
    }
    char name[50];
    int status = fscanf(file, "%s", name), line = 1, wc = 0;
    while(status != EOF){
        if(strcmp(name, "EOL") == 0){
            printf("%dth line contains %d word\n", line, wc);
            line++;
            wc = 0;
        }
        status = fscanf(file, "%s", name);
        wc++;
    }
}