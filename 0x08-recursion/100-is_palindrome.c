#include "main.h"

int pal_check(char *s, int a, int len);
int _strlen_recursion(char *s);

/**
 * is_palindrome - A function that checks if a string is a palindrome.
 * @s: The string to be reversed.
 * Return: 1 if string is a palindrome, 0 if not
 */
int is_palindrome(char *s)
{
	if (*s == 0)
		return (1);
	return (pal_check(s, 0, _strlen_recursion(s)));
}

/**
 * _strlen_recursion - A funtion that returns the length of a string.
 * @s: The string whose length is to be calculated
 * Return: String length
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * pal_check - Function checks the characters recursively for palindrome.
 * @s: The string to be checked.
 * @a: The iterator.
 * @len: String length
 * Return: 1 if palindrome, 0 if not
 */
int pal_check(char *s, int a, int len)
{
	if (*(s + a) != *(s + len - 1))
		return (0);
	if (a >= len)
		return (1);
	return (pal_check(s, a + 1, len - 1));
}
