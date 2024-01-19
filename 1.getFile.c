#include "monty.h"

/**
 * getFile - get cmd argument that is supposed to be
 * a monty file and handles it
 * @stack_ptr: pointer to the stack
 * @fd: name of the file
 * @insts: instruction to be carried out
 * Return: None
*/
void getFile(stack_t **stack_ptr, const char *fd, instruction_t insts[])
{
	FILE *montyF;

	montyF = fopen(fd, "r");
	if (montyF == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fd);
		exit(EXIT_FAILURE);
	}

	exec_instr(stack_ptr, montyF, insts);
	fclose(montyF);
}

/**
 * exec_instr - execute the functions
 * @stack_ptr: pointer to the stack
 * @insts: function to execute
 * @montyF: name of file
 * Return: none
*/
void exec_instr(stack_t **stack_ptr, FILE *montyF, instruction_t insts[])
{
	char read_montyF[BUFSIZ];
	char *opcode;
	unsigned int lnNum;
	int i;

	lnNum = 0;
	while (fgets(read_montyF, sizeof(read_montyF), montyF) != NULL)
	{
		lnNum++;
		opcode = strtok(read_montyF, " \n");
		if (opcode != NULL)
		{
			i = 0;
			while (insts[i].opcode != NULL)
			{
				if (strcmp(opcode, insts[i].opcode) == 0)
				{
					insts[i].f(stack_ptr, lnNum);
					break;
				}
				i++;
			}
		}
	}
}
