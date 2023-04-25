 #include "main.h"
/**
 * int_islowe - A function that checks for lowercase character
 * @c: is the character to be checked
 * Return: 1 if c is lowercase, 0 otherwise
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
