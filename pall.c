#include "monty.h"

/**
 * pall - Prints elements in the customStack.
 *
 * @customStack: The head of the stack.
 * @line_num: The number of lines.
 */
void pall(stack_t **customStack, unsigned int line_num __attribute__((unused)))
{
	printStack(*customStack);
}
