#include "monty_hf.h"


/**
 * main - entry point of a the monty program
 * @ac: number of cmd line arguments
 * @av: pointer to the array of cmd line arguments
 *
 * Return: always 0
*/

int main(int ac, char *av[])
{
	stack_t *stack_ptr;
	instruction_t insts[] = {
		{"push", pushToStack},
		{"pall", printStack},
		{"pint", printTop},
		{"pop", removeTop},
		{"swap", swapTopTwo},
		{"add", addTopTwo},
		{"nop", doNothing},
		{NULL, NULL}
	};
	stack_ptr = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s filename\n", av[0]);
		exit(EXIT_FAILURE);
	}

	getFile(&stack_ptr, av[1], insts);
	freeStackptr(stack_ptr);
	return (0);
}
