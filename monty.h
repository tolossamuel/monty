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
 * @opcode: The opcode string
 * @f: A pointer to the function that executes the action
 *
 * Description: This structure defines an operation code and its associated
 * function for stack, queues, LIFO, or FIFO operations.
 */

typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct stack_s - Element in a Stack
 * @n: The n stored in the element
 * @prev: A pointer to the previous element in the stack
 * @next: A pointer to the next element in the stack
 *
 * Description: This structure represents an element within
 * a stack data structure.
 * It holds a n, and links to both the previous and next
 * elements in the stack.
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @LiFi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int LiFi;
}  bus_t;
extern bus_t bus;

void pall(stack_t **stack_list, unsigned int line_num);
void push(stack_t **stack_list, unsigned int line_num);
void pint(stack_t **stack_list, unsigned int line_num);
void addNode(stack_t **head, int n);
void addQueue(stack_t **head, int n);
void pop(stack_t **stack_list, unsigned int line_num);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void add(stack_t **head, unsigned int counter);
void div(stack_t **head, unsigned int counter);
void mod(stack_t **head, unsigned int counter);
void mul(stack_t **head, unsigned int counter);
void nop(stack_t **head, unsigned int counter);
void pchar(stack_t **head, unsigned int counter);
void pstr(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter);
void queue(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void free_stack(stack_t *head);
void f_stack(stack_t **head, unsigned int counter);

#endif
