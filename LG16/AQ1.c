#include "queue_str.h"

void displayQueue(my_queue_t queue);
void strip_newline(char *str);


int main(void){
    FILE *file = fopen("LG16_files/math.txt", "r");
    if(file == NULL){
        printf("File cannot be opened!\n");
        return 1;
    }

    char name[STR_SIZE];
    char *difficulty;
    my_queue_t queue[3];

    for(int i = 0; i < 3; i++){
        initializeQ(&queue[i]);
    }

    while(fgets(name, sizeof(name), file))
    {
        difficulty = strstr(name, ":");

        if (difficulty == NULL) continue; // ":" yoksa atla

        difficulty += 2; // ':' ve boşluğu geç
        strip_newline(difficulty); // <-- burada olayı çözüyoruz

        if(strcmp(difficulty, "Easy") == 0){
            insert(&queue[0], name);
        }
        else if(strcmp(difficulty, "Medium") == 0){
            insert(&queue[1], name);
        }
        else if(strcmp(difficulty, "Hard") == 0){
            insert(&queue[2], name);
        }
    displayQueue(queue[0]);
}
}

void displayQueue(my_queue_t queue){
    char name[STR_SIZE];
    while (!isEmptyQ(&queue))
    {
        strcpy(name, dequeue(&queue));
        printf("%s\n",name);
    }
    
}

void strip_newline(char *str){
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL)
        *pos = '\0';
}