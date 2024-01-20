#include "monty.h"
/**
 * swapTopTwo - swaps the top two elements in the stack
 * @line_number: number of the line
 * @stack: pointer to the stack
 * Return: None
*/
void swapTopTwo(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;


	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = (*stack)->next;
	(*stack)->next = ptr->next;
	ptr->next = *stack;
	ptr->prev = NULL;

	if ((*stack)->next != NULL)
		(*stack)->next->prev = *stack;

	*stack = ptr;
}

/**
 * doNothing - function that just exists to be a pain in the ...
 * @stack: pointer to stack
 * @line_number: line number
 * Return: None
*/
void doNothing(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * freeStackptr - frees the allocated memory for element
 * @h: pointer to stack element
 * Return: None
*/
void freeStackptr(stack_t *h)
{
	stack_t *cn;

	while (h != NULL)
	{
		cn = h;
		h = h->next;
		free(cn);
	}
}
