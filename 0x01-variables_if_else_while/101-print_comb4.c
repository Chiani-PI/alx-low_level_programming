#include <stdio.h>

/**
 * main - Program prints all possible different combinations of three digits.
 * Return: Always 0 (Success)
 */

int main(void)
{
	int c, d, e;

	for (c = 48; c < 58; c++)
	{
		for (d = 49; d < 58; d++)
		{
			for (e = 50; e < 58; e++)
			{
				if (e > d && d > c)
				{
					putchar(c);
					putchar(d);
					putchar(e);

					if (c != 55 || d != 56)
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
