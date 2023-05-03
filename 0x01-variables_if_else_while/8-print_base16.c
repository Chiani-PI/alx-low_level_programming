#include <stdio.h>

/**
 * main - This program prints all the numbers of base 16 in lowercase,
 * followed by a new line.
 * Return: Always 0 (Success)
 */

int main(void)
{
	int b;

	for (b = 48; b < 58; b++)
	{
		putchar(b);
	}
	for (b = 97; b < 103; b++)
	{
		putchar(b);
	}
	putchar('\n');
	return (0);
}
