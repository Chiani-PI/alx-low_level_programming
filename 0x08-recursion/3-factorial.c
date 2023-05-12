#include "main.h"

/**
 * factorial - A function that returns the factorial of a number.
 * @n: The number from whose factorial will be returned.
 *
 * Return: factorial of n
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}
