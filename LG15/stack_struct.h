//
// Stack Implementation, CTIS 152
//
#include <stdio.h>

#define STACK_SIZE  100
typedef struct  
{
    char name[50];
    char startTime[24];
    char endTime[24];

}info_t;

typedef  info_t  SType;

SType  STACK_EMPTY = {};

typedef struct
{	int	top;
	SType data[STACK_SIZE];
} my_stack_t;

//Functions in this file...
void initializeS (my_stack_t *s);
int isEmptyS (my_stack_t *s);
int isFullS (my_stack_t *s);
void push (my_stack_t *s, SType item);
SType pop (my_stack_t *s);

//------------------------------------------------------------------------------

void initializeS (my_stack_t *s)
{
	s->top = -1;
}

//------------------------------------------------------------------------------

int isEmptyS (my_stack_t *s)
{
	if (s->top == -1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

int isFullS (my_stack_t *s)
{
	if (s->top == STACK_SIZE - 1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

void push (my_stack_t *s, SType item)
{
	if (isFullS (s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top)++;
		s->data[s->top] = item;
	}
}

//------------------------------------------------------------------------------

SType pop (my_stack_t *s)
{
	SType item;
	if (isEmptyS(s))
	{	printf("Error: Stack is empty!\n");
		item = STACK_EMPTY;	
	}
	else
	{	item = s->data[s->top];
		(s->top)--;
	}		    	
	return (item);
}
