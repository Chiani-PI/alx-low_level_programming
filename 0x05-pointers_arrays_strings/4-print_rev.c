#include "main.h"
/**
 * print_rev - A function that prints a string, in reverse,
 * followed by a new line
 * @s: string
 * Return: Always 0
 */

void print_rev(char *s)
{
	int longi = 0;
	int a;

	while (*s != '\0')
	{
		longi++;
		s++;
	}

	s--;

	for (a = longi; a > 0; a--)
	{
		_putchar(*s);
		s--;
	}
	_putchar('\n');
}
