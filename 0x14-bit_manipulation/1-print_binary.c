#include "main.h"

/**
 * print_binary - Function prints the binary representation of a given number
 * @n: The number which is to be printed in the binary rep
 */
void print_binary(unsigned long int n)
{
	int j, tally = 0;
	unsigned long int present;

	for (j = 63; j >= 0; j--)
	{
		present = n >> j;

		if (present & 1)
		{
			_putchar('1');
			tally++;
		}
		else if (tally)
			_putchar('0');
	}
	if (!tally)
		_putchar('0');
}
