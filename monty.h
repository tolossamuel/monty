#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdlib.h>

#define INSTRUCTIONS              \
	{                           \
		{"push", push},       \
		    {"pall", pall},     \
			{"pint", pint},   \
		    {"pop", pop},     \
		    {"swap", swap},   \
		    {"nop", nop},     \
		    {"div", divTheValues},    \
		    {"mul", mul},    \
		    {"add", addNode},    \
		    {"sub", sub},    \
		    {"f_mod", f_mod},	\
		    {"pchar", f_pchar},	\
		    {"f_pstr", f_pstr},   \
		    {"rotl", rotl},   \
		    {"rotr", rotr},   \
		{                     \
			NULL, NULL      \
		}                     \
	}

/**
 * struct stack_s - doubly linked list representation of
 * a customStack (or queue)
 * @n: integer
 * @prev: points to the previous element of the customStack (or queue)
 * @next: points to the next element of the customStack (or queue)
 *
 * Description: doubly linked list node structure
 * for customStack, queues, LIFO, FIFO
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
 * for customStack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **customStack, unsigned int line_number);
} instruction_t;

/**
 * struct OpcodeInfo - Information for the current opcode.
 * @stackMode: The customStack mode, can be "customStack" (default) or "queue."
 * @argument: The arguments provided for the operation.
 * Description: This global structure facilitates data
 * sharing between functions.
 */

typedef struct OpcodeInfo
{
	int stackMode;
	char *argument;
} OpcodeInfo;
extern OpcodeInfo global;

/* customStack utility functions available in linked_list.c */
stack_t *addBeginning(stack_t **customStack, const int n);
stack_t *Queue(stack_t **customStack, const int n);
void freeStack(stack_t *customStack);
size_t printStack(const stack_t *customStack);

void push(stack_t **customStack, unsigned int line_num);
void pall(stack_t **customStack, unsigned int line_num);
void pint(stack_t **customStack, unsigned int line_num);
void swap(stack_t **customStack, unsigned int line_num);
void pop(stack_t **customStack, unsigned int line_num);
void nop(stack_t **customStack, unsigned int line_num);
void divTheValues(stack_t **customStack, unsigned int line_num);
void addNode(stack_t **customStack, unsigned int line_num);
void sub(stack_t **customStack, unsigned int line_num);
void mul(stack_t **customStack, unsigned int line_num);
void f_mod(stack_t **customStack, unsigned int line_num);
void f_pchar(stack_t **customStack, unsigned int line_num);
void f_pstr(stack_t **customStack, unsigned int line_num);
void rotl(stack_t **customStack, unsigned int line_num);
void rotr(stack_t **customStack, unsigned int line_count);
int isDigit(char *string);
int isNumber(char *string);
void opcode(stack_t **customStack, char *str, unsigned int line_num);


#endif /* MONTY_H */
