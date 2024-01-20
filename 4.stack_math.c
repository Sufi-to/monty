#include "monty.h"
/**
 * addTopTwo - add the top two elements
 * @stack: pointer to the stack
 * @line_number: number of line
 * Return: None
*/
void addTopTwo(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	ptr = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);

	if (stack != NULL)
		(*stack)->prev = NULL;
}


/**
 * mulTopTwo - multiplies the top two elements
 * @stack: pointer to the stack
 * @line_number: number of line
 * Return: None
*/
void mulTopTwo(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	ptr = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);

	if (stack != NULL)
		(*stack)->prev = NULL;
}

/**
 * subTopTwo - multiplies the top two elements
 * @stack: pointer to the stack
 * @line_number: number of line
 * Return: None
*/
void subTopTwo(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	ptr = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);

	if (stack != NULL)
		(*stack)->prev = NULL;
}


/**
 * divTopTwo - multiplies the top two elements
 * @stack: pointer to the stack
 * @line_number: number of line
 * Return: None
*/

void divTopTwo(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	ptr = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);

	if (stack != NULL)
		(*stack)->prev = NULL;
}

/**
 * modTopTwo - multiplies the top two elements
 * @stack: pointer to the stack
 * @line_number: number of line
 * Return: None
*/

void modTopTwo(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	ptr = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);

	if (stack != NULL)
		(*stack)->prev = NULL;
}
