#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#define ERR_MSG "Error"

/**
 * is_digit - Will check if a string contains a non-digit char
 * @s: string to be checked
 * Return: 0 if a non-digit is found, 1 otherwise
 */
int is_digit(char *s)
{
	int j = 0;

	while (s[j])
	{
		if (s[j] < '0' || s[j] > '9')
			return (0);
		j++;
	}
	return (1);
}

/**
 * _strlen - Function that returns the length of a string
 * @s: string to be checked
 * Return: String length
 */
int _strlen(char *s)
{
	int j = 0;

	while (s[j] != '\0')
	{
		j++;
	}
	return (j);
}

/**
 * errors - Function that treats errors in the main function
 */
void errors(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * main - Function multiplies two positive integers
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, len, j, take, digit1, digit2, *result, a = 0;

	s1 = argv[1], s2 = argv[2];
	if (argc != 3 || !is_digit(s1) || !is_digit(s2))
		errors();
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		return (1);
	for (j = 0; j <= len1 + len2; j++)
		result[j] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = s1[len1] - '0';
		take = 0;
		for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
		{
			digit2 = s2[len2] - '0';
			take += result[len1 + len2 + 1] + (digit1 * digit2);
			result[len1 + len2 + 1] = take % 10;
			take /= 10;
		}
		if (take > 0)
			result[len1 + len2 + 1] += take;
	}
	for (j = 0; j < len - 1; j++)
	{
		if (result[j])
			a = 1;
		if (a)
			_putchar(result[j] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
