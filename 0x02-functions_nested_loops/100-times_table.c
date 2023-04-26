#include "main.h"

/**
 * print_times_table - Function prints the n times table starting from 0
 * @n: integer to print times table up to
 * Return: void
 */
void print_times_table(int n)
{
	int a, b, prod;

	if (n >= 0 && n <= 15)
	{
		for (a = 0; a <= n; a++)
		{
			for (b = 0; b <= n; b++)
			{
				res = a * b;
				if (b == 0)
					printf("%d", prod);
				else
					printf(", %d", prod);
			}
			printf("\n");
		}
	}
}
