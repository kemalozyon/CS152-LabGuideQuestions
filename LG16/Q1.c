#include <stdio.h>
#include "queue_int.h"


int main(void){
    int num;
    my_queue_t queue;
    initializeQ(&queue);
    do{
        printf("Enter a number (or negative to STOP) : ");
        scanf("%d",&num);
        if(num % 5 == 0){
            insert(&queue, num);
        }
    }while(num > 0);
    printf("QUEUE CONTENT\n _____________________________________________\n");
    while (!isEmptyQ(&queue))
    {
        num = dequeue(&queue);
        printf("%d\t", num);
    }
    printf("\n");
    
}