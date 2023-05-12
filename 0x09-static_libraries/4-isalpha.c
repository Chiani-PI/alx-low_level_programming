#include "main.h"
/**
 * _isalpha - This  function that checks for alphabetic character
 * @c: is the character to be checked
 * Return: 1 if c is a lette, 0 otherwise
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
