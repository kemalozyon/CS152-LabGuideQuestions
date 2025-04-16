#include "queue_str.h"


void displayQueue(my_queue_t queue);


int main(void){
    FILE *file = fopen("LG16_files/students.txt", "r");
    if(file == NULL){
        printf("File cannot be opened!\n");
        return 1;
    }
    int num;
    char name[20];
    my_queue_t queue;
    initializeQ(&queue);
    while (fscanf(file, "%s", name) != EOF)
    {
        insert(&queue, name);
    }
    displayQueue(queue);  
    printf("How many students getting on the bus? ");
    scanf("%d",&num);
    
    for(int i = 0; i < num; i++){
        strcpy(name, dequeue(&queue));
        printf("%s\n",name);
    }
    printf("\nWaiting Students:\n");
    displayQueue(queue);
}

void displayQueue(my_queue_t queue){
    char name[50];
    while (!isEmptyQ(&queue))
    {
        strcpy(name, dequeue(&queue));
        printf("%s\n",name);
    }
    
}