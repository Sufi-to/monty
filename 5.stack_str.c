#include "monty.h"

/**
 * printchrTop - converts the top elements int into ascii character
 * @stack: pointer to the head of the stack
 * @line_number: number of line
 * Return: None
*/
void printchrTop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 33 || (*stack)->n > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (char)(*stack)->n);
}
