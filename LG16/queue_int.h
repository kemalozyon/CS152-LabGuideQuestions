//
// Circular Queue Implementation, CTIS 152
//

#include <stdio.h>

#define QUEUE_SIZE  100


typedef  int  QType;

QType  QUEUE_EMPTY = -987654321;

typedef struct _Queue
{	int front, rear;
	QType data[QUEUE_SIZE];
	int counter;
} my_queue_t;

//Functions in this file...
void initializeQ (my_queue_t *q);
int isEmptyQ (my_queue_t *q);
int isFullQ (my_queue_t *q);
void insert (my_queue_t *q, QType item);
QType dequeue (my_queue_t *q);

//------------------------------------------------------------------------------

void initializeQ (my_queue_t *q)
{
	q->front = 0;
	q->rear  = -1;
	q->counter = 0;
}

//------------------------------------------------------------------------------

int isEmptyQ (my_queue_t *q)
{
	if (q->counter == 0)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

int isFullQ (my_queue_t *q)
{
	if (q->counter == QUEUE_SIZE)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

void insert (my_queue_t *q, QType item)
{
	if (isFullQ (q))
		printf("Error: Queue is full!\n");
	else 
	{	q->rear = (q->rear + 1) % QUEUE_SIZE;   // make it circular
		q->data[q->rear] = item;
		(q->counter)++;
	}
}

//------------------------------------------------------------------------------

QType dequeue (my_queue_t *q)
{
	QType item;
	if (isEmptyQ (q))
	{	printf("Error: Queue is empty!\n");
		item = QUEUE_EMPTY;
	}
	else
	{	item = q->data[q->front];	
		q->front = (q->front + 1) % QUEUE_SIZE;
		(q->counter)--;
	}
	return item;
}