#include "main.h"

/**
 * _atoi - A function that converts a string to an integer
 * @s: String to be converted to an integer
 * Return: The int converted from the string
 */
int _atoi(char *s)
{
	int j, e, m, len, g, digit;

	j = 0;
	e = 0;
	m = 0;
	len = 0;
	g = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (j < len && g == 0)
	{
		if (s[j] == '-')
			++e;

		if (s[j] >= '0' && s[j] <= '9')
		{
			digit = s[j] - '0';
			if (e % 2)
				digit = -digit;
			m = m * 10 + digit;
			g = 1;
			if (s[j + 1] < '0' || s[j + 1] > '9')
				break;
			g = 0;
		}
		j++;
	}

	if (f == 0)
		return (0);

	return (m);
}
