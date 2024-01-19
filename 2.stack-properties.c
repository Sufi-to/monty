#include "monty_hf.h"

/**
 * pushToStack - pushes an element to the top of the stack
 * @lnNum: number of the line
 * @stack: pointer to the stack
 * Return: None
*/
void pushToStack(stack_t **stack, unsigned int lnNum)
{
	char *cs;
	stack_t *new;
	int x;

	cs = strtok(NULL, " \n");
	if ((cs == NULL || !isdigit(*cs)) && ((*cs != '-' && !isdigit(*(cs + 1)))))
	{
		fprintf(stderr, "L%d: usage: push integer\n", lnNum);
		exit(EXIT_FAILURE);
	}
	x = atoi(cs);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = x;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;

	*stack = new;
}

/**
 * printStack - prints the whole stack
 * @lnNum: number of line
 * @stack: pointer to stack
 * Return: None
*/
void printStack(stack_t **stack, unsigned int lnNum)
{
	stack_t *ptr;
	(void)lnNum;
	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * printTop - prints the top element
 * @lnNum: number of line
 * @stack: pointer to stack
 * Return: None
*/
void printTop(stack_t **stack, unsigned int lnNum)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lnNum);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * removeTop - removes the top element
 * @lnNum: number of line
 * @stack: pointer to stack
 * Return: None
*/
void removeTop(stack_t **stack, unsigned int lnNum)
{
	stack_t *ptr;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lnNum);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(ptr);
}
