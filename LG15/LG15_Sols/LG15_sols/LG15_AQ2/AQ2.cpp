/* LG15_AQ2 -> Postfix & Infix Question */

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include "stack_int.h"

int calculate(int op1, int op2, char oper);
int evaluatePostfixExpression(char* expr);

int main(void)
{
	char exp[50];
	int	res;

	//read the expression as string
	printf("\nEnter an expression: ");
	scanf("%[^\n]s", exp);

	//calculate the postfix expression
	res = evaluatePostfixExpression(exp);

	//display the result
	printf("\nThe result is: %d\n", res);

	return(0);
}

int calculate(int op1, int op2, char oper)
{
	int	res;
	switch (oper)
	{
	case '+':	res = op1 + op2;
		break;
	case '-':	res = op2 - op1;
		break;
	case '/':	res = op2 / op1;
		break;
	case '*':	res = op1 * op2;
		break;
	}
	return(res);
}

int evaluatePostfixExpression(char* expr)
{
	stack_t	stack;
	int	i,
		len,
		num,
		op1,
		op2,
		res;

	len = strlen(expr);
	initializeS(&stack);

	for (i = 0; i < len; i++)
	{
		//ignore blank character
		if (expr[i] == ' ')
			i++;

		//if the character is a digit, convert the it to integer number and push to the stack
		if (expr[i] >= '0' && expr[i] <= '9')
		{
			num = expr[i] - '0';
			push(&stack, num);
		}
		else
		{
			//if the character is an operator, take the numbers from the stack and do the calculation
			op1 = pop(&stack);
			op2 = pop(&stack);
			res = calculate(op1, op2, expr[i]);
			push(&stack, res);
		}
	}
	return(pop(&stack));
}
