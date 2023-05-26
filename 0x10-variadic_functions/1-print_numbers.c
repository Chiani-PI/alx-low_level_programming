#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - Function prints numbers, followed by a new line.
 * @separator: The string that will be printed between numbers.
 * @n: The number of integers passed into the function.
 * @...: The variable number of numbers that is to be printed.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list numss;
	unsigned int indice;

	va_start(numss, n);

	for (indice = 0; indice < n; indice++)
	{
		printf("%d", va_arg(numss, int));

		if (indice != (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");

	va_end(numss);
}
