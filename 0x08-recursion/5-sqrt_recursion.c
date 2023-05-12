#include "main.h"

int true_sqrt_recursion(int n, int a);

/**
 * _sqrt_recursion - A function that returns the natural square root ofa number
 * @n: The number whose square root will be calculated.
 * Return: The computed square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (true_sqrt_recursion(n, 0));
}

/**
 * true_sqrt_recursion - A function that recurses to
 * find the natural square root of a number.
 * @n: The number whose square root will be calculated.
 * @a: That which will iterate.
 * Return: The computed square root.
 */
int true_sqrt_recursion(int n, int a)
{
	if (a * a > n)
		return (-1);
	if (a * a == n)
		return (a);
	return (true_sqrt_recursion(n, a + 1));
}
