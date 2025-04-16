#include "queue_struct.h"
#include <string.h>


void fillQueue(FILE *file, my_queue_t *queue);
void displayQueue(my_queue_t queue);
void classOfTheDay(my_queue_t queue);


int main(void){
    FILE *file = fopen("LG16_files/classes.txt", "r");
    if(file == NULL){
        printf("File cannot be opened");
    }
    my_queue_t queue;
    initializeQ(&queue);
    fillQueue(file, &queue);
    displayQueue(queue);
    classOfTheDay(queue);
}

void fillQueue(FILE *file, my_queue_t *queue){
    class_t class;
    while (fscanf(file, "%s %d",class.className, &class.questions) != EOF)
    {
        insert(queue, class);
    }
}

void displayQueue(my_queue_t queue){
    class_t class;
    while (!isEmptyQ(&queue))
    {
        class = dequeue(&queue);
        printf("%-10s %-5d\n",class.className,class.questions);
    }
}

void classOfTheDay(my_queue_t queue){
    int max;
    char name[10];
    class_t class;
    class = dequeue(&queue);
    strcpy(name, class.className);
    max = class.questions;
    while (!(isEmptyQ(&queue)))
    {
        class = dequeue(&queue);
        if(max < class.questions){
            max = class.questions;
            strcpy(name, class.className);
        }
    }
    printf("%-10s %-5d\n",name, max);
    
}