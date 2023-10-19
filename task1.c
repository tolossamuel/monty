#include "monty.h"

/**
 * pop - Delete top of list
 * @stack_list: A doubly linked list
 * @line_num: The line number in the file being executed
 */
void pop(stack_t **stack_list, unsigned int line_num)
{
stack_t *h;

if (*stack_list == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
fclose(bus.file);
free(bus.content);
free_stack(*stack_list);
exit(EXIT_FAILURE);
}
h = *stack_list;
*stack_list = h->next;
free(h);
}

/**
 * push - Insert a new n in list
 * @stack_list: A doubly linked list
 * @line_num: The line number in the file being executed
 */
void push(stack_t **stack_list, unsigned int line_num)
{
int n, j = 0, flag = 0;

if (bus.arg)
{
if (bus.arg[0] == '-')
j++;
for (; bus.arg[j] != '\0'; j++)
{
if (bus.arg[j] > 57 || bus.arg[j] < 48)
	flag = 1; }
if (flag == 1)
{ fprintf(stderr, "L%d: usage: push integer\n", line_num);
fclose(bus.file);
free(bus.content);
free_stack(*stack_list);
exit(EXIT_FAILURE); }}
else
{ fprintf(stderr, "L%d: usage: push integer\n", line_num);
fclose(bus.file);
free(bus.content);
free_stack(*stack_list);
exit(EXIT_FAILURE); }
n = atoi(bus.arg);
if (bus.LiFi == 0)
addNode(stack_list, n);
else
addQueue(stack_list, n);
}

