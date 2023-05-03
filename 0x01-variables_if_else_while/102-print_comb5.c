#include <stdio.h>

/**
 * main - Program prints all possible combinations of two two-digit numbers.
 * Return: Always 0 (Success)
 */

int main(void)
{
	int f, g;

	for (f = 0; f < 100; f++)
	{
		for (g = 0; g < 100; g++)
		{
			if (f < g)
			{
				putchar((f / 10) + 48);
				putchar((f % 10) + 48);
				putchar(' ');
				putchar((g / 10) + 48);
				putchar((g % 10) + 48);

				if (f != 98 || g != 99)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
