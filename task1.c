#include "monty.h"

/**
 * pop - Delete top of list
 * @stack_list: A doubly linked list
 * @line_num: The line number in the file being executed
 */
void pop(stack_t **stack_list, unsigned int line_num)
{
stack_t *temporary_size;

if (!*stack_list)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
free_all();
exit(EXIT_FAILURE);
}

temporary_size = *stack_list;
*stack_list = temporary_size->next;
if (temporary_size->next)
temporary_size->next->prev = NULL;
free(temporary_size);
}

/**
 * push - Insert a new n in list
 * @stack_list: A doubly linked list
 * @line_num: The line number in the file being executed
 */
void push(stack_t **stack_list, unsigned int line_num)
{
stack_t *tm = *stack_list;
char *num;
stack_t *temporary_size = NULL;

num = strtok(NULL, " \r\t\n");
if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
{
fprintf(stderr, "L%u: usage: push integer\n", line_num);
free_all();
exit(EXIT_FAILURE);
}
temporary_size = malloc(sizeof(stack_t));
if (!temporary_size)
{
fprintf(stderr, "Error: malloc failed\n");
free_all();
exit(EXIT_FAILURE);
}
temporary_size->n = atoi(num);
if (var.operation_mode == 0 || !*stack_list)
{
temporary_size->next = *stack_list;
temporary_size->prev = NULL;
if (*stack_list)
	(*stack_list)->prev = temporary_size;
*stack_list = temporary_size;
}
else
{
while (tm->next)
	tm = tm->next;
tm->next = temporary_size;
temporary_size->prev = tm;
temporary_size->next = NULL;
}
}
