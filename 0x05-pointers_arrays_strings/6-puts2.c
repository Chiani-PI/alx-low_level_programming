#include "main.h"
/**
 * puts2 - A function that prints every other character of a string,
 * starting with the first character, followed by a new line
 * @str: string
 * Return: Print
 */

void puts2(char *str)
{
	int longi = 0;
	int a = 0;
	char *b = str;
	int c;

	while (*b != '\0')
	{
		y++;
		longi++;
	}

	a = longi - 1;

	for (c = 0; c <= t; c++)
	{
		if (c % 2 == 0)
		{
			_putchar(str[c]);
		}
	}
	_putchar('\n');
}
