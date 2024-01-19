#include "monty_hf.h"
/**
 * swapTopTwo - swaps the top two elements in the stack
 * @lnNum: number of the line
 * @stack: pointer to the stack
 * Return: None
*/
void swapTopTwo(stack_t **stack, unsigned int lnNum)
{
	stack_t *ptr;


	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lnNum);
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
 * @lnNum: line number
 * Return: None
*/
void doNothing(stack_t **stack, unsigned int lnNum)
{
	(void)stack;
	(void)lnNum;
}

/**
 * freestackptr - frees the allocated memory for element
 * @h: pointer to stack element
 * Return: None
*/
void freestackptr(stack_t *h)
{
	stack_t *cn;

	while (h != NULL)
	{
		cn = h;
		h = h->next;
		free(cn);
	}
}
