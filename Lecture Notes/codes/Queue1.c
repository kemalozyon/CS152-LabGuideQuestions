
#include "stack_int.h"
#include "queue_int.h"

void reverseQueue(my_queue_t *queue);
void displayQueue(my_queue_t queue);
int main(void){
    my_queue_t queue;
    initializeQ(&queue);

    for(int i = 0; i < 30; i++){
        insert(&queue, i +1 ) ;
    }
    displayQueue(queue);
    reverseQueue(&queue);
    displayQueue(queue);
}

//IT gives all the variables into a stack then it will push it from stack to the same queue therefore the order will be reversed
void reverseQueue(my_queue_t *queue){
    my_stack_t stack;
    initializeS(&stack);
    int num;
    while(!isEmptyQ(queue)){
        num = dequeue(queue);
        push(&stack, num);
    }
    while (!isEmptyS(&stack))
    {
        num = pop(&stack);
        insert(queue, num);
    }
}

void displayQueue(my_queue_t queue){
    int num;
    while(!isEmptyQ(&queue)){
        num = dequeue(&queue);
        printf("%3d ", num);
    }
    printf("\n");
}