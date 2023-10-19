#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>

#define Bufsize 30

/**
 * struct instruction_s - Opcode and its corresponding action function
 * @operation_code: The opcode string
 * @action_function: A pointer to the function that executes the action
 *
 * Description: This structure defines an operation code and its associated
 * function for stack, queues, LIFO, or FIFO operations.
 */

typedef struct instruction_s
{
char *operation_code;
void (*action_function)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct stack_s - Element in a Stack
 * @value: The value stored in the element
 * @prev: A pointer to the previous element in the stack
 * @next: A pointer to the next element in the stack
 *
 * Description: This structure represents an element within
 * a stack data structure.
 * It holds a value, and links to both the previous and next
 * elements in the stack.
 */
typedef struct stack_s
{
int value;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct glob_var - Global Variables for Program
 * @file_pointer: A pointer to the file being processed
 * @buffer: A character buffer used for temporary storage
 * @temporary_size: The size of temporary storage buffer
 * @opcode_dictionary: A pointer to the opcode dictionary
 * @stack_head: A pointer to the head of the stack
 * @current_line_number: The current line number in the input file
 * @operation_mode: The current mode of operation
 *
 * Description: This structure defines a collection of global variables used by
 * the program, including file handling, buffers, a dictionary of opcodes, the
 * stack head, the current line number, and the program's operation mode.
 */
typedef struct glob_var
{
FILE *file_pointer;
char *buffer;
size_t temporary_size;
instruction_t *opcode_dictionary;
stack_t *stack_head;
unsigned int current_line_number;
int operation_mode;
} vars;

extern vars var;
vars var;

void pall(stack_t **stack_list, unsigned int line_num);
void push(stack_t **stack_list, unsigned int line_num);
void pint(stack_t **stack_list, unsigned int line_num);

#endif
