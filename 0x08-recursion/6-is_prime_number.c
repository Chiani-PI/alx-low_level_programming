#include "main.h"

int true_prime(int n, int a);

/**
 * is_prime_number - A function that checks if an integer is a prime number.
 * @n: The integer to be checked.
 * Return: 1 if the input integer is a prime number, otherwise return 0.
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (true_prime(n, n - 1));
}

/**
 * true_prime - A funtion that determines if an integer is prime recursively
 * @n: The integer to be checked.
 * @a: Integer to iterate
 *
 * Return: 1 if the input integer is a prime number, otherwise return 0
.
 */
int true_prime(int n, int a)
{
	if (a == 1)
		return (1);
	if (n % a == 0 && i > 0)
		return (0);
	return (true_prime(n, a - 1));
}
