#include "main.h"
/**
 * _strlen_recursion - A function that returns the length of a string.
 * @s: The string which will be measured.
 *
 * Return: Length of the string
 */
int _strlen_recursion(char *s)
{
	int longit = 0;

	if (*s)
	{
		longit++;
		longit += _strlen_recursion(s + 1);
	}

	return (longit);
}
