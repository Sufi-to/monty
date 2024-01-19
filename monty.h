#ifndef MONTY_H
#define MONTY_H


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void freestackptr(stack_t *h);
void getFile(stack_t **stack_ptr, const char *fd, instruction_t inst[]);
void exec_instr(stack_t **stack_ptr, FILE *montyF, instruction_t insts[]);
void pushToStack(stack_t **stack, unsigned int lnNum);
void printStack(stack_t **stack, unsigned int lnNum);
void printTop(stack_t **stack, unsigned int lnNum);
void removeTop(stack_t **stack, unsigned int lnNum);
void swapTopTwo(stack_t **stack, unsigned int lnNum);
void doNothing(stack_t **stack, unsigned int lnNum);
void addTopTwo(stack_t **stack, unsigned int lnNum);

#endif
