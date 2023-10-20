#include <ctype.h>
#include "monty.h"

/**
 * isDigit - Verifies if a string is a digit.
 *
 * @string: The string to check.
 *
 * Return: 1 if it's a digit, 0 if it's not.
 */
int isDigit(char *string)
{
	if (!string || *string == '\0')
	return (0);
	if (*string == '-')
	string++;
	while (*string)
	{
	if (isdigit(*string) == 0)
	return (0);
	string++;
	}
	return (1);
}
/**
 * isNumber - Determines whether a given string is a number.
 *
 * @string: The provided string.
 *
 * Return: 1 if the string is a number, otherwise, 0.
 */
int isNumber(char *string)
{
	int i;

	if (!string)
		return (0);

	for (i = 0; string[i]; i++)
		if (i < '0' || i > '9')
			return (0);

	return (1);
}
