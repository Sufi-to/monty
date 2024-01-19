#include "monty_hf.h"
/**
 * addTopTwo - add the top two elements
 * @stack: pointer to the stack
 * @lnNum: number of line
 * Return: None
*/
void addTopTwo(stack_t **stack, unsigned int lnNum)
{
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lnNum);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	ptr = *stack;
	*stack = (*stack)->next;

	if (stack != NULL)
		(*stack)->prev = NULL;
}
