/* LG15_AQ1 -> Integer Stack */

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include "stack_int.h"

#define SENTINEL -9

void displayStack(stack_t stackp);
int CountStack(stack_t s);
SType RemMaxStack(stack_t* s);
SType SendNthToEnd(stack_t* s, int n);
int menu();

int main(void)
{
	stack_t stack;
	int num, N;
	int choice;

	initializeS(&stack);

	printf("\nEnter a number: ");
	scanf("%d", &num);

	while (!isFullS(&stack) && num != SENTINEL)
	{
		push(&stack, num);

		printf("Enter a number: ");
		scanf("%d", &num);
	}


	choice = menu();

	while (choice != 4)
	{
		switch (choice)
		{
		case 1:
			printf("\nSTACK CONTENT\n");
			displayStack(stack);

			printf("\n\nNumber of elements in the stack: %d\n", CountStack(stack));
			break;
		case 2:
			RemMaxStack(&stack);

			printf("\nSTACK CONTENT\n");
			displayStack(stack);
			break;
		case 3:
			printf("\nEnter N: ");
			scanf("%d", &N);

			int stack_size = CountStack(stack);

			if (N<1 || N>stack_size)
				printf("\nN must be between 1 and size of the stack!\n");
			else
				SendNthToEnd(&stack, N);

			printf("\nSTACK CONTENT\n");
			displayStack(stack);

			break;
		}
		choice = menu();
	}

	return 0;
}

int menu()
{
	int ch;

	printf("\n       MENU");
	printf("\n************************");
	printf("\n1) Count Stack");
	printf("\n2) Remove Maximum Element");
	printf("\n3) Send Nth To End");
	printf("\n4) Exit");

	printf("\nEnter your choice: ");
	scanf("%d", &ch);

	return(ch);
}
/**************************************************************/
/*                    ADDITIONAL STACK FUNCTIONS              */
/**************************************************************/

void displayStack(stack_t stackp)
{

	while (!isEmptyS(&stackp))
		printf("%d\n", pop(&stackp));
}

//Counts the number of elements in the stack
// Stack content does not change
int CountStack(stack_t s)
{
	int	cnt = 0;

	while (!isEmptyS(&s))
	{
		pop(&s);
		cnt++;
	}

	return(cnt);
}

//Removes the maximum element from the stack
SType RemMaxStack(stack_t* s)
{
	SType	value,
		max = -999;

	stack_t temp;
	initializeS(&temp);


	while (!isEmptyS(s))
	{
		value = pop(s);
		push(&temp, value);

		if (value >= max)
		{
			max = value;
		}
	}

	while (!isEmptyS(&temp))
	{
		value = pop(&temp);

		if (value != max)
			push(s, value);
	}

	return(max);
}

//The nth element from the top is sent to the bottom of the stack
SType SendNthToEnd(stack_t* s, int n)
{
	SType	value,
		move;

	int	cnt = 0;

	stack_t temp;
	initializeS(&temp);


	while (!isEmptyS(s))
	{
		value = pop(s);
		cnt++;

		if (cnt == n)
			move = value;
		else
			push(&temp, value);
	}

	push(s, move);

	while (!isEmptyS(&temp))
	{
		value = pop(&temp);

		push(s, value);
	}

	return(move);
}
