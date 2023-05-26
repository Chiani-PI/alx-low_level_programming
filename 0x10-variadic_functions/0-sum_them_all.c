#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Function feturns the sum of all its paramters.
 * @n: The number of paramters passed to the function.
 * @...: Variable number of paramters whose sum is to be evaluated.
 *
 * Return: If n == 0 - 0
 * Otherwise - Sum of all parameters.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list bq;
	unsigned int j, sum = 0;

	va_start(bq, n);

	for (j = 0; j < n; j++)
		sum += va_arg(bq, int);

	va_end(bq);

	return (sum);
}
