#include "monty.h"


/**
 * main - entry point of a the monty program
 * @ac: number of cmd line arguments
 * @av: pointer to the array of cmd line arguments
 *
 * Return: always 0
*/

int main(int ac, char *av[])
{
	stack_t *stack;
	instruction_t insts[] = {
		{"push", pushToStack},
		{"pall", printStack},
		{"pint", printTop},
		{"pop", removeTop},
		{"swap", swapTopTwo},
		{"add", addTopTwo},
		{"nop", doNothing},
		{"mul", mulTopTwo},
		{"sub", subTopTwo},
		{"div", divTopTwo},
		{"mod", modTopTwo},
		{"pchar", printchrTop},
		{NULL, NULL}
	};
	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s filename\n", av[0]);
		exit(EXIT_FAILURE);
	}

	getFile(&stack, av[1], insts);
	freeStackptr(stack);
	return (0);
}
